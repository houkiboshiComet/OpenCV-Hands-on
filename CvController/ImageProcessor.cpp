#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using cv::Mat;
#include <random>

namespace OpenCVApp {

	template <typename T>
	void ImageProcessor::toSafeValue(T min, T* value, T max) {

		*value = std::max(min, *value);
		*value = std::min(max, *value);

	}

	/**
	* @brief <Hands-on EX1> �摜�����[�h����B
	* @param path �摜�t�@�C���̃p�X
	* @param out Mat�`���̉摜�̏����o����
	* @detail �摜��CV_8UC3�`���̃t���J���[�摜�Ƃ��ēǂݍ��܂��B
	*/
	void ImageProcessor::readImage(const std::string& path, cv::Mat* out) {
		*out = cv::imread(path, 0);
	}
	bool ImageProcessor::writeImage(const std::string& path, const cv::Mat* in) {
		return cv::imwrite(path, *in);
	}

	const int MaxWitdh::BRIGHTNESS = 255;
	/**
	* @brief <Hands-on EX2> �摜��RGB�̖��̖��邳��ύX����B
	* @param src �ϊ����̉摜
	* @param r �ԐF�̖��邳 ( -MaxWitdh::BRIGHTNESS <= r <= MaxWitdh::BRIGHTNESS )
	* @param g �ΐF�̖��邳 ( -MaxWitdh::BRIGHTNESS <= g <= MaxWitdh::BRIGHTNESS )
	* @param b �F�̖��邳 ( -MaxWitdh::BRIGHTNESS <= b <= MaxWitdh::BRIGHTNESS )
	* @param dst �ϊ���̉摜
	* @detail src��RGB����Mat�ɕ������A���ꂼ��̖��邳��ύX����B
	*/
	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst) {
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &r, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &g, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &b, MaxWitdh::BRIGHTNESS);

		std::vector<cv::Mat> rgb;
		split(*src, rgb);

		src->copyTo(*dst);
	}

	const int MaxLevel::BLUR = 10;
	/**
	* @brief <Hands-on EX3> �摜�ɂڂ������ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::BLUR )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�Ăڂ����̌��ʂ͋����Ȃ�B
	*/
	void ImageProcessor::blur(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::BLUR);
		src->copyTo(*dst);
	}

	const int MaxLevel::SHARPNESS = 10;
	/**
	* @brief <Hands-on EX4> �摜�ɑN�s�����ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::SHARPNESS )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�đN�s�����ʂ͋����Ȃ�B
	*/
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);

		Mat kernel(3, 3, CV_64F);
		kernel = cv::Scalar(0);
		kernel.at<double>(1, 1) = 1.0 - level * 0.1;

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}

	const int MaxLevel::PENCIL = 10;
	/**
	* @brief <Hands-on EX5.1> �摜�������M�ŕ`�����悤�Ȑ���摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst �ϊ���̉摜
	* @detail �摜����G�b�W�����o���邱�ƂŁA�摜���̗֊s�����o����B
	* �֊s�����A�w�i�𔒂Ƃ��邱�ƂŁA����摜�𓾂�B
	* level�ɔ�Ⴕ�đ����̃G�b�W�����o����B
	*/
	void ImageProcessor::drawWithPencil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		cv::cvtColor(*src, *dst, CV_RGB2GRAY);
		cv::cvtColor(*dst, *dst, CV_GRAY2RGB);

	}

	/**
	* @brief <Hands-on EX5.2> �摜��F���M�ŕ`�����悤�ȃt���J���[�̐���摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst �ϊ���̉摜
	* @detail �����̐�����쐬���A�}�X�N�Ƃ��邱�ƂŃt���J���[�̐���摜���쐬����B
	*/
	void ImageProcessor::drawWithColoredPencil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		Mat mask;
		drawWithPencil(src, level, &mask);

		src->copyTo(*dst);
	}

	const int MaxLevel::OIL_PAINT = 10;
	/**
	* @brief <Hands-on EX6> �摜����G�ŏ������悤�ȃN���X�^�����O���ꂽ�摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::OIL_PAINT )
	* @param dst �ϊ���̉摜
	* @detail �~�[���V�t�g�@��p���ĉ�f�l�N���X�^�����O���s���B
	* level�ɔ�Ⴕ�āA�N���X�^�����O�̕����g�傷��B(��G�c�ȃN���X�^�����O�ɂȂ�B)
	*/
	void ImageProcessor::toOilPaint(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::OIL_PAINT);
		src->copyTo(*dst);
	}


