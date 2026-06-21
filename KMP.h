#pragma once
#include <vector>
#include <string>

std::vector<int> GetNext(const std::string& pattern);
std::vector<int> KMP(const std::string& text, const std::string& pattern);
