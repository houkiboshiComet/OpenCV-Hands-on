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
		effectedImage = new Mat();

	}


	ImageController::~ImageController()
	{
		delete originalImage;
		delete displayImage;
		delete effectedImage;
	}

	Mat ImageController::getImage() {
		if (displayImage->empty()) {
			throw std::runtime_error("dsiplayss image empty");
		}
		return *displayImage;
	}

	void ImageController::load(const std::string& imageFile) {
		ImageProcessor::readImage(imageFile, originalImage);
		
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
		originalImage->copyTo(*effectedImage);
		originalImage->copyTo(*displayImage);
	}

	bool ImageController::save(const std::string& imageFile) {
		if (displayImage->empty()) {
			return false;
		}
		try {
			return ImageProcessor::writeImage(imageFile, displayImage);
		}
		catch (cv::Exception e) {
			throw std::runtime_error(e.what());
		}
	}

	void ImageController::applyBaseSetting(const Mat* src, Mat* dst) {

		ImageProcessor::changeBrightness(src,
			Settings::toSignedValue(redSetting, 255),
			Settings::toSignedValue(greenSetting, 255),
			Settings::toSignedValue(blueSetting, 255),
			dst);

		if (blurSetting > Settings::CENTRAL_SETTING_VALUE) {
			int blurLevl = Settings::toSignedValue(blurSetting, MaxLevel::BLUR);
			ImageProcessor::blur(dst, blurLevl, dst);
		}
		else if (blurSetting < Settings::CENTRAL_SETTING_VALUE) {
			int sharpLevel = std::abs(Settings::toSignedValue(blurSetting, MaxLevel::SHARPNESS));
			ImageProcessor::sharpen(dst, sharpLevel, dst);
		}
	}

	void ImageController::applyEffect(const Mat* src, Mat* dst) {

		if (effectSetting <= Settings::MIN_SETTING_VALUE) {
			src->copyTo(*dst);
			return;
		}

		int level = 0;
		switch (currentEffect)
		{
		case EffectType::BALCK_PENCIL:
			level = Settings::toValue(effectSetting, MaxLevel::PENCIL);
			ImageProcessor::drawWithPenclil(src, level, dst);
			break;

		case EffectType::COLOR_PENCIL:
			level = Settings::toValue(effectSetting, MaxLevel::PENCIL);
			ImageProcessor::drawWithColorPenclil(src, level, dst);
			break;

		case EffectType::OIL_PAINT:
			level = Settings::toValue(effectSetting, MaxLevel::OIL_PAINT);
			ImageProcessor::toOilPaint(src, level, dst);
			break;

		case EffectType::SNOW_STORM:
			level = Settings::toValue(effectSetting, MaxLevel::SNOW_STORM);
			ImageProcessor::causeSnowStorm(src, level, dst);
			break;

		case  EffectType::ORIGINAL:
			level = Settings::toValue(effectSetting, MaxLevel::ORIGINAL);
			ImageProcessor::applyOriginalEffect(src, level, dst);
			break;

		case EffectType::NONE:
		default:
			src->copyTo(*dst);
			break;
		}

	}


	void ImageController::updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur) {

		redSetting = r;
		greenSetting = g;
		blueSetting = b;
		blurSetting = blur;

		/* effectedImage作成はコストが重いため、
		既に作成したものを使いまわす。*/
		if (!effectedImage->empty()) {
			applyBaseSetting(effectedImage, displayImage);
		}
	}

	void ImageController::updateEffect(setting_t setting, EffectType effect) {

		currentEffect = effect;
		effectSetting = setting;

		if (!originalImage->empty()) {
			applyEffect(originalImage, effectedImage);
			applyBaseSetting(effectedImage, displayImage);
		}
	}

}
