#include "LoadCSV.h"

/// std
#include <iostream>
#include <fstream>
#include <sstream>


std::vector<std::vector<int>> LoadCSV(const std::string& _filePath) {
	std::vector<std::vector<int>> csvData;

	/// ファイルを開く
	std::ifstream file(_filePath);
	if (!file.is_open()) {
		std::cerr << "ファイルを開くことができません: " << _filePath << std::endl;
		return csvData;
	}

	/// ファイル内のデータをcsvDataに格納する
	std::string line;
	while (std::getline(file, line)) {
		
		std::vector<int> row;
		std::stringstream lineStream(line);
		std::string cell;

		while (std::getline(lineStream, cell, ',')) {
			row.push_back(std::stoi(cell));
		}
		
		csvData.push_back(row);
	}

	file.close();
	return csvData;
}
