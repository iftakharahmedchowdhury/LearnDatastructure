#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

vector<int> adj[300009];
stack<int> st;
bool visited[300009];
bool onstack[300009];
bool cycle = false;

bool dfs(int u) // when i  need to check cycle
{
    visited[u] = true;
    onstack[u] = true; // when i  need to check cycle

    int v;
    for (int i = 0; i < adj[u].size(); i++)
    {
       

        v = adj[u][i];
        if (visited[v] && onstack[v]) // when i  need to check cycle
        {
            // cycle true
            return true;
        }

        else if (!visited[v])
        {
            if (dfs(v))
            {
                // cycle true
                return true;
            }
        }
    }

    onstack[u] = false;
    st.push(u);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    /* while (t--)
    {
    } */
    memset(visited, 0, sizeof(visited));
    memset(onstack, 0, sizeof(onstack));

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cycle = dfs(i);
        }
    }

    if (cycle)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
}
