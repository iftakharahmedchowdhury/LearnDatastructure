    #include <bits/stdc++.h>
    using namespace std;
     
    int32_t main()
    {
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }
        vector<vector<int>> graph(26);
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (words[i][0] != words[i + 1][0])
            {
                graph[words[i][0] - 'a'].push_back(words[i + 1][0] - 'a');
            }
            else
            {
                int k = 1;
                int l = 1;
                while (k < words[i].length() && l < words[i + 1].length() && words[i][k] == words[i + 1][l])
                {
                    k++;
                    l++;
                }
                if (l == words[i + 1].length() && k != words[i].length())
                {
                    ok = false;
                    break;
                }
                else if (k == words[i].length())
                {
                    continue;
                }
                else
                {
                    graph[words[i][k] - 'a'].push_back(words[i + 1][l] - 'a');
                }
            }
        }
        vector<int> indegree(26, 0);
        vector<int> vis(26, 0);
        for (auto nodes : graph)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                indegree[nodes[i]]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] == 0)
            {
                pq.push(i);
                vis[i] = 1;
            }
        }
        string s = "";
        while (!pq.empty())
        {
            int node = pq.top();
            pq.pop();
            s += (node +'a');
            for (auto v : graph[node])
            {
                if (!vis[v])
                {
                    indegree[v]--;
                    if (indegree[v] == 0)
                    {
                        pq.push(v);
                        vis[v]=1;
                    }
                }
            }
        }
        if(ok==false || s.length()!=26) cout<<"Impossible"<<endl;
        else cout<<s<<endl;
     
        return 0;
    }

