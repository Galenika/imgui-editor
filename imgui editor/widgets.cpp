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
		*v = !(*v);

	const ImRect check_bb(pos, pos + ImVec2((ckb_include_square_sz_x ? square_sz : 0) + (ckb_include_custom_size_x ? ckb_total_bb_size_x : 0), 
											(ckb_include_square_sz_y ? square_sz : 0) + (ckb_include_custom_size_y ? ckb_total_bb_size_y : 0)));

	ImGui::RenderFrame(check_bb.Min, check_bb.Max, ImGui::GetColorU32((held && hovered) ? ImGuiCol_FrameBgActive : hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg), true, style.FrameRounding);
	ImU32 check_col = ImGui::GetColorU32(ImGuiCol_CheckMark);

	if (*v)
	{
		const float pad = ImMax(1.0f, IM_FLOOR(square_sz / 6.0f));
		ImGui::RenderCheckMark(window->DrawList, check_bb.Min + ImVec2(pad, pad), check_col, square_sz - pad * 2.0f);
	}

    ImGui::RenderText(ImVec2(check_bb.Max.x + style.ItemInnerSpacing.x + label_pos_x, check_bb.Min.y + style.FramePadding.y + label_pos_y), label);

	return pressed;
}