//
// Created by oleg on 25.10.2019.
//
#define m_esp regs[4]
class proc {
public:
    int* memory = nullptr;
    my_stack<int> return_stack;
    int regs[5];
    int mem_size;
    int heap_head;

    proc (int size) {
        ASSERT(size > 10);
        memory = (int*) calloc(size, sizeof(int));
        heap_head = 2;
        memory[0] = 0;
        memory[1] = 0;
        memory[2] = -1;
        m_esp = size;
        mem_size = size;
    }

    int stack_size() {
        ASSERT(m_esp <= mem_size);
        ASSERT(m_esp > heap_head);
        return mem_size - m_esp;
    }

    void stack_push(int t) {
        ASSERT(m_esp <= mem_size);
        ASSERT(m_esp > heap_head + 1);
        m_esp--;
        memory[m_esp] = t;
    }

    int stack_pop() {
        ASSERT(stack_size() > 0);
        m_esp++;
        return memory[m_esp - 1];
    }

    int stack_back() {
        ASSERT(stack_size() > 0);
        return memory[m_esp];
    }

    int my_malloc (int cnt) {
        ASSERT(cnt > 0);
        int start = 2;
        while (memory[start] != -1 && (memory[start - 2] != 0 || (memory[start - 1] != cnt && memory[start - 1] < cnt + 3))) {
            if (memory[start - 2] == 0 && memory[memory[start] - 2] == 0) {
                memory[start - 1] += memory[memory[start] - 1] + 3;
                memory[start] = memory[memory[start]];
            }
            else start = memory[start];
        }

        if (memory[start - 2] == 0 && (memory[start - 1] == cnt || memory[start - 1] >= cnt + 3) ) {
            if (memory[start - 1] == cnt) {
                memory[start - 2] = 1;
                return start + 1;
            }
            else {
                memory[start - 2] = 1;
                int w = start + cnt + 1;
                memory[w] = 0;
                memory[w + 1] = memory[start - 1] - cnt - 3;
                memory[start - 1] = cnt;
                memory[w + 2] = memory[start];
                /*memory[w] = 13;*/
                memory[start] = w + 2;
                return start + 1;
            }
        }
        else if (memory[start] == -1) {
            int w = start + memory[start - 1] + 1;
            ASSERT(w + 2 + cnt < m_esp);
            memory[w] = 1;
            memory[w + 1] = cnt;
            memory[start] = w + 2;
            memory[w + 2] = -1;
            heap_head = w + 2 + cnt;
            return w + 3;
        }
    }
    void my_free (int ptr) {
        ASSERT((ptr >= 3) && (ptr < heap_head));
        ASSERT(memory[ptr - 3] == 1);
        memory[ptr - 3] = 0;
    }
    void print () {
        for (int i = 0; i < mem_size; ++i) {
            std::cout<<memory[i]<<" ";
        }
        std::cout<<std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout<<regs[i]<<" ";
        }
        std::cout<<std::endl;
    }
};
#undef m_esp