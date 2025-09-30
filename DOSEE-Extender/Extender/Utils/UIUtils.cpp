#include "pch.h"
#include <Extender/ScriptExtender.h>
#include "UIUtils.h"

BEGIN_SE()

UIObject* UIUtils::GetUIByType(UIObject::TypeID typeID)
{
	auto manager = *gStaticSymbols->UIObjectManager__Instance;
	for (int i = 0; i < manager->UIObjectsCount; ++i)
	{
		auto ui = manager->UIObjects[i];
		if (ui->TypeId == (int)typeID)
		{
			return ui;
		}
	}
	return nullptr;
}

ig::InvokeDataValue UIUtils::CreateDoubleInvokeData(int value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Double;
	data.DoubleVal = value;
	return data;
}

ig::InvokeDataValue UIUtils::CreateBoolInvokeData(bool value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Bool;
	data.BoolVal = value;
	return data;
}

ig::InvokeDataValue UIUtils::CreateStringInvokeData(STDWString value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::WString;
	data.WStringVal = value;
	data.StringVal = "";
	data.BoolVal = false;
	data.DoubleVal = 0;
	return data;
}

bool UIUtils::IsPausedOrInputFocused()
{
	return ((*gStaticSymbols->UIObjectManager__Instance)->AggregateModalFlags_m & 0x1e00) != 0;
}

bool UIUtils::IsModifierKey(RawInputType input)
{
	return input == RawInputType::LShift || input == RawInputType::RShift || input == RawInputType::LCtrl || input == RawInputType::RCtrl || input == RawInputType::LAlt || input == RawInputType::RAlt || input == RawInputType::LGUI || input == RawInputType::RGUI;
}

bool UIUtils::IsVisible(UIObject* ui)
{
	return (ui->Flags & (int)UIObject::UIFlags::Visible) != 0;
}

END_SE()
