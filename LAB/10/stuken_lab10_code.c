#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int id;
    struct LNode *prev;
    struct LNode *next;
} LNode;

typedef struct LHead {
    int count;
    LNode *first;
    LNode *last;
} LHead;

LHead* init_list() {
    LHead* ph = NULL;
    ph = (LHead*)malloc(sizeof(LHead));
    if (ph != NULL) {
        ph -> count = 0;
        ph -> first = NULL;
        ph -> last = NULL;
    }
    LNode* first_node = NULL;
    first_node = (LNode*)malloc(sizeof(LNode));
    ph -> first = first_node;
    ph -> last = first_node;
    first_node -> id = 1;
    first_node -> prev = first_node;
    first_node -> next = first_node;

    return ph;
}

LNode* add_node(LNode* curr_node) {
    LNode* node = NULL;
    LNode* temp_node = NULL;
    temp_node = (LNode*)malloc(sizeof(LNode));
    node = curr_node -> next;
    curr_node -> next = temp_node;
    temp_node -> next = node;
    temp_node -> prev = curr_node;
    temp_node -> id = curr_node -> id + 1;
    node -> prev = temp_node;
    return temp_node;
}

void print_list(LHead* head) {
    LNode* p = head -> first;
    do {
        if (p == head -> first) {
            printf("%d - head\n",p -> id);
        }
        else {
            printf("%d\n",p -> id);
        }
        p = p -> next;
    } while (p != head -> first);
    
}

LNode* search_by_pos(LHead* head,int pos) {
    LNode* p = head -> first;
    for (int i = 0;i < pos;i++) {
        p = p -> next;
    }
    return p;
}

LHead* move_head(LHead* old_head,int pos) {
    old_head = search_by_pos(old_head,pos);
    return old_head;
}

int main() {
    LHead* head = init_list();
    LNode* first_node = head -> first;
    LNode* temp = first_node;
    int pos;
    for (int i = 0;i < 11;i++) {
        LNode* node = add_node(temp);
        temp = node;
    }
    puts("--------------------------------");
    puts("Old list (head is first element)");
    print_list(head);
    puts("--------------------------------");
    puts("Enter id of element to become head");
    scanf("%d",&pos);
    puts("New list (head is element you chose)");
    head = (LHead*)move_head(head,pos-1);
    print_list(head);
    puts("--------------------------------");

    return 0;
}