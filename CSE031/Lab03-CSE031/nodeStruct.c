#include <stdio.h>
#include <stdlib.h>
struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};
int main() {
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
    printf("Floating value of head: %d\n", head->iValue);
    printf("Integer value of head: %f\n", head->fValue);
    printf("Address of head: %p\n", &head);
// Insert code here
return 0;
}