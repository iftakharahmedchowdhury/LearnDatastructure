#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    // cin >> t;
    // while (t--)
    //{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        count++;
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto t : adj[x])
        {
            inDegree[t]--;
            if (inDegree[t] == 0)
            {
                q.push(t);
            }
        }
    }

    //}
}
