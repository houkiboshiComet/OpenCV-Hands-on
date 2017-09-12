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

	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst) {
		toSafeValue<int>(-255, &r, 255);
		toSafeValue<int>(-255, &g, 255);
		toSafeValue<int>(-255, &b, 255);

		std::vector<cv::Mat> rgb;
		
		split(*src, rgb);
		
		rgb[0] += b;
		rgb[1] += g;
		rgb[2] += r;

		merge(rgb, *dst);
	}

	void ImageProcessor::blur(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, 10);

		int sideSize = 3 + level * 2;
		GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), (double) level);
	}
	
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, 10);
		
		int sideSize = 3 + (level / 2) * 2; /* (level / 2) * 2 ÇÕ2ÇÃî{êîÇï€èÿÇ∑ÇÈÇΩÇﬂ */
		int centerIndex = sideSize / 2;

		double intensity = level * 0.05;
		double intensitySum = 0.0;

		Mat kernel(sideSize, sideSize, CV_64F);
		
		for (int y = 0; y < sideSize; y++) {
			for (int x = 0; x < sideSize; x++) {
				if (y == centerIndex && x == centerIndex) {
					continue;
				}
				kernel.at<double>(y, x) = -intensity;
				intensitySum += intensity;
			}
		}
		kernel.at<double>(centerIndex, centerIndex) = intensitySum + 1;

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}


}