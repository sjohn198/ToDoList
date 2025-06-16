#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

void load_from_disk(std::vector<std::string>& tasks, std::vector<char>& states, const std::string& filename);
void save_to_disk(const std::vector<std::string>& tasks, const std::vector<char>& states, const std::string& filename);