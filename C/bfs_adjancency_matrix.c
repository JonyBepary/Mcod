// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbeary
//  http://jony-blog.github.io/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef long long ll;
typedef unsigned long long ull;
#define N 100 // maximum capacity of adjancency_matrix (graph). can be increase if needed.
int nv = 0;   // number of vertices

// node for queue
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queue
{
    node *head;
    node *tail;
} queue;
// initializing node after declarion.
void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

// Adding node from the back in queue
bool push(queue *q, int value)
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

// Picking and removing node from the front in queue
int pop(queue *q)
{
    if (q->head == NULL)
    {
        return -1;
    }
    node *tmp = q->head;
    int result = tmp->data;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    // printf("%lli\n", result);
    return result;
}

// printing adjancency_matrix (graph)  in grid format;
int adj_print(int adj_matrix[N][N], int min)
{
    for (int i = min; i < nv; i++)
    {
        for (int j = min; j < nv; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// returns largest parameter between tro
int maxval(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

// Adding edge adjancency_matrix (graph);
int add_edge(int adj_matrix[N][N], int u, int v)
{
    if (maxval(u, v) > N)
    {
        printf("SIZE_LIMIT exceed!!!\n");
        return -1;
    }
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
    return 0;
}

// Searching a vertex/node from adjancency_matrix (graph);
// Need adjancency_matrix, vertex to start from, and vertex need to search;
bool bfs(int adj_matrix[N][N], int start, int item)
{
    queue q;
    init_queue(&q);
    push(&q, start);
    int visited[N] = {0}, current;
    while (q.tail != NULL)
    {
        current = pop(&q);
        if (visited[current] == 1)
            continue;

        for (int i = 0; i < nv; i++)
        {

            if (adj_matrix[current][i])
            {
                if (i == item)
                {
                    printf("Item found!!!\n");
                    return true;
                }
                else
                {
                    push(&q, i);
                }
            }
        }
        visited[current] = 1;
    }
    printf("Item not found!!!\n");
    return false;
}
int main()
{
    // nv = 6;
    // scanf("%d", &nv);

    int u, v, adj_matrix[N][N] = {{0}};
    int start, item;
    while (1)
    {
        scanf("%d%d", &u, &v);
        if (!(u || v))
            break;
        if (nv < maxval(u, v))
            nv = maxval(u, v) + 1;

        add_edge(adj_matrix, u, v);
    }
    // add_edge(adj_matrix, 5, 1);
    // add_edge(adj_matrix, 3, 2);
    // add_edge(adj_matrix, 4, 1);
    // add_edge(adj_matrix, 4, 3);
    // add_edge(adj_matrix, 3, 7);

    // adj_print(adj_matrix, 1);
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Node to search: ");
    scanf("%d", &item);
    bfs(adj_matrix, start, item);
    return 0;
}
