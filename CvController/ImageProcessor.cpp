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

	void ImageProcessor::readImage(const std::string& path, cv::Mat* out) {
		*out = cv::imread(path, cv::IMREAD_COLOR);
	}
	bool ImageProcessor::writeImage(const std::string& path, const cv::Mat* in) {
		return cv::imwrite(path, *in);
		
 	}

	const int MaxWitdh::BRIGHTNESS = 255;
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
	void ImageProcessor::blur(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::BLUR);

		int sideSize = 3 + level * 2;
		cv::GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), 0.1 + level);
	}

	const int MaxLevel::SHARPNESS = 10;
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);

		int sideSize = 3 + (level / 2) * 2; /* levelの増加に応じて、3,3, 5,5, 7 ・・・と増える*/
		int centerIndex = sideSize / 2;

		/* 鮮鋭化フィルタ */
		Mat kernel(sideSize, sideSize, CV_64F);

		double sumReduceElement = -0.8 * (level + 1); /* 減算する要素数の合計 */
		double centerElement = -sumReduceElement + 1;

		int sidecount = sideSize / 2;
		/**
		 * 1画素当たりの減算する要素数
		 * 合計が、sumReduceElementとなるよう、ループ内で中心からの距離に応じて帳尻合わせをする。
		 */
		double localReduceElement = sumReduceElement / (8.0 * sidecount);

		for (int y = 0; y < sideSize; y++) {
			for (int x = 0; x < sideSize; x++) {
				if (y == centerIndex && x == centerIndex) {
					kernel.at<double>(centerIndex, centerIndex) = centerElement;
					continue;
				}
				/* 中心からのチェス盤距離 */
				int distanceFromCenter = std::max(std::abs(y - centerIndex), std::abs(x - centerIndex));
				kernel.at<double>(y, x) = localReduceElement / distanceFromCenter;
			}
		}

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}

	const int MaxLevel::PENCIL = 10;
	void ImageProcessor::drawWithPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		cv::cvtColor(*src, *dst, CV_RGB2GRAY);

		double topThreash = 200.0 - level * 20.0;
		double bottomThreash = 150.0 - level * 15.0;

		cv::Canny(*dst, *dst, topThreash, bottomThreash);

		cv::cvtColor(*dst, *dst, CV_GRAY2RGB);
		*dst = ~*dst;
	}

	void ImageProcessor::drawWithColorPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		Mat mask;
		drawWithPenclil(src, level, &mask);

		*dst = (*src + mask);
	}

	const int MaxLevel::OIL_PAINT = 10;
	void ImageProcessor::toOilPaint(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::OIL_PAINT);

		float windowWidth = 2.0f * level;
		float colorWidth = 5.0f * level;

		cv::pyrMeanShiftFiltering(*src, *dst, windowWidth, colorWidth);
	}


#define RAND(max) (rand() % (max))
#define DOUBLE_RAND() ((double) rand() / (double) RAND_MAX)
	
	const int MaxLevel::SNOW_STORM = 200;
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
			
			double angle = std::_Pi / 4.0; /* π/2 (45°)を基準に */
			angle += (DOUBLE_RAND() - 0.5) * std::_Pi / 9.0; /* 左右にπ/ 18 (3°)回転 */

			double ratio = 0.5 + 0.5 * DOUBLE_RAND(); /* 0.5 ～ 1.0の倍率 */
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


	const int MaxLevel::ORIGINAL = 10;
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		/* duumy */

	}
}