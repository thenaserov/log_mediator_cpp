#include "Controller.h"

Controller::Controller()
{
}

std::vector<std::string> Controller::readLogsFromFile(std::string path)
{
	_file_operator.openFile(path);
	return _file_operator.readLines();
}

void Controller::getLog()
{
}

void Controller::checkConnection()
{
}

void Controller::logToFile()
{
}

void Controller::logToServer()
{
}
