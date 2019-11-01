//
// Created by oleg on 25.10.2019.
//
start_definition
    add_registers_count(5)
    add_commands_count(23)
    start_registers_definition
        add_register(AX)
        add_register(BX)
        add_register(CX)
        add_register(DX)
        add_register(ESP)
    end_registers_definition
    start_commands_definition
        start_add_command(ADD)
            add_args_count(ADD, 0)
            end_add_args
            add_code(ADD)
            add_prog_code (
                ASSERT(proc->stack_size() >= 2);
                int a = POP();
                int b = POP();
                PUSH(a+b);)
            end_add_code
        start_add_command(MUL     )
            add_args_count(MUL, 0)
            end_add_args
            add_code(MUL)
            add_prog_code (
                    ASSERT(proc->stack_size() >= 2);
                    int a = POP();
                    int b = POP();
                    PUSH (int (1ll* a * b / 1000));)
            end_add_code
        start_add_command(SUB     )
            add_args_count(SUB, 0)
            end_add_args
            add_code(SUB)
            add_prog_code (ASSERT(proc->stack_size() >= 2);
                           int a = POP();
                           int b = POP();
                           PUSH(a - b);)
            end_add_code
        start_add_command(PUSHREG    )
            add_args_count(PUSHREG, 1)
            add_args_type(PUSHREG, reg)
            end_add_args
            add_code(PUSHREG)
            add_prog_code (ASSERT(pos < code_size);
                           int reg_pos = code->ptr[pos];
                           ASSERT(0 <= reg_pos);
                           ASSERT(comp.registers_count > reg_pos);
                           PUSH(proc->regs[reg_pos]);
                           ++pos;)
            end_add_code
        start_add_command(POP     )
            add_args_count(POP, 1)
            add_args_type(POP, reg)
            end_add_args
            add_code(POP)
            add_prog_code (ASSERT(proc->stack_size() > 0);
                           int reg_pos = code->ptr[pos];
                           ASSERT(0 <= reg_pos);
                           ASSERT(comp.registers_count > reg_pos);
                           proc->regs[reg_pos] = POP();
                           ++pos;)
            end_add_code
        start_add_command(GET     )
            add_args_count(GET, 1)
            add_args_type(GET, reg)
            end_add_args
            add_code(GET)
            add_prog_code (ASSERT(proc->stack_size() > 0);
                           ASSERT(pos < code_size);
                           int reg_pos = code->ptr[pos];
                           ASSERT(0 <= reg_pos);
                           ASSERT(comp.registers_count > reg_pos);
                           proc->regs[reg_pos] = proc->stack_back();
                           ++pos;)
            end_add_code
        start_add_command(PRINTS  )
            add_args_count(PRINTS, 0)
            end_add_args
            add_code(PRINTS)
            add_prog_code (std::cout<<"Roots: ";)
            end_add_code
        start_add_command(PRINTREG)
            add_args_count(PRINTREG, 1)
            add_args_type(PRINTREG, reg)
            end_add_args
            add_code(PRINTREG)
            add_prog_code (ASSERT(pos < code_size);
                           int reg_pos = code->ptr[pos];
                           ASSERT(0 <= reg_pos);
                           ASSERT(comp.registers_count > reg_pos);
                           double w = proc->regs[reg_pos];
                           w /= 1000;
                           std::cout << w << std::endl;
                           ++pos;)
            end_add_code
        start_add_command(JMP     )
            add_args_count(JMP, 1)
            add_args_type(JMP, label)
            end_add_args
            add_code(JMP)
            add_prog_code (ASSERT(pos < code_size);
                           int label = code->ptr[pos];
                           ASSERT(label < code_size);
                           pos = label;)
            end_add_code
        start_add_command(JA      )
            add_args_count(JA, 1)
            add_args_type(JA, label)
            end_add_args
            add_code(JA)
            add_prog_code(J_IF_CMP(>);)
            end_add_code
        start_add_command(JAE     )
            add_args_count(JAE, 1)
            add_args_type(JAE, label)
            end_add_args
            add_code(JAE)
            add_prog_code (J_IF_CMP(>=);)
            end_add_code
        start_add_command(JB      )
            add_args_count(JB, 1)
            add_args_type(JB, label)
            end_add_args
            add_code(JB)
            add_prog_code (J_IF_CMP(<);)
            end_add_code
        start_add_command(JBE     )
            add_args_count(JBE, 1)
            add_args_type(JBE, label)
            end_add_args
            add_code(JBE)
            add_prog_code (J_IF_CMP(<=);)
            end_add_code
        start_add_command(JE      )
            add_args_count(JE, 1)
            add_args_type(JE, label)
            end_add_args
            add_code(JE)
            add_prog_code (J_IF_CMP(==);)
            end_add_code
        start_add_command(JNE     )
            add_args_count(JNE, 1)
            add_args_type(JNE, label)
            end_add_args
            add_code(JNE)
            add_prog_code (J_IF_CMP(!=);)
            end_add_code
        start_add_command(DIV     )
            add_args_count(DIV, 0)
            end_add_args
            add_code(DIV)
            add_prog_code (ASSERT(proc->stack_size() >= 2);
                                   int a = POP();
                                   int b = POP();
                                   double w = a;
                                   w/=b;
                                   w*=1000;
                                   PUSH(int(w));)
            end_add_code
        start_add_command(EMP     )
            add_args_count(EMP, 0)
            end_add_args
            add_code(EMP)
            add_prog_code ()
            end_add_code
        start_add_command(READREG     )
            add_args_count(READREG, 1)
            add_args_type(READREG, reg)
            end_add_args
            add_code(READREG)
            add_prog_code (ASSERT(pos < code_size);
                                   int reg_pos = code->ptr[pos];
                                   ASSERT(0 <= reg_pos);
                                   ASSERT(comp.registers_count > reg_pos);
                                   int w;
                                   std::cin >> w;
                                   w*=1000;
                                   proc->regs[reg_pos] = w;
                                   ++pos;)
            end_add_code
        start_add_command(PUSHCST    )
            add_args_count(PUSHCST, 1)
            add_args_type(PUSHCST, cst)
            end_add_args
            add_code(PUSHCST)
            add_prog_code (ASSERT(pos < code_size);
                               int ans = code->ptr[pos];
                               PUSH(ans);
                               ++pos;)
            end_add_code
        start_add_command(GETSQROOT)
            add_args_count(GETSQROOT, 0)
            end_add_args
            add_code(GETSQROOT)
            add_prog_code (ASSERT(proc->stack_size() >= 1);
                             double a = POP();
                             a = a / 1000;
                             a = sqrt(a) * 1000;
                             PUSH(int(w));)
            end_add_code
        start_add_command(POPE     )
            add_args_count(POPE, 0)
            end_add_args
            add_code(POPE)
            add_prog_code (ASSERT(proc->stack_size() > 0);
                             int q = POP();
                             ++pos;)
        end_add_code
        start_add_command(CALL     )
            add_args_count(CALL, 1)
            add_args_type(CALL, label)
            end_add_args
            add_code(CALL)
            add_prog_code (ASSERT(pos < code_size);
                               proc->return_stack.push_back(pos + 1);
                               int label = code->ptr[pos];
                               ASSERT(label < code_size);
                               pos = label;)
            end_add_code
        start_add_command(RET     )
            add_args_count(RET, 0)
            end_add_args
            add_code(RET)
            add_prog_code (ASSERT(proc->return_stack.size() > 0);
                               pos = proc->return_stack.back();
                               ASSERT(pos < code_size);
                               proc->return_stack.pop_back();)
            end_add_code
        start_add_command(MALLOC     )
             add_args_count(MALLOC, 1)
             add_args_type(MALLOC, reg)
             end_add_args
             add_code(MALLOC)
             add_prog_code (ASSERT(pos < code_size);
                                  int reg_pos = code->ptr[pos];
                                  ASSERT(0 <= reg_pos);
                                  ASSERT(comp.registers_count > reg_pos);
                                  ASSERT(proc->stack_size() > 0);
                                  int a = POP();
                                  proc->regs[reg_pos] = proc->my_malloc(a);
                                  ++pos;)
             end_add_code
        start_add_command(FREE     )
        add_args_count(FREE, 0)
        end_add_args
        add_code(FREE)
        add_prog_code (ASSERT(pos < code_size);
                             ASSERT(proc->stack_size() > 0);
                             int a = POP();
                             proc->my_free(a);
                             ++pos;)
        end_add_code

        start_add_command(PUSHMEM )
        add_args_count(PUSHMEM, 0)
        end_add_args
        add_code(PUSHMEM)
        add_prog_code (ASSERT(pos < code_size);
                               ASSERT(proc->stack_size() > 0);
                               int a = POP();
                               int b = POP();
                               proc->memory[a] = b;
                                       ++pos;)
                      end_add_code

        start_add_command(PUSHMEMREG )
        add_args_count(PUSHMEMREG, 1)
        add_args_type(PUSHMEMREG, reg)
        end_add_args
        add_code(PUSHMEMREG)
        add_prog_code (ASSERT(pos < code_size);
                               ASSERT(proc->stack_size() > 0);
                               int reg_pos = code->ptr[pos];
                               ASSERT(0 <= reg_pos);
                               ASSERT(comp.registers_count > reg_pos);
                               int a = POP();
                               proc->memory[a] = proc->regs[reg_pos];
                               ++pos;)
                      end_add_code

        start_add_command(PUSHMEMCST    )
        add_args_count(PUSHMEMCST, 1)
        add_args_type(PUSHMEMCST, cst)
        end_add_args
        add_code(PUSHMEMCST)
        add_prog_code (ASSERT(pos < code_size);
                               int ans = code->ptr[pos];
                               ASSERT(proc->stack_size() > 0);
                               int a = POP();
                               proc->memory[a] = ans;
                               ++pos;)
        end_add_code

        start_add_command(GETMEMREG )
        add_args_count(GETMEMREG, 1)
        add_args_type(GETMEMREG, reg)
        end_add_args
        add_code(GETMEMREG)
        add_prog_code (ASSERT(pos < code_size);
                               ASSERT(proc->stack_size() > 0);
                               int reg_pos = code->ptr[pos];
                               ASSERT(0 <= reg_pos);
                               ASSERT(comp.registers_count > reg_pos);
                               int a = POP();
                               proc->regs[reg_pos] = proc->memory[a];
                                       ++pos;)
        end_add_code
    end_commands_definition
end_definition