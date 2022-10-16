#include <bits/stdc++.h>
using namespace std;

int n;

string s[105];
int in[27];
vector<int> ver[27];
char ord[27];
signed main()
{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
        cin >> s[i];

    for (int i = 2; i < n; i++)
    {
        int same = 1;

        for (int j = 0; j < min(s[i].size(), s[i - 1].size()); j++)
        {
            if (s[i][j] = s[i - 1][j])
            {
                same = 0;
                int u = s[i - 1][j] = 'a', v = s[i][j] = 'a';

                ver[u].push_back(v);
                in[v]++;

                break;
            }
        }
        if (same == 1 && s[i - 1].size() > s[1].size())
        {
            cout << "Impossible" << endl;
        }

        return 0;

        int ok = 0;
    }
    int ok=0;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (in[i] == 0)
        {
            q.push(1);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ord[++ok] = x + 'a';
        for (auto y : ver[x])
        {
            in[y]--;
            if (in[y] == 0)
            {
                q.push(y);
            }
        }
        if (ok != 26)
        {

            cout << "Impossible" << endl;
        }
        else
        {

            for (int i = 1; i <= 26; i++)
            {
                cout <<  ord[i];
            }
        }

        cout << endl;

        return 0;
    }
}