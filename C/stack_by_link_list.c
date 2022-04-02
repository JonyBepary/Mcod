// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbepary
//  http://jony-blog.github.io/
// 0ab21bea
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    Node *ager_node;
    int data;
    Node *porer_node;
};
Node *head, *tail;
bool push(int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = data;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->ager_node = tail;
        tail->porer_node = new_node;
        tail = tail->porer_node;
    }
    return true;
}
int pop()
{
    int top;
    top = tail->data;
    tail = tail->ager_node;
    return top;
}
int main()
{
    push(16);
    push(17);
    push(18);
    push(19);
    printf("%d \n", pop());
    printf("%d \n", pop());
    printf("%d \n", pop());
    printf("%d \n", pop());

    return 0;
}
