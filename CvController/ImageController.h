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
		int redSetting = Properties::CENTRAL_SETTING_VALUE;
		int greenSetting = Properties::CENTRAL_SETTING_VALUE;
		int blueSetting = Properties::CENTRAL_SETTING_VALUE;
		int blurSetting = Properties::CENTRAL_SETTING_VALUE;

		static int toSignedValue(int setting, int maxAbs);

	public:
		ImageController();
		~ImageController();
		void updateBaseSettings(int r, int g, int b, int blur);

		cv::Mat getImage();
		void update(const std::string& imageFile);
	};

	class ImagingExeption : std::runtime_error {
		
	};
}

