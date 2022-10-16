#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
// vector<int >adj[n];
vector<int> adj[10000];
/* vector<int> revAdj[10000]; */
stack<int> st;
bool visited[10000];

// bool onstack[50];
//  int color[50];

// void dfs(int u) // when i dont need to check cycle
void dfs(int u) // when i  need to check cycle
{
    visited[u] = true;

    int v;
    for (int i = 0; i < adj[u].size(); i++)
    {

        v = adj[u][i];

        if (!visited[v])
        {

            dfs(v);
        }
    }

    st.push(u);
}

void miniHitLightDFS(int u) // when i  need to check cycle
{
    visited[u] = true;

    int v;
    for (int i = 0; i < adj[u].size(); i++)
    {

        v = adj[u][i];

        if (!visited[v])
        {

            miniHitLightDFS(v);
        }
    }

    // st.push(u);
}

int main()
{
    bool cycle;
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        tc++;
       int minimumLight=0;

        memset(visited, 0, sizeof(visited));
        // memset(color, 0, sizeof(color));

        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        memset(visited, 0, sizeof(visited));
       

        for (int i = 1; i <= n; i++) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        memset(visited, 0, sizeof(visited));

        while (!st.empty())
        {
            // cout << st.top() << endl;
            if (!visited[st.top()])
            {
                miniHitLightDFS(st.top());
                minimumLight++;
               

            }
             st.pop();
        }

        cout << "Case " << tc << ": " << minimumLight << endl;
    }

    return 0;
}
