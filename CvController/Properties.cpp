#include "Properties.h"

#include <algorithm>

namespace OpenCVApp {
	const setting_t Settings::MAX_SETTING_VALUE = 100;
	const setting_t Settings::MIN_SETTING_VALUE = 0;
	const setting_t Settings::CENTRAL_SETTING_VALUE = (MAX_SETTING_VALUE + MIN_SETTING_VALUE) / 2;

	int Settings::toSignedValue(setting_t setting, int maxAbs) {
		int base = setting - CENTRAL_SETTING_VALUE;

		double ratioToResult = 2.0 * maxAbs /
			(double)(MAX_SETTING_VALUE - MIN_SETTING_VALUE);
		int result = (int)std::round(ratioToResult * base);

		return result > 0 ? std::min(result, maxAbs) : std::max(result, -maxAbs);
	}

	int Settings::toValue(setting_t setting, int max) {
		int base = (setting - Settings::MIN_SETTING_VALUE);

		double ratioToResult = (double)max / (double)(Settings::MAX_SETTING_VALUE - Settings::MIN_SETTING_VALUE);
		int result = (int)std::round(ratioToResult * setting);
		return std::min(result, max);
	}

	setting_t Settings::toSafety(setting_t setting) {
		if (setting > Settings::MAX_SETTING_VALUE) {
			return Settings::MAX_SETTING_VALUE;
		}
		if (setting < Settings::MIN_SETTING_VALUE) {
			return Settings::MIN_SETTING_VALUE;
		}
		return setting;
	}

	const EffectPack Effects::none = { EffectType::NONE, "None" };
	const EffectPack Effects::blackPencil = { EffectType::BALCK_PENCIL, "BlackPencil" };
	const EffectPack Effects::colorPencil = { EffectType::COLOR_PENCIL, "ColorPencil" };
	const EffectPack Effects::oilPaint = { EffectType::OIL_PAINT, "Oil Paint" };
	const EffectPack Effects::snowstorm = { EffectType::SNOW_STORM, "Snow Storm" };
	const EffectPack Effects::twinkle = { EffectType::TWINKLE, "Twinkle" };
	const EffectPack Effects::sepia = { EffectType::SEPIA, "Sepia" };
	const EffectPack Effects::gamma = { EffectType::GAMMA, "Gamma Correction" };
	const EffectPack Effects::sketch = { EffectType::SKETCH, "Sketch" };
	const EffectPack Effects::original = { EffectType::ORIGINAL, "Your Original" };
	
	const EffectPack Effects::set[] = {
		Effects::none,
		Effects::blackPencil,
		Effects::colorPencil,
		Effects::oilPaint,
		Effects::snowstorm,
		Effects::twinkle,
		Effects::sepia,
		Effects::gamma,
		Effects::sketch,
		Effects::original,
	};
	const int Effects::EFFECT_COUNT = sizeof(set) / sizeof(set[0]);
}
