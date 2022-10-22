#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e5 + 5;

#define endl '\n'

/* ###################### start########################### */
vector<pair<int, int>> adj[100005];
int n, m;

void dijkstra(int source)
{
    vector<int> visit(100005, 0);
    vector<int> dist(100005, INF);

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (st.size() > 0)
    {
        auto node = *st.begin();

        int v_dist = node.first;
        int v = node.second;
        cout << "v----->" << v << endl;
        st.erase(st.begin());
        if (visit[v] == 1)
            continue;
        visit[v] = 1;
        for (auto child : adj[v])
        {
            int child_v = child.first;
            cout << "child_v---->" << child_v << endl;
            int wt = child.second;
            cout << "wt------>" << wt << endl;

            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                cout << "if: dist[chiild_v]" << dist[child_v] << "---->"
                     << "dist[v] + wt : " << dist[v] + wt << endl;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    cout << "#########ans########" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "----wt--->" << dist[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y, wt;
            cin >> x >> y >> wt;
            adj[x].push_back({y, wt});
        }

        // for (int i = 0; i <=n; i++)
        //{
        dijkstra(0);
        // }
    }
}
