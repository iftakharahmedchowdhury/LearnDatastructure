#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

vector<int> adj[10009];
stack<int> topoStack;
int node, e;
bool V[10009];
void dfs1(int u)
{
    V[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (!V[adj[u][i]])
        {
            dfs1(adj[u][i]);
        }
    }
    topoStack.push(u);
}
void dfs2(int u)
{
    V[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (!V[adj[u][i]])
        {
            dfs2(adj[u][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        cin >> node >> e;
        for (int i = 0; i <= node; i++)
            adj[i].clear();

        while (e--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        memset(V, false, sizeof V);
        int cnt = 0;
        for (int i = 1; i <= node; i++)
            if (!V[i])
                dfs1(i);
        memset(V, false, sizeof V);

        while (!topoStack.empty())
        {
            // cout << st.top() << endl;
            if (!V[topoStack.top()])
            {
                dfs2(topoStack.top());
                cnt++;
            }
            topoStack.pop();
        }

        cout << "Case " << cs++ << ": " << cnt << endl;
    }
    return 0;
}