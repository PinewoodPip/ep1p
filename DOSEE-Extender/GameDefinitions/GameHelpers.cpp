#include <pch.h>

#include <GameDefinitions/Base/Base.h>
#include <GameDefinitions/Symbols.h>
//#include <GameDefinitions/Enumerations.h>
//#include <GameDefinitions/GameObjects/Ai.h>
//#include <GameDefinitions/GameObjects/Movement.h>
//#include <GameDefinitions/GameObjects/Skill.h>
//#include <GameDefinitions/GameObjects/Render.h>
//#include <GameDefinitions/Alignment.h>
//#include <Extender/ScriptExtender.h>
//#include <GameDefinitions/PropertyMaps/PropertyMaps.h>
#include <GameDefinitions/Base/HalfHelpers.h>
#include "Utils.h"
#include <algorithm>

namespace dse
{
	/*EnumRegistry& EnumRegistry::Get()
	{
		static EnumRegistry reg;
		return reg;
	}

	void EnumRegistry::Register(EnumInfoStore<EnumUnderlyingType>* ei)
	{
		assert(EnumsByName.find(ei->EnumName) == EnumsByName.end());
		EnumsByName.insert(std::make_pair(ei->EnumName, ei));
		ei->RegistryIndex = (int32_t)EnumsById.size();
		EnumsById.push_back(ei);
	}


	BitmaskRegistry& BitmaskRegistry::Get()
	{
		static BitmaskRegistry reg;
		return reg;
	}

	void BitmaskRegistry::Register(BitmaskInfoStore<EnumUnderlyingType>* ei)
	{
		assert(BitfieldsByName.find(ei->EnumName) == BitfieldsByName.end());
		BitfieldsByName.insert(std::make_pair(ei->EnumName, ei));
		ei->RegistryIndex = (int32_t)BitfieldsById.size();
		BitfieldsById.push_back(ei);
	}


	IObjectFactory::~IObjectFactory() {}*/

	StaticSymbols* gStaticSymbols{ nullptr };

	void InitStaticSymbols()
	{
		gStaticSymbols = new StaticSymbols();
	}

	/*RuntimeStringHandle::RuntimeStringHandle()
	{
		Handle = GFS.strNullStringHandle;
	}*/

	void StaticSymbols::CanonicalizePath(STDString& path) const
	{
		if (path.find('\\') != std::string::npos) {
			WARN("Path contains backslashes: \"%s\"; canonical paths should only contain forward slashes.", path.c_str());
		}

		std::replace(path.begin(), path.end(), '\\', '/');
	}

	// TODO editor support?
	/*STDString StaticSymbols::ToPath(StringView path, PathRootType root, bool canonicalize) const
	{
		if (ls__PathRoots == nullptr) {
			ERR("LibraryManager::ToPath(): Path root API not available!");
			return "";
		}

		STDString canonicalPath(path);
		if (canonicalize) {
			CanonicalizePath(canonicalPath);
		}

		auto rootPath = ls__PathRoots[(unsigned)root];
		if (rootPath == nullptr) {
			ERR("StaticSymbols::ToPath(): Path roots not initialized!");
			return "";
		}

		STDString absolutePath(*rootPath);
		absolutePath += "/" + canonicalPath;
		return absolutePath;
	}

	FileReaderPin StaticSymbols::MakeFileReader(StringView path, PathRootType root, bool canonicalize) const
	{
		if (ls__PathRoots == nullptr || ls__FileReader__ctor == nullptr) {
			ERR("StaticSymbols::MakeFileReader(): File reader API not available!");
			return FileReaderPin(nullptr);
		}

		auto absolutePath = ToPath(path, root, canonicalize);

		Path lsPath;
		lsPath.Name = absolutePath;

		auto reader = GameAlloc<FileReader>();
		ls__FileReader__ctor(reader, lsPath, 2);
		return FileReaderPin(reader);
	}*/

	namespace esv
	{
		char const* const sActionStateNames[] = {
			"None",
			nullptr,
			"Attack",
			"Die",
			"Hit",
			"Idle",
			"Animation",
			"PrepareSkill",
			"UseSkill",
			"PickUp",
			"Drop",
			"MoveItem",
			"KnockedDown",
			"Summoning",
			"Polymorphing",
			"UseItem",
			"CombineItem",
			"TeleportFall",
			"Sheath",
			"Unsheath",
			"Identify",
			"Repair",
			"Lockpick",
			"DisarmTrap",
			"Incapacitated",
			"JumpFlight",
			nullptr
		};
	}


	//bool ig::FlashObject::GetValueWorkaround(char const* path, ig::DataType desiredType, InvokeDataValue& value, int arrayIndex)
	//{
	//	switch (desiredType) {
	//	case ig::DataType::None:
	//		return GetValueWorkaround(path, ig::DataType::Bool, value, arrayIndex)
	//			|| GetValueWorkaround(path, ig::DataType::Double, value, arrayIndex)
	//			|| GetValueWorkaround(path, ig::DataType::String, value, arrayIndex);

	//		// Bool and Double are implemented correctly in EoCApp
	//	case ig::DataType::Bool:
	//	case ig::DataType::Double:
	//		return GetValue(path, desiredType, value, arrayIndex);

	//		// Strings returned by the vanilla GetValue() are truncated at 512 bytes; for some use cases (status description etc.)
	//		// this is too short, so we use a non-static buffer size instead
	//	case ig::DataType::String:
	//	{
	//		ig::IggyValuePath val;
	//		auto const& sym = GetStaticSymbols();
	//		if (!sym.IgValuePathMakeNameRef(&val, IggyValue, path)) {
	//			return false;
	//		}

