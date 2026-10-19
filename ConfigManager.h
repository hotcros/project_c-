#pragma once
#include <string>
#include <fstream>
using namespace std;
struct AppConfig {
	int windowWidth = 1280;
	int windowHeight = 720;
	bool fullscreen = false;
};
inline bool saveConfigBin(const string& path, const AppConfig& cfg) {
	ofstream out(path, ios::binary);
	if (!out.is_open()) return false;
	out.write(reinterpret_cast<const char*>(&cfg), sizeof(AppConfig));
	return out.good();
}