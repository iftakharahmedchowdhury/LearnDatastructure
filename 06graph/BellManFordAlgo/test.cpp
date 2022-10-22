/*

Input--->



Enter the number of nodes:

5

Enter the number of edges:

8



1 2 3
3 2 5
3 1 1
1 3 2
1 4 2
0 2 4
4 3 -3
0 1 -1
Enter the source:

0



Output--->



0 -1 2 -2 1

Cycle is present



*/

#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
// const ll INF = 1e18;
const int INF = 1e5;

#define endl '\n'

int main()
{

    int n;

    cout << "Enter the number of nodes: " << endl;

    cin >> n;

    int m;

    cout << "Enter the number of edges: " << endl;

    cin >> m;

    vector<int> dist(n, INF);

    vector<pair<int,int>> edges[100005];

    for (int i = 0; i < m; i++)
    {

        int u, v, w;

        cin >> u >> v >> w;

        edges[u].push_back({v, w});
    }

    int source;

    cout << "Enter the source: " << endl;

    cin >> source;

    dist[source] = 0;

    bool change = false;

    for (int i = 0; i < n; i++)
    {

        for (auto it : edges[source])
        {
             int v = it.first;
            cout << "child_v---->" << endl;
            int w = it.second;
           
           /*  int u = edges[i][0];

            int v = it[1];

            int w = it[2]; */

            if (dist[v] > dist[i] + w)
            {

                change = true;
            }

            dist[v] = min(dist[v], w + dist[i]);
        }
    }

    for (auto distIT : dist)
    {

        cout << distIT << " ";
    }

    cout << endl;

    if (change)
    {

        cout << "Cycle is present" << endl;
    }
    else
    {

        cout << "Cycle is not present" << endl;
    }

    return 0;
}
