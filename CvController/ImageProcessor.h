#pragma once
namespace cv{
	class Mat;
}

namespace OpenCVApp {
	class ImageProcessor
	{
	public:
		static void changeBrightness(const cv::Mat* src, int r, int g, int b, const cv::Mat* dst);
	};
}