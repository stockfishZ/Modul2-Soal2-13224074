#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int h;
    struct Node *next;
}Node;

Node *node_create(int input) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->h = input;
    n->next = NULL;
    return n;
}

int push(Node **head, char c) {
    Node *n = node_create(c);
    if (n == NULL) return 0;
    n->next = *head;
    *head = n;
    return 1;
}

void pop(Node **head) {
    if (*head == NULL) return;
    Node *top = *head;
    *head = top->next;
    free(top);
}

void check(char *s){
    Node *head = NULL;
    char num[100]; int max;
    int len = 0;
    int i = 0; int j = 0;

    for (int i = 0; i < strlen(s); i++){
        if (s[i] == ' ') continue;
        printf("read: %c\n", s[i]);
        j = i;
        for (int i = 0; i < strlen(s); i++){
            if (s[j] != ' ' && s[j] != '\0'){
                num[j-i] = s[j];
            }else if (s[j] == ' ' || s[j] == '\0'){
                max = j-i;
                printf("max: '%d'\n", max);
                break;
            }
            printf(" %d ", j);
        }
        num[max] = '\0';
        printf("char: %s\n", num);
        int numednum = atoi(num);
        printf("int: %d\n\n", numednum);
    }
}

int main(){
    char *s = malloc(200);
    if (s == NULL) return 0;

    fgets(s, sizeof(s), stdin);
    //printf("%d", strlen(s));

    //check(s);

    printf("NONE");
    return 0;
}
