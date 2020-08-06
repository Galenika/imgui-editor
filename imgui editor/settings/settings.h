#pragma once

#include "cvar_saver.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../list.h"

namespace WidgetCheckbox
{
	extern bool ttb_include_label_size_x;
	extern bool ttb_include_label_size_y;
	extern bool ttb_include_frame_padding_y;
	extern int ttb_frame_padding_multiplier;

	extern bool ttb_include_custom_size_x;
	extern bool ttb_include_custom_size_y;
	extern int ttb_total_bb_size_x;
	extern int ttb_total_bb_size_y;

	extern bool draw_total_bb_border;

	///////////////////////////////////////////

	extern bool ckb_include_square_sz_x;
	extern bool ckb_include_square_sz_y;

	extern bool ckb_include_custom_size_x;
	extern bool ckb_include_custom_size_y;

	extern int ckb_total_bb_size_x;
	extern int ckb_total_bb_size_y;

	///////////////////////////////////////////////

	extern int label_pos_x;
	extern int label_pos_y;
}

namespace Settings
{
    extern float       Alpha;
    extern ImVec2      WindowPadding;
    extern float       WindowRounding;
    extern float       WindowBorderSize;
    extern ImVec2      WindowMinSize;
    extern ImVec2      WindowTitleAlign;
    extern float       ChildRounding;
    extern float       ChildBorderSize;
    extern float       PopupRounding;
    extern float       PopupBorderSize;
    extern ImVec2      FramePadding;
    extern float       FrameRounding;
    extern float       FrameBorderSize;
    extern ImVec2      ItemSpacing;
    extern ImVec2      ItemInnerSpacing;
    extern ImVec2      TouchExtraPadding;
    extern float       IndentSpacing;
    extern float       ColumnsMinSpacing;
    extern float       ScrollbarSize;
    extern float       ScrollbarRounding;
    extern float       GrabMinSize;
    extern float       GrabRounding;
    extern float       TabMinWidthForUnselectedCloseButton;
    extern ImVec2      ButtonTextAlign;
    extern ImVec2      SelectableTextAlign;
    extern ImVec2      DisplayWindowPadding;
    extern ImVec2      DisplaySafeAreaPadding;
    extern float       MouseCursorScale;
    extern bool        AntiAliasedLines;
    extern bool        AntiAliasedFill;
    extern float       CurveTessellationTol;
    extern float       CircleSegmentMaxError;

    extern int total_items;
    extern ImVec2 windowsize;

    extern bool no_titlebar,
        no_scrollbar,
        no_move,
        no_resize,
        no_collapse,
        no_close,
        no_nav,
        no_background,
        no_bring_to_front, no_menu;

    extern bool setwindow;

	extern bool menu_config_state;

    extern float Text[4];
    extern float TextDisabled[4];
    extern float WindowBg[4];
    extern float ChildBg[4];
    extern float PopupBg[4];
    extern float Border[4];
    extern float BorderShadow[4];
    extern float FrameBg[4];
    extern float FrameBgHovered[4];
    extern float FrameBgActive[4];
    extern float TitleBg[4];
    extern float TitleBgActive[4];
    extern float TitleBgCollapsed[4];
    extern float MenuBarBg[4];
    extern float ScrollbarBg[4];
    extern float ScrollbarGrab[4];
    extern float ScrollbarGrabHovered[4];
    extern float ScrollbarGrabActive[4];
    extern float CheckMark[4];
    extern float SliderGrab[4];
    extern float SliderGrabActive[4];
    extern float Button[4];
    extern float ButtonHovered[4];
    extern float ButtonActive[4];
    extern float Header[4];
    extern float HeaderHovered[4];
    extern float HeaderActive[4];
    extern float Separator[4];
    extern float SeparatorHovered[4];
    extern float SeparatorActive[4];
    extern float ResizeGrip[4];
    extern float ResizeGripHovered[4];
    extern float ResizeGripActive[4];
    extern float TextSelectedBg[4];
    extern float DragDropTarget[4];

	extern float width;

    int LoadSettings(string szIniFile);
    int SaveSettings(string szIniFile);
}
