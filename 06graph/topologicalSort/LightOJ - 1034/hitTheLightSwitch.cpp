#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, tc = 0;
    cin>>t;

    while (t--)
    {
        tc++;
        int n, m, count = 0;

        cin >> n >> m;

        vector<int> inDegree(n, 0);
        vector<int> adj[n + 1];

        for (int i = 0; i < m; i++)
        {

            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            inDegree[v]++;
        }

        int max = *max_element(inDegree.begin(), inDegree.end());
        cout << "Case "<<tc<<": " << max << endl;
    }
}
