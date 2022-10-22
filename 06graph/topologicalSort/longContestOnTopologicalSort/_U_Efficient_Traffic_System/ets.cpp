

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
vector<int> adj[1000000 + 5];

bool cycle = 0;

int main()
{

    /*    ios_base::sync_with_stdio(0);
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
       st.empty(); */

    // int t;
    // cin >> t;
    // while (t--)
    //{

    // memset(visited, 0, sizeof(visited));
    int indeg[109];
    int outdeg[109];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }

    //cout << *max(indeg, outdeg) << endl;
    int nn = sizeof(indeg) / sizeof(indeg[0]);
    int inDeg = *max_element(indeg, indeg + nn);

    int mm = sizeof(outdeg) / sizeof(outdeg[0]);
    int outDeg = *max_element(outdeg, outdeg + mm);

    cout << max(inDeg, outDeg) << endl;

    return 0;
}
