#include "settings.h"
#include "../list.h"

namespace WidgetCheckbox
{
	bool ttb_include_label_size_x = true;
	bool ttb_include_label_size_y = true;

	bool ttb_include_frame_padding_y = true;
	int ttb_frame_padding_multiplier = 2;

	bool ttb_include_custom_size_x = false;
	bool ttb_include_custom_size_y = false;

	int ttb_total_bb_size_x = 0;
	int ttb_total_bb_size_y = 0;

	bool draw_total_bb_border = false;

	///////////////////////////////////////////////

	bool ckb_include_square_sz_x = true;
	bool ckb_include_square_sz_y = true;

	bool ckb_include_custom_size_x = false;
	bool ckb_include_custom_size_y = false;

	int ckb_total_bb_size_x = 0;
	int ckb_total_bb_size_y = 0;

	///////////////////////////////////////////////

	int label_pos_x = 20;
	int label_pos_y = 0;

	///////////////////////////////////////////////
}

namespace Settings
{
    float       Alpha;
    ImVec2      WindowPadding = { 6,6 };
    float       WindowRounding = 0.f;
    float       WindowBorderSize = 1.f;
    ImVec2      WindowMinSize = { 100,100 };
    ImVec2      WindowTitleAlign = { 0,0.5f };
    float       ChildRounding = 0.f;
    float       ChildBorderSize = 1.f;
    float       PopupRounding = 0.f;
    float       PopupBorderSize = 1.f;
    ImVec2      FramePadding = { 4,3 };
    float       FrameRounding = 0.f;
    float       FrameBorderSize = 1.f;
    ImVec2      ItemSpacing = { 8,4 };
    ImVec2      ItemInnerSpacing = { 4,4 };
    ImVec2      TouchExtraPadding = { 0,0 };
    float       IndentSpacing = 21.f;
    float       ColumnsMinSpacing;
    float       ScrollbarSize = 1.f;
    float       ScrollbarRounding;
    float       GrabMinSize = 1.f;
    float       GrabRounding = 0.f;
    float       TabMinWidthForUnselectedCloseButton;
    ImVec2      ButtonTextAlign = { 0.5f,0.5f };
    ImVec2      SelectableTextAlign = { 0.5f,0.5f };
    ImVec2      DisplayWindowPadding = { 0.5f,0.5f };
    ImVec2      DisplaySafeAreaPadding = { 3,3 };
    float       MouseCursorScale;
    bool        AntiAliasedLines;
    bool        AntiAliasedFill;
    float       CurveTessellationTol;
    float       CircleSegmentMaxError;

    int total_items = 0;
    ImVec2 windowsize = { 400,400 };

    bool no_titlebar,
        no_scrollbar,
        no_move,
        no_resize,
        no_collapse,
        no_close,
        no_nav,
        no_background,
        no_bring_to_front, no_menu;

    bool setwindow = false;

	bool menu_config_state = false;

