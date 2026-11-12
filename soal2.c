//Rafa Satria Pratama
//13224074 – Modul 2 – Soal 2

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

int push(Node **head, int c) {
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
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\r' || s[i] == '\t') continue;

        int j = i;
        max = 0;
        while (s[j] != ' ' && s[j] != '\n' && s[j] != '\r' && s[j] != '\t' && s[j] != '\0'){
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
        if (p == 1 || p == n) continue;

        int depth = n - p;
        int left = 0, right = 0, h = 0;
        int d = 0;
        Node *cur = head;

        while (cur != NULL){
            if (d == depth - 1) right = cur->h;
            if (d == depth)     h = cur->h;
            if (d == depth + 1) left = cur->h;
            cur = cur->next;
            d++;
        }

        if (left > h && right > h) push(&res, p);
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
        printf("NONE\n");
        free(s);
        return 0;
    }

    check(s);

    free(s);
    return 0;
}
