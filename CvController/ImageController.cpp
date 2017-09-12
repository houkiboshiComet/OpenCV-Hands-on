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

		ImageProcessor::changeBrightness(originalImage,
			Settings::toSignedValue(redSetting, 255), 
			Settings::toSignedValue(greenSetting, 255),
			Settings::toSignedValue(blueSetting, 255), 
			displayImage);

		int blurValue = Settings::toSignedValue(blurSetting, 10);

		if (blurValue > 0) {
			ImageProcessor::blur(displayImage, blurValue, displayImage);
		}
		else if (blurValue < 0) {
			ImageProcessor::sharpen(displayImage, std::abs(blurValue), displayImage);
		}

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
	void ImageController::updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur) {
		redSetting = r;
		greenSetting = g;
		blueSetting = b;
		blurSetting = blur;
	}

}