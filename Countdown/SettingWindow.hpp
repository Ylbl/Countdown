#include "Main.h"

void settingWindow() {
	if (!isOpenSettingWindow) {
		return;
	}
	ImGui::Begin(u8"����");

	ImGui::Checkbox(u8"�̶���С", &noResize.data);
	ImGui::Checkbox(u8"�̶�λ��", &noMove.data);
	ImGui::Checkbox(u8"�ޱ�����", &noTitle.data);

	if (ImGui::Button(u8"�ر�")) {
		isOpenSettingWindow = false;
	}

	ImGui::End();
}