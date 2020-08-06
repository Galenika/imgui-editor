#include "widgets.h"

using namespace WidgetCheckbox;

bool Checkbox(const char* label, bool* v)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	const float square_sz = ImGui::GetFrameHeight();
	const ImVec2 pos = window->DC.CursorPos;
	const ImRect total_bb(pos, pos + ImVec2(square_sz + (style.ItemInnerSpacing.x + (ttb_include_label_size_x ? label_size.x : 0) + ttb_total_bb_size_x),
		ttb_total_bb_size_y + (ttb_include_label_size_y ? label_size.y : 0) + (ttb_include_frame_padding_y ? style.FramePadding.y * ttb_frame_padding_multiplier : 0)));

	ImGui::ItemSize(total_bb, style.FramePadding.y);
	ImGui::ItemAdd(total_bb, id);

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);

	if (pressed)
		* v = !(*v);

	for (auto iter = list_checkboxback.begin(); iter != list_checkboxback.end(); iter++)
	{
		switch (iter->draw)
		{
		case 0:  window->DrawList->AddLine(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->thinkness);  break;
		case 1:  window->DrawList->AddRect(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15, iter->thinkness);  break;
		case 2:  window->DrawList->AddRectFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15); break;
		case 3:  window->DrawList->AddRectFilledMultiColor(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->color1, iter->color2, iter->color3); break;
		case 4:  window->DrawList->AddCircle(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments, iter->thinkness);  break;
		case 5:   window->DrawList->AddCircleFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments);  break;
		default:
			break;
		}

	}

	if (*v)
	{
		for (auto iter = list_checkboxactive.begin(); iter != list_checkboxactive.end(); iter++)
		{
			switch (iter->draw)
			{
			case 0:  window->DrawList->AddLine(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->thinkness);  break;
			case 1:  window->DrawList->AddRect(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15, iter->thinkness);  break;
			case 2:  window->DrawList->AddRectFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15); break;
			case 3:  window->DrawList->AddRectFilledMultiColor(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->color1, iter->color2, iter->color3); break;
			case 4:  window->DrawList->AddCircle(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments, iter->thinkness);  break;
			case 5:   window->DrawList->AddCircleFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments);  break;
			default:
				break;
			}
		}
	}
	else
	{
		for (auto iter = list_checkboxdeactive.begin(); iter != list_checkboxdeactive.end(); iter++)
		{
			switch (iter->draw)
			{
			case 0:  window->DrawList->AddLine(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->thinkness);  break;
			case 1:  window->DrawList->AddRect(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15, iter->thinkness);  break;
			case 2:  window->DrawList->AddRectFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->round, 15); break;
			case 3:  window->DrawList->AddRectFilledMultiColor(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), ImVec2(total_bb.Min.x + iter->pos3, total_bb.Min.y + iter->pos4), iter->color0, iter->color1, iter->color2, iter->color3); break;
			case 4:  window->DrawList->AddCircle(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments, iter->thinkness);  break;
			case 5:   window->DrawList->AddCircleFilled(ImVec2(total_bb.Min.x + iter->pos1, total_bb.Min.y + iter->pos2), iter->radius, iter->color0, iter->segments);  break;
			default:
				break;
			}
		}
	}

	ImGui::RenderText(ImVec2(total_bb.Min.x + style.ItemInnerSpacing.x + label_pos_x, total_bb.Min.y + style.FramePadding.y + label_pos_y), label);

	if (draw_total_bb_border)
		window->DrawList->AddRect(total_bb.Min, total_bb.Max, ImColor(212, 255, 0));

	return pressed;
}