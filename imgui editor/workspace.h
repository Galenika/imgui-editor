#pragma once

#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#include "imgui/notifies.h"
#include "settings/settings.h"

#include "widgets.h"

using namespace Settings;

void BackGround()
{
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    ImGui::SetNextWindowPos({ 0,0 });
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
    ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

    for (int i = 0; i <= ImGui::GetIO().DisplaySize.x; i += 10)
    {
        ImGui::GetWindowDrawList()->AddLine({ ImGui::GetWindowPos().x + i, 0 }, { ImGui::GetWindowPos().x + i,  ImGui::GetWindowPos().y + ImGui::GetIO().DisplaySize.y }, ImColor(50, 50, 50, 250));
    }

    for (int i = 0; i <= ImGui::GetIO().DisplaySize.y; i += 10)
    {
        ImGui::GetWindowDrawList()->AddLine({ 0, ImGui::GetWindowPos().x + i }, { ImGui::GetWindowPos().x + ImGui::GetIO().DisplaySize.x ,ImGui::GetWindowPos().x + i }, ImColor(50, 50, 50, 250));
    }

    notifies::handle(ImGui::GetWindowDrawList());

    ImGui::End();
    ImGui::PopStyleColor();
}


void EditedWindow()
{
    auto flags = (no_titlebar ? ImGuiWindowFlags_NoTitleBar : NULL) |
        (no_scrollbar ? ImGuiWindowFlags_NoScrollbar : NULL) |
        (no_menu ? ImGuiWindowFlags_MenuBar : NULL) |
        (no_move ? ImGuiWindowFlags_NoMove : NULL) |
        (no_resize ? ImGuiWindowFlags_NoResize : NULL) |
        (no_collapse ? ImGuiWindowFlags_NoCollapse : NULL) |
        (no_nav ? ImGuiWindowFlags_NoNav : NULL) |
        (no_background ? ImGuiWindowFlags_NoBackground : NULL) |
        (no_bring_to_front ? ImGuiWindowFlags_NoBringToFrontOnFocus : NULL);


    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, WindowPadding);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, FramePadding);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ItemSpacing);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ItemInnerSpacing);
    ImGui::PushStyleVar(ImGuiStyleVar_IndentSpacing, IndentSpacing);
    ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, ScrollbarSize);
    ImGui::PushStyleVar(ImGuiStyleVar_GrabMinSize, GrabMinSize);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, WindowBorderSize);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, ChildBorderSize);
    ImGui::PushStyleVar(ImGuiStyleVar_PopupBorderSize, PopupBorderSize);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, FrameBorderSize);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, WindowRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, ChildRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, FrameRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_PopupRounding, PopupRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarRounding, ScrollbarRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, GrabRounding);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, WindowTitleAlign);
    ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ButtonTextAlign);
    ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, SelectableTextAlign);

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Text[0], Text[1], Text[2], Text[3]));
    ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImVec4(TextDisabled[0], TextDisabled[1], TextDisabled[2], TextDisabled[3]));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(WindowBg[0], WindowBg[1], WindowBg[2], WindowBg[3]));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(ChildBg[0], ChildBg[1], ChildBg[2], ChildBg[3]));
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(PopupBg[0], PopupBg[1], PopupBg[2], PopupBg[3]));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(Border[0], Border[1], Border[2], Border[3]));
    ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(BorderShadow[0], BorderShadow[1], BorderShadow[2], BorderShadow[3]));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(FrameBg[0], FrameBg[1], FrameBg[2], FrameBg[3]));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(FrameBgHovered[0], FrameBgHovered[1], FrameBgHovered[2], FrameBgHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(FrameBgActive[0], FrameBgActive[1], FrameBgActive[2], FrameBgActive[3]));
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(TitleBg[0], TitleBg[1], TitleBg[2], TitleBg[3]));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(TitleBgActive[0], TitleBgActive[1], TitleBgActive[2], TitleBgActive[3]));
    ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, ImVec4(TitleBgCollapsed[0], TitleBgCollapsed[1], TitleBgCollapsed[2], TitleBgCollapsed[3]));
    ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(MenuBarBg[0], MenuBarBg[1], MenuBarBg[2], MenuBarBg[3]));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, ImVec4(ScrollbarBg[0], ScrollbarBg[1], ScrollbarBg[2], ScrollbarBg[3]));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, ImVec4(ScrollbarGrab[0], ScrollbarGrab[1], ScrollbarGrab[2], ScrollbarGrab[3]));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, ImVec4(ScrollbarGrabHovered[0], ScrollbarGrabHovered[1], ScrollbarGrabHovered[2], ScrollbarGrabHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, ImVec4(ScrollbarGrabActive[0], ScrollbarGrabActive[1], ScrollbarGrabActive[2], ScrollbarGrabActive[3]));
    ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(CheckMark[0], CheckMark[1], CheckMark[2], CheckMark[3]));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(SliderGrab[0], SliderGrab[1], SliderGrab[2], SliderGrab[3]));
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(SliderGrabActive[0], SliderGrabActive[1], SliderGrabActive[2], SliderGrabActive[3]));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(Button[0], Button[1], Button[2], Button[3]));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ButtonHovered[0], ButtonHovered[1], ButtonHovered[2], ButtonHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ButtonActive[0], ButtonActive[1], ButtonActive[2], ButtonActive[3]));
    ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(Header[0], Header[1], Header[2], Header[3]));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(HeaderHovered[0], HeaderHovered[1], HeaderHovered[2], HeaderHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(HeaderActive[0], HeaderActive[1], HeaderActive[2], HeaderActive[3]));
    ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(Separator[0], Separator[1], Separator[2], Separator[3]));
    ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(SeparatorHovered[0], SeparatorHovered[1], SeparatorHovered[2], SeparatorHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(SeparatorActive[0], SeparatorActive[1], SeparatorActive[2], SeparatorActive[3]));
    ImGui::PushStyleColor(ImGuiCol_ResizeGrip, ImVec4(ResizeGrip[0], ResizeGrip[1], ResizeGrip[2], ResizeGrip[3]));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered, ImVec4(ResizeGripHovered[0], ResizeGripHovered[1], ResizeGripHovered[2], ResizeGripHovered[3]));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripActive, ImVec4(ResizeGripActive[0], ResizeGripActive[1], ResizeGripActive[2], ResizeGripActive[3]));
    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(TextSelectedBg[0], TextSelectedBg[1], TextSelectedBg[2], TextSelectedBg[3]));
    ImGui::PushStyleColor(ImGuiCol_DragDropTarget, ImVec4(DragDropTarget[0], DragDropTarget[1], DragDropTarget[2], DragDropTarget[3]));


    if (!setwindow)
    {
        ImGui::SetNextWindowSize(windowsize);
        setwindow = true;
    }

    ImGui::Begin("Edited1", nullptr, flags);
    {
        for (auto iter = list_lines.begin(); iter != list_lines.end(); iter++)
        {
            switch (iter->draw)
            {
            case 0:  ImGui::GetWindowDrawList()->AddLine(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), ImVec2(ImGui::GetWindowPos().x + iter->pos3, ImGui::GetWindowPos().y + iter->pos4), iter->color0, iter->thinkness);  break;
            case 1:  ImGui::GetWindowDrawList()->AddRect(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), ImVec2(ImGui::GetWindowPos().x + iter->pos3, ImGui::GetWindowPos().y + iter->pos4), iter->color0, iter->round, 15, iter->thinkness);  break;
            case 2:  ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), ImVec2(ImGui::GetWindowPos().x + iter->pos3, ImGui::GetWindowPos().y + iter->pos4), iter->color0, iter->round, 15); break;
            case 3:  ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), ImVec2(ImGui::GetWindowPos().x + iter->pos3, ImGui::GetWindowPos().y + iter->pos4), iter->color0, iter->color1, iter->color2, iter->color3); break;
            case 4:  ImGui::GetWindowDrawList()->AddCircle(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), iter->radius, iter->color0, iter->segments, iter->thinkness);  break;
            case 5:   ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(ImGui::GetWindowPos().x + iter->pos1, ImGui::GetWindowPos().y + iter->pos2), iter->radius, iter->color0, iter->segments);  break;
            default:
                break;
            }
        }


        /*if (io.KeysDown[VK_NUMPAD4])
        {
            pos_sett1 = io.MousePos.x - ImGui::GetWindowPos().x;
            pos_sett2 = io.MousePos.y - ImGui::GetWindowPos().y;
        }*/
    }
    ImGui::End();

    ImGui::PopStyleVar(20);
    ImGui::PopStyleColor(35);
}

void EditedWidget()
{
	auto flags = (no_titlebar ? ImGuiWindowFlags_NoTitleBar : NULL) |
		(no_scrollbar ? ImGuiWindowFlags_NoScrollbar : NULL) |
		(no_menu ? ImGuiWindowFlags_MenuBar : NULL) |
		(no_move ? ImGuiWindowFlags_NoMove : NULL) |
		(no_resize ? ImGuiWindowFlags_NoResize : NULL) |
		(no_collapse ? ImGuiWindowFlags_NoCollapse : NULL) |
		(no_nav ? ImGuiWindowFlags_NoNav : NULL) |
		(no_background ? ImGuiWindowFlags_NoBackground : NULL) |
		(no_bring_to_front ? ImGuiWindowFlags_NoBringToFrontOnFocus : NULL);


	ImGui::SetNextWindowSize(windowsize);

	static bool checkbox = false;

	ImGui::Begin("Widgets1", nullptr, flags);
	{
		Checkbox("Checkbox", &checkbox);
	}
	ImGui::End();
}
