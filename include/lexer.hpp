#ifndef _LEXER_HPP__
#define __LEXER_HPP__

#include <string>

class Lexer{
    private:
        long int curr_position;                     // index for walking the file one char at a time
        std::string token = "temproary token";      // the return string
        std::string source_file_buffer;             // load whole file into buffer

    public:
        Lexer (std::string source);
        std::string get_next_token ();
        void print();                               // for debugging purposesw to access private variables
};

#endif