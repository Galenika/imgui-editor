#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS
#define IM_USE using namespace ImGui;

#include "settings/settings.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imstb_textedit.h"

bool Checkbox(const char* label, bool* v);
