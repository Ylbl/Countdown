#pragma once
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#pragma comment(lib,"d3d9")

#include "SmartData.hpp"

extern ImGuiStyle* style=nullptr;

extern ImFont* simkai_18=nullptr;
extern ImFont* simkai_22=nullptr;

extern unsigned short int r = 255;
extern unsigned short int g = 0;
extern unsigned short int b = 0;

extern bool isOpenSettingWindow=false;
//
//extern bool noResize = false;
//extern bool noMove = false;
//extern bool noTitle = false;

SmartData<bool> noResize("noResize");
SmartData<bool> noMove("noMove");
SmartData<bool> noTitle("noTitle");


void Init();
void Update();