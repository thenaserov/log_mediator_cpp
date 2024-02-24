#pragma once
#include <string>
#include <vector>


class LogGenerator {

public:
	LogGenerator();
	~LogGenerator();
	void regenerateLog();
	std::string gettLogAsString();
	void addAnElementToCurrentLog(std::string element);
	void clearLogsVector();

private:
	std::string _log = "";
	std::string _full_log = "";
	std::vector<std::string> _logs_vector;

protected:

};
