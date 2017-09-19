// CvController.h

#pragma once

using namespace System;

#include <string>

namespace cv{
	class Mat;
}

#using <system.drawing.dll>
#include "ImageController.h"


namespace OpenCVApp {

	public ref class ImagingWrapper
	{
	public:
		void load(String^ fileName);
		void save(String^ fileName);
		void setCascadeData(String^ xml);
		
		System::Drawing::Bitmap^ getImage();
		void updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur);
		static array<String^>^ getEffectNames();
		static int MAX_SETTING_VALUE();
		static int MIN_SETTING_VALUE();
		static int CENTRAL_SETTING_VALUE();
		void updateEffect(String^ name, setting_t setting);
		void detectObject(setting_t setting, int minNeighbors);

		ImagingWrapper();
		~ImagingWrapper();

	private:
		ImageController* controller;

		static EffectType toEffect(String^ str);
		static System::Drawing::Bitmap^ toBitmap(const cv::Mat* src);
		static std::string toStdStr(String^ src);

	};	

}
