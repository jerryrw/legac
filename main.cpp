/***
 * Driver program for building a basic compiler
 */

#include "include/assembly_stub.hpp"
#include "include/lexer.hpp"
#include "include/sourcefile.hpp"

#include <cstdio>
#include <iostream>
#include <string>


int main (int argc, char* argv[]) {
    
    std::string command;                    // for the system commands for pre-processing and linking using gcc
    std::string source_file_name;           // full name of the source code file to be compiled
    std::string filename;                   // for filename without extension
    std::string extension;                  // for the extension
    const char* command_to_pass;            // needs to be a c-string
    bool clean_up = false;                  //to remove intermediate files while debugging
    int result;                             // for holding various result codes

/* commented out while debugging

    if (argc < 2) {
        std::cout << "No filename to process" << std::endl;
        return 1;                                //TODO Need to settle on an error plan
    }
    
    source_file_name = argv[1];                  //TODO error checking: does file exist?
*/
    source_file_name = "test.c";    //TODO for debugging

    filename = source_file_name.substr(0,source_file_name.find("."));     // split filename from extension
    extension = source_file_name.substr(1,source_file_name.find("."));
    // result = extension.compare("c");     // correct file extension
    
    command = "gcc -E -P " + source_file_name + " -o " + filename + ".i";    // run the preprocessor on the file
    command_to_pass = command.c_str();
    result = system(command_to_pass);
    if (result !=0) {                       //TODO error handling
        std::cout << "An error occured in pre-processing" << std::endl;
        return 1;
    }
    std::string intermediate_file_name = filename + ".i";  // set the intermediate filename

// This is where the actual compiler part kicks in
    Sourcefile thefile(intermediate_file_name);           // read the source code file into a buffer
    Lexer lexer(thefile.get_file_buffer());               // instantiate the lexer using the buffer
    std::string temp_token = lexer.get_next_token();
    while (temp_token != "") {
        std::cout << temp_token << std::endl;
        temp_token = lexer.get_next_token();
    }
    
    write_asm_stub (filename + ".s");       // write a pre-prepared ASM file undil compiler complete


    // Assemble and link the file into an executable
    command = "gcc -z noexecstack -Wall " + filename + ".s -o " + filename;
    command_to_pass = command.c_str();
    result = system(command_to_pass);
    if (result != 0) {                      //TODO Error handling
        std::cout << "An error occured in llinking" << std::endl;
        return 1;
    }

    if (clean_up) {                         // remove extra file clutter
        command = "rm " + filename + ".i " + filename + ".s";
        command_to_pass = command.c_str();
        result = system(command_to_pass);
        if (result != 0) {                      //TODO Error handling
            return 1;
        }
    }


    return 0;
}