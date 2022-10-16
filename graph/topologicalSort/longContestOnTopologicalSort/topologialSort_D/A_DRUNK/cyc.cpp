/*
5 6
1 2
2 3
2 4
4 3
4 5
3 5
//////////////
4 4
1 2
2 3
3 4
4 1

5 5
1 2
2 3
3 4
1 4
5 2


7 12
0 1
0 2
0 3
1 3
1 4
3 2
4 3
2 5
3 5
3 6
4 6
6 5
////////////most usefull tasecase
5 6
1 2
3 4
4 1
2 3
1 5
3 1
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
// vector<int >adj[n];
vector<int> adj[50];
stack<int> st;
bool visited[50];
bool onstack[50];
// int color[50];

// void dfs(int u) // when i dont need to check cycle
bool checkCycle(int node)
{
    visited[node] = 1;
    onstack[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (checkCycle(it))
                return true;
        }
        else if (onstack[it])
        {
            return true;
        }
    }
    onstack[node] = 0;
    st.push(node);
    return false;
}

bool isCyclic(int N)
{

    memset(visited, 0, sizeof visited);
    memset(onstack, 0, sizeof onstack);

    for (int i = 0; i <N; i++)
    {
        if (!visited[i])
        {
            // cout << i << endl;
            if (checkCycle(i))
            {
                return true;
            }
        }
    }
    return false;
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
        memset(visited, 0, sizeof(visited));
        // memset(color, 0, sizeof(color));
        map<string, int> strMap;
        //cin >> n >> m;
        n=0;
        cin>>m;
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
        /* for (int i = 1; i <= n; i++) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
        {
            if (!visited[i])
            {
                cycle = isCyclic(i);
            }
        } */
        cycle = isCyclic(n);

       /*  while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        } */

        if (cycle)
        {
            cout << "Case " << tc << ": "
                 << "No" << endl;
        }
        else
        {
            cout << "Case " << tc << ": "
                 << "Yes" << endl;
        }
    }

    return 0;
}
