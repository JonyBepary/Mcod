// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbeary
//  http://jony-blog.github.io/

#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
list<int> a_list[100];
bool add_edge(list<int> a_list[], int u, int v)
{
    a_list[u].push_back(v);
    a_list[v].push_back(u);
}
void printgraph(int n)
{
    list<int>::iterator it;
    for (int i = 0; i < n + 1; i++)
    {
        cout << i << ": ";
        for (it = a_list[i].begin(); it != a_list[i].end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
}

bool search(int start, int item)
{
    queue<int> q;
    q.push(start);
    map<int, bool> visited;
    list<int>::iterator it;
    while (!q.empty())
    {
        int cr = q.front();
        q.pop();
        if (visited[cr])
            continue;
        for (it = a_list[cr].begin(); it != a_list[cr].end(); it++)
        {

            if (*it == item)
            {
                cout << "data found !!!" << endl;
                return true;
            }
            else
            {
                q.push(*it);
            }
        }
        visited[cr] = true;
    }

    cout << "data not found !!!" << endl;
    return false;
}
int main()
{
    int n = 100;
    add_edge(a_list, 2, 1);
    add_edge(a_list, 3, 1);
    add_edge(a_list, 3, 7);
    add_edge(a_list, 3, 8);
    add_edge(a_list, 8, 5);
    add_edge(a_list, 8, 7);
    add_edge(a_list, 5, 10);
    add_edge(a_list, 4, 1);
    add_edge(a_list, 4, 7);
    add_edge(a_list, 9, 7);
    add_edge(a_list, 9, 10);
    add_edge(a_list, 2, 6);
    add_edge(a_list, 10, 6);
    printgraph(10);
    search(1, 11);
    return 0;
}
