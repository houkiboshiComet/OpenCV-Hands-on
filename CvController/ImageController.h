#pragma once
#include <string>
#include "Properties.h"

namespace cv{
	class Mat;
}


namespace OpenCVApp {
	class ImageController
	{
	private:
		cv::Mat* originalImage;
		cv::Mat* displayImage;
		setting_t redSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t greenSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t blueSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t blurSetting = Settings::CENTRAL_SETTING_VALUE;
		

	public:
		ImageController();
		~ImageController();
		void updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur);

		cv::Mat getImage();
		void update(const std::string& imageFile);
	};

	class ImagingExeption : std::runtime_error {
		
	};
}

