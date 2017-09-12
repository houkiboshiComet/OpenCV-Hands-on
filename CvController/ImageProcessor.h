#pragma once
namespace cv{
	class Mat;
}

namespace OpenCVApp {
	class ImageProcessor
	{
	public:
		static void changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst);
		static void blur(const cv::Mat* src, int level, cv::Mat* dst);
		static void sharpen(const cv::Mat* src, int level, cv::Mat* dst);

	private:
		template <typename T>
		static void toSafeValue(T min, T* value,  T max);
	};
}