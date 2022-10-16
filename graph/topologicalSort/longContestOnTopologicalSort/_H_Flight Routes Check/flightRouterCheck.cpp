#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

vector<int> adj[100009];
vector<int> revAdj[100009];
bool visited[100009];
bool visited2[100009];
stack<int> st;
int n, m;
void dfs(int u)
{

    visited[u] == true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int x = adj[u][i];
        if (visited[x]==false)
        {
            dfs(x);
        }
    }
    //st.push(u);
}

void revDfs(int v)
{
    //cout << "rev DFS" << endl;
    visited2[v] == true;
    for (int i = 0; i < revAdj[v].size(); i++)
    {
        int x = revAdj[v][i];
        if (visited2[x]==false)
        {
            revDfs(x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*  int t;
     cin >> t;
     while (t--)
     {
     } */

    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <=n; i++)
    {

        if (visited[i]==false)
        {
            cout << "NO" << endl;

            cout << 1 << " " << i<< endl;

            return 0;
        }
    }
    memset(visited2, 0, sizeof(visited2));

    // for (int v = 1; v <= n; v++)
    // {
    //int topV = st.top();
    //revDfs(topV);
    //}
    revDfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (visited2[i]==false)
        {
            cout << "NO" << endl;

            cout << i << " " << 1 << endl;

            return 0;
        }
    }

    cout << "YES" << endl;
}
