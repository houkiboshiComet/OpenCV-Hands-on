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
	* @brief <Handson EX1> �摜�����[�h����B
	* @param path �摜�t�@�C���̃p�X
	* @param out Mat�`���̉摜�̏����o����
	* @detail �摜��CV_8UC3�`���̃t���J���[�摜�Ƃ��ēǂݍ��܂��B
	*/
	void ImageProcessor::readImage(const std::string& path, cv::Mat* out) {
		*out = cv::imread(path, cv::IMREAD_COLOR); 
	}
	bool ImageProcessor::writeImage(const std::string& path, const cv::Mat* in) {
		return cv::imwrite(path, *in);
		
 	}

	const int MaxWitdh::BRIGHTNESS = 255;
	/**
	* @brief <Handson EX2> �摜��RGB�̖��̖��邳��ύX����B
	* @param src �ϊ����̉摜
	* @param r �ԐF�̖��邳 ( -MaxWitdh::BRIGHTNESS <= r <= MaxWitdh::BRIGHTNESS )
	* @param g �ΐF�̖��邳 ( -MaxWitdh::BRIGHTNESS <= g <= MaxWitdh::BRIGHTNESS )
	* @param b �F�̖��邳 ( -MaxWitdh::BRIGHTNESS <= b <= MaxWitdh::BRIGHTNESS )
	* @param dst �ϊ���̉摜
	* @detail src��rgb����Mat�ɕ������A���ꂼ��̖��邳��ύX����B
	*/
	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst) {
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &r, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &g, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &b, MaxWitdh::BRIGHTNESS);

		std::vector<cv::Mat> rgb;

		split(*src, rgb);

		rgb[0] += b;
		rgb[1] += g;
		rgb[2] += r;

		merge(rgb, *dst);
	}

	const int MaxLevel::BLUR = 10;
	/**
	* @brief <Handson EX3> �摜�ɂڂ������ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::BLUR )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�Ăڂ����̌��ʂ͋����Ȃ�B
	*/
	void ImageProcessor::blur(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::BLUR);

		int sideSize = 3 + level * 2;
		cv::GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), 0.1 + level);
	}

	const int MaxLevel::SHARPNESS = 10;
	/**
	* @brief <Handson EX4> �摜�ɑN�s�����ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::SHARPNESS )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�đN�s�����ʂ͋����Ȃ�B
	*/
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);

		int sideSize = 3 + (level / 2) * 2; /* level�̑����ɉ����āA3,3, 5,5, 7 �E�E�E�Ƒ�����*/
		int centerIndex = sideSize / 2;

		/* �N�s���t�B���^ */
		Mat kernel(sideSize, sideSize, CV_64F);

		double sumReduceElement = -0.8 * (level + 1); /* ���Z����v�f���̍��v */
		double centerElement = -sumReduceElement + 1;

		int sidecount = sideSize / 2;
		/**
		 * 1��f������̌��Z����v�f��
		 * ���v���AsumReduceElement�ƂȂ�悤�A���[�v���Œ��S����̋����ɉ����Ē��K���킹������B
		 */
		double localReduceElement = sumReduceElement / (8.0 * sidecount);

		for (int y = 0; y < sideSize; y++) {
			for (int x = 0; x < sideSize; x++) {
				if (y == centerIndex && x == centerIndex) {
					kernel.at<double>(centerIndex, centerIndex) = centerElement;
					continue;
				}
				/* ���S����̃`�F�X�Ջ��� */
				int distanceFromCenter = std::max(std::abs(y - centerIndex), std::abs(x - centerIndex));
				kernel.at<double>(y, x) = localReduceElement / distanceFromCenter;
			}
		}

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}

	const int MaxLevel::PENCIL = 10;
	/**
	* @brief <Handson EX5.1> �摜�������M�ŕ`�����悤�Ȑ���摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst �ϊ���̉摜
	* @detail �摜����G�b�W�����o���邱�ƂŁA�摜���̗֊s�����o����B
	* �֊s�����A�w�i�𔒂Ƃ��邱�ƂŁA����摜�𓾂�B
	* level�ɔ�Ⴕ�đ����̃G�b�W�����o����B
	*/
	void ImageProcessor::drawWithPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		cv::cvtColor(*src, *dst, CV_RGB2GRAY);

		double topThreash = 200.0 - level * 20.0;
		double bottomThreash = 150.0 - level * 15.0;

		cv::Canny(*dst, *dst, topThreash, bottomThreash);

		cv::cvtColor(*dst, *dst, CV_GRAY2RGB);
		*dst = ~*dst;
	}

	/**
	* @brief <Handson EX5.2> �摜��F���M�ŕ`�����悤�ȃt���J���[�̐���摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst �ϊ���̉摜
	* @detail �����̐�����쐬���A�}�X�N�Ƃ��邱�ƂŃt���J���[�̐���摜���쐬����B
	*/
	void ImageProcessor::drawWithColorPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		Mat mask;
		drawWithPenclil(src, level, &mask);

		*dst = (*src + mask);
	}

	const int MaxLevel::OIL_PAINT = 10;
	/**
	* @brief <Handson EX6> �摜����G�ŏ������悤�ȃN���X�^�����O���ꂽ�摜�ɕϊ�����B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::OIL_PAINT )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�N���X�^�����O�̕����g�傷��B(��G�c�ȃN���X�^�����O�ɂȂ�B)
	*/
	void ImageProcessor::toOilPaint(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::OIL_PAINT);

		float windowWidth = 2.0f * level;
		float colorWidth = 5.0f * level;

		cv::pyrMeanShiftFiltering(*src, *dst, windowWidth, colorWidth);
	}


