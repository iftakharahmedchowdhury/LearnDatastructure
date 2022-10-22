

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
vector<int> adj[10000 + 5];
stack<int> st;
int visited[10000 + 5];
bool drunk = 1;

// void dfs(int u) // when i dont need to check cycle
void dfs(int v)
{
    int i;
    visited[v] = 1;
    if (drunk == 0)
        return;
    for (i = 0; i < adj[v].size(); i++)
    {
        if (visited[adj[v][i]] == 1)
        {
            drunk = 0;
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
        memset(visited, 0, sizeof(visited));
        for (auto &v : adj)
        {
            v.clear();
        }
        st.empty();

        map<string, int> strMap;

        cin >> n >> m;
        // cin >> m;
        n = 0;
        drunk = 1;
        for (int i = 0; i < m; i++)
        {
            // string x, y;
            int x, y;

            cin >> x >> y;
            /*  if (strMap.find(x) == strMap.end())
             {
                 strMap[x] = n++;
             }
             if (strMap.find(y) == strMap.end())
             {
                 strMap[y] = n++;
             } */
            // cin >> u >> v;
            // adj[strMap[x]].push_back(strMap[y]);
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        if (!drunk)
        {
            cout << "No cycle" << endl;
        }
        else
        {
            cout << "has cycle" << endl;
        }
    }
    return 0;
}
