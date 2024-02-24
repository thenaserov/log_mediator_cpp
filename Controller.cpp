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
	_hb.ping("google.com");
}

void Controller::logToFile()
{

}

void Controller::logToServer()
{
}

void Controller::operate()
{
	// get log
	while (1) {

	}

	// check elastic server
	while (1) {
		
	}

	// log the logs
	while (1) {

	}
}
