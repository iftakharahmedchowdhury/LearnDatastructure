//AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
vector<int> adj[1000000 + 5];
stack<int> st;
int visited[1000000 + 5];
bool cycle = 0;


void dfs(int v)
{
    if (cycle == 1)
    {
        return;
    }

    visited[v] = 1;

    for (int i = adj[v].size() - 1; i >= 0; i--)
    {
        if (visited[adj[v][i]] == 1)
        {
            cycle = 1;
            return;
            //  cout<<v<<"  "<<adj[v][i]<<endl;
        }
        else if (visited[adj[v][i]] == 0)
        {
            dfs(adj[v][i]);
        }
    }
    st.push(v);
    visited[v] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    st.empty();

    // int t;
    // cin >> t;
    // while (t--)
    //{
    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = n; i >= 1; i--) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    /* while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    } */

    if (cycle == 1)
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}
