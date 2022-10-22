#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;

bool visited[100005], revVisited[100005];

vector<int> ajd[100005], revAdj[100005];
void dfs1(int a)
{

    visited[a] = true;

    for (int i = 0; i < ajd[a].size(); i++)
    {

        int x = ajd[a][i];
        if (visited[x] == false)
            dfs1(x);
    }
}

void dfs2(int a)
{

    revVisited[a] = true;

    for (int i = 0; i < revAdj[a].size(); i++)
    {

        int x = revAdj[a][i];

        if (revVisited[x] == false)
            dfs2(x);
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

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;

        ajd[u].push_back(v);

        revAdj[v].push_back(u);
    }

    dfs1(1);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {

            cout << "NO" << endl;

            cout << 1 << " " << i << endl;

            return 0;
        }
    }
    dfs2(1);

    for (int i = 1; i <= n; i++)
    {

        if (revVisited[i] == false)
        {
            cout << "NO" << endl;

            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}