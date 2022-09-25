#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define endl '\n'

#include <bits/stdc++.h>
using namespace std;

char graph[100][100];
int u, w;

bool visited[100][100];

int dirX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dirY[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y)
{
    // countStepst<<"valid"<<endl;
    if (x >= 0 && y >= 0 && x < u && y < w && graph[x][y] == '@' && !visited[x][y])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bfs(int x, int y)
{
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    visited[x][y] = true;

    while (!Q.empty())
    {

        int xQueueFV = Q.front();
        Q.pop();
        int yQueueFV = Q.front();
        Q.pop();
        visited[xQueueFV][yQueueFV] = true;

        for (int i = 0; i < 8; i++)
        {
            int x1 = xQueueFV + dirX[i];
            int y1 = yQueueFV + dirY[i];
            if (valid(x1, y1))
            {
                visited[x1][y1] = true;
                Q.push(x1);
                Q.push(y1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool t = true;

    while (t)
    {

        int countSteps = 0;
        memset(visited, false, sizeof(visited));

        cin >> u >> w;
        if (u == 0 && w == 0)
        {
            return 0;
        }

        for (int ii = 0; ii < u; ii++)
        {

            for (int jj = 0; jj < w; jj++)
            {
                cin >> graph[ii][jj];
            }
        }

        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (graph[i][j] == '@' && !visited[i][j])
                {
                    bfs(i, j);
                    countSteps++;
                }
            }
        }

        cout << countSteps << endl;
    }
}
