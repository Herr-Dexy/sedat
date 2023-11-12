#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++(s->top)] = c;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

void checkParentheses() {
    FILE *file = fopen("burayioku.txt", "r");
    if (!file) {
        printf("Could not open file burayioku.txt\n");
        return;
    }

    Stack stack;
    initialize(&stack);

    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), c)) {
                printf("Unmatched parentheses\n");
                fclose(file);
                return;
            }
        }
    }

    if (!isEmpty(&stack)) {
        printf("Unmatched parentheses at the end of the file\n");
    } else {
        printf("All parentheses are matched.\n");
    }

    fclose(file);
}

int main() {
    checkParentheses();
    return 0;
}
