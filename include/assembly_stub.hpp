#ifndef __ASSEMBLY_STUB_HPP__
#define __ASSEMBLY_STUB_HPP__

#include <fstream>

std::string assembly_stub = ".globl main\n main:\n movl $2, %eax\n ret\n";

int write_asm_stub (std::string filename) {     // write stub to file
    std::ofstream file;
    file.open(filename);        //TODO error checking
    file << assembly_stub;
    file.close();

    return 0;
}
#endif