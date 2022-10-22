
////AC
#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

vector<int> adj[200009];
stack<int> st;
int visited[200009];
int check[200009];
bool cc = false;
void DFS(int u)
{
    visited[u] = 1;
    int v;
    for (int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if (visited[v] == 0)
        {
            DFS(v);
        }
        else if (visited[v] == 1)
        {
            cout << "IMPOSSIBLE" << endl;
            cc = true;
        }
    }
    visited[u] = 2;
    st.push(u);
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
    memset(check, 0, sizeof(visited));

    int n, m;
    cin>>n>>m;
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
            DFS(i);
        }
    }

    if (!cc)
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
}
