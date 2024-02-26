#include "LogGenerator.h"

LogGenerator::LogGenerator()
{
}

LogGenerator::~LogGenerator()
{
}

void LogGenerator::regenerateLog()
{
	if (_logs_vector.size() > 0) {
		for (std::vector<std::string>::iterator it = _logs_vector.begin(); it != _logs_vector.end(); it++) {
			_full_log += *it + "|";
		}
	}
	if(_full_log != "")
		_full_log.pop_back(); // This removes the last "|"
	clearLogsVector();
}

std::string LogGenerator::getLogAsString()
{
	regenerateLog();
 	auto log = _full_log;
	_full_log.clear();
	return log;
	
}

void LogGenerator::addAnElementToCurrentLog(std::string element)
{
	_logs_vector.emplace_back(element);
}

void LogGenerator::clearLogsVector()
{
	_logs_vector.clear();
}
