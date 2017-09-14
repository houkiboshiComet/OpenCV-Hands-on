#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace OpenCVApp {

	template <typename T>
	void ImageProcessor::toSafeValue(T min, T* value, T max) {

		*value = std::max(min, *value);
		*value = std::min(max, *value);

	}

	const int MaxWitdh::BRIGHTNESS = 255;
	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst) {
		toSafeValue<int>(- MaxWitdh::BRIGHTNESS, &r, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(- MaxWitdh::BRIGHTNESS, &g, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(- MaxWitdh::BRIGHTNESS, &b, MaxWitdh::BRIGHTNESS);

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
		GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), (double) level);
	}
	
	const int MaxLevel::SHARPNESS = 10;
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);
		
		int sideSize = 3 + (level / 3) * 2; /* levelの増加に応じて、3,3,3, 5,5,5, 7 ・・・と増える*/
		int centerIndex = sideSize / 2;

		double intensity = level * 0.01;
		double intensitySum = 0.0;

		Mat kernel(sideSize, sideSize, CV_64F);
		
		for (int y = 0; y < sideSize; y++) {
			for (int x = 0; x < sideSize; x++) {
				if (y == centerIndex && x == centerIndex) {
					continue;
				}
				double localIntensity = -intensity / (std::abs(y - centerIndex) + std::abs(x - centerIndex));
				kernel.at<double>(y, x) = -localIntensity;
				intensitySum += localIntensity;
			}
		}
		kernel.at<double>(centerIndex, centerIndex) = intensitySum + 1;

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}

	const int MaxLevel::EDGE = 10;
	void ImageProcessor::detectEdge(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);
		
		cvtColor(*src, *dst, CV_RGB2GRAY);
		
		double topThreash = 200.0 - level * 20.0;
		double bottomThreash = 150.0 - level * 15.0;

		cv::Canny(*dst, *dst, topThreash, bottomThreash);
		cvtColor(*dst, *dst, CV_GRAY2RGB);
		
		*dst = ~*dst;
	}

	const int MaxLevel::ORIGINAL = 10;
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		//meanShift
	}
}