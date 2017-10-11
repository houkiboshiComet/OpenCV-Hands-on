#include "ImagingWrapper.h"
#include "Properties.h"
#include "ImagingException.h"
#include "CvControlException.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#pragma managed
#include <iostream>
#include <string>

using namespace System::Drawing;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

namespace OpenCVApp {

	void ImagingWrapper::load(String^ fileName) {
		try {
			controller->load(toStdStr(fileName));
		}
		catch (CvControlException e) {
			throw gcnew ImagingException(gcnew String(e.what()));
		}
	}
	void ImagingWrapper::save(String^ fileName) {
		try {
			if (!controller->save(toStdStr(fileName))) {
				throw gcnew ImagingException("failed to save " + fileName);
			}
		}
		catch (CvControlException e) {
			throw gcnew ImagingException(gcnew String(e.what()));
		}
	}

	void ImagingWrapper::setCascadeData(String^ xml) {
		try {
			controller->setCascadeData(toStdStr(xml));
		}
		catch (CvControlException e) {
			throw gcnew ImagingException(gcnew String(e.what()));
		}
	}

	System::Drawing::Bitmap^ ImagingWrapper::getImage() {
		try {
			cv::Mat mat = controller->getImage();
			return toBitmap(&mat);
		}
		catch (CvControlException) {
			return nullptr;
		}
	}

	ImagingWrapper::ImagingWrapper() {
		controller = new ImageController();
	}

	ImagingWrapper::~ImagingWrapper() {
		delete controller;
	}


	Bitmap^ ImagingWrapper::toBitmap(const cv::Mat* src) {

		IplImage iplImage = *src;
		Bitmap^ bmp = gcnew Bitmap(iplImage.width, iplImage.height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

		Drawing::Imaging::BitmapData^ bd = bmp->LockBits(Rectangle(0, 0, iplImage.width, iplImage.height), Drawing::Imaging::ImageLockMode::WriteOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

		for (int i = 0; i < iplImage.height; i++) {
			uchar *p = (uchar *)bd->Scan0.ToPointer() + i * bd->Stride;
			memcpy(p, iplImage.imageData + iplImage.widthStep * i, iplImage.widthStep);
		}

		bmp->UnlockBits(bd);
		return bmp;

	}
	std::string ImagingWrapper::toStdStr(String^ src) {
		using namespace System::Runtime::InteropServices;

		int len = System::Text::Encoding::GetEncoding("UTF-8")->GetByteCount(src);

		char* charArray = new char[len + 1];
		memset(charArray, 0x00, sizeof(char)*len + 1);

		const char* buf = static_cast<const char*>((Marshal::StringToHGlobalAnsi(src)).ToPointer());
		strncpy_s(charArray, len + 1, buf, _TRUNCATE);
		Marshal::FreeHGlobal(IntPtr((void*)buf));

		std::string result = std::string(charArray);
		delete[] charArray;

		return result;
	}

	void ImagingWrapper::updateBaseSettings(setting_t r, setting_t g, setting_t b, setting_t blur) {
		controller->updateBaseSettings(
			Settings::toSafety(r),
			Settings::toSafety(g),
			Settings::toSafety(b),
			Settings::toSafety(blur)
			);
	}
	
	EffectType ImagingWrapper::toEffect(String^ str) {
		std::string stdStr = toStdStr(str);

		for (int i = 0; i < Effects::EFFECT_COUNT; i++) {
			if (stdStr == Effects::set[i].name) {
				return Effects::set[i].type;
			}
		}
		return EffectType::NONE;
	}

	array<String^>^ ImagingWrapper::getEffectNames() {
		array<String^>^ names = gcnew array<String^>(Effects::EFFECT_COUNT);

		for (int i = 0; i < Effects::EFFECT_COUNT; i++) {
			names[i] = gcnew String(Effects::set[i].name.c_str());
		}
		return names;
	}

	void ImagingWrapper::updateEffect(String^ name, setting_t setting) {
		controller->updateEffect(setting, toEffect(name));
	}

	int ImagingWrapper::MAX_SETTING_VALUE() {
		return Settings::MAX_SETTING_VALUE;
	}
	int ImagingWrapper::MIN_SETTING_VALUE() {
		return Settings::MIN_SETTING_VALUE;
	}
	int ImagingWrapper::CENTRAL_SETTING_VALUE() {
		return Settings::CENTRAL_SETTING_VALUE;
	}

	void ImagingWrapper::detectObject(setting_t setting, int minNeighbors) {
		try {
			controller->detectObject(setting, minNeighbors);
		}
		catch (CvControlException e) {
			throw gcnew ImagingException(gcnew String(e.what()));
		}

	}
}