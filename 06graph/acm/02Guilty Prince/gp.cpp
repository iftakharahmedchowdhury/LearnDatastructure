#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

char graph[20][20]; // said that not more than 20
bool visited[20][20];
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
int countPlace = 0;
int w, h;

bool valid(int x, int y)
{
    // cout<<"valid"<<endl;
    if (x >= 0 && y >= 0 && x < h && y < w && graph[x][y] != '#' && visited[x][y] != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int DFS(int a, int b)
{
    // cout<<"DFS"<<endl;
    visited[a][b] = 1;
    countPlace++;

    for (int i = 0; i < 4; i++)
    {
        int x = a + dirX[i];
        int y = b + dirY[i];

        if (valid(x, y))
        {
            DFS(x, y);
        }
    }
    return countPlace;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--)
    {
        cs++;
        countPlace = 0;
        memset(visited,0,sizeof(visited));

        cin >> w >> h;
        int f, g;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == '@')
                {
                    f = i;
                    g = j;
                    // cout<<"if"<<endl;
                }
                // cout<<"for-2"<<endl;
            }
           // cout << "for - 1" << endl;
        }

        DFS(f, g);
        cout << "Case " << cs << ": " << countPlace << endl;
    }
}
