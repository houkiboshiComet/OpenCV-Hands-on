#include "ImageController.h"
#include "ImageProcessor.h"
#include "CvControlException.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace OpenCVApp {

	ImageController::ImageController()
	{
		originalImage = new Mat();
		displayImage = new Mat();
		completedImage = new Mat();
		effectedImage = new Mat();
		cascadeClassifier = new CascadeClassifier();
	}


	ImageController::~ImageController()
	{
		delete originalImage;
		delete displayImage;
		delete effectedImage;
		delete completedImage;
		delete cascadeClassifier;
	}

	Mat ImageController::getImage() {
		if (displayImage->empty()) {
			throw CvControlException("dsiplay image empty");
		}
		return *displayImage;
	}

	void ImageController::load(const std::string& imageFile) {
		ImageProcessor::readImage(imageFile, originalImage);

		if (originalImage->empty()) {
			throw CvControlException("cannot imread");
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
		originalImage->copyTo(*completedImage);
		originalImage->copyTo(*displayImage);
	}

	bool ImageController::save(const std::string& imageFile) {
		if (displayImage->empty()) {
			throw CvControlException("dsiplay image empty");
		}
		try {
			return ImageProcessor::writeImage(imageFile, displayImage);
		}
		catch (cv::Exception e) {
			throw CvControlException(e.what());
		}
	}

	void ImageController::setCascadeData(const std::string& xml) {

		try {
			cascadeClassifier->load(xml);
			if (cascadeClassifier->empty()) {
				throw CvControlException("cannot create cascade classifier from [" + xml + "]");
			}
		}
		catch (cv::Exception e) {
			throw CvControlException(e.what());
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
			ImageProcessor::drawWithPencil(src, level, dst);
			break;

		case EffectType::COLOR_PENCIL:
			level = Settings::toValue(effectSetting, MaxLevel::PENCIL);
			ImageProcessor::drawWithColoredPencil(src, level, dst);
			break;

		case EffectType::OIL_PAINT:
			level = Settings::toValue(effectSetting, MaxLevel::OIL_PAINT);
			ImageProcessor::toOilPaint(src, level, dst);
			break;

		case EffectType::SNOW_STORM:
			level = Settings::toValue(effectSetting, MaxLevel::SNOW_STORM);
			ImageProcessor::causeSnowStorm(src, level, dst);
			break;

		case EffectType::ORIGINAL:
			level = Settings::toValue(effectSetting, MaxLevel::ORIGINAL);
			ImageProcessor::applyOriginalEffect(src, level, dst);
			break;

		case EffectType::TWINKLE:
			level = Settings::toValue(effectSetting, MaxLevel::DEFAULT);
			ImageProcessor::addStars(src, level, dst);
			break;

		case EffectType::SEPIA:
			level = Settings::toValue(effectSetting, MaxLevel::DEFAULT);
			ImageProcessor::toSepiaImage(src, level, dst);
			break;

		case EffectType::SKETCH :
			level = Settings::toValue(effectSetting, MaxLevel::DEFAULT);
			ImageProcessor::skecth(src, level, dst);
			break;

		case EffectType::GAMMA:
			level = Settings::toSignedValue(effectSetting, MaxWitdh::DEFAULT);
			ImageProcessor::applyGammaCorrection(src, level, dst);
			break;

		case EffectType::NONE:
		default:
			src->copyTo(*dst);
			break;
		}

	}

	void ImageController::detectObject(setting_t setting, int minNeighbors) {
		if (completedImage->empty()) {
			throw CvControlException("Image for detection is empty.");
		}
		if (cascadeClassifier->empty()) {
			throw CvControlException("Cascade Classifier is empty.");
		}
		try {
			ImageProcessor::detectObject(
				completedImage,
				Settings::toValue(setting, MaxLevel::DETECTION),
				displayImage,
				cascadeClassifier,
				minNeighbors);
		}
		catch (cv::Exception e) {
			throw CvControlException(e.what());
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
			applyBaseSetting(effectedImage, completedImage);
			completedImage->copyTo(*displayImage);
		}
	}

	void ImageController::updateEffect(setting_t setting, EffectType effect) {

		currentEffect = effect;
		effectSetting = setting;

		if (!originalImage->empty()) {
			applyEffect(originalImage, effectedImage);
			applyBaseSetting(effectedImage, completedImage);
			completedImage->copyTo(*displayImage);
		}
	}

}
