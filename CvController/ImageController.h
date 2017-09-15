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
		cv::Mat* effectedImage;
		cv::Mat* displayImage;
		setting_t redSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t greenSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t blueSetting = Settings::CENTRAL_SETTING_VALUE;
		setting_t blurSetting = Settings::CENTRAL_SETTING_VALUE;

		setting_t effectSetting = Settings::MIN_SETTING_VALUE;
		EffectType currentEffect = EffectType::NONE;

		void applyBaseSetting(const cv::Mat* src, cv::Mat* dst);
		void applyEffect(const cv::Mat* src, cv::Mat* dst);

	public:
		ImageController();
		~ImageController();
		void updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur);
		void updateEffect(setting_t setting, EffectType effect);

		cv::Mat getImage();
		void load(const std::string& imageFile);
		bool save(const std::string& imageFile);
	};
}

