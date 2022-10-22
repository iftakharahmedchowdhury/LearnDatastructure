#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> nodeNeighbour[100002];
bool isVisited[100002] = {0};

int cs = 0;
int vam = 0;
int luk = 0;

void CLR()
{
    for (int i = 0; i < 100002; i++)
    {
     nodeNeighbour[i].clear();   
    }
     for (int i = 0; i < 100002; i++)
    {
     isVisited[i]=0;   
    }
    
}

void depthFirstSearch(int node)
{

    isVisited[node] = true;
    for (int n : nodeNeighbour[node])
    {
        if (isVisited[n])
        {
            vam++;
        }

        else if (!isVisited[n])
        {
            luk++;
            depthFirstSearch(n);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vam = 0;
        luk = 0;

        cs++;
        int edges;
        cin >> edges;

        int startnodeCount = 0;
        int startNode;
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            if (startnodeCount == 0)
            {
                startNode = u;
            }

            nodeNeighbour[u].push_back(v);
            nodeNeighbour[v].push_back(u);
        }

        depthFirstSearch(startNode);

        if (vam > luk)
        {
            cout << "Case " << cs << ": " << vam << endl;
        }
        else
        {
            cout << "Case " << cs << ": " << luk << endl;
        }

        CLR();
    }

    return 0;
}