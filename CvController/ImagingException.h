#pragma once

using namespace System;

namespace OpenCVApp {
	public ref class ImagingException : Exception
	{	
	public:
	 	ImagingException(String^ message);
	};
}
