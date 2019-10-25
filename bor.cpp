//
// Created by oleg on 25.10.2019.
//

class bor {
public:
    bor() {
        zero_node = new bor_node;
    }
    ~bor() {
        delete(zero_node);
    }
    void add (const char* str, int value) {
        ASSERT(str);
        bor_node* cur_node = zero_node;
        int i = 0;
        while (str[i] != '\0' && str[i] != ':') {
            ASSERT(str[i] >= 0);
            if (cur_node->nodes[str[i]] == nullptr) {
                cur_node->nodes[str[i]] = new bor_node;
            }
            cur_node = cur_node->nodes[str[i]];
            ++i;
        }
        cur_node->value = value;
    }
    int check (const char* str) {
        ASSERT(str);
        bor_node* cur_node = zero_node;
        int i = 0;
        while (str[i] != '\0' && str[i] != ':') {
            ASSERT(str[i] >= 0);
            if (cur_node->nodes[str[i]] == nullptr) {
                return -1;
            }
            cur_node = cur_node->nodes[str[i]];
            ++i;
        }
        return cur_node -> value;
    }
private:
    struct bor_node {
        bor_node* nodes[128];
        int value;
        bor_node() {
            for (int i = 0; i < 26; ++i)
                nodes[i] = nullptr;
            value = -1;
        }
        ~bor_node() {
            for (int i = 0; i < 26; ++i)
                if (nodes[i] != nullptr) delete(nodes[i]);
        }
    };
    bor_node* zero_node;
};
