#pragma once
#include <string>

namespace cv{
	class Mat;
}


namespace OpenCVApp {
	class ImagingController
	{
	private:
		cv::Mat* originalImage;
		
	public:
		ImagingController();
		~ImagingController();

		cv::Mat getImage();
		void update(const std::string& imageFile);
	};
}

