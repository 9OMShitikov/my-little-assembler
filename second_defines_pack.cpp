//
// Created by oleg on 25.10.2019.
//
#define start_definition class assembler_compile { \
public:

#define add_registers_count(arg) int registers_count = arg;

#define add_commands_count(arg) int commands_count = arg;

#define start_registers_definition  char** registers_names; \
bor registers_find; \
bor commands_find; \
char** commands_names; \
int* args_count; \
types** args_types; \
assembler_compile () { \
    registers_names = new char* [registers_count]; \
    for (int i = 0; i < registers_count; ++i) registers_names[i] = new char[8];

#define add_register(arg) strcpy(registers_names[arg], #arg); \
registers_find.add(#arg, arg);

#define end_registers_definition

#define start_commands_definition commands_names = new char* [commands_count];\
for (int i = 0; i < commands_count; ++i) commands_names[i] = new char[8]; \
args_count = new int [commands_count]; \
args_types = new types* [commands_count];\
int arg_pos = 0;

#define start_add_command(arg) strcpy(commands_names[arg], #arg); \
commands_find.add(#arg, arg);

#define add_args_count(cmd, arg) args_count[cmd] = arg; \
args_types[cmd] = new types[arg]; \
arg_pos = 0;

#define add_args_type(cmd, arg) args_types[cmd][arg_pos] = arg; ++arg_pos;

#define end_add_args

#define add_code(cmd)
#define add_prog_code(code)
#define end_add_code
#define end_commands_definition
#define end_definition } \
~assembler_compile() { \
    for (int i = 0; i < registers_count; ++i) { \
        delete registers_names[i]; \
    } \
    delete registers_names; \
    for (int i = 0; i < commands_count; ++i) { \
        delete commands_names[i]; \
        delete args_types[i]; \
    } \
    delete commands_names; \
    delete args_count; \
    delete args_types; \
} \
};


