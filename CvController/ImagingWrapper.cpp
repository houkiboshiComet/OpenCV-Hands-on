#include "ImagingWrapper.h"
#include "Properties.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#pragma managed

#include <string>
using namespace System::Drawing;

namespace OpenCVApp {

	void ImagingWrapper::read(String^ fileName) {
		try {
			controller->update(toStdStr(fileName));
		}
		catch (std::runtime_error e) {
			throw gcnew System::IO::IOException(gcnew String(e.what()));
		}
	}
	System::Drawing::Bitmap^ ImagingWrapper::getImage() {
		cv::Mat mat = controller->getImage();
		return toBitmap(&mat);
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
	
	int ImagingWrapper::toSafetyValue(int value) {
		if (value > Properties::MAX_SETTING_VALUE) {
			return Properties::MAX_SETTING_VALUE;
		}
		if (value < Properties::MIN_SETTING_VALUE) {
			return Properties::MIN_SETTING_VALUE;
		}
		return value;
	}

	void ImagingWrapper::updateBaseSettings(int r, int g, int b, int blur) {
		controller->updateBaseSettings(
			toSafetyValue(r),
			toSafetyValue(g),
			toSafetyValue(b),
			toSafetyValue(blur)
			);
	}
}