
#include "stdafx.h"
#include "USonJISStrategy.h"
#include "NormalKeyEmulation.h"
#include "PressAndReleaseDecorator.h"
#include "ShiftPressDecorator.h"
#include "ShiftReleaseDecorator.h"
#include "NopEmulation.h"

void USonJISStrategy::getEmulationMap(EmulationMapType *dest) {

	dest->clear();

	// @
	dest->emplace(
		KeyCondition('2', true),
		std::make_unique<ShiftReleaseDecorator>(
			std::make_unique<NormalKeyEmulation>(VK_OEM_3)
		)
	);
	// ^
	dest->emplace(
		KeyCondition('6', true),
		std::make_unique<ShiftReleaseDecorator>(
			std::make_unique<NormalKeyEmulation>(VK_OEM_7)
		)
	);
	// &
	dest->emplace(KeyCondition('7', true), std::make_unique<NormalKeyEmulation>('6'));
	// *
	dest->emplace(KeyCondition('8', true), std::make_unique<NormalKeyEmulation>(VK_OEM_1));
	// (
	dest->emplace(KeyCondition('9', true), std::make_unique<NormalKeyEmulation>('8'));
	// )
	dest->emplace(KeyCondition('0', true), std::make_unique<NormalKeyEmulation>('9'));
	// _
	dest->emplace(KeyCondition(VK_OEM_MINUS, true), std::make_unique<NormalKeyEmulation>(VK_OEM_102));
	// =
	dest->emplace(
		KeyCondition(VK_OEM_7),
		std::make_unique<ShiftPressDecorator>(
			std::make_unique<NormalKeyEmulation>(VK_OEM_MINUS)
		)
	);
	// +
	dest->emplace(KeyCondition(VK_OEM_7, true), std::make_unique<NormalKeyEmulation>(VK_OEM_PLUS));

	// `
	dest->emplace(KeyCondition(VK_OEM_AUTO), std::make_unique<NopEmulation>());
	dest->emplace(
		KeyCondition(VK_OEM_ENLW),
		std::make_unique<PressAndReleaseDecorator>(
			std::make_unique<ShiftPressDecorator>(
				std::make_unique<NormalKeyEmulation>(VK_OEM_3)
			)
		)
	);
	// ~
	dest->emplace(KeyCondition(VK_OEM_AUTO, true), new NopEmulation());
	dest->emplace(
		KeyCondition(VK_OEM_ENLW, true),
		std::make_unique<PressAndReleaseDecorator>(
			std::make_unique<NormalKeyEmulation>(VK_OEM_7)
		)
	);

	// [
	dest->emplace(KeyCondition(VK_OEM_3), std::make_unique<NormalKeyEmulation>(VK_OEM_4));
	// ]
	dest->emplace(KeyCondition(VK_OEM_4), std::make_unique<NormalKeyEmulation>(VK_OEM_6));

	// {
	dest->emplace(KeyCondition(VK_OEM_3, true), std::make_unique<NormalKeyEmulation>(VK_OEM_4));
	// }
	dest->emplace(KeyCondition(VK_OEM_4, true), std::make_unique<NormalKeyEmulation>(VK_OEM_6));
	// :
	dest->emplace(KeyCondition(
		VK_OEM_PLUS, true),
		std::make_unique<ShiftReleaseDecorator>(std::make_unique<NormalKeyEmulation>(VK_OEM_1))
	);
	// '
	dest->emplace(
		KeyCondition(VK_OEM_1),
		std::make_unique<ShiftPressDecorator>(std::make_unique<NormalKeyEmulation>('7'))
	);
	// "
	dest->emplace(KeyCondition(VK_OEM_1, true), std::make_unique<NormalKeyEmulation>('2'));
	// '\'
	dest->emplace(KeyCondition(VK_OEM_6), std::make_unique<NormalKeyEmulation>(VK_OEM_5));
	// |
	dest->emplace(KeyCondition(VK_OEM_6, true), std::make_unique<NormalKeyEmulation>(VK_OEM_5));
}
