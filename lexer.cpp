#include "include/lexer.hpp"
#include "include/sourcefile.hpp"
#include <iostream>
#include <string>
#include <set>

Lexer::Lexer (std::string source) {
    Lexer::curr_position = 0;
    Lexer::source_file_buffer = source;
}

std::string Lexer::get_next_token() {       //TODO consider an itorator??
    char character;
    std::set<char> whitespace = {' ', '\r', '\n', '\t'};
    std::set<char> operators = {'(', ')', ';', '{', '}'};
    token = "";
    
    for (int i = this->curr_position; i<source_file_buffer.length(); i++) {       // walk through the file one char at a time
        character = this->source_file_buffer[this->curr_position];

        // skip the whitespace
        if (whitespace.count(character)) {                                  // charater is in whitespace set
            while (whitespace.count(character)) {
                this->curr_position = this->curr_position + 1;              // advance the position index
                character = this->source_file_buffer[this->curr_position];  // get the next character
            } 
        }
        if (operators.count(character)) {                   // character is in operators set
                                                            //TODO two character operators
            token = character;                              // save the operator
            this->curr_position = this->curr_position + 1;  // advance the position index
            return token;
        }
        if (isdigit(character)){                                // at this level the digit is not in an identifier
            while (isdigit(character)) {
                token += character;                             // append the digit to the token
                this->curr_position = this->curr_position + 1;  // advance the position index
                character = this->source_file_buffer[this->curr_position];
            }
            return token;
        }
        if (isalpha(character)) {                               // identifiers and keywords
            while (isalpha(character) | isdigit(character) | character == '_') {
                token += character;                             // append the character to the token
                this->curr_position = this->curr_position + 1;  // advance the position index
                character = this->source_file_buffer[this->curr_position];
            }
            return token;
        }
    }
    return token;       // should be empty string here
}

void Lexer::print() {                           // for debug purposes
    std::cout << "in the lexer" << std::endl;
    std::cout << this->source_file_buffer << std::endl;
    std::cout << "leaving lexer" << std::endl;
}