#define RAND(max) (rand() % (max))
#define DOUBLE_RAND() (((double) rand() * 2.0 / (double) RAND_MAX) - 1.0)
	const int MaxLevel::SNOW_STORM = 200;
	/**
	* @brief <Hands-on EX7> �摜�ɐ���̂悤�Ȍ��ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::SNOW_STORM )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�����̐Ⴊ�`�悳���B
	* ��̈ʒu�A�`��́A�A�t�B���ϊ��ɂ��K�����ƃ����_�����������Č��肳���B
	*/
	void ImageProcessor::causeSnowStorm(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SNOW_STORM);
		src->copyTo(*dst);

		srand((unsigned)time(NULL));

		Mat circle(20, 20, CV_8UC3, cv::Scalar(0));
		cv::circle(circle, cv::Point(10, 10), 5, cv::Scalar(200, 150, 150), -1, CV_AA);
		ImageProcessor::blur(&circle, 1, &circle);
		Mat canvas(src->size(), CV_8UC3);

		for (int i = 0; i < level; i++) {
			canvas = cv::Scalar(0);

			Mat matrix = (cv::Mat_<double>(2, 3) <<
				1.0, 0.0, RAND(src->cols),
				0.0, 1.0, 0);

			cv::warpAffine(circle, canvas, matrix, src->size(), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
			*dst += canvas;
		}

	}


	const int MaxLevel::DETECTION = 10;
	/**
	* @brief <Hands-on EX8> �摜�̒�����ړI�̕��̂��܂ދ�`�����o���A���̋�`��`�悷��B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::DETECTION )
	* @param cascade ���̌��o�̂��߂̃J�X�P�[�h���ފ�N���X�̃I�u�W�F�N�g
	* @param minNeighbors ���̌��ƂȂ��`�ɕK�v�ȁA�ŏ��̋ߖT��`��( 1 <= minNeighbors)
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�����ɕ��̌��o���s���B
	* ���o���镨�͈̂�����cascade�Ɉˑ�����B
	*/
	void ImageProcessor::detectObject(const cv::Mat* src, int level, cv::Mat* dst, cv::CascadeClassifier* cascade, int minNeighbors) {
		toSafeValue<int>(0, &level, MaxLevel::DETECTION);
		toSafeValue<int>(1, &minNeighbors, 0x7fffffff);

		src->copyTo(*dst);

		Mat graySubject;
		cv::cvtColor(*src, graySubject, cv::COLOR_BGR2GRAY);

		std::vector<cv::Rect> rects;

		for (auto rect : rects) {
			cv::rectangle(*dst, rect, cv::Scalar(100, 255, 100), 2);
		}
	}

	const int MaxLevel::ORIGINAL = 10;
	/**
	* @brief <Hands-on EX��> �摜�ɃI���W�i���̃G�t�F�N�g��������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::ORIGINAL )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�I���W�i���̃G�t�F�N�g�������B
	*/
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		src->copyTo(*dst);
	}

	/******************************************************************/
	// �ȉ��A�G�t�F�N�g�̃T���v�� 
	/******************************************************************/
	const int MaxLevel::DEFAULT = 10;
	const int MaxWitdh::DEFAULT = 10;

	void ImageProcessor::addStars(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::DEFAULT);
		src->copyTo(*dst);

		srand((unsigned)time(NULL));
		int sides = src->cols / 20;
		Mat star(sides, sides, CV_8UC3, cv::Scalar(0));
		cv::Point points[10];
		cv::Point trianglePoints[3];
		for (int i = 0; i < 10; i++) {
			double diameter = i % 2 == 0 ? sides / 5 : sides / 2;
			points[i] = cv::Point(
				(int)std::round(std::cos(std::_Pi  * i / 5.0) * diameter + sides / 2),
				(int)std::round(std::sin(std::_Pi  * i / 5.0) * diameter + sides / 2));
		}
		for (int i = 0; i < 5; i++) {
			int origin = i * 2;
			trianglePoints[0] = points[origin];
			trianglePoints[1] = points[(origin + 3) % 10];
			trianglePoints[2] = points[(origin + 7) % 10];
			cv::fillConvexPoly(star, trianglePoints, 3, cv::Scalar(150, 150, 150), CV_AA);
		}

		ImageProcessor::blur(&star, 1, &star);
		Mat canvas(src->size(), CV_8UC3);
		Mat colorStar = star.clone();
		for (int i = 0; i < level * 10; i++) {
			canvas = cv::Scalar(0);
			ImageProcessor::changeBrightness(&star, -RAND(100), -RAND(100), -RAND(100), &colorStar);

			double size = 1.0 + DOUBLE_RAND() * 0.5;
			double angle = 0.6 + 0.4 * DOUBLE_RAND(); /* 0.2 �` 1.0�̔{�� */
			Mat matrix = (cv::Mat_<double>(2, 3) <<
				size * std::sin(angle), -size * std::cos(angle), RAND(src->cols),
				size * std::cos(angle), size * std::sin(angle), RAND(src->rows));
			cv::warpAffine(colorStar, canvas, matrix, src->size(), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
			*dst += canvas;

		}
	}

	void ImageProcessor::toSepiaImage(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::DEFAULT);

		Mat sepiaImage;
		cv::cvtColor(*src, sepiaImage, cv::COLOR_RGB2GRAY);
		cv::cvtColor(sepiaImage, sepiaImage, cv::COLOR_GRAY2RGB);
		ImageProcessor::changeBrightness(&sepiaImage, 50, 20, -30, &sepiaImage);

		double ratio = (level + 1.0) / (MaxLevel::DEFAULT + 1.0);

		*dst = ratio* sepiaImage + (*src * (1.0 - ratio));
	}
	void ImageProcessor::skecth(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::DEFAULT);
		double ratio = (double)(MaxLevel::DEFAULT - level) / (MaxLevel::DEFAULT);

		float sigma_s = (float)(150.0 * ratio + 10.0); /* 10.0 �` 160.0 */
		float sigma_r = (float)(0.28 * ratio + 0.02);  /* 0.02 �` 0.30 */
		float shade_factor = (float)(0.07 * ratio + 0.01); /* 0.01 �` 0.08 */

		Mat grayResultBuff;
		cv::pencilSketch(*src, grayResultBuff, *dst, sigma_s, sigma_r, shade_factor);
	}

	void ImageProcessor::applyGammaCorrection(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(-MaxWitdh::DEFAULT, &level, MaxWitdh::DEFAULT);
		double gamma = pow(4.0, (double)level / MaxWitdh::DEFAULT);

		Mat table(1, 256, CV_8UC1);
		for (int i = 0; i < 256; i++) {
			table.at<uchar>(i) = (uchar)(pow((double)i / 255.0, 1.0 / gamma) * 255.0);
		}

		cv::LUT(*src, table, *dst);
	}
}