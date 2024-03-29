#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int main()
{
    int n, m;
    // cin >> n >> m;
    while (cin >> n >> m, n != 0 || m != 0)
    {
        int indegree[n + 1];
        vector<int> adjList[n + 1];

        memset(indegree, 0, sizeof(indegree));

        int u, v;
        while (m--)
        {
            cin >> u >> v;
            adjList[u].push_back(v);
            indegree[v]++;
        }

        // topological sort.

        queue<int> q;

        for (int i = 1; i <= n; i++)
        {

            // cout<<"indegree : "<<i<<" -->"<<indegree[i]<<endl;
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            u = q.front();
            q.pop();

            cout << ' ';
            cout << u;

            for (int i = 0; i < adjList[u].size(); i++)
            {
                v = adjList[u][i];
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        cout << endl;
    }

    return 0;
}