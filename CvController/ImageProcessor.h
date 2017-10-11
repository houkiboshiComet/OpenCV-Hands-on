#pragma once

#include <string>

namespace cv{
	class Mat;
	class CascadeClassifier;
}

namespace OpenCVApp {

	class MaxLevel {
	public:
		static const int SHARPNESS;
		static const int BLUR;
		static const int PENCIL;
		static const int OIL_PAINT;
		static const int SNOW_STORM;
		static const int ORIGINAL;
		static const int DETECTION;
		static const int DEFAULT;
	};
	class MaxWitdh {
	public:
		static const int BRIGHTNESS;
		static const int DEFAULT;
	};

	class ImageProcessor
	{
	public:
		static void readImage(const std::string& path, cv::Mat* out);
		static bool writeImage(const std::string& path, const cv::Mat* in);

		static void changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst);
		static void blur(const cv::Mat* src, int level, cv::Mat* dst);
		static void sharpen(const cv::Mat* src, int level, cv::Mat* dst);
		static void drawWithPencil(const cv::Mat* src, int level, cv::Mat* dst);
		static void drawWithColoredPencil(const cv::Mat* src, int level, cv::Mat* dst);
		static void toOilPaint(const cv::Mat* src, int level, cv::Mat* dst);
		static void causeSnowStorm(const cv::Mat* src, int level, cv::Mat* dst);

		static void applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst);

		/*************** エフェクトのサンプル ********************/
		static void addStars(const cv::Mat* src, int level, cv::Mat* dst);
		static void toSepiaImage(const cv::Mat* src, int level, cv::Mat* dst);
		static void skecth(const cv::Mat* src, int level, cv::Mat* dst);
		static void applyGammaCorrection(const cv::Mat* src, int level, cv::Mat* dst);

		static void detectObject(const cv::Mat* src, int level, cv::Mat* dst, cv::CascadeClassifier* cascade, int minNeighbors);


	private:
		template <typename T>
		static void toSafeValue(T min, T* value, T max);
	};
}