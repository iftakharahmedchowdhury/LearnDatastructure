#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
int a, b;
vector<int> adj[100009];
vector<int> adj2[100009];
int visited[100009];
// bool visited2[100009];
stack<int> st;
int k = 0;

void dfs(int u)
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

void dfs2(int u)
{
    visited[u] = k;
    int v;
    for (int i = 0; i < adj2[u].size(); i++)
    {
        v = adj2[u][i];

        if (!visited[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* int t;
    cin >> t;
    while (t--)
    {
    } */
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    /*  for (int i = 1; i <= n; i++)
     {

         if (ans[i] == 0)
         {
             dfs2(i, k++);
         }
     } */
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if (!visited[x])
        {
            k++;
            dfs2(x);
        }
    }
    cout << k << endl;
    for (int i = 1; i <= n; i++)
        cout << visited[i] << " ";
}
