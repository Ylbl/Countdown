#include "Main.h"

bool shouDemoWindow = true;

void settingWindow() {
	if (!isOpenSettingWindow) {
		return;
	}
	ImGui::Begin(u8"����");

	ImGui::Checkbox(u8"�̶���С", &noResize.mData);
	ImGui::Checkbox(u8"�̶�λ��", &noMove.mData);
	ImGui::Checkbox(u8"�ޱ�����", &noTitle.mData);
	ImGui::Checkbox(u8"�򿪵��Դ���", &shouDemoWindow);
	if (shouDemoWindow) {
		ImGui::ShowDemoWindow(&shouDemoWindow);
	}

	if (ImGui::Button(u8"�ر�")) {
		isOpenSettingWindow = false;
	}

	ImGui::End();
}