#pragma once
#include "FileOperator.h"
#include <vector>

class Controller{

public:
	Controller();
	std::vector<std::string> readLogsFromFile(std::string path);
	void getLog(); // get from anywhere and give it to the LogGenerator
	void checkConnection();
	void logToFile();
	void logToServer();

private:
	FileOperator _file_operator{};

protected:
};