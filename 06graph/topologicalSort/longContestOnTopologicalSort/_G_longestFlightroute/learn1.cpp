#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m, a, b, in[100005], dis[100005], parent[100005];
vector<int> adj[100005], ans;
void bfs()
{
    queue<int> q;
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i : adj[now])
        {
            // cout<<"i->"<<i<<" dis[i]: "<<dis[i]<<" dis[now] + 1 : "<<dis[now] + 1<<endl;
            if (dis[i] < dis[now] + 1)
            {
                parent[i] = now;
                dis[i] = dis[now] + 1;
            }
            in[i]--;
            if (in[i] == 0)
                q.push(i);
        }
    }
    if (dis[n] < 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        ans.push_back(n);
        while (ans.back() != 1)
        {
            ans.push_back(parent[ans.back()]);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = -1e9;
    }

    bfs();
}