#include "Main.h"

void settingWindow() {
	if (!isOpenSettingWindow) {
		return;
	}
	ImGui::Begin(u8"设置");

	ImGui::Checkbox(u8"固定大小", &noResize.data);
	ImGui::Checkbox(u8"固定位置", &noMove.data);
	ImGui::Checkbox(u8"无标题栏", &noTitle.data);

	if (ImGui::Button(u8"关闭")) {
		isOpenSettingWindow = false;
	}

	ImGui::End();
}