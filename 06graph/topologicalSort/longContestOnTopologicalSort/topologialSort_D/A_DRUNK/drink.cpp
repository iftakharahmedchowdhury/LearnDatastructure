

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'
#define int long long int

int n, m;
vector<int> adj[10000 + 5];
stack<int> st;
bool visited[10000 + 5];
bool markCycle[10000 + 5];

// void dfs(int u) // when i dont need to check cycle
bool dfs(int u) // when i  need to check cycle
{
    visited[u] = true;
    markCycle[u] = true; // when i  need to check cycle

    int v;
    for (int i = 0; i < adj[u].size(); i++)
    {

        v = adj[u][i];
        if (visited[v] && markCycle[v]) // when i  need to check cycle
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

    markCycle[u] = false;
    st.push(u);
    return false;
}

int main()
{
    bool cycle;
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    st.empty();

    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        tc++;

        map<string, int> strMap;
        strMap.clear();

        // cin >> n >> m;
        cin >> m;
        n = 0;
        memset(visited, 0, sizeof(visited));
        memset(markCycle, 0, sizeof(markCycle));
        for (auto &v : adj)
        {
            v.clear();
        }
        st.empty();
        for (int i = 0; i < m; i++)
        {
            string x, y;

            cin >> x >> y;
            if (strMap.find(x) == strMap.end())
            {
                strMap[x] = n++;
            }
            if (strMap.find(y) == strMap.end())
            {
                strMap[y] = n++;
            }
            // cin >> u >> v;
            adj[strMap[x]].push_back(strMap[y]);
        }
        for (int i = 0; i < n; i++) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
        {
            if (!visited[i])
            {
                cycle = dfs(i);
            }
        }

        /*   while (!st.empty())
          {
              cout << st.top() << " ";
              st.pop();
          }
   */

        if (!cycle)
        {
            cout << "Case " << tc << ": "
                 << "Yes" << endl;
        }
        else
        {
            cout << "Case " << tc << ": "
                 << "No" << endl;
        }
    }
    return 0;
}
