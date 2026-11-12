
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
    Node *res = NULL;
    char num[100]; int max;
    int n = 0;

    for (int i = 0; i < strlen(s); i++){
        if (s[i] == ' ' || s[i] == '\n') continue;

        int j = i;
        max = 0;
        while (s[j] != ' ' && s[j] != '\n' && s[j] != '\0'){
            num[max] = s[j];
            max++;
            j++;
        }
        num[max] = '\0';

        int numednum = atoi(num);
        push(&head, numednum);
        n++;

        i = j - 1;
    }

    for (int p = n; p >= 1; p--){
        int depth = n - p;
        int maxRight = 0, maxLeft = 0, h = 0;
        int d = 0;
        Node *cur = head;

        while (cur != NULL){
            if (d < depth && cur->h > maxRight) maxRight = cur->h;
            if (d == depth) h = cur->h;
            if (d > depth && cur->h > maxLeft) maxLeft = cur->h;
            cur = cur->next;
            d++;
        }

        if (maxLeft > h && maxRight > h) push(&res, p);
    }

    int first = 1;
    while (res != NULL){
        if (!first) printf(" ");
        printf("%d", res->h);
        first = 0;
        pop(&res);
    }
    if (first) printf("NONE");
    printf("\n");

    while (head != NULL) pop(&head);
}

int main(){
    char *s = malloc(200);
    if (s == NULL) return 0;

    if (fgets(s, 200, stdin) == NULL){
        free(s);
        return 0;
    }

    check(s);

    free(s);
    return 0;
}
