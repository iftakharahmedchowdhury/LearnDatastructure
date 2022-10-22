#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;

vector<int> g[1024], topo;
int visited[1024];

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visited[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
}
void dfs2(int u) {
    visited[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int x, y;
    while (cin>>n>>m) {
        for (int i = 0; i <= n; i++)
            g[i].clear();
        
        for (int i = 0; i < m; i++) {
            cin>>x>>y;
           /*  if (y == 0)
                continue; */
            g[x].push_back(y);
        }
        memset(visited, 0, sizeof(visited));
        topo.clear();
        for (int i = 0; i <= n; i++) {
            if (visited[i] == 0)
                dfs(i);
        }
        reverse(topo.begin(), topo.end());
        memset(visited, 0, sizeof(visited));
        
        int ret = 0;
        for (int i = 0; i < topo.size(); i++) {
            int u = topo[i];
            if (visited[u]) continue;
            ret++;
            dfs2(u);
        }
        cout<<ret-1<<endl;
    }
    return 0;
}