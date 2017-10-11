#pragma once

#include <stdexcept>
using  std::runtime_error;
using std::string;

namespace OpenCVApp {
	class CvControlException : runtime_error
	{
	public:
		CvControlException(std::string message);
		const char* what();
	};
}

