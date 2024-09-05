#ifndef __SOURCEFILE_HPP__
#define __SOURCEFILE_HPP__

#include <fstream>

class Sourcefile {

    private:
        std::string file_contents;

    public:
        Sourcefile (std::string filename);
        std::string& get_file_buffer ();
};

#endif