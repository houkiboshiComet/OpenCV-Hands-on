#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using cv::Mat;

namespace OpenCVApp {

	template <typename T>
	void ImageProcessor::toSafeValue(T min, T* value, T max) {

		*value = std::max(min, *value);
		*value = std::min(max, *value);

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
		cv::GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), (double)level);
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

	const int MaxLevel::SNOW_STORM = 100;
	void ImageProcessor::causeSnowStorm(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SNOW_STORM);
		/* TO DO
		 case snow storm by Affine transformation */

	}


	const int MaxLevel::ORIGINAL = 10;
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		/* duumy */

	}
}