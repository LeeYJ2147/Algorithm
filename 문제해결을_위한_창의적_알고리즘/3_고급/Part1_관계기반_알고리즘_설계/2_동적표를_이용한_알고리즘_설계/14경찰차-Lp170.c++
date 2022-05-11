#include <cstdio>

struct w{int x; int y;} acc[16]; //E[1010][2]라고 하면 E[]

int m, n, DT[16][16];

int min(int a, int b) {return a<b?a:b;}
int abs(int a) {return a>0?a:-a;}

int dis(int a, int b)
{
    return abs(acc[a].x-acc[b].x)+abs(acc[a].y-acc[b].y);
}

int f(int a, int b)
{
    if(!DT[a][b])
    {
        int next=(a>b?a:b)+1;
        if(next > m+1) return DT[a][b]=0;
        else DT[a][b] = min(f(next,b)+dis(next,b),f(a,next)+dis(a,next));
    }
    return DT[a][b];
}

int main()
{
    scanf("%d %d", &n, &m);
    acc[0].x=1, acc[0].y=1;
    acc[1].x=n, acc[1].y=n;
    for(int i=2; i<m+2; i++)
        scanf("%d %d", &acc[i].x, &acc[i].y);
    printf("%d\n", f(0, 1));
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f

int E[1010][2], n, m, ans=INF, DT[1100][1100];

int min(int a, int b){ return a>b ? b:a;}
int abs(int a){ return a>0 ? a:-a;}

int dist(int a, int b)
{
    return abs(E[a][0]-E[b][0])+abs(E[a][1]-E[b][1]);
}

int main()
{
    scanf("%d %d", &n, &m);
    E[0][0]=E[0][1]=1, E[1][0]=E[1][1]=n;
    for(int i=2; i<m+2; i++)
        scanf("%d %d", &E[i][0], &E[i][1]);
    memset(DT, 0x3f, sizeof(DT)), DT[0][1]=0;
    for(int i=0; i<m+2; i++)
    for(int j=1; j<m+2; j++)
    {
        if(i==j) DT[i][j]==INF;
        else if(i>j)
        {
        if(i-1>j) DT[i][j]=DT[i-1][j]+dist(i-1,i);
        else for(int k=0; k<j; k++)
            DT[i][j]=min(DT[i][j],DT[k][j]+dist(k,i));
        }
        else
        {
        if(j-1>i) DT[i][j]= DT[i][j-1]+dist(j-1,j);
        else for(int k=1; k<i; k++)
            DT[i][j]=min(DT[i][j],DT[i][k]+dist(k,j));
        }
    }
    for(int i=0; i<m+2; i++)
    ans = min(ans, min(DT[i][m+1], DT[m+1][i]));
    printf("%d\n", ans);
    return 0
}
*/