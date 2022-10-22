#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dict.push_back(s);
    }
    vector<int> indegree(26, 0);
    vector<int> adj[26];
    bool flag = true;
    for (int i = 0; i < (n - 1); i++)
    {
        int j = 0;
        int k = 0;
        while (j < dict[i].length() and k < dict[i + 1].length())
        {
            if (dict[i][j] != dict[i + 1][k])
            {
                adj[dict[i][j] - 'a'].push_back(dict[i + 1][k] - 'a');
                indegree[dict[i + 1][k] - 'a']++;
                break;
            }
            j++;
            k++;
        }
        if (k == dict[i + 1].length())
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        string res = "";
        vector<int> vis(26, 0);
        priority_queue<int, vector<int>, greater<int>> pq;// create mini heap (low to high)
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
        bool ok = true;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] != 0)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            cout << "Impossible"
                 << "\n";
        else
            cout << res << "\n";
    }
    else
        cout << "Impossible"
             << "\n";
    return 0;
}