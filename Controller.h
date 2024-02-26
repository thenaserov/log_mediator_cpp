#pragma once
#include "LogGenerator.h"
#include "FileOperator.h"
#include "HeartBeat.h"
#include <vector>
#include <thread>
#include <mutex>

class Controller{

public:
	Controller();
	std::vector<std::string> readLogsFromFile(std::string path);
	void writeLogsToFile(std::string path, std::vector<std::string> logs);
	void setElasticServerAddress(std::string address);

	// _thread_log_check
	void getLog();

	// heartbeat
	void checkConnection();

	// _thread_do_log
	void doLog();

	void logToFile();
	void logToServer();

	// main
	void operate();

private:
	FileOperator _log_file_reader;
	FileOperator _log_file_writer;
	LogGenerator _log_gen;
	HeartBeat _hb;

	std::mutex _mtx;
	std::thread _thread_heartbeat;
	std::thread _thread_log_check;
	std::thread _thread_do_log;
	std::string _elastic_server_address = "";

protected:
};
