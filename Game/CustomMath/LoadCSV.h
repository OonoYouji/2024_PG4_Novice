#pragma once

/// std
#include <vector>
#include <string>

/// @brief CSVファイルを読み込む
/// @param _filePath 読み込む対象のCSVファイルのパス
/// @return 二次元配列に変換されたCSVファイルのデータ
std::vector<std::vector<int>> LoadCSV(const std::string& _filePath);