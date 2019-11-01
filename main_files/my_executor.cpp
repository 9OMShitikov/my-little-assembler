#include <iostream>

#include "strings_read_functions.h"
#include "string.h"
#include "math.h"

#include "my_stack.h"
#include "my_stack.cpp"

#include "bor.cpp"

#include "processor.cpp"

#include "first_defines_pack.cpp"
#include "compiler_data.cpp"
#include "remove_defines.cpp"

#include "second_defines_pack.cpp"
#include "compiler_data.cpp"
#include "remove_defines.cpp"

#include "third_defines_pack.cpp"
#include "execution_code_defines_pack.cpp"
#include "compiler_data.cpp"
#include "remove_execution_code_defines.cpp"
#include "remove_defines.cpp"

int main(int args, char* argv[]) {
    proc cur_proc (50);
    assembler_compile comp;
    const char* input_file;
    if (args < 2) input_file = "result.txt";
    else input_file = argv[1];

    AutoFree<int> code;
    int size = read_file_bin(&code, input_file);

    for (int i = 0; i < size;) {
        /*std::cout<<i<<" "<<comp.commands_names[code.ptr[i]]<<std::endl;*/
        exec_cmd(i, &code, &cur_proc, size, comp);
        /*cur_proc.print();*/
    }
    /*cur_proc.print();*/
    return 0;
}
