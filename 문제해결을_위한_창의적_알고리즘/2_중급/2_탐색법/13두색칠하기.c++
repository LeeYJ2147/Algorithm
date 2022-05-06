//I solved this perfectively!!!!!
#include <stdio.h>

int n, m, S[201][201], v[201];

void input(void)
{
    scanf("%d\n%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        S[x][y] = 1;
        S[y][x] = 1;
    }
    v[0] = 1;
}

bool solve()
{
    for(int i=0; i<n; i++) for(int j=i; j<n; j++)
    {
        if(S[i][j])
        {
            if(!v[j])
            {
                if(v[i] == 1) v[j] = 2;
                else v[j] = 1;
            }
            else if(v[i] == v[j]) return false;
        }
    }
    return true;
}

int main()
{
    input();
    if(solve() == false) printf("IMPOSSIBLE");
    else printf("OK");
}







/*
1. 인접행렬
#include <stdio.h>

int n, m, G[200][200], visited[200];

void solve(int v, int c)
{
    visited[v] = c;
    int can = 1;
    for(int i=0; i<n; i++)
        if(G[v][i] && visited[i] == c) can=0;
    
    if(!can)
    {
        visited[v] = 0;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && G[v][i])
        {
            solve(i, 1);
            solve(i, 2);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        G[s][e] = G[e][s] = 1;
    }
    solve(0, 1);
    for(int i=0; i<n; i++)
        if(visited[i] == 0)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
    printf("OK");
    return 0;
}



2. 인접리스트
#include <stdio.h>
#include <vector>

int n, m, visited[200];
std::vector<int> G[200];

void solve(int v, int c)
{
    visited[v] = c;
    int can = 1;
    for(int i=0l; i<G[v].size(); i++)
        if(visited[G[v][i]] == c) can = 0;
    if(!can)
    {
        visited[v] = 0;
        return 0;
    }
    for(int i=0l i<G[v].size(); i++)
    {
        if(!visited[G[v][i]])
        {
            solve(G[v][i], 1);
            solve(G[v][i], 2);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        G[s].push_back(e);
        G[e].push_back(s);
    }
    solve(0, 1);
    for(int i=0; i<n; i++)
        if(visited[i] == 0)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
    printf("OK");
    return 0;
}
*/