#include "LogGenerator.h"

LogGenerator::LogGenerator()
{
}

LogGenerator::~LogGenerator()
{
}

void LogGenerator::regenerateLog()
{
	for (std::vector<std::string>::iterator it = _logs_vector.begin(); it != _logs_vector.end(); it++) {
		_full_log += *it + "|";
	}
	_full_log.pop_back(); // This removes the last "|"
}

std::string LogGenerator::gettLogAsString()
{
	regenerateLog();
	return _full_log;
}

void LogGenerator::addAnElementToCurrentLog(std::string element)
{
	_logs_vector.emplace_back(element);
}

void LogGenerator::clearLogsVector()
{
	_logs_vector.clear();
}
