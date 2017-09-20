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
		OIL_PAINT,
		SNOW_STORM,
		ORIGINAL,
		TWINKLE,
		SEPIA,
		GAMMA,
		SKETCH
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
		static const EffectPack oilPaint;
		static const EffectPack snowstorm;
		
		static const EffectPack twinkle;
		static const EffectPack sepia;
		static const EffectPack gamma;
		static const EffectPack sketch;

		static const EffectPack original;
		static const EffectPack set[];
		static const int EFFECT_COUNT;
	};

}

