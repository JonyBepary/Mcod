// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbeary
//  http://jony-blog.github.io/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<vector<bool>> adj_mat;
void vct_print(adj_mat &ara, int number_vertices)
{
    for (int i = 1; i < number_vertices; i++)
    {
        for (int j = 1; j < number_vertices; j++)
        {
            cout << ara[i][j] << "  ";
        }
        cout << endl;
    }
}
void add_edge(adj_mat &ara, int u, int v)
{

    ara[u][v] = true;
    ara[v][u] = true;
}

bool bfs(adj_mat &ara, int start, int item)
{
    queue<int> q;
    q.push(start);
    int current;
    vector<bool> vis(ara.size(), false);
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        if (vis[current])
            continue;

        for (int j = 0; j < ara[current].size(); j++)
        {
            if (ara[current][j])
            {
                if (j == item)
                {
                    cout << "item found !!\n";
                    return 0;
                }
                else
                {
                    q.push(j);
                }
            }
        }
        vis[current] = true;
    }
    cout << "item not found !!\n";
    return false;
}
int main()
{
    int number_vertices = 7;
    adj_mat ara(number_vertices + 2, vector<bool>(number_vertices + 2, false));

    // vct_print(ara, number_vertices);
    add_edge(ara, 6, 4);
    add_edge(ara, 4, 5);
    add_edge(ara, 4, 3);
    add_edge(ara, 5, 1);
    add_edge(ara, 5, 2);
    add_edge(ara, 2, 3);
    add_edge(ara, 1, 2);
    // cout << "\n\n-----------------------\n\n";
    // vct_print(ara, number_vertices);
    bfs(ara, 6, 7);
    return 0;
}
