#include "codeoutput.h"

using namespace Settings;

#include "project_selection.h"

void CodeOutPut()
{
	std::string path = "C:\\PERS0NA2EDITOR\\";
	path.append(ConfigList[iConfigSelect]);
	path.erase(path.size() - 9);
	path.append(".cpp");

	auto out = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);

	if (!out.is_open())
		throw std::exception("Failed to open output file");


	out << "void init_styles(ImGuiStyle& style)\n{\n";


	out << "  style.WindowPadding = ImVec2(" << std::to_string(WindowPadding.x) << "f," << std::to_string(WindowPadding.y) << "f);\n";
	out << "  style.FramePadding = ImVec2(" << std::to_string(FramePadding.x) << "f," << std::to_string(FramePadding.y) << "f);\n";
	out << "  style.ItemSpacing = ImVec2(" << std::to_string(ItemSpacing.x) << "f," << std::to_string(ItemSpacing.y) << "f);\n";
	out << "  style.ItemInnerSpacing = ImVec2(" << std::to_string(ItemInnerSpacing.x) << "f," << std::to_string(ItemInnerSpacing.y) << "f);\n";
	out << "  style.IndentSpacing = " << std::to_string(IndentSpacing) << "f;\n";
	out << "  style.ScrollbarSize = " << std::to_string(ScrollbarSize) << "f;\n";
	out << "  style.GrabMinSize = " << std::to_string(GrabMinSize) << "f;\n";
	out << "  style.WindowBorderSize = " << std::to_string(WindowBorderSize) << "f;\n";
	out << "  style.ChildBorderSize = " << std::to_string(ChildBorderSize) << "f;\n";
	out << "  style.PopupBorderSize = " << std::to_string(PopupBorderSize) << "f;\n";
	out << "  style.FrameBorderSize = " << std::to_string(FrameBorderSize) << "f;\n";
	out << "  style.WindowRounding = " << std::to_string(WindowRounding) << "f;\n";
	out << "  style.ChildRounding = " << std::to_string(ChildRounding) << "f;\n";
	out << "  style.FrameRounding = " << std::to_string(FrameRounding) << "f;\n";
	out << "  style.PopupRounding = " << std::to_string(PopupRounding) << "f;\n";
	out << "  style.ScrollbarRounding = " << std::to_string(ScrollbarRounding) << "f;\n";
	out << "  style.GrabRounding = " << std::to_string(GrabRounding) << "f;\n";
	out << "  style.WindowTitleAlign = ImVec2(" << std::to_string(WindowTitleAlign.x) << "f,"<< std::to_string(WindowTitleAlign.y) << "f);\n";
	out << "  style.ButtonTextAlign = ImVec2(" << std::to_string(ButtonTextAlign.x) << "f," << std::to_string(ButtonTextAlign.y) << "f);\n";
	out << "  style.SelectableTextAlign = ImVec2(" << std::to_string(SelectableTextAlign.x) << "f," << std::to_string(SelectableTextAlign.y) << "f);\n\n";

	/*
	code3.append("  style.Colors[ImGuiCol_Text] = ImVec4("); code3.append(std::to_string(Text[0])); code3.append("f,");  code3.append(std::to_string(Text[1])); code3.append("f,");  code3.append(std::to_string(Text[2])); code3.append("f,");  code3.append(std::to_string(Text[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_TextDisabled] = ImVec4("); code3.append(std::to_string(TextDisabled[0])); code3.append("f,");  code3.append(std::to_string(TextDisabled[1])); code3.append("f,");  code3.append(std::to_string(TextDisabled[2])); code3.append("f,");  code3.append(std::to_string(TextDisabled[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_WindowBg] = ImVec4("); code3.append(std::to_string(WindowBg[0])); code3.append("f,");  code3.append(std::to_string(WindowBg[1])); code3.append("f,");   code3.append(std::to_string(WindowBg[2])); code3.append("f,");  code3.append(std::to_string(WindowBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ChildBg] = ImVec4("); code3.append(std::to_string(ChildBg[0])); code3.append("f,");  code3.append(std::to_string(ChildBg[1])); code3.append("f,");  code3.append(std::to_string(ChildBg[2]));  code3.append("f,");  code3.append(std::to_string(ChildBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_PopupBg] = ImVec4("); code3.append(std::to_string(PopupBg[0])); code3.append("f,");  code3.append(std::to_string(PopupBg[1])); code3.append("f,");  code3.append(std::to_string(PopupBg[2])); code3.append("f,");  code3.append(std::to_string(PopupBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_Border] = ImVec4("); code3.append(std::to_string(Border[0])); code3.append("f,");  code3.append(std::to_string(Border[1])); code3.append("f,");  code3.append(std::to_string(Border[2])); code3.append("f,");  code3.append(std::to_string(Border[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_BorderShadow] = ImVec4("); code3.append(std::to_string(BorderShadow[0])); code3.append("f,");   code3.append(std::to_string(BorderShadow[1])); code3.append("f,");  code3.append(std::to_string(BorderShadow[2])); code3.append("f,");  code3.append(std::to_string(BorderShadow[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_FrameBg] = ImVec4("); code3.append(std::to_string(FrameBg[0])); code3.append("f,");   code3.append(std::to_string(FrameBg[1])); code3.append("f,");  code3.append(std::to_string(FrameBg[2])); code3.append("f,");   code3.append(std::to_string(FrameBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_FrameBgHovered] = ImVec4("); code3.append(std::to_string(FrameBgHovered[0])); code3.append("f,");  code3.append(std::to_string(FrameBgHovered[1])); code3.append("f,");   code3.append(std::to_string(FrameBgHovered[2])); code3.append("f,");   code3.append(std::to_string(FrameBgHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_FrameBgActive] = ImVec4("); code3.append(std::to_string(FrameBgActive[0])); code3.append("f,");  code3.append(std::to_string(FrameBgActive[1])); code3.append("f,");   code3.append(std::to_string(FrameBgActive[2])); code3.append("f,");   code3.append(std::to_string(FrameBgActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_TitleBg] = ImVec4("); code3.append(std::to_string(TitleBg[0])); code3.append("f,");  code3.append(std::to_string(TitleBg[1])); code3.append("f,");  code3.append(std::to_string(TitleBg[2])); code3.append("f,");  code3.append(std::to_string(TitleBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_TitleBgActive] = ImVec4("); code3.append(std::to_string(TitleBgActive[0])); code3.append("f,");   code3.append(std::to_string(TitleBgActive[1])); code3.append("f,");  code3.append(std::to_string(TitleBgActive[2])); code3.append("f,");   code3.append(std::to_string(TitleBgActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4("); code3.append(std::to_string(TitleBgCollapsed[0])); code3.append("f,");   code3.append(std::to_string(TitleBgCollapsed[1])); code3.append("f,");   code3.append(std::to_string(TitleBgCollapsed[2])); code3.append("f,");   code3.append(std::to_string(TitleBgCollapsed[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_MenuBarBg] = ImVec4("); code3.append(std::to_string(MenuBarBg[0]));  code3.append("f,");  code3.append(std::to_string(MenuBarBg[1])); code3.append("f,");   code3.append(std::to_string(MenuBarBg[2])); code3.append("f,");   code3.append(std::to_string(MenuBarBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ScrollbarBg] = ImVec4("); code3.append(std::to_string(ScrollbarBg[0])); code3.append("f,");  code3.append(std::to_string(ScrollbarBg[1])); code3.append("f,");   code3.append(std::to_string(ScrollbarBg[2])); code3.append("f,");   code3.append(std::to_string(ScrollbarBg[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4("); code3.append(std::to_string(ScrollbarGrab[0])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrab[1])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrab[2])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrab[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4("); code3.append(std::to_string(ScrollbarGrabHovered[0])); code3.append("f,");  code3.append(std::to_string(ScrollbarGrabHovered[1])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrabHovered[2])); code3.append("f,");  code3.append(std::to_string(ScrollbarGrabHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4("); code3.append(std::to_string(ScrollbarGrabActive[0])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrabActive[1])); code3.append("f,");   code3.append(std::to_string(ScrollbarGrabActive[2])); code3.append("f,");  code3.append(std::to_string(ScrollbarGrabActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_CheckMark] = ImVec4("); code3.append(std::to_string(CheckMark[0])); code3.append("f,");  code3.append(std::to_string(CheckMark[1])); code3.append("f,");   code3.append(std::to_string(CheckMark[2])); code3.append("f,");   code3.append(std::to_string(CheckMark[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_SliderGrab] = ImVec4("); code3.append(std::to_string(SliderGrab[0])); code3.append("f,");  code3.append(std::to_string(SliderGrab[1])); code3.append("f,");   code3.append(std::to_string(SliderGrab[2])); code3.append("f,");   code3.append(std::to_string(SliderGrab[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_SliderGrabActive] = ImVec4("); code3.append(std::to_string(SliderGrabActive[0])); code3.append("f,");  code3.append(std::to_string(SliderGrabActive[1])); code3.append("f,");   code3.append(std::to_string(SliderGrabActive[2])); code3.append("f,");  code3.append(std::to_string(SliderGrabActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_Button] = ImVec4("); code3.append(std::to_string(Button[0])); code3.append("f,");   code3.append(std::to_string(Button[1])); code3.append("f,");   code3.append(std::to_string(Button[2])); code3.append("f,");   code3.append(std::to_string(Button[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ButtonHovered] = ImVec4("); code3.append(std::to_string(ButtonHovered[0])); code3.append("f,");   code3.append(std::to_string(ButtonHovered[1])); code3.append("f,");   code3.append(std::to_string(ButtonHovered[2])); code3.append("f,");  code3.append(std::to_string(ButtonHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ButtonActive] = ImVec4("); code3.append(std::to_string(ButtonActive[0])); code3.append("f,");   code3.append(std::to_string(ButtonActive[1])); code3.append("f,");   code3.append(std::to_string(ButtonActive[2])); code3.append("f,");   code3.append(std::to_string(ButtonActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_Header] = ImVec4("); code3.append(std::to_string(Header[0])); code3.append("f,");   code3.append(std::to_string(Header[1])); code3.append("f,");   code3.append(std::to_string(Header[2])); code3.append("f,");   code3.append(std::to_string(Header[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_HeaderHovered] = ImVec4("); code3.append(std::to_string(HeaderHovered[0])); code3.append("f,");   code3.append(std::to_string(HeaderHovered[1])); code3.append("f,");   code3.append(std::to_string(HeaderHovered[2])); code3.append("f,");  code3.append(std::to_string(HeaderHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_HeaderActive] = ImVec4("); code3.append(std::to_string(HeaderActive[0])); code3.append("f,");   code3.append(std::to_string(HeaderActive[1])); code3.append("f,");   code3.append(std::to_string(HeaderActive[2])); code3.append("f,");   code3.append(std::to_string(HeaderActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_Separator] = ImVec4("); code3.append(std::to_string(Separator[0])); code3.append("f,");   code3.append(std::to_string(Separator[1])); code3.append("f,");   code3.append(std::to_string(Separator[2])); code3.append("f,");   code3.append(std::to_string(Separator[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_SeparatorHovered] = ImVec4("); code3.append(std::to_string(SeparatorHovered[0])); code3.append("f,");   code3.append(std::to_string(SeparatorHovered[1])); code3.append("f,");   code3.append(std::to_string(SeparatorHovered[2])); code3.append("f,");  code3.append(std::to_string(SeparatorHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_SeparatorActive] = ImVec4("); code3.append(std::to_string(SeparatorActive[0])); code3.append("f,");   code3.append(std::to_string(SeparatorActive[1])); code3.append("f,");   code3.append(std::to_string(SeparatorActive[2])); code3.append("f,");  code3.append(std::to_string(SeparatorActive[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ResizeGrip] = ImVec4("); code3.append(std::to_string(ResizeGrip[0])); code3.append("f,");  code3.append(std::to_string(ResizeGrip[1])); code3.append("f,");   code3.append(std::to_string(ResizeGrip[2])); code3.append("f,");   code3.append(std::to_string(ResizeGrip[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4("); code3.append(std::to_string(ResizeGripHovered[0])); code3.append("f,");   code3.append(std::to_string(ResizeGripHovered[1])); code3.append("f,");   code3.append(std::to_string(ResizeGripHovered[2])); code3.append("f,");   code3.append(std::to_string(ResizeGripHovered[3])); code3.append("f"); code3.append(");\n");
	code3.append("  style.Colors[ImGuiCol_ResizeGripActive] = ImVec4("); code3.append(std::to_string(ResizeGripActive[0])); code3.append("f,");   code3.append(std::to_string(ResizeGripActive[1])); code3.append("f,");   code3.append(std::to_string(ResizeGripActive[2])); code3.append("f,");   code3.append(std::to_string(ResizeGripActive[3])); code3.append("f"); code3.append(");\n");
	code4.append("  style.Colors[ImGuiCol_TextSelectedBg] = ImVec4("); code4.append(std::to_string(TextSelectedBg[0])); code3.append("f,"); 2 code4.append(std::to_string(TextSelectedBg[1])); code3.append("f,"); 2  code4.append(std::to_string(TextSelectedBg[2])); code3.append("f,"); 2  code4.append(std::to_string(TextSelectedBg[3])); code4.append("f"); code4.append(");\n");
	code4.append("  style.Colors[ImGuiCol_DragDropTarget] = ImVec4("); code4.append(std::to_string(DragDropTarget[0])); code3.append("f,"); 2 code4.append(std::to_string(DragDropTarget[1])); code3.append("f,"); 2  code4.append(std::to_string(DragDropTarget[2])); code3.append("f,"); 2  code4.append(std::to_string(DragDropTarget[3])); code4.append("f"); code4.append(");\n");
	code4.append("}");*/


	out.close();

	ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_RESTORE);
}