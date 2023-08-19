#include "Main.h"

bool shouDemoWindow = true;

void settingWindow() {
	if (!isOpenSettingWindow) {
		return;
	}
	ImGui::Begin(u8"设置");

	ImGui::Checkbox(u8"固定大小", &noResize.mData);
	ImGui::Checkbox(u8"固定位置", &noMove.mData);
	ImGui::Checkbox(u8"无标题栏", &noTitle.mData);
	ImGui::Checkbox(u8"打开调试窗口", &shouDemoWindow);
	if (shouDemoWindow) {
		ImGui::ShowDemoWindow(&shouDemoWindow);
	}

	if (ImGui::Button(u8"关闭")) {
		isOpenSettingWindow = false;
	}

	ImGui::End();
}