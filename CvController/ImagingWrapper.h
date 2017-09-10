// CvController.h

#pragma once

using namespace System;
#include <string>

namespace cv{
	class Mat;
}

#using <system.drawing.dll>
#include "ImagingController.h"

namespace OpenCVApp {

	public ref class ImagingWrapper
	{
	public:
		System::Drawing::Bitmap^ read(String^ fileName);

		ImagingWrapper();
		~ImagingWrapper();

	private:
		ImagingController* controller;


		static System::Drawing::Bitmap^ toBitmap(const cv::Mat* src);
		static std::string toStdStr(String^ src);

	};
}
