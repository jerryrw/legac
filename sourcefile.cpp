
#include "include/sourcefile.hpp"
#include <fstream>
#include <iostream>

Sourcefile::Sourcefile (std::string filename) {

    std::ifstream file(filename);               // open file by name

    file.seekg(0,std::ios::end);                // calc the size of the file in bytes
    size_t filesize = file.tellg();             // save filesize
    std::string buffer(filesize,' ');           // create the read buffer
    file.seekg(0);                              // return to the beginning of the file
    file.read(&buffer[0], filesize);            // read the file into the buffer
    file.close();                               // close the file

    Sourcefile::file_contents = buffer;         //TODO is this by ref or by value???
}

std::string& Sourcefile::get_file_buffer () {
    return Sourcefile::file_contents;
}


