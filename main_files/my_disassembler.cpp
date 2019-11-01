#include <iostream>

#include "strings_read_functions.h"
#include "string.h"
#include <math.h>

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

void print_arg(types type, int arg, char* cur_str, assembler_compile *comp) {
    char* buffch = (char*) calloc(10, sizeof(int));
    switch (type) {
        case cst: {
            if (arg >= 0 && arg%1000 == 0) sprintf(buffch, " %d", arg/1000);
            else if (arg > 0 && (-arg)%1000 == 0) sprintf(buffch, " %f", double(arg)/1000);
            else {
                double w = arg;
                sprintf(buffch, " %f", w/1000);
            }
        } break;
        case reg: {
            ASSERT(arg < comp->registers_count);
            ASSERT(0 <= arg);
            sprintf(buffch, " %s", comp->registers_names[arg]);
        } break;
        case label: {
            sprintf(buffch, " %d", arg);
        }
    }
    strcat(cur_str, buffch);
    delete (buffch);
}

void get_cmd(int& pos, AutoFree<int> *code, assembler_compile *comp, int code_size, FILE* file) {
    ASSERT(pos < code_size);
    ASSERT(code);
    ASSERT(comp);
    char* curstr = (char*) calloc(20, sizeof(char));
    ASSERT((*code).ptr[pos] < comp->commands_count);
    ASSERT((*code).ptr[pos] >= 0);
    strcpy(curstr, comp->commands_names[(*code).ptr[pos]]);
    int w = (*code).ptr[pos];
    ++pos;
    for (int i = 0; i < comp->args_count[w]; ++i) {
        print_arg(comp->args_types[w][i], (*code).ptr[pos], curstr, comp);
        ++pos;
    }
    fputs(curstr, file);
    free(curstr);
}
int main(int args, char* argv []) {
    assembler_compile comp;
    const char* input_file;
    const char* output_file;

    if (args <= 1) input_file = "result.txt";
    else input_file = argv[1];

    if (args <= 2) output_file = "disass_result.txt";
    else output_file = argv[2];

    AutoFree<int> code;
    int size = read_file_bin(&code, input_file);
    clear_output(output_file);
    ASSERT(output_file);
    FILE *file = fopen(output_file, "a");
    ASSERT(file);
    for (int i = 0; i < size;) {
        get_cmd(i, &code, &comp, size, file);
        fputc('\n', file);
    }
    ASSERT(fclose(file) == 0);
    return 0;
}