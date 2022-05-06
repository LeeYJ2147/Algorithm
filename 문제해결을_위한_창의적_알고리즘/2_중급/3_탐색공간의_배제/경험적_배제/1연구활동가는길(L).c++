#include <stdio.h>
int n, m, min=0xfffffff, map[101][101], visited[101];

void f(int num, int move)
{
    if(num == n)
    {
        if(move < min) min = move;
        return;
    }
    if(move > min) return;
    for(int i=1; i<=n; i++)
        if(map[num][i] && !visited[i])
        {
            visited[i] = 1;
            f(i, move + map[num][i]);
            visited[i] = 0;
        }
}

int main()
{
    int x, y, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++)
    {
        scanf("%d %d %d", &x, &y, &k);
        map[x][y] = map[y][x] = k;
    }
    f(1, 0);
    printf("%d\n", min == 0xfffffff ? -1:min);
    return 0;
}

/*
#include <stdio.h>
int n, m, G[11][11], sol=0x7fffffff, chk[11];

void solve(int V, int W)
{
    if(W>sol) return;
    if(V==n)
    {
        if(W<sol) sol = W;
        return;
    }
    for(int i=1; i<=n; i++)
        if(!chk[i] && G[V][i])
        {
            chk[i]=1;
            solve(i, W+G[V][i]);
            chk[i]=0;
        }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        G[s][e] = G[e][s] = w;
    }
    solve(1, 0);
    printf("%d\n", sol==0x7fffffff ? -1:sol);
    return 0;
}
*/
/* 단순탐욕법 추가 / 수학적으로 가장 유리한 상태만을 골라서 답 하나 추적
#include <stdio.h>
int n, m, G[1001][1001], sol, chk[1001], greedy_chk[1001];

void greedy_ans(int V)
{
    int W=0; t;
    greedy_chk[V]=1;
    while(V != n)
    {
        int min = 0x7fffffff;
        for(int i=1; i<=n; i++)
            if(!greedy_chk[i] && G[V][i] && G[V][i] < min)
            {
                greedy_chk[i] = 1;
                min = G[V][i];
                t=i;
            }
        sol += G[V][t];
        V = t;
    }
}

void solve(int V, int W)
{
    if(W>sol) return;
    if(V==n)
    {
        if(W<sol) sol = W;
        return;
    }
    for(int i=1; i<=n; i++)
        if(!chk[i] && G[V][i])
        {
            chk[i]=1;
            solve(i, W+G[V][i]);
            chk[i] = 0;
        }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        G[s][e] = G[e][s] = w;
    }
    greedy_ans(1);
    solve(1, 0);
    printf("%d\n", sol==0x7fffffff ? -1:sol);
    return 0;
}
*/