	//		if (arrayIndex >= 0) {
	//			sym.IgValuePathSetArrayIndex(&val, arrayIndex);
	//		}

	//		int resultLength{ 0 };
	//		// Get length of string
	//		if (sym.IgValueGetStringUTF8(&val, 0, 0, 0x10000, nullptr, &resultLength)) {
	//			return false;
	//		}

	//		// Fetch string directly to STDString buffer
	//		value.TypeId = ig::DataType::String;
	//		value.StringVal.resize(resultLength);
	//		return sym.IgValueGetStringUTF8(&val, 0, 0, resultLength, value.StringVal.data(), &resultLength) == 0;
	//	}

	//	default:
	//		ERR("Attempted to fetch Flash value with unknown type %d", desiredType);
	//		return false;
	//	}
	//}

	/*UIObject* UIObjectManager::GetByType(int typeId) const
	{
		for (auto ui : UIObjects) {
			if (ui->Type == typeId) {
				return ui;
			}
		}

		return nullptr;
	}*/

	/*void UIObject::OnFunctionCalled(const char* a1, unsigned int a2, ig::InvokeDataValue* a3)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnFunctionCalled(this, a1, a2, a3);
	}

	void UIObject::CustomDrawCallback(void* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->CustomDrawCallback(this, a1);
	}

	void UIObject::Destroy(bool a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Destroy(this, a1);
	}

	void UIObject::SetHandle(ComponentHandle* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SetHandle(this, a1);
	}

	ComponentHandle* UIObject::GetHandle(ComponentHandle* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetHandle(this, a1);
	}

	void UIObject::RequestDelete()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->RequestDelete(this);
	}

	void UIObject::SetOwnerPlayerId(uint64_t a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SetOwnerPlayerId(this, a1);
	}

	void UIObject::SetPos(glm::ivec2 const& a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SetPos(this, a1);
	}

	void UIObject::KeepWithin(int a1, int a2)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->KeepWithin(this, a1, a2);
	}

	void UIObject::Show()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Show(this);
	}

	void UIObject::Hide()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Hide(this);
	}

	const char* UIObject::GetDebugName()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetDebugName(this);
	}

	bool UIObject::IsControllerUI()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->IsControllerUI(this);
	}

	void UIObject::Init()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Init(this);
	}

	void UIObject::InitAPI()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->InitAPI(this);
	}

	void UIObject::Update(float a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Update(this, a1);
	}

	void UIObject::PostUpdate(float a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->PostUpdate(this, a1);
	}

	void UIObject::Render(void* a1, void* a2)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Render(this, a1, a2);
	}

	void UIObject::RegisterInvokeNames()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->RegisterInvokeNames(this);
	}

	void UIObject::Resize()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Resize(this);
	}

	void* UIObject::OnInputEvent(void* a1, void* a2)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnInputEvent(this, a1, a2);
	}

	uint8_t* UIObject::SendEventToFlash(uint8_t* a2, void* a3, unsigned int a4)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SendEventToFlash(this, a2, a3, a4);
	}

	void* UIObject::OnInputEventText(void* a1, void* a2)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnInputEventText(this, a1, a2);
	}

	uint16_t* UIObject::OnUnlinkedInput(uint16_t* a1, uint32_t a2, uint16_t a3)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnUnlinkedInput(this, a1, a2, a3);
	}

	void UIObject::SetModifierStates(bool a1, bool a2, bool a3, bool a4)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SetModifierStates(this, a1, a2, a3, a4);
	}

	bool UIObject::OnAPIPreResetDevice(void* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnAPIPreResetDevice(this, a1);
	}

	bool UIObject::OnAPIPostResetDevice(void* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnAPIPostResetDevice(this, a1);
	}

	void UIObject::OnControllerModeChanged()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnControllerModeChanged(this);
	}

	void UIObject::OnPlayerDisconnect(int a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->OnPlayerDisconnect(this, a1);
	}

	void UIObject::ReleaseRenderData()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->ReleaseRenderData(this);
	}

	void UIObject::PrepareRenderData()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->PrepareRenderData(this);
	}

	void UIObject::DoPrepareRenderData()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->DoPrepareRenderData(this);
	}

	void UIObject::Activate()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Activate(this);
	}

	void UIObject::Deactivate()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Deactivate(this);
	}

	void UIObject::LoseFocus()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->LoseFocus(this);
	}

	int64_t UIObject::GetBitmapHeight()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetBitmapHeight(this);
	}

	int64_t UIObject::GetBitmapWidth()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetBitmapWidth(this);
	}

	void* UIObject::GetCharacter()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetCharacter(this);
	}

	bool UIObject::SetPlayerHandle(ComponentHandle* handle)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->SetPlayerHandle(this, handle);
	}

	ComponentHandle* UIObject::GetPlayerHandle(ComponentHandle* handle)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->GetPlayerHandle(this, handle);
	}

	bool UIObject::Unknown1()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Unknown1(this);
	}

	void UIObject::Unknown2()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Unknown2(this);
	}

	void* UIObject::Unknown3()
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Unknown3(this);
	}

	void UIObject::Unknown4(void* a1)
	{
		return GetStaticSymbols().ecl__EoCUI__vftable->Unknown4(this, a1);
	}*/

	/*namespace ecl
	{
		EoCUI::EoCUI(dse::Path* path)
		{
			GetStaticSymbols().ecl__EoCUI__ctor(this, path);
		}
	}*/
}