    float Text[4] = { 0.90f, 0.90f, 0.90f, 1.00f };
    float TextDisabled[4] = { 0.60f, 0.60f, 0.60f, 1.00f };
    float WindowBg[4] = { 0.00f, 0.00f, 0.00f, 0.70f };
    float ChildBg[4] = { 0.00f, 0.00f, 0.00f, 0.00f };
    float PopupBg[4] = { 0.11f, 0.11f, 0.14f, 0.92f };
    float Border[4] = { 0.50f, 0.50f, 0.50f, 0.50f };
    float BorderShadow[4] = { 0.00f, 0.00f, 0.00f, 0.00f };
    float FrameBg[4] = { 0.43f, 0.43f, 0.43f, 0.39f };
    float FrameBgHovered[4] = { 0.47f, 0.47f, 0.69f, 0.40f };
    float FrameBgActive[4] = { 0.42f, 0.41f, 0.64f, 0.69f };
    float TitleBg[4] = { 0.27f, 0.27f, 0.54f, 0.83f };
    float TitleBgActive[4] = { 0.32f, 0.32f, 0.63f, 0.87f };
    float TitleBgCollapsed[4] = { 0.40f, 0.40f, 0.80f, 0.20f };
    float MenuBarBg[4] = { 0.40f, 0.40f, 0.55f, 0.80f };
    float ScrollbarBg[4] = { 0.20f, 0.25f, 0.30f, 0.60f };
    float ScrollbarGrab[4] = { 0.40f, 0.40f, 0.80f, 0.30f };
    float ScrollbarGrabHovered[4] = { 0.40f, 0.40f, 0.80f, 0.40f };
    float ScrollbarGrabActive[4] = { 0.41f, 0.39f, 0.80f, 0.60f };
    float CheckMark[4] = { 0.90f, 0.90f, 0.90f, 0.50f };
    float SliderGrab[4] = { 1.00f, 1.00f, 1.00f, 0.30f };
    float SliderGrabActive[4] = { 0.41f, 0.39f, 0.80f, 0.60f };
    float Button[4] = { 0.35f, 0.40f, 0.61f, 0.62f };
    float ButtonHovered[4] = { 0.40f, 0.48f, 0.71f, 0.79f };
    float ButtonActive[4] = { 0.46f, 0.54f, 0.80f, 1.00f };
    float Header[4] = { 0.40f, 0.40f, 0.90f, 0.45f };
    float HeaderHovered[4] = { 0.45f, 0.45f, 0.90f, 0.80f };
    float HeaderActive[4] = { 0.53f, 0.53f, 0.87f, 0.80f };
    float Separator[4] = { 0.50f, 0.50f, 0.50f, 0.60f };
    float SeparatorHovered[4] = { 0.60f, 0.60f, 0.70f, 1.00f };
    float SeparatorActive[4] = { 0.70f, 0.70f, 0.90f, 1.00f };
    float ResizeGrip[4] = { 1.00f, 1.00f, 1.00f, 0.16f };
    float ResizeGripHovered[4] = { 0.78f, 0.82f, 1.00f, 0.60f };
    float ResizeGripActive[4] = { 0.78f, 0.82f, 1.00f, 0.90f };
    float TextSelectedBg[4] = { 0.00f, 0.00f, 1.00f, 0.35f };
    float DragDropTarget[4] = { 1.00f, 1.00f, 0.00f, 0.90f };

	float width = 430;

