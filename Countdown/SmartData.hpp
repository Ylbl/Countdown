#include <fstream>
#include "json.hpp"
//using namespace nlohmann;

nlohmann::json configFileJson;
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

#include <stdlib.h>
#include <string>
template <typename T>
class SmartData {
public:
	SmartData(std::string _key) {
		key = _key;

		loadFile();

		data = configFileJson.at(key);

	}

	void set(T _data) {
		if (data != _data) {
			data = _data;

			configFileJson[key] = data;

			saveFile();
		}
	}

	T data;
protected:
	//T data;
	std::string key;
};