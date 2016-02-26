#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int n, m, j, dist[400], s, t;
char line[150], *tok;
vector<vi> AdjList;
queue<int> q;
vi p;

int bfs()
{
    dist[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=0 ; i<AdjList[u].size() ; i++)
        {
            int v = AdjList[u][i];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                p[v] = u;
                if (v == t) return dist[v];
                q.push(v);
            }
        }
    }
    return -1;
}

void printPath(int u)
{
    if (u == s) printf("%d", s+1);
    else
    {
        printPath(p[u]);
        printf(" %d", u+1);
    }
}

int main()
{
    while (scanf("%d\n", &n) == 1)
    {
        AdjList.assign(n, vi());
        for (int i=0 ; i<n ; i++)
        {
            gets(line);
            tok = strtok(line, " ,-");
            while ((tok = strtok(NULL, " ,-")) != NULL)
            {
                sscanf(tok, "%d", &j);
                j--;
                AdjList[i].push_back(j);
            }
        }
        printf("-----\n");
        scanf("%d\n", &m);
        while (m--)
        {
            scanf("%d %d\n", &s, &t);
            s--;
            t--;
            q = queue<int>();
            memset(dist, -1, sizeof dist);
            p.assign(n, -1);
            int res = bfs();
            if (res != -1)
                printPath(t);
            else
                printf("connection impossible");
            printf("\n");
        }
    }
}
