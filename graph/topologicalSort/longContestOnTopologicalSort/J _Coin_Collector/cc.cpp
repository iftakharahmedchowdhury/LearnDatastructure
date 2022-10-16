#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

int n, m;
int a, b;
int coin[100009];
vector<int> adj[100009];
bool visited[100009];
int parent[100009];
vector<long long int> ans;

void dfs(int u)
{
   // cout<<"dfs u :"<<u<<endl;
    visited[u] = true;
    int x;
    for (int i = 0; i < adj[u].size(); i++)
    {

        x = adj[u][i];
       //  cout<<"dfs for"<<" i : "<<i<<" x: "<<x<<endl;
        if (!visited[x])
        {
           // cout<<"dfs for if"<<endl;
            parent[x] = u;
            dfs(x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    /*   cin >> t;
      while (t--)
      {
      } */

    memset(visited, false, sizeof(visited));
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
       // cout<<i+1<<endl;
    }
    for (int i = 0; i < m; i++)
    {
      //  cout<<i+5<<endl;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
       // cout<<i+9<<endl;
        if (!visited[i])
        {
            dfs(i);
        }
    }

    ans.push_back(n);
    //cout<<"ans"<<endl;
    while (ans.back() != 1)
    {
       // cout<<"ans while"<<endl;
        ans.push_back(parent[ans.back()]);
    }
    reverse(ans.begin(), ans.end());
    int value=0;
   // cout<<"ans rev"<<endl;
    for (int i : ans)
    {
         value+=coin[i-1];
       //cout << i << " ";
    }
    //cout<<endl;
    //cout<<coin[0]<<" "<<coin[1]<<" "<<coin[2]<<" "<<coin[3]<<endl;
     cout<<value<<endl;
}
