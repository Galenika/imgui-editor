#include "codeoutput.h"

///
///
///
///  ËÞÒÛÉ ÁËßÒÜ ÃÎÂÍÎ ÊÎÄ ÍÀÕÓÉ ÇÀÊÐÎÉ È ÍÅ ÑÌÎÒÐÈ ÑÓÊÀ
///
///
///

void toClipboard(HWND hwnd, const std::string& s) {
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

static int code_tab = 0;

using namespace Settings;

void CodeOutPut()
{
	auto window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

	ImGui::SetNextWindowSize({ ImGui::GetIO().DisplaySize.x - width,ImGui::GetIO().DisplaySize.y - 18 });
	ImGui::SetNextWindowPos({ width,18 });

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });

	ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

	ImGui::Begin("CodeOutPut", nullptr, window_flags);
	{
		ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetWindowPos(), { ImGui::GetWindowPos().x + ImGui::GetIO().DisplaySize.x + 10,ImGui::GetWindowPos().y + ImGui::GetIO().DisplaySize.y }, ImColor(40, 40, 40));

		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::SameLine(5);
		if (ImGui::BeginTabBar("TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip))
		{
			if (ImGui::BeginTabItem("Menu Code"))
			{
				code_tab = 0;
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Style Code"))
			{
				code_tab = 1;
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::Spacing();
		ImGui::SameLine(5);
		ToolBarE::BeginChild("Child 5", ImVec2{ ImGui::GetIO().DisplaySize.x - width - 10,ImGui::GetIO().DisplaySize.y - 52 }, false, NULL);
		{
			if (code_tab == 0)
			{
				std::string code;
				std::string code3;
				std::string code4;
				std::string code5;

				code3.append("auto flags = ");
				no_titlebar ? code3.append("ImGuiWindowFlags_NoTitleBar") : code3.append("NULL");                 code3.append(" | ");
				no_scrollbar ? code3.append("ImGuiWindowFlags_NoScrollbar") : code3.append("NULL"); code3.append(" | ");
				no_menu ? code3.append("ImGuiWindowFlags_MenuBar") : code3.append("NULL"); code3.append(" | ");
				no_move ? code3.append("ImGuiWindowFlags_NoMove") : code3.append("NULL"); code3.append(" | ");
				no_resize ? code3.append("ImGuiWindowFlags_NoResize") : code3.append("NULL"); code3.append(" | ");
				no_collapse ? code3.append("ImGuiWindowFlags_NoCollapse") : code3.append("NULL"); code3.append(" | ");
				no_nav ? code3.append("ImGuiWindowFlags_NoNav") : code3.append("NULL"); code3.append(" | ");
				no_background ? code3.append("ImGuiWindowFlags_NoBackground") : code3.append("NULL"); code3.append(" | ");
				no_bring_to_front ? code3.append("ImGuiWindowFlags_NoBringToFrontOnFocus") : code3.append("NULL"); code3.append(";\n\n");

				code3.append("ImGui::SetNextWindowSize({"); code3.append(std::to_string(windowsize.x));  code3.append("f,"); code3.append(std::to_string(windowsize.y)); code3.append("f});\n\n");

				code3.append("ImGui::Begin(\"Edited\", nullptr, flags);\n{\n");
				code3.append("   ImVec2 p = ImGui::GetWindowPos();\n");

				ImGui::Text(code3.c_str());

				for (auto iter = list_lines.begin(); iter != list_lines.end(); iter++)
				{
					code4.append("   ImGui::GetWindowDrawList()->");

					if (iter->draw == 0)
					{
						code4.append("AddLine(ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos1));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos2));
						code4.append("), ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos3));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos4));
						code4.append("), ");
						code4.append("ImColor(");
						code4.append(std::to_string(iter->color0.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.w)); code4.append("f),");
						code4.append(std::to_string(iter->thinkness));
						code4.append(");");


						ImGui::Text("   ImGui::GetWindowDrawList()->AddLine(ImVec2(p.x + %i, p.y + %i), ImVec2(p.x + %i, p.y + %i), ImColor(%ff,%ff,%ff,%ff),%ff);", iter->pos1, iter->pos2, iter->pos3, iter->pos4, iter->color0.Value.x, iter->color0.Value.y, iter->color0.Value.z, iter->color0.Value.w, iter->thinkness);

						code4.append("  // ");
						code4.append(iter->name);
						code4.append("\n");
					}

					if (iter->draw == 1)
					{
						code4.append("AddRect(ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos1));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos2));
						code4.append("), ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos3));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos4));
						code4.append("), ");
						code4.append("ImColor(");
						code4.append(std::to_string(iter->color0.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.w)); code4.append("f),");
						code4.append(std::to_string(iter->round));
						code4.append(", 15, ");
						code4.append(std::to_string(iter->thinkness));
						code4.append("); ");

						code4.append(" // ");
						code4.append(iter->name);
						code4.append("\n");

						ImGui::Text("   ImGui::GetWindowDrawList()->AddRect(ImVec2(p.x + %i, p.y + %i), ImVec2(p.x + %i, p.y + %i), ImColor(%ff,%ff,%ff,%ff),%ff, 15, %f);", iter->pos1, iter->pos2, iter->pos3, iter->pos4, iter->color0.Value.x, iter->color0.Value.y, iter->color0.Value.z, iter->color0.Value.w, iter->round, iter->thinkness);
					}

					if (iter->draw == 2)
					{
						code4.append("AddRectFilled(ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos1));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos2));
						code4.append("), ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos3));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos4));
						code4.append("), ");
						code4.append("ImColor(");
						code4.append(std::to_string(iter->color0.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.w)); code4.append("f),");
						code4.append(std::to_string(iter->round));
						code4.append(", 15);");

						ImGui::Text("   ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + %i, p.y + %i), ImVec2(p.x + %i, p.y + %i), ImColor(%ff,%ff,%ff,%ff),%i, 15);", iter->pos1, iter->pos2, iter->pos3, iter->pos4, iter->color0.Value.x, iter->color0.Value.y, iter->color0.Value.z, iter->color0.Value.w, iter->round);


						code4.append(" // ");
						code4.append(iter->name);
						code4.append("\n");
					}

					if (iter->draw == 3)
					{
						code4.append("AddRectFilledMultiColor(ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos1));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos2));
						code4.append("), ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos3));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos4));
						code4.append("), ");
						code4.append("ImColor(");
						code4.append(std::to_string(iter->color0.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.w)); code4.append("f),");

						code4.append("ImColor(");
						code4.append(std::to_string(iter->color1.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color1.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color1.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color1.Value.w)); code4.append("f),");


						code4.append("ImColor(");
						code4.append(std::to_string(iter->color2.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color2.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color2.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color2.Value.w)); code4.append("f),");


						code4.append("ImColor(");
						code4.append(std::to_string(iter->color3.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color3.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color3.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color3.Value.w)); code4.append("f)");
						code4.append(");");

						code4.append(" // ");
						code4.append(iter->name);
						code4.append("\n");
					}

					if (iter->draw == 4)
					{
						code4.append("AddCircle(ImVec2(p.x + ");
						code4.append(std::to_string(iter->pos1));
						code4.append(", p.y + ");
						code4.append(std::to_string(iter->pos2));
						code4.append("),");
						code4.append(std::to_string(iter->radius));
						code4.append(", ImColor(");
						code4.append(std::to_string(iter->color0.Value.x)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.y)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.z)); code4.append("f,");
						code4.append(std::to_string(iter->color0.Value.w)); code4.append("f),");
						code4.append(std::to_string(iter->segments));
						code4.append(",");
						code4.append(std::to_string(iter->thinkness));
						code4.append(");");

						code4.append(" // ");
						code4.append(iter->name);
						code4.append("\n");
					}
				}

				code.append("}\nImGui::End();\n\n");

				ImGui::Text(code.c_str());

				std::string big;
				big.append(code4);
				big.append(code);

				if (ImGui::Button("Copy"))
				{
					toClipboard(NULL, big);
				}
			}

			if (code_tab == 1)
			{
				std::string code2;
				std::string code3;
				std::string code4;

				code2.append("void init_styles(ImGuiStyle& style)\n{\n");


				code2.append("  style.WindowPadding = ImVec2("); code2.append(std::to_string(WindowPadding.x));  code2.append("f,"); code2.append(std::to_string(WindowPadding.y)); code2.append("f);\n");
				code2.append("  style.FramePadding = ImVec2("); code2.append(std::to_string(FramePadding.x));  code2.append("f,"); code2.append(std::to_string(FramePadding.y)); code2.append("f);\n");
				code2.append("  style.ItemSpacing = ImVec2("); code2.append(std::to_string(ItemSpacing.x));  code2.append("f,"); code2.append(std::to_string(ItemSpacing.y)); code2.append("f);\n");
				code2.append("  style.ItemInnerSpacing = ImVec2("); code2.append(std::to_string(ItemInnerSpacing.x));  code2.append("f,"); code2.append(std::to_string(ItemInnerSpacing.y)); code2.append("f);\n");
				code2.append("  style.IndentSpacing = "); code2.append(std::to_string(IndentSpacing)); code2.append("f;\n");
				code2.append("  style.ScrollbarSize = "); code2.append(std::to_string(ScrollbarSize)); code2.append("f;\n");
				code2.append("  style.GrabMinSize = "); code2.append(std::to_string(GrabMinSize)); code2.append("f;\n");
				code2.append("  style.WindowBorderSize = "); code2.append(std::to_string(WindowBorderSize)); code2.append("f;\n");
				code2.append("  style.ChildBorderSize = "); code2.append(std::to_string(ChildBorderSize)); code2.append("f;\n");
				code2.append("  style.PopupBorderSize = "); code2.append(std::to_string(PopupBorderSize)); code2.append("f;\n");
				code2.append("  style.FrameBorderSize = "); code2.append(std::to_string(FrameBorderSize)); code2.append("f;\n");
				code2.append("  style.WindowRounding = "); code2.append(std::to_string(WindowRounding)); code2.append("f;\n");
				code2.append("  style.ChildRounding = "); code2.append(std::to_string(ChildRounding)); code2.append("f;\n");
				code2.append("  style.FrameRounding = "); code2.append(std::to_string(FrameRounding)); code2.append("f;\n");
				code2.append("  style.PopupRounding = "); code2.append(std::to_string(PopupRounding)); code2.append("f;\n");
				code2.append("  style.ScrollbarRounding = "); code2.append(std::to_string(ScrollbarRounding)); code2.append("f;\n");
				code2.append("  style.GrabRounding = "); code2.append(std::to_string(GrabRounding)); code2.append("f;\n");
				code2.append("  style.WindowTitleAlign = ImVec2("); code2.append(std::to_string(WindowTitleAlign.x));  code2.append("f,"); code2.append(std::to_string(WindowTitleAlign.y)); code2.append("f);\n");
				code2.append("  style.ButtonTextAlign = ImVec2("); code2.append(std::to_string(ButtonTextAlign.x));  code2.append("f,"); code2.append(std::to_string(ButtonTextAlign.y)); code2.append("f);\n");
				code2.append("  style.SelectableTextAlign = ImVec2("); code2.append(std::to_string(SelectableTextAlign.x));  code2.append("f,"); code2.append(std::to_string(SelectableTextAlign.y)); code2.append("f);\n");

				ImGui::Text(code2.c_str());

#define FXuita code3.append("f,");
#define FXuita2 code4.append("f,");

				code3.append("  style.Colors[ImGuiCol_Text] = ImVec4("); code3.append(std::to_string(Text[0])); FXuita code3.append(std::to_string(Text[1])); FXuita code3.append(std::to_string(Text[2])); FXuita code3.append(std::to_string(Text[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_TextDisabled] = ImVec4("); code3.append(std::to_string(TextDisabled[0])); FXuita code3.append(std::to_string(TextDisabled[1])); FXuita code3.append(std::to_string(TextDisabled[2])); FXuita code3.append(std::to_string(TextDisabled[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_WindowBg] = ImVec4("); code3.append(std::to_string(WindowBg[0])); FXuita code3.append(std::to_string(WindowBg[1])); FXuita  code3.append(std::to_string(WindowBg[2])); FXuita code3.append(std::to_string(WindowBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ChildBg] = ImVec4("); code3.append(std::to_string(ChildBg[0])); FXuita code3.append(std::to_string(ChildBg[1])); FXuita code3.append(std::to_string(ChildBg[2]));  FXuita code3.append(std::to_string(ChildBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_PopupBg] = ImVec4("); code3.append(std::to_string(PopupBg[0])); FXuita code3.append(std::to_string(PopupBg[1])); FXuita code3.append(std::to_string(PopupBg[2])); FXuita code3.append(std::to_string(PopupBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_Border] = ImVec4("); code3.append(std::to_string(Border[0])); FXuita code3.append(std::to_string(Border[1])); FXuita code3.append(std::to_string(Border[2])); FXuita code3.append(std::to_string(Border[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_BorderShadow] = ImVec4("); code3.append(std::to_string(BorderShadow[0])); FXuita  code3.append(std::to_string(BorderShadow[1])); FXuita code3.append(std::to_string(BorderShadow[2])); FXuita code3.append(std::to_string(BorderShadow[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_FrameBg] = ImVec4("); code3.append(std::to_string(FrameBg[0])); FXuita  code3.append(std::to_string(FrameBg[1])); FXuita code3.append(std::to_string(FrameBg[2])); FXuita  code3.append(std::to_string(FrameBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_FrameBgHovered] = ImVec4("); code3.append(std::to_string(FrameBgHovered[0])); FXuita code3.append(std::to_string(FrameBgHovered[1])); FXuita  code3.append(std::to_string(FrameBgHovered[2])); FXuita  code3.append(std::to_string(FrameBgHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_FrameBgActive] = ImVec4("); code3.append(std::to_string(FrameBgActive[0])); FXuita code3.append(std::to_string(FrameBgActive[1])); FXuita  code3.append(std::to_string(FrameBgActive[2])); FXuita  code3.append(std::to_string(FrameBgActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_TitleBg] = ImVec4("); code3.append(std::to_string(TitleBg[0])); FXuita code3.append(std::to_string(TitleBg[1])); FXuita code3.append(std::to_string(TitleBg[2])); FXuita code3.append(std::to_string(TitleBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_TitleBgActive] = ImVec4("); code3.append(std::to_string(TitleBgActive[0])); FXuita  code3.append(std::to_string(TitleBgActive[1])); FXuita code3.append(std::to_string(TitleBgActive[2])); FXuita  code3.append(std::to_string(TitleBgActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4("); code3.append(std::to_string(TitleBgCollapsed[0])); FXuita  code3.append(std::to_string(TitleBgCollapsed[1])); FXuita  code3.append(std::to_string(TitleBgCollapsed[2])); FXuita  code3.append(std::to_string(TitleBgCollapsed[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_MenuBarBg] = ImVec4("); code3.append(std::to_string(MenuBarBg[0]));  FXuita code3.append(std::to_string(MenuBarBg[1])); FXuita  code3.append(std::to_string(MenuBarBg[2])); FXuita  code3.append(std::to_string(MenuBarBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ScrollbarBg] = ImVec4("); code3.append(std::to_string(ScrollbarBg[0])); FXuita code3.append(std::to_string(ScrollbarBg[1])); FXuita  code3.append(std::to_string(ScrollbarBg[2])); FXuita  code3.append(std::to_string(ScrollbarBg[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4("); code3.append(std::to_string(ScrollbarGrab[0])); FXuita  code3.append(std::to_string(ScrollbarGrab[1])); FXuita  code3.append(std::to_string(ScrollbarGrab[2])); FXuita  code3.append(std::to_string(ScrollbarGrab[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4("); code3.append(std::to_string(ScrollbarGrabHovered[0])); FXuita code3.append(std::to_string(ScrollbarGrabHovered[1])); FXuita  code3.append(std::to_string(ScrollbarGrabHovered[2])); FXuita code3.append(std::to_string(ScrollbarGrabHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4("); code3.append(std::to_string(ScrollbarGrabActive[0])); FXuita  code3.append(std::to_string(ScrollbarGrabActive[1])); FXuita  code3.append(std::to_string(ScrollbarGrabActive[2])); FXuita code3.append(std::to_string(ScrollbarGrabActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_CheckMark] = ImVec4("); code3.append(std::to_string(CheckMark[0])); FXuita code3.append(std::to_string(CheckMark[1])); FXuita  code3.append(std::to_string(CheckMark[2])); FXuita  code3.append(std::to_string(CheckMark[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_SliderGrab] = ImVec4("); code3.append(std::to_string(SliderGrab[0])); FXuita code3.append(std::to_string(SliderGrab[1])); FXuita  code3.append(std::to_string(SliderGrab[2])); FXuita  code3.append(std::to_string(SliderGrab[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_SliderGrabActive] = ImVec4("); code3.append(std::to_string(SliderGrabActive[0])); FXuita code3.append(std::to_string(SliderGrabActive[1])); FXuita  code3.append(std::to_string(SliderGrabActive[2])); FXuita code3.append(std::to_string(SliderGrabActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_Button] = ImVec4("); code3.append(std::to_string(Button[0])); FXuita  code3.append(std::to_string(Button[1])); FXuita  code3.append(std::to_string(Button[2])); FXuita  code3.append(std::to_string(Button[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ButtonHovered] = ImVec4("); code3.append(std::to_string(ButtonHovered[0])); FXuita  code3.append(std::to_string(ButtonHovered[1])); FXuita  code3.append(std::to_string(ButtonHovered[2])); FXuita code3.append(std::to_string(ButtonHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ButtonActive] = ImVec4("); code3.append(std::to_string(ButtonActive[0])); FXuita  code3.append(std::to_string(ButtonActive[1])); FXuita  code3.append(std::to_string(ButtonActive[2])); FXuita  code3.append(std::to_string(ButtonActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_Header] = ImVec4("); code3.append(std::to_string(Header[0])); FXuita  code3.append(std::to_string(Header[1])); FXuita  code3.append(std::to_string(Header[2])); FXuita  code3.append(std::to_string(Header[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_HeaderHovered] = ImVec4("); code3.append(std::to_string(HeaderHovered[0])); FXuita  code3.append(std::to_string(HeaderHovered[1])); FXuita  code3.append(std::to_string(HeaderHovered[2])); FXuita code3.append(std::to_string(HeaderHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_HeaderActive] = ImVec4("); code3.append(std::to_string(HeaderActive[0])); FXuita  code3.append(std::to_string(HeaderActive[1])); FXuita  code3.append(std::to_string(HeaderActive[2])); FXuita  code3.append(std::to_string(HeaderActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_Separator] = ImVec4("); code3.append(std::to_string(Separator[0])); FXuita  code3.append(std::to_string(Separator[1])); FXuita  code3.append(std::to_string(Separator[2])); FXuita  code3.append(std::to_string(Separator[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_SeparatorHovered] = ImVec4("); code3.append(std::to_string(SeparatorHovered[0])); FXuita  code3.append(std::to_string(SeparatorHovered[1])); FXuita  code3.append(std::to_string(SeparatorHovered[2])); FXuita code3.append(std::to_string(SeparatorHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_SeparatorActive] = ImVec4("); code3.append(std::to_string(SeparatorActive[0])); FXuita  code3.append(std::to_string(SeparatorActive[1])); FXuita  code3.append(std::to_string(SeparatorActive[2])); FXuita code3.append(std::to_string(SeparatorActive[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ResizeGrip] = ImVec4("); code3.append(std::to_string(ResizeGrip[0])); FXuita code3.append(std::to_string(ResizeGrip[1])); FXuita  code3.append(std::to_string(ResizeGrip[2])); FXuita  code3.append(std::to_string(ResizeGrip[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4("); code3.append(std::to_string(ResizeGripHovered[0])); FXuita  code3.append(std::to_string(ResizeGripHovered[1])); FXuita  code3.append(std::to_string(ResizeGripHovered[2])); FXuita  code3.append(std::to_string(ResizeGripHovered[3])); code3.append("f"); code3.append(");\n");
				code3.append("  style.Colors[ImGuiCol_ResizeGripActive] = ImVec4("); code3.append(std::to_string(ResizeGripActive[0])); FXuita  code3.append(std::to_string(ResizeGripActive[1])); FXuita  code3.append(std::to_string(ResizeGripActive[2])); FXuita  code3.append(std::to_string(ResizeGripActive[3])); code3.append("f"); code3.append(");\n");
				code4.append("  style.Colors[ImGuiCol_TextSelectedBg] = ImVec4("); code4.append(std::to_string(TextSelectedBg[0])); FXuita2 code4.append(std::to_string(TextSelectedBg[1])); FXuita2  code4.append(std::to_string(TextSelectedBg[2])); FXuita2  code4.append(std::to_string(TextSelectedBg[3])); code4.append("f"); code4.append(");\n");
				code4.append("  style.Colors[ImGuiCol_DragDropTarget] = ImVec4("); code4.append(std::to_string(DragDropTarget[0])); FXuita2 code4.append(std::to_string(DragDropTarget[1])); FXuita2  code4.append(std::to_string(DragDropTarget[2])); FXuita2  code4.append(std::to_string(DragDropTarget[3])); code4.append("f"); code4.append(");\n");
				code4.append("}");
				ImGui::Text(code3.c_str());
				ImGui::Text(code4.c_str());

				std::string big;
				big.append(code2);
				big.append(code3);
				big.append(code4);

				if (ImGui::Button("Copy"))
				{
					toClipboard(NULL, big);
				}
			}
			if (code_tab == 2)
			{

			}
		}
		ToolBarE::EndChild();
	}
	ImGui::End();


	ImGui::PopStyleVar(1);
	ImGui::PopStyleColor(6);
}