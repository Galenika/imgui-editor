#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "settings/settings.h"

#include <vector>
#include <string>
using namespace std;

extern vector<string> ConfigList;

typedef void(*LPSEARCHFUNC)(LPCTSTR lpszFileName);

void ReadConfigs(LPCTSTR lpszFileName);
void RefreshConfigs();
void Saver();

extern int iMenuSheme;
extern int iConfigSelect;
extern char ConfigName[24];

