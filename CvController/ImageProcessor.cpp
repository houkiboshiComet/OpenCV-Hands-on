#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace OpenCVApp {
	
	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, const cv::Mat* dst) {

		std::vector<cv::Mat> rgb;
		Mat intermediate = src->clone();  // ���摜�����������Ȃ��悤�f�B�[�v�R�s�[
		
		split(intermediate, rgb);
		
		rgb[0] += b;
		rgb[1] += g;
		rgb[2] += r;

		merge(rgb, *dst);
	}
}