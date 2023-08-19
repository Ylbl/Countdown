#include "Main.h"

#include "StringToUTF8.hpp"
#include "GetRestTime.hpp"

#include <iostream>
static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::BeginItemTooltip())
	{
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}
void mainWindow() {
	style->Colors[ImGuiCol_Text] = ImVec4(1, 1, 1, 1.00f);

	ImGuiWindowFlags flag=0;

	if (noResize.data) {
		flag |= ImGuiWindowFlags_NoResize;
	}
	if (noMove.data) {
		flag |= ImGuiWindowFlags_NoMove;
	}
	if (noTitle.data) {
		flag |= ImGuiWindowFlags_NoTitleBar;
	}

	ImGui::Begin("MainWindow", NULL, flag);

	ImGui::Text(u8"距离  "); ImGui::SameLine();

	ImGui::PushFont(simkai_22);
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(r,g,b, 255));
	//ImGui::TextColored(ImVec4(r, g, b, 1), u8"中考"); ImGui::SameLine();
	ImGui::Text(u8"中考"); ImGui::SameLine();
	ImGui::PopStyleColor();
	ImGui::PopFont();
	//ImGui::TextWrapped("NB: Cursor & selection are preserved when refocusing last used item in code.");
	ImGui::Text(u8"  仅剩"); ImGui::SameLine(); HelpMarker(u8"到2024/6/14");

	ImGui::Text(string_To_UTF8(getRestTime()).c_str());

	if (ImGui::Button(u8"设置")) {
		isOpenSettingWindow = true;
	}

	ImGui::End();

}

