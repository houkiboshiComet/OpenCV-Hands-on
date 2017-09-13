#pragma once
#include <string>

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

	enum EffectType {
		NONE,
		BALCK_PENCIL,
		COLOR_PENCIL,
		ORIGINAL
	};

	const struct EffectPack
	{
		EffectType type;
		std::string name;
	};
	class Effects {
	public:
		static const EffectPack none;
		static const EffectPack blackPencil;
		static const EffectPack colorPencil;

		static const EffectPack original;
		static const EffectPack set[];
		static const int EFFECT_COUNT;
	};

}

