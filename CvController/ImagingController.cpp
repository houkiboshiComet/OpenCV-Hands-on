#include "ImagingController.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace OpenCVApp {
	
	ImagingController::ImagingController()
	{
		originalImage = new Mat();
	}


	ImagingController::~ImagingController()
	{
		delete originalImage;
	}

	Mat ImagingController::getImage() {
		return *originalImage;
	}

	void ImagingController::update(const std::string& imageFile) {
		/* EX 1.1 */
		*originalImage = imread(imageFile, 0);
		
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
	}


}