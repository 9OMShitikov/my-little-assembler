//
// Created by oleg on 31.10.2019.
//

#define POP() proc->stack_pop();

#define PUSH(expr) proc->stack_push(expr);

#define J_IF_CMP(comp) ASSERT(proc->stack_size() >= 2); \
                       int a = POP(); \
                       int b = POP(); \
                       ASSERT(pos < code_size); \
                       int label = code->ptr[pos]; \
                       ASSERT(label < code_size); \
                       if (b comp a) pos = label; \
                       else ++pos;
