#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H

#include <fstream>
#include <vector>
#include <string>

class FileOperator
{
public:
    FileOperator();
    bool openFile(std::string path);
    bool closeAnyOpenFile();
private:
    std::fstream _file;
protected:

};

#endif // FILEOPERATOR_H
