#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
if (argc < 4 || argc > 5)
	return (1);
std::string s1(argv[2]);
std::string s2(argv[3]);
std::string straminer(argv[1]);
std::ifstream file(straminer.c_str(), std::ios::in);
if (!file.is_open())
	return (1);
std::string line;
std::string newFile = straminer + ".replace";
std::ofstream replaceFile(newFile.c_str(), std::ios::trunc | std::ios::out);
while (std::getline(file, line)) {
	while (line.find(s1) != std::string::npos) {
		size_t sub = line.find(s1);
		line.erase(sub, s1.length());
		line.insert(sub, s2);
	}
	replaceFile << line << "\n";
}
return (0);
}