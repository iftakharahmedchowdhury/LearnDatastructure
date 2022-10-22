#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 230;
int n, cnt, len, m;
int a[MAXN], cur, nxt, in[MAXN], vis[MAXN];
bool flag;
string s, ss;
vector<int> G[MAXN];

void toposort()
{
    queue<int> q;
    for (int i = 97; i <= 122; ++i)
    {
        if (in[i] == 0 && vis[i] != 0)
        {
            q.push(i);
        }
    }
    while (q.empty() == 0)
    {
        cur = q.front();
        q.pop();
        a[++cnt] = cur;
        for (int i = 0; i < G[cur].size(); ++i)
        {
            nxt = G[cur][i];
            in[nxt]--;
            if (in[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    // for (int i = 1; i <= cnt; ++i)
    // {
    //     cout << (char)a[i];
    // }
    if (cnt != m)
    {
        printf("Impossible");
    }
    else
    {
        for (int i = 1; i <= cnt; ++i)
        {
            cout << (char)a[i];
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (vis[i] == 0)
            {
                cout << (char)i;
            }
        }
    }
    return;
}

void yunosuke(string s)
{
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        int qwq = s[i];
        if (vis[qwq] == 0)
        {
            ++m;
        }
        vis[qwq] = 1;
    }
    return;
}

int main()
{
    scanf("%d", &n);
    cin >> s;
    yunosuke(s);
    for (int i = 2; i <= n; ++i)
    {
        flag = 0;
        cin >> ss;
        yunosuke(ss);
        len = min(s.length(), ss.length());
        // cout << len << "\n";
        for (int j = 0; j < len; ++j)
        {
            if (s[j] != ss[j])
            {
                G[s[j]].push_back(ss[j]);
                ++in[ss[j]];
                flag = 1;
                break;
            }
        }
        if (flag == 0 && s.length() > ss.length())
        {
            printf("Impossible");
            return 0;
        }
        s = ss;
    }

    toposort();
    return 0;
}