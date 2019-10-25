//
// Created by oleg on 25.10.2019.
//
#define start_definition enum types {\
cst,\
reg,\
label,\
};

#define add_registers_count(arg)
#define add_commands_count(arg)
#define start_registers_definition enum registers {
#define add_register(arg) arg,
#define end_registers_definition };
#define start_commands_definition  enum commands {
#define start_add_command(arg) arg,
#define add_args_count(cmd, arg)
#define add_args_type(cmd, arg)
#define end_add_args
#define add_code(cmd)
#define add_prog_code(code)
#define end_add_code
#define end_commands_definition };
#define end_definition