#define RAND(max) (rand() % (max))
#define DOUBLE_RAND() (((double) rand() * 2.0 / (double) RAND_MAX) - 1.0)
	const int MaxLevel::SNOW_STORM = 200;
	/**
	* @brief <Handson EX7> �摜�ɐ���̂悤�Ȍ��ʂ�������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::SNOW_STORM )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�����̐Ⴊ�`�悳���B
	* ��̈ʒu�A�`��́A�A�t�B���ϊ��ɂ��K�����ƃ����_�����������Č��肳���B
	*/
	void ImageProcessor::causeSnowStorm(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SNOW_STORM);
		src->copyTo(*dst);

		srand((unsigned) time(NULL));

		Mat circle(20, 20, CV_8UC3, cv::Scalar(0));
		cv::circle(circle, cv::Point(10, 10), 5, cv::Scalar(200, 150, 150), -1, CV_AA);
		ImageProcessor::blur(&circle, 1, &circle);
		Mat canvas(src->size(), CV_8UC3);

		for (int i = 0; i < level; i++) {
			canvas = cv::Scalar(0);
			
			double angle = std::_Pi / 4.0; /* ��/4 (45��)����� */
			angle += DOUBLE_RAND() * std::_Pi / 10; /* ���E�ɍő��/ 18 (10��)��] */

			double ratio = 0.5 + 0.5 * DOUBLE_RAND(); /* 0.5 �` 1.0�̔{�� */
			double height = 1.0 * ratio;
			double width = 2.0 * ratio;
			/*
			 * | sin -cos |   | w 0 |   | w*sin -h*cos |
			 * | cos  sin | X | 0 h | = | w*cos  h*sin |
			**/
			Mat matrix = (cv::Mat_<double>(2, 3) <<
				width * std::sin(angle), -height * std::cos(angle), RAND(src->cols),
				width * std::cos(angle),  height * std::sin(angle), RAND(src->rows));
			
			cv::warpAffine(circle, canvas, matrix, src->size(), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
			*dst += canvas;
		}

	}


	

	const int MaxLevel::DETECTION = 10;
	/**
	* @brief <Handson EX8> �摜�̒�����ړI�̕��̂��܂ދ�`�����o���A���̋�`��`�悷��B
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
		toSafeValue<int>(1, &minNeighbors, 0x7ffffff );

		double scaleFactor = 1.55 - 0.5 * (level / (double) MaxLevel::DETECTION);

		src->copyTo(*dst);
		
		Mat graySubject;
		cv::cvtColor(*src, graySubject, cv::COLOR_BGR2GRAY);

		std::vector<cv::Rect> rects;
	
		cascade->detectMultiScale(graySubject, rects, scaleFactor, minNeighbors);

		for (auto rect : rects) {
			cv::rectangle(*dst, rect, cv::Scalar(100,255,100), 2);
		}
	}

	const int MaxLevel::ORIGINAL = 10;
	/**
	* @brief <Handson EX��> �摜�ɃI���W�i���̃G�t�F�N�g��������B
	* @param src �ϊ����̉摜
	* @param level ���ʂ̃��x�� ( 0 <= level <=  MaxLevel::ORIGINAL )
	* @param dst �ϊ���̉摜
	* @detail level�ɔ�Ⴕ�āA�I���W�i���̃G�t�F�N�g�������B
	*/
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		src->copyTo(*dst);
	}
}