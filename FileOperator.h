#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileOperator {

public:
	FileOperator();
	~FileOperator();
	bool isOpen();
	void openFileRead();
	void openFileWrite();
	std::vector<std::string> readLines();
	void writeLines(std::vector<std::string>& lines);
	void setPath(std::string& path);


private:
	std::fstream _file;
	std::string _path;
	std::vector<std::string> _lines;

protected:
};
