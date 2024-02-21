#include "FileOperator.h"

FileOperator::FileOperator()
{
}

FileOperator::~FileOperator()
{
	delete this;
}

bool FileOperator::isOpen(std::string path)
{
	return _file.is_open();
}

bool FileOperator::openFile(std::string path)
{
	_file.open(path, std::ios::in | std::ios::out);
}


std::vector<std::string> FileOperator::readLines()
{
	if (_file.is_open()) {
		std::string text;
		while (std::getline(_file, text)) {
			// std::cout << text << "\n";
			_lines.push_back(text);
		}
		_file.close();
	}
	return _lines;
}
