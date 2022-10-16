#include <bits/stdc++.h> // see C++ Tips & Tricks

using namespace std;

using ll = long long;

using vi = vector<int>;

#define pb push_back

#define rsz resize

#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

using pi = pair<int, int>;

#define f first

#define s second

#define mp make_pair


vi adj[100005],adj2[100005];
bool vis[100005];

void dfs(int v)
{

    vis[v] = true;

    for (int to : adj[v])
    {

        if (!vis[to])
        {

            dfs(to);
        }
    }
}

void dfs2(int v)
{

    vis[v] = true;

    for (int to : adj2[v])
    {

        if (!vis[to])
        {

            dfs2(to);
        }
    }
}

int main()
{

    

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;

        u--, v--;

        adj[u].pb(v);

        adj[v].pb(u);
    }

    dfs(1);

    for (int i = 1; i <n; i++)
    {

        if (!vis[i])
        {

            cout << "NO" << '\n';

            cout << 1 << " " << i + 1 << '\n';

            return 0;
        }
    }

    memset(vis, false, sizeof(vis)); // fill vis with false

    dfs2(1);

    for (int i = 1; i <n; i++)
    {

        if (!vis[i])
        {

            cout << "NO" << '\n';

            cout << i + 1 << " " << 1 << '\n';

            return 0;
        }
    }

    cout << "YES" << '\n';
}