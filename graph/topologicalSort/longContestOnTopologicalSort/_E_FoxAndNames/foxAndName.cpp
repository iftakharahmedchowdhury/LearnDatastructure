#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define ll long long int
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

vector<string> inputString;
vector<int> indegree(26, 0);
vector<int> adj[26];
bool flag = true;
bool checkDeg = true;

void bfs()
{
    if (flag)
    {
        string res = "";
        vector<int> vis(26, 0);
        priority_queue<int, vector<int>, greater<int>> pq; // create mini heap (low to high)
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] == 0)
            {
                pq.push(i);
                vis[i] = 1;
            }
        }
        while (!pq.empty())
        {
            int node = pq.top();
            res += (node + 'a');
            pq.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    indegree[it]--;
                    if (indegree[it] == 0)
                    {
                        pq.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] != 0)
            {
                checkDeg = false;
                break;
            }
        }
        if (!checkDeg)
            cout << "Impossible" << endl;
        else
            cout << res << endl;
    }
    else
        cout << "Impossible" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*   int t;
      cin >> t;
      while (t--)
      {
      } */
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        inputString.push_back(s);
    }

    for (int i = 0; i < (n - 1); i++)
    {
        int j = 0;
        int k = 0;
        while (j < inputString[i].length() and k < inputString[i + 1].length())
        {
            if (inputString[i][j] != inputString[i + 1][k])
            {
                adj[inputString[i][j] - 'a'].push_back(inputString[i + 1][k] - 'a');

                indegree[inputString[i + 1][k] - 'a']++;

                break;
            }

            j++;
            k++;
        }
        if (k == inputString[i + 1].length())
        {
            flag = false;
            break;
        }
    }
    bfs();
}
