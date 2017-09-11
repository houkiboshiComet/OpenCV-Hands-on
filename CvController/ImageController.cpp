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
		ImageProcessor::changeBrightness(originalImage, 
			toSignedValue(redSetting, 255), toSignedValue(greenSetting, 255), 
			toSignedValue(blueSetting, 255), displayImage);
		
		return *displayImage;
	}

	int ImageController::toSignedValue(int setting, int maxAbs) {
		
		int base = setting - Properties::CENTRAL_SETTING_VALUE;
		double ratioToResult = 2.0 * maxAbs / 
			(double) ( Properties::MAX_SETTING_VALUE - Properties::MIN_SETTING_VALUE);
		
		int result = (int)std::round(ratioToResult * base);
		
		return result > 0 ? std::min(result, maxAbs) : std::max(result, -maxAbs);
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
	void ImageController::updateBaseSettings(int r, int g, int b, int blur) {
		redSetting = r;
		greenSetting = g;
		blueSetting = b;
		blurSetting = blur;
	}

}