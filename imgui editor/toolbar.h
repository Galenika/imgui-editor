#pragma once

#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#include "toolbar_customs.h"

#include "imgui/notifies.h"

#include "binary_to_compressed_c.h"

#include <ctime>

#include "settings/settings.h"
using namespace Settings;

std::string GenerateRandomTitle(int length)
{
    std::vector<std::string> v_alphabet = {
        "q", "w", "e", "r", "t", "y", "u", "i",
        "o", "p", "a", "s", "d", "f", "g", "h",
        "j", "k", "l", "z", "x", "c", "v", "b",
        "n", "m", "Q", "W", "E", "R", "T", "Y",
        "U", "I", "O", "P", "A", "S", "D", "F",
        "G", "H", "J", "K", "L", "Z", "X", "C",
        "V", "B", "N", "M", "1", "2", "3", "4",
        "5", "6", "7", "8", "9"
    };

    srand(time(NULL));
    std::string res = "";
    for (int i = 0; i < length; ++i)
    {
        res += v_alphabet[rand() % v_alphabet.size()];
    }
    return res;
}

static int tab = 0;
static bool code_output = 0;
static int pos_sett1, pos_sett2, pos_sett3, pos_sett4;
static int thinkness = 1;
 float color1[4] = {1.f,1.f,1.f,1.f};
 float color2[4] = { 1.f,1.f,1.f,1.f };
 float color3[4] = { 1.f,1.f,1.f,1.f };
 float color4[4] = { 1.f,1.f,1.f,1.f };

static ImVec4 color14;

static int segments = 0;
static int rounding = 0;
static int radius = 0;

static int list_type = 0;

#include <Shlobj_core.h>
#include "list.h"

#include "imgui/imgui_internal.h"

char itemname[64];

void MenuBar()
{
    if (ImGui::BeginMainMenuBar()) {

        if (ImGui::MenuItem("File", nullptr))
            menu_config_state = !menu_config_state;


        if (menu_config_state)
        {
            ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);

            if (ImGui::MenuItem("Layots", nullptr, tab == 0))
                tab = 0;

            if (ImGui::MenuItem("Window", nullptr, tab == 3))
                tab = 3;

            if (ImGui::MenuItem("Code Output", nullptr, code_output == 1))
                code_output = !code_output;

            ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);

            if (ImGui::MenuItem("Byte Creator", nullptr, tab == 5))
                tab = 5;
        }

        ImGui::SameLine(ImGui::GetIO().DisplaySize.x - 20 - ImGui::CalcTextSize("PERS0NA2`S IMGUI EDITOR").x);
        ImGui::TextColored(ImColor(75, 179, 75), "PERS0NA2`S IMGUI EDITOR");

        ImGui::EndMainMenuBar();
    }
}

#include <fstream>
#include <vector>
#include <array>

static int sub_tabishe = 0;

#include "imgui/imfilebrowser.h"

ImGui::FileBrowser fileDialog;
ImGui::FileBrowser fontDialog;

