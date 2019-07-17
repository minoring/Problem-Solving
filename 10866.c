#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_COMMAND  8
#define MAX_COMMAND_LEN 12

typedef struct Node_ {
        int data;
        struct Node_* prev;
        struct Node_* next;
} Node;

typedef struct Deque_ {
        int size;
        Node* front;
        Node* rear;
} Deque;


void execute_command(const char* command, Deque* deque);
void push_front(Deque* deque);
void push_back(Deque* deque);
void pop_front(Deque* deque);
void pop_back(Deque* deque);
void size(Deque* deque);
void empty(Deque* deque);
void front(Deque* deque);
void back(Deque* deque);
void create_first_elem(int data, Deque* deque);


int main() {
        int num_command;
        char command[MAX_COMMAND_LEN];
        scanf("%d", &num_command);

        Deque deque;
        deque.size = 0;
        deque.front = NULL;
        deque.rear = NULL;

        for (int i = 0; i < num_command; ++i) {
                scanf("%s", command);
                execute_command(command, &deque);
        }
}

void execute_command(const char* command, Deque* deque) {
        const char COMMAND[NUM_COMMAND][MAX_COMMAND_LEN] = {
                "push_front",
                "push_back",
                "pop_front",
                "pop_back",
                "size",
                "empty",
                "front",
                "back"
        };
        void (*com_func[NUM_COMMAND])(Deque*) = {
                push_front,
                push_back,
                pop_front,
                pop_back,
                size,
                empty,
                front,
                back
        };

        unsigned int command_idx = 0;
        while (strcmp(command, COMMAND[command_idx]) != 0) 
                command_idx++;
        
        com_func[command_idx](deque);
}

void push_front(Deque* deque) {
        int input_data;
        scanf("%d", &input_data);

        if (deque->front == NULL) {
                create_first_elem(input_data, deque);

        } else {
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->data = input_data;
                new_node->next = deque->front;
                new_node->prev = NULL;
                deque->front->prev = new_node;
                deque->front = new_node;
        }
        deque->size++;
}

void push_back(Deque* deque) {
        int input_data;
        scanf("%d", &input_data);

        if (deque->front == NULL) {
                create_first_elem(input_data, deque);
        } else {
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->data = input_data;
                new_node->next = NULL; 
                new_node->prev = deque->rear; 
                deque->rear->next = new_node;
                deque->rear = new_node;
        }
        deque->size++;
}

void pop_front(Deque* deque) {
        front(deque);

        if (deque->front == deque->rear) {
                // This is the last one
                free(deque->front);
                deque->front = NULL;
                deque->rear = NULL;
                deque->size = 0;
        } else {
                Node* delete_node = deque->front;
                deque->front = deque->front->next;
                free(delete_node);
                deque->front->prev = NULL;
                deque->size--;
        }
}

void pop_back(Deque* deque) {
        back(deque);

        if (deque->front == deque->rear) {
                free(deque->front);
                deque->front = NULL;
                deque->rear = NULL;
                deque->size = 0;
        } else {
                Node* delete_node = deque->rear;
                deque->rear = deque->rear->prev;
                free(delete_node);
                deque->rear->next = NULL;
                deque->size--;
        }
}

void size(Deque* deque) {
        printf("%d\n", deque->size);
}

void empty(Deque* deque) {
        printf("%d\n", (deque->size == 0) ? 1 : 0);
}

void front(Deque* deque) {
        if (deque->size == 0) {
                printf("-1\n");
                return;
        }

        printf("%d\n", deque->front->data);
}

void back(Deque* deque) {
        if (deque->size == 0) {
                printf("-1\n");
                return;
        }

        printf("%d\n", deque->rear->data);
}

void create_first_elem(int data, Deque* deque) {
        deque->front = (Node*)malloc(sizeof(Node));
        deque->rear = deque->front;
        deque->front->data = data;
        deque->front->prev = NULL;
        deque->rear->next = NULL;
}