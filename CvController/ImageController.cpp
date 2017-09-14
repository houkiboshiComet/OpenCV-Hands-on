#include "ImageController.h"
#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace OpenCVApp {
	
	ImageController::ImageController()
	{
		originalImage = new Mat();
		displayImage = new Mat();

	}


	ImageController::~ImageController()
	{
		delete originalImage;
		delete displayImage;
	}

	Mat ImageController::getImage() {
		if (originalImage->empty()) {
			throw std::runtime_error("image empty");
		}
		applyBaseSetting(originalImage, displayImage);
		applyEffect(displayImage, displayImage);
		
		return *displayImage;
	}

	void ImageController::update(const std::string& imageFile) {
		/* EX 1.1 */
		*originalImage = imread(imageFile, IMREAD_COLOR);
		if (originalImage->empty()) {
			throw std::runtime_error("cannot imread");
		}
		switch (originalImage->type())
		{
		case CV_8UC1:
			cvtColor(*originalImage, *originalImage, CV_GRAY2BGR);
			break;

		case CV_8UC4:
			cvtColor(*originalImage, *originalImage, CV_BGRA2RGB);
			break;

		case CV_8UC3:
		default:
			break;
		}
		originalImage->copyTo(*displayImage);
	}

	void ImageController::applyBaseSetting(const Mat* src, Mat* dst) {
		
		ImageProcessor::changeBrightness(src,
			Settings::toSignedValue(redSetting, 255),
			Settings::toSignedValue(greenSetting, 255),
			Settings::toSignedValue(blueSetting, 255),
			dst);

		if (blurSetting > Settings::CENTRAL_SETTING_VALUE) {
			int blurLevl = Settings::toSignedValue(blurSetting, MaxLevel::BLUR);
			ImageProcessor::blur(src, blurLevl, dst);
		}
		else if (blurSetting < Settings::CENTRAL_SETTING_VALUE) {
			int sharpLevel = std::abs(Settings::toSignedValue(blurSetting, MaxLevel::EDGE));
			ImageProcessor::sharpen(src, sharpLevel, dst);
		}
	}

	void ImageController::applyEffect(const Mat* src, Mat* dst) {

		if (effectSetting <= Settings::MIN_SETTING_VALUE) {
			return;
		}
		switch (currentEffect)
		{
		case EffectType::BALCK_PENCIL: {
										   int edgeLevel = Settings::toValue(effectSetting, MaxLevel::EDGE);
										   ImageProcessor::detectEdge(src, edgeLevel, dst);
										  
		} break;
			
		case EffectType::COLOR_PENCIL: {
										   int edgeLevel = Settings::toValue(effectSetting, MaxLevel::EDGE);
										   Mat mask;
										   ImageProcessor::detectEdge(src, edgeLevel, &mask);
										   
										   *dst += mask;
		} break;

		case  EffectType::ORIGINAL: {
										int level = Settings::toValue(effectSetting, MaxLevel::ORIGINAL);
										ImageProcessor::applyOriginalEffect(src, 10, dst);
		}
		case EffectType::NONE :
		default:
			break;
		}

	}


	void ImageController::updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur) {
		redSetting = r;
		greenSetting = g;
		blueSetting = b;
		blurSetting = blur;
	}

	void ImageController::updateEffect(setting_t setting, EffectType effect) {
		currentEffect = effect;
		effectSetting = setting;
	}

}