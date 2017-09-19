#include "CvControlException.h"

namespace OpenCVApp {
	
	CvControlException::CvControlException(std::string message) : runtime_error(message) {

	}
	
	const char*  CvControlException::what() {
		return runtime_error::what();
	}
}