void ToolBar()
{
    fileDialog.SetTitle("File to BYTE Array");

    auto window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove;

    ImVec2 toolbarsize = { width, ImGui::GetIO().DisplaySize.y - 18 };

    ImGui::SetNextWindowSize(toolbarsize);
    ImGui::SetNextWindowPos({ 0,18 });

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0,0});

    ImGui::PushStyleColor(ImGuiCol_FrameBg,ImVec4(120/255.f,120 / 255.f,120 / 255.f,150 / 255.f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 150 / 255.f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(110 / 255.f, 110 / 255.f, 110 / 255.f, 150 / 255.f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 150 / 255.f));

    ImGui::Begin("Editor", nullptr, window_flags);
    {
        ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetWindowPos(), {ImGui::GetWindowPos().x + ImGui::GetIO().DisplaySize.x + 10,ImGui::GetWindowPos().y + ImGui::GetIO().DisplaySize.y },ImColor(40, 40, 40));
        width = ImGui::GetWindowSize().x;
        if (tab == 0)
        {
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(5);
            if (ImGui::BeginTabBar("TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip))
            {
                if (ImGui::BeginTabItem("Add Element"))
                {
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::Spacing();
            ImGui::SameLine(5);
            ToolBarE::BeginChild("Child 1", ImVec2{ width - 10,275 }, false, NULL);
            {
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SameLine(10);
				ImGui::BeginChild("Child 15", ImVec2{ width - 30,270 }, false, NULL);
				{
					ImGui::PushItemWidth(width - 30);
					ImGui::Combo("##1", &list_type, ("Add Line\0\rAdd Rect\0\rAdd Rect Filled\0\rAdd Rect Filled Multicolor\0\rAdd Circle\0\rAdd Circle Filled\0\0"));

					ImGui::PushItemWidth(width - 150);
					ImGui::InputText("Name", itemname, 64);
					ImGui::InputInt("POS1 X", &pos_sett1);
					ImGui::InputInt("POS1 Y", &pos_sett2);

					if (list_type != 4 & list_type != 5)
						ImGui::InputInt("POS2 X", &pos_sett3),
						ImGui::InputInt("POS2 Y", &pos_sett4);
					

					if (list_type == 0 | list_type == 1 | list_type == 4 | list_type == 6)
						ImGui::SliderInt("Thinkness", &thinkness, 1, 10);

					if (list_type == 1 | list_type == 2)
						ImGui::SliderInt("Rounding", &rounding, 0, 16);
					

					if (list_type == 4 | list_type == 5)
						ImGui::InputInt("Radius", &radius);
					

					if (list_type == 4 | list_type == 5)
						ImGui::InputInt("Segments", &segments);
					

					ImGui::ColorEdit4("Color 1", color1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);

					if (list_type == 3)
					{
						ImGui::ColorEdit4("Color 2", color2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
						ImGui::ColorEdit4("Color 3", color3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
						ImGui::ColorEdit4("Color 4", color4, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
					}

					if (ImGui::Button("Add Item"))
					{
						if (itemname[0] != NULL)
						{
							list_lines.push_back(drawlist_struct(list_type, itemname, GenerateRandomTitle(10), pos_sett1, pos_sett2, pos_sett3, pos_sett4, ImColor(color1[0], color1[1], color1[2], color1[3]), ImColor(color2[0], color2[1], color2[2], color2[3]), ImColor(color3[0], color3[1], color3[2], color3[3]), ImColor(color4[0], color4[1], color4[2], color4[3]), thinkness, segments, rounding, radius));
							notifies::push("Element created successfully", notify_state_s::success_state);
						}
						else
						{
							notifies::push("Please type element name", notify_state_s::success_state);
						}
					}
				}
				ImGui::EndChild();
            }
            ToolBarE::EndChild();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(5);
            if (ImGui::BeginTabBar("TabBar 2", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip))
            {
                if (ImGui::BeginTabItem("Elements"))
                {
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::Spacing();
            ImGui::SameLine(5);
            ImGui::Spacing();
            ImGui::SameLine(5);
            ToolBarE::BeginChild("Child 2", ImVec2{ width- 10,ImGui::GetIO().DisplaySize.y - 358 },false,NULL);
            {
                ImGui::Spacing();
                ImGui::Spacing();
        
                for (auto iter = list_lines.begin(); iter != list_lines.end(); iter++)
                {
                    if(ToolBarE::Item(width - 10,iter->draw, iter->name, iter->secret_name, iter->pos1, iter->pos2, iter->pos3, iter->pos4, iter->color0,iter->color1,iter->color2,iter->color3, thinkness, segments, rounding, radius))
                      list_lines.erase(iter);

                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::Spacing();
                }
            }
            ToolBarE::EndChild();
        }
        if (tab == 3)
        {
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(5);
            if (ImGui::BeginTabBar("TabBar 2", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip))
            {
                if (ImGui::BeginTabItem("Window Flags"))
                {
                    sub_tabishe = 0;
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Window Colors"))
                {
                    sub_tabishe = 1;
                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }
            ImGui::Spacing();
            ImGui::SameLine(5);
            ToolBarE::BeginChild("Child 4", ImVec2{ width - 10,ImGui::GetIO().DisplaySize.y - 52 }, false, NULL);
            {
                if (sub_tabishe == 0)
                {
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SameLine(10);
                    ImGui::BeginChild("Child 5", ImVec2{ width - 30,ImGui::GetIO().DisplaySize.y - 60 }, false, NULL);
                    {
                        ImGui::PushItemWidth(width - 180);
                        ImGui::SliderFloat2("Window Size", (float*)& windowsize, 0.0f, 1000, "%.0f");
                        if (ImGui::Button("Apply"))
                            setwindow = false;
                        ImGui::Separator();
                        ImGui::SliderFloat2("Window Padding", (float*)& WindowPadding, 0.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat2("Frame Padding", (float*)& FramePadding, 0.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat2("Item Spacing", (float*)& ItemSpacing, 0.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat2("Item Inner Spacing", (float*)& ItemInnerSpacing, 0.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat2("Touch Extra Padding", (float*)& TouchExtraPadding, 0.0f, 10.0f, "%.0f");
                        ImGui::SliderFloat("Indent Spacing", &IndentSpacing, 0.0f, 30.0f, "%.0f");
                        ImGui::Separator();
                        ImGui::SliderFloat("Scrollbar Size", &ScrollbarSize, 1.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat("Grab Min Size", &GrabMinSize, 1.0f, 20.0f, "%.0f");
                        ImGui::SliderFloat("Window Border Size", &WindowBorderSize, 0.0f, 1.0f, "%.0f");
                        ImGui::SliderFloat("Child Border Size", &ChildBorderSize, 0.0f, 1.0f, "%.0f");
                        ImGui::SliderFloat("Popup Border Size", &PopupBorderSize, 0.0f, 1.0f, "%.0f");
                        ImGui::SliderFloat("Frame Border Size", &FrameBorderSize, 0.0f, 1.0f, "%.0f");
                        ImGui::Separator();
                        ImGui::SliderFloat("Window Rounding", &WindowRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::SliderFloat("Child Rounding", &ChildRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::SliderFloat("Frame Rounding", &FrameRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::SliderFloat("Popup Rounding", &PopupRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::SliderFloat("Scrollbar Rounding", &ScrollbarRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::SliderFloat("Grab Rounding", &GrabRounding, 0.0f, 12.0f, "%.0f");
                        ImGui::Separator();
                        ImGui::SliderFloat2("Window Title Align", (float*)& WindowTitleAlign, 0.0f, 1.0f, "%.2f");
                        ImGui::SliderFloat2("Button Align", (float*)& ButtonTextAlign, 0.0f, 1.0f, "%.2f");
                        ImGui::SliderFloat2("Selectable Align", (float*)& SelectableTextAlign, 0.0f, 1.0f, "%.2f");
                        ImGui::Separator();
                        ImGui::Checkbox("No titlebar", &no_titlebar);
                        ImGui::Checkbox("No scrollbar", &no_scrollbar);
                        ImGui::Checkbox("Menu Bar", &no_menu);
                        ImGui::Checkbox("No move", &no_move);
                        ImGui::Checkbox("No resize", &no_resize);
                        ImGui::Checkbox("No collapse", &no_collapse);
                        ImGui::Checkbox("No nav", &no_nav);
                        ImGui::Checkbox("No background", &no_background);
                        ImGui::Checkbox("No bring to front", &no_bring_to_front);
                    }
                    ImGui::EndChild();
                }
                if (sub_tabishe == 1)
                {
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SameLine(10);
                    ImGui::BeginChild("Child 7", ImVec2{ width - 30,ImGui::GetIO().DisplaySize.y - 60 }, false, NULL);
                    {
                        ImGui::PushItemWidth(width - 180);
                        ImGui::ColorEdit4("Text", Text, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("TextDisabled", TextDisabled, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("WindowBg", WindowBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ChildBg", ChildBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("PopupBg", PopupBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("Border", Border, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("BorderShadow", BorderShadow, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("FrameBg", FrameBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("FrameBgHovered", FrameBgHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("FrameBgActive", FrameBgActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("TitleBg", TitleBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("TitleBgActive", TitleBgActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("TitleBgCollapsed", TitleBgCollapsed, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("MenuBarBg", MenuBarBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ScrollbarBg", ScrollbarBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ScrollbarGrab", ScrollbarGrab, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ScrollbarGrabHovered", ScrollbarGrabHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ScrollbarGrabActive", ScrollbarGrabActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("CheckMark", CheckMark, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("SliderGrab", SliderGrab, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("SliderGrabActive", SliderGrabActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("Button", Button, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ButtonHovered", ButtonHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ButtonActive", ButtonActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("Header", Header, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("HeaderHovered", HeaderHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("HeaderActive", HeaderActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("Separator", Separator, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("SeparatorHovered", SeparatorHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("SeparatorActive", SeparatorActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ResizeGrip", ResizeGrip, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ResizeGripHovered", ResizeGripHovered, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("ResizeGripActive", ResizeGripActive, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("TextSelectedBg", TextSelectedBg, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                        ImGui::ColorEdit4("DragDropTarget", DragDropTarget, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_InputRGB);
                    }
                    ImGui::EndChild();
                }
            }
            ToolBarE::EndChild();
        }
        if (tab == 5)
        {
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(5);
            if (ImGui::BeginTabBar("TabBar 3", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip))
            {
                if (ImGui::BeginTabItem("Files"))
                {
					sub_tabishe = 0;
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::Spacing();
            ImGui::SameLine(5);
            ToolBarE::BeginChild("Child 10", ImVec2{ width - 10,ImGui::GetIO().DisplaySize.y - 52 }, false, NULL);
            {
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::SameLine(10);
                ImGui::BeginChild("Child 11", ImVec2{ width - 30,ImGui::GetIO().DisplaySize.y - 60 }, false, NULL);
                {
                    ImGui::PushItemWidth(width - 180);

					if (sub_tabishe == 0)
					{
						if (ImGui::Button("Select a file to convert to bytes"))
							fileDialog.Open();

						ImGui::SameLine();
						if (ImGui::Button("Convert"))
						{
							auto file = std::ifstream(fileDialog.GetSelected().string().c_str(), std::ios::binary);

							std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

							file.close();

							auto out = std::ofstream("C:\\PERS0NA2EDITOR\\out.cpp", std::ofstream::out | std::ofstream::trunc);
							if (!out.is_open())
								throw std::exception("Failed to open output file");

							out << "BYTE array[" << bytes.size() << "] = " << std::endl <<
								"{" << "\t";

							for (auto i = 0u; i < bytes.size(); i++)
							{
								if (i % 16 == 0)
								{
									out << std::endl;
									out << "\t";
								}

								out << std::showbase << std::hex << static_cast<int16_t>(bytes.at(i)) << ", ";
							}

							out << std::endl << "};";

							out.close();

							ShellExecute(NULL, "open", "c:\\PERS0NA2EDITOR\\out.cpp", NULL, NULL, SW_RESTORE);
						}

						fileDialog.Display();
					}
				
                }
                ImGui::EndChild();
            }
            ToolBarE::EndChild();
        }
    }
    ImGui::End();

    ImGui::PopStyleVar(1);
    ImGui::PopStyleColor(6);
}
