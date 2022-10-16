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

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
vector<int> adj[1000000+5];
stack<int> st;
bool visited[10000+5];
bool markCycle[10000+5];


// void dfs(int u) // when i dont need to check cycle
bool dfs(int u)  // when i  need to check cycle
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
                //cycle true
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

    // int t;
    // cin >> t;
    // while (t--)
    //{
    memset(visited, 0, sizeof(visited));
    memset(markCycle, 0, sizeof(markCycle));
   

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) // 0 node graph i=0;i<n if 1 node graph i=1;i<=n
    {
        if (!visited[i])
        {
         cycle = dfs(i);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

   
    if (cycle)
    {
        cout << "Sandro fails." << endl;
    }
 
   
    return 0;
}
