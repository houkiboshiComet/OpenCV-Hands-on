#pragma once

namespace OpenCVApp {
	typedef int setting_t;
	class Settings
	{
	public:
		static const setting_t MAX_SETTING_VALUE;
		static const setting_t MIN_SETTING_VALUE;
		static const setting_t CENTRAL_SETTING_VALUE;

		static int toSignedValue(setting_t setting, int maxAbs);
		static int toValue(setting_t setting, int max);
		static setting_t toSafety(setting_t setting);
	};

	enum Effects {

	};
}

