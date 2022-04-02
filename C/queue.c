// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2021
//  @jbepary
//  http://jony-blog.github.io/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned long long ull;
typedef struct node
{
    ll data;
    struct node *next;
} node;
typedef struct queue
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        return false;
    }

    newnode->data = value;
    newnode->next = NULL;
    if (q->tail != NULL)
        q->tail->next = newnode;

    q->tail = newnode;
    if (q->head == NULL)
        q->head = newnode;
    return true;
}

ll dequeue(queue *q)
{
    if (q->head == NULL)
    {
        return -1;
    }
    node *tmp = q->head;
    ll result = tmp->data;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    // printf("%lli\n", result);
    return result;
}

int main()
{
    queue q1, q2, q3;
    ll t;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);
    enqueue(&q1, 101);
    enqueue(&q2, 204);
    enqueue(&q2, 223);
    enqueue(&q2, 232);
    enqueue(&q2, 241);
    enqueue(&q3, 303);
    while (-1)
    {
        t = dequeue(&q2);
        if (t == -1)
            break;

        printf("%lli\n", t);
        // printf("%lli\n", dequeue(&q2));
    }

    return 0;
}
