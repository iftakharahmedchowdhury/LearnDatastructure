#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;

vector<int> adj[100005];

vector<int> backAdj[100005];

int main()
{

    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int inDegree[n + 1], dp[n + 1];

    for (int i = 0; i <= n; i++)
    {

        inDegree[i] = 0;

        dp[i] = 0;
    }

    dp[1] = 1;

    for (int i = 0; i < m; i++)
    {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);

        backAdj[b].push_back(a);

        inDegree[b]++;
    }
    // cout << inDegree[n] << endl;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {

        if (inDegree[i] == 0)
        {

            q.push(i);
        }
    }

    while (!q.empty())
    {

        int node = q.front();

        q.pop();

        for (int next : adj[node])
        {

            inDegree[next]--;

            if (inDegree[next] == 0)
                q.push(next);
        }

        for (int prev : backAdj[node])
        {

            dp[node] = (dp[node] + dp[prev]) % 1000000007;
        }
    }

    cout << dp[n] << endl;

    return 0;
}