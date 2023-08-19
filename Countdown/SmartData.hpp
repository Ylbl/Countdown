#pragma region 本地化
#include <fstream>
#include "json.hpp"

nlohmann::ordered_json configFileJson;
int loadFile() {
	std::ifstream configFile("C:\\Config.json");
	configFile >> configFileJson;
	return 0;
}
int saveFile() {
	std::ofstream o("C:\\Config.json");
	o << std::setw(4) << configFileJson << std::endl;

	return 0;
}

#pragma endregion

#pragma region 智能变量(

#include <iostream>
#include <string>
template <typename T>
class SmartData {
public:
	SmartData(std::string _key) {
		key = _key;

		loadFile();

		//mData = data = configFileJson.at(key);

		if (!configFileJson[key].is_null()) {
			mData = data = configFileJson[key];
		}


	}

	void set(T _data) {
		std::cout << "保存" << "\n";
		if (data != _data) {
			data = _data;

			configFileJson[key] = data;

			saveFile();
		}
	}

	void check() {
		if (mData != data) {
			set(mData);
		}
	}

	T mData;
protected:
	T data;
	std::string key;
};
#pragma endregion
