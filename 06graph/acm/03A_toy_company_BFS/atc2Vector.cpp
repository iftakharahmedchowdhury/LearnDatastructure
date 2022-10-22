#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

string startS, endS;
vector<string> vt; // for storing forbidden char
map<string, int> visited;

int bfs()
{

    queue<string> q;
    q.push(startS);
    int res = 0;
    while (!q.empty())
    {
        res++;
        int size = q.size();

        while (size--)
        {
            string currentWord = q.front();
            q.pop();
            for (int i = 0; i < currentWord.size(); i++)
            {

                string t1 = currentWord;
                string t2 = currentWord;
                t1[i] = (char)((currentWord[i] - 'a' + 1) % 26 + 'a');
                t2[i] = (char)((currentWord[i] - 'a' - 1 + 26) % 26 + 'a');

                if ((count(vt.begin(), vt.end(), t1)))

                {
                    continue;
                }

                if (!(count(vt.begin(), vt.end(), t1)) && t1 == endS || !(count(vt.begin(), vt.end(), t2)) && t2 == endS)

                {

                    return res;
                }
                if (!(count(vt.begin(), vt.end(), t1)) && visited[t1] == 0)

                {
                    q.push(t1);
                    visited[t1] = 1;
                }
                if (!(count(vt.begin(), vt.end(), t2)) && visited[t2] == 0)

                {
                    q.push(t2);
                    visited[t2] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{

    int t, cs = 0;

    cin >> t;
    while (t--)
    {
        cin >> startS >> endS;
        int x;
        cin >> x;
        string s1, s2, s3;

        for (int f = 0; f < x; f++)
        {

            cin >> s1 >> s2 >> s3;

            for (int i = 0; i < s1.size(); i++)
            {
                for (int j = 0; j < s2.size(); j++)
                {
                    for (int g = 0; g < s3.size(); g++)
                    {
                        string sr = "";
                        sr += s1[i];
                        sr += s2[j];
                        sr += s3[g];
                        vt.push_back(sr);
                    }
                }
            }
        }
        cout << "Case " << ++cs << ": ";
        if ((count(vt.begin(), vt.end(), startS)))
        {
            cout << "-1" << endl;
        }

        else if (startS == endS)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << bfs() << endl;
        }
        vt.clear();
        visited.clear();
    }
}
