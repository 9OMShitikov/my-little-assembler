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
#include "compiler_data.cpp"
#include "remove_defines.cpp"

bool arg_check(types type, std::string_view &st, assembler_compile& comp, bor& labels_bor) {
    switch (type) {
        case cst: {
        } break;

        case reg: {
            if (comp.registers_find.check(st.data()) == -1) return 0;
        } break;

        case label: {
        } break;

        default: {
        }
    }
    return 1;
}

int arg_get(types type, std::string_view &st, assembler_compile& comp, bor& labels_bor) {
    switch (type) {
        case cst: {
            return strtol(st.data(), nullptr, 10) * 1000;
        } break;

        case reg: {
            return comp.registers_find.check(st.data());
        } break;

        case label: {
            return labels_bor.check(st.data());
        } break;

        default: {
        }
    }
    return 1;
}
void decode_str (int& line_numb, AutoFree<std::string_view>& lines,
                 my_stack <int> &codes, int& pos,
                 bor& labels_bor, assembler_compile& comp,
                 bool print) {
    std::string_view st = lines.ptr[line_numb];
    if (st[st.size() - 1] == ':') {
        if (!print) labels_bor.add(st.data(), pos);
        ++line_numb;
        ++pos;
        if (print) codes.push_back(16);
        return;
    }
    int w = comp.commands_find.check(st.data());
    ASSERT(w != -1);
    ASSERT(w < comp.commands_count);
    if (print) codes.push_back(w);
    ++pos;
    ++line_numb;
    for (int i = 0; i < comp.args_count[w]; ++i) {
        ASSERT (arg_check(comp.args_types[w][i], lines.ptr[line_numb], comp, labels_bor));
        if (print)
            codes.push_back(arg_get(comp.args_types[w][i], lines.ptr[line_numb], comp, labels_bor));
        ++pos;
        ++line_numb;
    }
}

int main(int args, char* argv []) {
    assembler_compile comp;
    AutoFree<char> buff;
    const char* input_file;
    const char* output_file;

    if (args <= 1) input_file = "input.txt";
    else input_file = argv[1];

    if (args <= 2) output_file = "result.txt";
    else output_file = argv[2];

    clear_output(output_file);

    int poem_size = read_file(&buff, input_file);
    AutoFree<std::string_view> lines;
    int count = make_string_array(&lines, &buff, poem_size);
    bor labels_bor;
    my_stack<int> codes;
    int pos = 0;
    for (int i = 0; i < count;) {
        /*std::cout<<i<<" "<<lines.ptr[i]<<std::endl;*/
        decode_str (i, lines, codes, pos, labels_bor, comp, 0);
    }
    pos = 0;
    for (int i = 0; i < count;) {
        /*std::cout<<i<<" "<<lines.ptr[i]<<std::endl;*/
        decode_str (i, lines, codes, pos, labels_bor, comp, 1);
    }
    int* codes_buff = codes.get_buff_ptr();
    print_bin(codes.size(), &codes_buff, output_file);
    return 0;
}