//
// Created by oleg on 25.10.2019.
//

#define start_definition void exec_cmd(int& pos, AutoFree<int> *code, proc* proc, int code_size, assembler_compile& comp) { \
ASSERT(pos < code_size); \
ASSERT(code); \
ASSERT(proc); \
char* curstr = (char*) calloc(20, sizeof(char)); \
ASSERT((*code).ptr[pos] >= 0); \
commands w = (commands)(*code).ptr[pos]; \
++pos; \
switch(w) {

#define add_registers_count(arg)

#define add_commands_count(arg)

#define start_registers_definition

#define add_register(arg)

#define end_registers_definition

#define start_commands_definition

#define start_add_command(arg)

#define add_args_count(cmd, arg)

#define add_args_type(cmd, arg)

#define end_add_args

#define add_code(cmd) case cmd: {
#define add_prog_code(code) code
#define end_add_code } break;
#define end_commands_definition
#define end_definition } }