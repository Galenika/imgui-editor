
#include "project_selection.h"

vector<string> ConfigList;

BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = FALSE)
{
	LPTSTR part;
	char tmp[MAX_PATH];
	char name[MAX_PATH];

	HANDLE hSearch = NULL;
	WIN32_FIND_DATA wfd;
	memset(&wfd, 0, sizeof(WIN32_FIND_DATA));

	if (bInnerFolders)
	{
		if (GetFullPathName(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
		strcpy(name, part);
		strcpy(part, "*.*");
		wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
		if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
			do
			{
				if (!strncmp(wfd.cFileName, ".", 1) || !strncmp(wfd.cFileName, "..", 2))
					continue;

				if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					char next[MAX_PATH];
					if (GetFullPathName(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
					strcpy(part, wfd.cFileName);
					strcat(next, "\\");
					strcat(next, name);

					SearchFiles(next, lpSearchFunc, TRUE);
				}
			} while (FindNextFile(hSearch, &wfd));
			FindClose(hSearch);
	}

	if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE)
		return TRUE;
	do
		if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			char file[MAX_PATH];
			if (GetFullPathName(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
			strcpy(part, wfd.cFileName);

			lpSearchFunc(wfd.cFileName);
		}
	while (FindNextFile(hSearch, &wfd));
	FindClose(hSearch);
	return TRUE;
}

static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
	auto& vector = *static_cast<std::vector<std::string>*>(vec);
	if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
	*out_text = vector.at(idx).c_str();
	return true;
};

bool ComboBoxArray(const char* label, int* currIndex, std::vector<std::string>& values)
{
	if (values.empty()) { return false; }
	return ImGui::Combo(label, currIndex, vector_getter,
		static_cast<void*>(&values), values.size());
}

void ReadConfigs(LPCTSTR lpszFileName)
{
	ConfigList.push_back(lpszFileName);
}

void RefreshConfigs()
{
	ConfigList.clear();
	string ConfigDir = "C:\\PERS0NA2EDITOR\\*.pers0na2";
	SearchFiles(ConfigDir.c_str(), ReadConfigs, FALSE);
}

void Saver()
{
	auto window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

	ImGui::SetNextWindowPos({ ImGui::GetIO().DisplaySize.x / 2 - 155,ImGui::GetIO().DisplaySize.y / 2 - 55 });
	ImGui::SetNextWindowSize({ 310,111 });

	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(60 / 255.f, 60 / 255.f, 60 / 255.f, 150 / 255.f));

	ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

	ImGui::Begin("config list", nullptr, window_flags);
	{
		static int iMenuSheme = 1;
		static int iConfigSelect = 0;
		static char ConfigName[11] = { 0 };
		ImGui::PushItemWidth(292);

		ImGui::SetCursorPos({ 10,10 });
		ImGui::BeginGroup();

		ComboBoxArray("123", &iConfigSelect, ConfigList);

		if (ImGui::Button("Open Project")) 
		{
			if (Settings::LoadSettings("C:\\PERS0NA2EDITOR\\" + ConfigList[iConfigSelect]) == 1)
			{
				Settings::menu_config_state = true;
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Save Project"))
		{
			if (Settings::SaveSettings("C:\\PERS0NA2EDITOR\\" + ConfigList[iConfigSelect]) == 1) 
			{
				Settings::menu_config_state = true;
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Refresh List")) 
		{
			RefreshConfigs();
		}

		ImGui::Separator();

		ImGui::InputText("", ConfigName, 11);

		if (ImGui::Button("Create New Project"))
		{
			string ConfigFileName = ConfigName;
			if (ConfigFileName.size() < 1 || ConfigFileName == "")
			{
				ConfigFileName = "default";
			}

			if (Settings::SaveSettings("C:\\PERS0NA2EDITOR\\" + ConfigFileName + ".pers0na2") == 1) {
				Settings::menu_config_state = true;
			}

			RefreshConfigs();
		}
		ImGui::Spacing();
		ImGui::EndGroup();
	}
	ImGui::End();

	ImGui::PopStyleColor(7);
}
