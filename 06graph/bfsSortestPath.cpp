#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> G[10000];

int main()
{
    int n; // total node number
    cin >> n;
    int edge; // total edge number
    cin >> edge;
    while (edge--)
    {
        int x, y; // for Adjacency List
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int visited[n] = {0}; // array for mark visited node
    int d[n];             // shortest distance of source to distance
    int p[n];             // parent array
    int s = 0;            // source vertices
    visited[s] = 1;       // make source vertices visited so make it true
    d[s] = 0;             // 0 to 0 no distance so for source 0 set distance 0;
    p[s] = -1;            // start node dont hav parent so we mark it as -1

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : G[v])
        {
            if (!visited[u])
            {
                visited[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
}