    int LoadSettings(string szIniFile)
    {
        try
        {
            if (Cvar::InitPath(szIniFile.c_str()) == 1)
            {
                return 1;
            }
        }
        catch (...)
        {
            return 1;
        }

        list_lines.clear();

        Cvar::LoadColor("Colors", "Text", Text);
        Cvar::LoadColor("Colors", "TextDisabled", TextDisabled);
        Cvar::LoadColor("Colors", "WindowBg", WindowBg);
        Cvar::LoadColor("Colors", "ChildBg", ChildBg);
        Cvar::LoadColor("Colors", "PopupBg", PopupBg);
        Cvar::LoadColor("Colors", "Border", Border);
        Cvar::LoadColor("Colors", "BorderShadow", BorderShadow);
        Cvar::LoadColor("Colors", "FrameBg", FrameBg);
        Cvar::LoadColor("Colors", "FrameBgHovered", FrameBgHovered);
        Cvar::LoadColor("Colors", "FrameBgActive", FrameBgActive);
        Cvar::LoadColor("Colors", "TitleBg", TitleBg);
        Cvar::LoadColor("Colors", "TitleBgActive", TitleBgActive);
        Cvar::LoadColor("Colors", "TitleBgCollapsed", TitleBgCollapsed);
        Cvar::LoadColor("Colors", "MenuBarBg", MenuBarBg);
        Cvar::LoadColor("Colors", "ScrollbarBg", ScrollbarBg);
        Cvar::LoadColor("Colors", "ScrollbarGrab", ScrollbarGrab);
        Cvar::LoadColor("Colors", "ScrollbarGrabHovered", ScrollbarGrabHovered);
        Cvar::LoadColor("Colors", "ScrollbarGrabActive", ScrollbarGrabActive);
        Cvar::LoadColor("Colors", "CheckMark", CheckMark);
        Cvar::LoadColor("Colors", "SliderGrab", SliderGrab);
        Cvar::LoadColor("Colors", "SliderGrabActive", SliderGrabActive);
        Cvar::LoadColor("Colors", "Button", Button);
        Cvar::LoadColor("Colors", "ButtonHovered", ButtonHovered);
        Cvar::LoadColor("Colors", "ButtonActive", ButtonActive);
        Cvar::LoadColor("Colors", "Header", Header);
        Cvar::LoadColor("Colors", "HeaderHovered", HeaderHovered);
        Cvar::LoadColor("Colors", "HeaderActive", HeaderActive);
        Cvar::LoadColor("Colors", "Separator", Separator);
        Cvar::LoadColor("Colors", "SeparatorHovered", SeparatorHovered);
        Cvar::LoadColor("Colors", "SeparatorActive", SeparatorActive);
        Cvar::LoadColor("Colors", "ResizeGrip", ResizeGrip);
        Cvar::LoadColor("Colors", "ResizeGripHovered", ResizeGripHovered);
        Cvar::LoadColor("Colors", "ResizeGripActive", ResizeGripActive);
        Cvar::LoadColor("Colors", "TextSelectedBg", TextSelectedBg);
        Cvar::LoadColor("Colors", "DragDropTarget", DragDropTarget);

        Alpha = Cvar::LoadCvar("Flags", "Alpha", Alpha);
        WindowPadding.x = Cvar::LoadCvar("Flags", "WindowPadding.x", WindowPadding.x);
        WindowPadding.y = Cvar::LoadCvar("Flags", "WindowPadding.x", WindowPadding.y);
        windowsize.x = Cvar::LoadCvar("Flags", "WindowSize.x", windowsize.x);
        windowsize.y = Cvar::LoadCvar("Flags", "WindowSize.y", windowsize.y);
        WindowRounding = Cvar::LoadCvar("Flags", "WindowRounding", WindowRounding);
        WindowBorderSize = Cvar::LoadCvar("Flags", "WindowBorderSize", WindowBorderSize);
        WindowMinSize.x = Cvar::LoadCvar("Flags", "WindowMinSize.x", WindowMinSize.x);
        WindowMinSize.y = Cvar::LoadCvar("Flags", "WindowMinSize.y", WindowMinSize.y);
        WindowTitleAlign.x = Cvar::LoadCvar("Flags", "WindowTitleAlign.x", WindowTitleAlign.x);
        WindowTitleAlign.y = Cvar::LoadCvar("Flags", "WindowTitleAlign.y", WindowTitleAlign.y);
        ChildRounding = Cvar::LoadCvar("Flags", "ChildRounding", ChildRounding);
        ChildBorderSize = Cvar::LoadCvar("Flags", "ChildBorderSize", ChildBorderSize);
        PopupRounding = Cvar::LoadCvar("Flags", "PopupRounding", PopupRounding);
        PopupBorderSize = Cvar::LoadCvar("Flags", "PopupBorderSize", PopupBorderSize);
        FramePadding.x = Cvar::LoadCvar("Flags", "FramePadding.x", FramePadding.x);
        FramePadding.y = Cvar::LoadCvar("Flags", "FramePadding.y", FramePadding.y);
        FrameRounding = Cvar::LoadCvar("Flags", "FrameRounding", FrameRounding);
        FrameBorderSize = Cvar::LoadCvar("Flags", "FrameBorderSize", FrameBorderSize);
        TouchExtraPadding.x = Cvar::LoadCvar("Flags", "TouchExtraPadding.x", TouchExtraPadding.x);
        TouchExtraPadding.y = Cvar::LoadCvar("Flags", "TouchExtraPadding.y", TouchExtraPadding.y);
        ItemInnerSpacing.x = Cvar::LoadCvar("Flags", "ItemInnerSpacing.x", ItemInnerSpacing.x);
        ItemInnerSpacing.y = Cvar::LoadCvar("Flags", "ItemInnerSpacing.y", ItemInnerSpacing.y);
        ItemSpacing.x = Cvar::LoadCvar("Flags", "ItemSpacing.x", ItemSpacing.x);
        ItemSpacing.y = Cvar::LoadCvar("Flags", "ItemSpacing.y", ItemSpacing.y);
        IndentSpacing = Cvar::LoadCvar("Flags", "IndentSpacing", IndentSpacing);
        ColumnsMinSpacing = Cvar::LoadCvar("Flags", "ColumnsMinSpacing", ColumnsMinSpacing);
        ScrollbarSize = Cvar::LoadCvar("Flags", "ScrollbarSize", ScrollbarSize);
        ScrollbarRounding = Cvar::LoadCvar("Flags", "ScrollbarRounding", ScrollbarRounding);
        GrabMinSize = Cvar::LoadCvar("Flags", "GrabMinSize", GrabMinSize);
        GrabRounding = Cvar::LoadCvar("Flags", "GrabRounding", GrabRounding);
        TabMinWidthForUnselectedCloseButton = Cvar::LoadCvar("Flags", "TabMinWidthForUnselectedCloseButton", TabMinWidthForUnselectedCloseButton);
        DisplaySafeAreaPadding.x = Cvar::LoadCvar("Flags", "DisplaySafeAreaPadding.x", DisplaySafeAreaPadding.x);
        DisplaySafeAreaPadding.y = Cvar::LoadCvar("Flags", "DisplaySafeAreaPadding.y", DisplaySafeAreaPadding.y);
        DisplayWindowPadding.x = Cvar::LoadCvar("Flags", "DisplayWindowPadding.x", DisplayWindowPadding.x);
        DisplayWindowPadding.y = Cvar::LoadCvar("Flags", "DisplayWindowPadding.y", DisplayWindowPadding.y);
        SelectableTextAlign.x = Cvar::LoadCvar("Flags", "SelectableTextAlign.x", SelectableTextAlign.x);
        SelectableTextAlign.y = Cvar::LoadCvar("Flags", "SelectableTextAlign.y", SelectableTextAlign.y);
        ButtonTextAlign.x = Cvar::LoadCvar("Flags", "ButtonTextAlign.x", ButtonTextAlign.x);
        ButtonTextAlign.y = Cvar::LoadCvar("Flags", "ButtonTextAlign.y", ButtonTextAlign.y);
        MouseCursorScale = Cvar::LoadCvar("Flags", "MouseCursorScale", MouseCursorScale);
        AntiAliasedLines = Cvar::LoadCvar("Flags", "AntiAliasedLines", AntiAliasedLines);
        AntiAliasedFill = Cvar::LoadCvar("Flags", "AntiAliasedFill", AntiAliasedFill);
        CurveTessellationTol = Cvar::LoadCvar("Flags", "CurveTessellationTol", CurveTessellationTol);
        CircleSegmentMaxError = Cvar::LoadCvar("Flags", "CircleSegmentMaxError", CircleSegmentMaxError);

        total_items = Cvar::LoadCvar("Elements Data", "total_elements", total_items);

        for (auto iter = 0; iter < total_items; iter++)
        {
            std::string sectionname = "Element";
            sectionname.append(std::to_string(iter));


            list_lines.push_back(drawlist_struct(
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "draw_type", 0),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "description", "2"),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "secretname", "2"),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "pos1", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "pos2", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "pos3", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "pos4", 1),
                                                ImColor(Cvar::LoadCvar((char*)sectionname.c_str(), "color0.r", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color0.g", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color0.b", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color0.a", 0.f)),
                                                ImColor(Cvar::LoadCvar((char*)sectionname.c_str(), "color1.r", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color1.g", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color1.b", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color1.a", 0.f)),
                                                ImColor(Cvar::LoadCvar((char*)sectionname.c_str(), "color2.r", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color2.g", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color2.b", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color2.a", 0.f)),
                                                ImColor(Cvar::LoadCvar((char*)sectionname.c_str(), "color3.r", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color3.g", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color3.b", 0.f),
                                                    Cvar::LoadCvar((char*)sectionname.c_str(), "color3.a", 0.f)),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "thinkness", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "segments", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "rounding", 1),
                                                Cvar::LoadCvar((char*)sectionname.c_str(), "radius", 1)));
        }
    }

    int SaveSettings(string szIniFile)
    {
        try {
            if (Cvar::InitPath(szIniFile.c_str()) == 1)
            {
                return 1;
            }
        }
        catch (...)
        {
            return 1;
        }

        Cvar::SaveColor("Colors", "Text", Text);
        Cvar::SaveColor("Colors", "TextDisabled", TextDisabled);
        Cvar::SaveColor("Colors", "WindowBg", WindowBg);
        Cvar::SaveColor("Colors", "ChildBg", ChildBg);
        Cvar::SaveColor("Colors", "PopupBg", PopupBg);
        Cvar::SaveColor("Colors", "Border", Border);
        Cvar::SaveColor("Colors", "BorderShadow", BorderShadow);
        Cvar::SaveColor("Colors", "FrameBg", FrameBg);
        Cvar::SaveColor("Colors", "FrameBgHovered", FrameBgHovered);
        Cvar::SaveColor("Colors", "FrameBgActive", FrameBgActive);
        Cvar::SaveColor("Colors", "TitleBg", TitleBg);
        Cvar::SaveColor("Colors", "TitleBgActive", TitleBgActive);
        Cvar::SaveColor("Colors", "TitleBgCollapsed", TitleBgCollapsed);
        Cvar::SaveColor("Colors", "MenuBarBg", MenuBarBg);
        Cvar::SaveColor("Colors", "ScrollbarBg", ScrollbarBg);
        Cvar::SaveColor("Colors", "ScrollbarGrab", ScrollbarGrab);
        Cvar::SaveColor("Colors", "ScrollbarGrabHovered", ScrollbarGrabHovered);
        Cvar::SaveColor("Colors", "ScrollbarGrabActive", ScrollbarGrabActive);
        Cvar::SaveColor("Colors", "CheckMark", CheckMark);
        Cvar::SaveColor("Colors", "SliderGrab", SliderGrab);
        Cvar::SaveColor("Colors", "SliderGrabActive", SliderGrabActive);
        Cvar::SaveColor("Colors", "Button", Button);
        Cvar::SaveColor("Colors", "ButtonHovered", ButtonHovered);
        Cvar::SaveColor("Colors", "ButtonActive", ButtonActive);
        Cvar::SaveColor("Colors", "Header", Header);
        Cvar::SaveColor("Colors", "HeaderHovered", HeaderHovered);
        Cvar::SaveColor("Colors", "HeaderActive", HeaderActive);
        Cvar::SaveColor("Colors", "Separator", Separator);
        Cvar::SaveColor("Colors", "SeparatorHovered", SeparatorHovered);
        Cvar::SaveColor("Colors", "SeparatorActive", SeparatorActive);
        Cvar::SaveColor("Colors", "ResizeGrip", ResizeGrip);
        Cvar::SaveColor("Colors", "ResizeGripHovered", ResizeGripHovered);
        Cvar::SaveColor("Colors", "ResizeGripActive", ResizeGripActive);
        Cvar::SaveColor("Colors", "TextSelectedBg", TextSelectedBg);
        Cvar::SaveColor("Colors", "DragDropTarget", DragDropTarget);

        Cvar::SaveCvar("Flags", "Alpha", Alpha);
        Cvar::SaveCvar("Flags", "WindowPadding.x", WindowPadding.x);
        Cvar::SaveCvar("Flags", "WindowPadding.x", WindowPadding.y);
        Cvar::SaveCvar("Flags", "WindowSize.x", windowsize.x);
        Cvar::SaveCvar("Flags", "WindowSize.y", windowsize.y);
        Cvar::SaveCvar("Flags", "WindowRounding", WindowRounding);
        Cvar::SaveCvar("Flags", "WindowBorderSize", WindowBorderSize);
        Cvar::SaveCvar("Flags", "WindowMinSize.x", WindowMinSize.x);
        Cvar::SaveCvar("Flags", "WindowMinSize.y", WindowMinSize.y);
        Cvar::SaveCvar("Flags", "WindowTitleAlign.x", WindowTitleAlign.x);
        Cvar::SaveCvar("Flags", "WindowTitleAlign.y", WindowTitleAlign.y);
        Cvar::SaveCvar("Flags", "ChildRounding", ChildRounding);
        Cvar::SaveCvar("Flags", "ChildBorderSize", ChildBorderSize);
        Cvar::SaveCvar("Flags", "PopupRounding", PopupRounding);
        Cvar::SaveCvar("Flags", "PopupBorderSize", PopupBorderSize);
        Cvar::SaveCvar("Flags", "FramePadding.x", FramePadding.x);
        Cvar::SaveCvar("Flags", "FramePadding.y", FramePadding.y);
        Cvar::SaveCvar("Flags", "FrameRounding", FrameRounding);
        Cvar::SaveCvar("Flags", "FrameBorderSize", FrameBorderSize);
        Cvar::SaveCvar("Flags", "TouchExtraPadding.x", TouchExtraPadding.x);
        Cvar::SaveCvar("Flags", "TouchExtraPadding.y", TouchExtraPadding.y);
        Cvar::SaveCvar("Flags", "ItemInnerSpacing.x", ItemInnerSpacing.x);
        Cvar::SaveCvar("Flags", "ItemInnerSpacing.y", ItemInnerSpacing.y);
        Cvar::SaveCvar("Flags", "ItemSpacing.x", ItemSpacing.x);
        Cvar::SaveCvar("Flags", "ItemSpacing.y", ItemSpacing.y);
        Cvar::SaveCvar("Flags", "IndentSpacing", IndentSpacing);
        Cvar::SaveCvar("Flags", "ColumnsMinSpacing", ColumnsMinSpacing);
        Cvar::SaveCvar("Flags", "ScrollbarSize", ScrollbarSize);
        Cvar::SaveCvar("Flags", "ScrollbarRounding", ScrollbarRounding);
        Cvar::SaveCvar("Flags", "GrabMinSize", GrabMinSize);
        Cvar::SaveCvar("Flags", "GrabRounding", GrabRounding);
        Cvar::SaveCvar("Flags", "TabMinWidthForUnselectedCloseButton", TabMinWidthForUnselectedCloseButton);
        Cvar::SaveCvar("Flags", "DisplaySafeAreaPadding.x", DisplaySafeAreaPadding.x);
        Cvar::SaveCvar("Flags", "DisplaySafeAreaPadding.y", DisplaySafeAreaPadding.y);
        Cvar::SaveCvar("Flags", "DisplayWindowPadding.x", DisplayWindowPadding.x);
        Cvar::SaveCvar("Flags", "DisplayWindowPadding.y", DisplayWindowPadding.y);
        Cvar::SaveCvar("Flags", "SelectableTextAlign.x", SelectableTextAlign.x);
        Cvar::SaveCvar("Flags", "SelectableTextAlign.y", SelectableTextAlign.y);
        Cvar::SaveCvar("Flags", "ButtonTextAlign.x", ButtonTextAlign.x);
        Cvar::SaveCvar("Flags", "ButtonTextAlign.y", ButtonTextAlign.y);
        Cvar::SaveCvar("Flags", "MouseCursorScale", MouseCursorScale);
        Cvar::SaveCvar("Flags", "AntiAliasedLines", AntiAliasedLines);
        Cvar::SaveCvar("Flags", "AntiAliasedFill", AntiAliasedFill);
        Cvar::SaveCvar("Flags", "CurveTessellationTol", CurveTessellationTol);
        Cvar::SaveCvar("Flags", "CircleSegmentMaxError", CircleSegmentMaxError);

        Cvar::SaveCvar("Elements Data", "total_elements", (int)list_lines.size());

        for (auto iter = list_lines.begin(); iter != list_lines.end(); iter++)
        {
            std::string sectionname = "Element";
            sectionname.append(std::to_string(distance(list_lines.begin(), iter)));

            Cvar::SaveCvar((char*)sectionname.c_str(), "draw_type", iter->draw);
            Cvar::SaveCvar((char*)sectionname.c_str(), "description", iter->name);
            Cvar::SaveCvar((char*)sectionname.c_str(), "secretname", iter->secret_name);

            Cvar::SaveCvar((char*)sectionname.c_str(), "pos1", iter->pos1);
            Cvar::SaveCvar((char*)sectionname.c_str(), "pos2", iter->pos2);
            Cvar::SaveCvar((char*)sectionname.c_str(), "pos3", iter->pos3);
            Cvar::SaveCvar((char*)sectionname.c_str(), "pos4", iter->pos4);

            Cvar::SaveCvar((char*)sectionname.c_str(), "color0.r", iter->color0.Value.x);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color0.g", iter->color0.Value.y);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color0.b", iter->color0.Value.z);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color0.a", iter->color0.Value.w);

            Cvar::SaveCvar((char*)sectionname.c_str(), "color1.r", iter->color1.Value.x);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color1.g", iter->color1.Value.y);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color1.b", iter->color1.Value.z);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color1.a", iter->color1.Value.w);

            Cvar::SaveCvar((char*)sectionname.c_str(), "color2.r", iter->color2.Value.x);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color2.g", iter->color2.Value.y);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color2.b", iter->color2.Value.z);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color2.a", iter->color2.Value.w);

            Cvar::SaveCvar((char*)sectionname.c_str(), "color3.r", iter->color3.Value.x);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color3.g", iter->color3.Value.y);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color3.b", iter->color3.Value.z);
            Cvar::SaveCvar((char*)sectionname.c_str(), "color3.a", iter->color3.Value.w);

            Cvar::SaveCvar((char*)sectionname.c_str(), "thinkness", iter->thinkness);
            Cvar::SaveCvar((char*)sectionname.c_str(), "segments", iter->segments);
            Cvar::SaveCvar((char*)sectionname.c_str(), "rounding", iter->round);
            Cvar::SaveCvar((char*)sectionname.c_str(), "radius", iter->radius);
        }
    }
}
