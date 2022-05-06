#include <stdio.h>

int n, w, ans = 0xfffffff, dis[2]; //n은 길이, w는 처리사건개수 
struct j{int x; int y;};
j p[2], to[16], temp[16];

void solve(int num, int move, int W, int x, int y, int nx, int ny)
{
    if(nx - x > 0) move += nx - x;
    else move -= nx - x;
    if(ny - y > 0) move += ny - y;
    else move -= ny - y;

    p[num].x = x;
    p[num].y = y;

    if(W == w)
    {
        if(ans > move) ans = move;
    }
    else
    {
       temp[W] = p[0];
        solve(0, move, W+1, to[W].x, to[W].y, p[0].x, p[0].y);
        p[0] = temp[W];
        temp[W] = p[1];
        solve(1, move, W+1, to[W].x, to[W].y, p[1].x, p[1].y);
        p[1] = temp[W];
    }
}

int main()
{
    scanf("%d %d", &n, &w);
    p[0].x = 1, p[0].y = 1;
    p[1].x = n, p[1].y = n;
    for(int i = 0; i<w; i++)
        scanf("%d %d", &to[i].x, &to[i].y);
    temp[0] = p[0];
    solve(0, 0, 1, to[0].x, to[0].y, p[0].x, p[0].y);
    p[0] = temp[0];
    temp[0] = p[1];
    solve(1, 0, 1, to[0].x, to[0].y, p[1].x, p[1].y);
    temp[0] = p[1];
    printf("%d", ans);
}



/*
#include <stido.h>

int E[1010][2], n, m, ans = 987654321, dis[1002][1002];

int min(int a, int b)
{
    return a>b ? b:a;
}
int abs(int a)
{
    return a>0 ? a:-a;
}
int dis(int a, int b)
{
    return abs(E[a][0] - E[b][0]) + abs(E[a][1] - E[b][1]);
}
void solve(int a, int b, int d)
{
    int next = (a>b ? a:b)+1;
    if(next >= m+2)
    {
        if(d<ans) ans = d;
        return;
    }
    solve(next, b, d+dis[a][next]);
    solve(a, next, d+dis[b][next]);
}
int main()
{
    scanf("%d%d", &n, &m);
    E[0][0] = E[0][1] = 1;
    E[1][0] = E[1][1] = n;
    for(int i=2; i<m+2; i++)
        scanf("%d%d", &E[i][0], &E[i][1]);
    for(int i=0; i<m+2; i++)
        for(j=0; j<m+2; j++)
            dis[i][j] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
    solve(0, 1, 0);
    printf("%d"< ans);
    return 0;
}