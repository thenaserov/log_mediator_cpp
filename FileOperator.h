#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileOperator {

public:
	FileOperator();
	~FileOperator();
	bool isOpen(std::string path);
	bool openFile(std::string path);
	std::vector<std::string> readLines();

private:
	std::fstream _file{};
	std::vector<std::string> _lines{};

protected:
};
