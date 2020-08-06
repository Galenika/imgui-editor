#pragma once

#include <unordered_map>
#include <list>
#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

struct drawlist_struct
{
    drawlist_struct(int style, std::string nm, std::string nmsecret, int pos1_, int pos2_, int pos3_, int pos4_, ImColor color20, ImColor color21, ImColor color22, ImColor color23, int think, int segment, int rounding, int rad)
    {
        name = nm;
        secret_name = nmsecret;  draw = style;
        pos1 = pos1_; pos2 = pos2_;
        pos3 = pos3_; pos4 = pos4_;
        color0 = color20; color1 = color21;
        color2 = color22; color3 = color23;
        thinkness = think; segments = segment;
        round = rounding; radius = rad;
    }

    int draw;
    int round;
    int pos1, pos2, pos3, pos4;
    std::string name, secret_name;
    ImColor color0, color1, color2, color3;
    float thinkness;
    int segments, radius;
};

extern std::list<drawlist_struct> list_lines;

struct checkbox_struct
{
	checkbox_struct(int style, std::string nm, std::string nmsecret, int pos1_, int pos2_, int pos3_, int pos4_, ImColor color20, ImColor color21, ImColor color22, ImColor color23, int think, int segment, int rounding, int rad)
	{
		name = nm;
		secret_name = nmsecret;  draw = style;
		pos1 = pos1_; pos2 = pos2_;
		pos3 = pos3_; pos4 = pos4_;
		color0 = color20; color1 = color21;
		color2 = color22; color3 = color23;
		thinkness = think; segments = segment;
		round = rounding; radius = rad;
	}

	int draw;
	int round;
	int pos1, pos2, pos3, pos4;
	std::string name, secret_name;
	ImColor color0, color1, color2, color3;
	float thinkness;
	int segments, radius;
};

extern std::list<checkbox_struct> list_checkboxback;
extern std::list<checkbox_struct> list_checkboxactive;
extern std::list<checkbox_struct> list_checkboxdeactive;