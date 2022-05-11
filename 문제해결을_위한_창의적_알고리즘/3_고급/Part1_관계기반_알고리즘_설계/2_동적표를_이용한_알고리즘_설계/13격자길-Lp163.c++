#include <cstdio>

int DT[101][101];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    DT[0][0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=m*i/n; j++)
        {
            if(j <= m*(i-1)/n) DT[i][j] = DT[i-1][j]+DT[i][j-1];
            else DT[i][j] = DT[i][j-1];
        }
    printf("%d\n", DT[n][m]);
    return 0;
}

//이전에 해결한 방법 + 동적표
/*
#include <cstdio>

int n, m, DT[110][110];

bool Available(int a, int b)
{
    return (!b || (double)n/m<=(double)a/b);
}

int f(int a, int b)
{
    if(DT[a][b]==0)
    {
        if(a>n || b>m || !Available(a,b)) DT[a][b]=0;
        else if(a==n && b==m) DT[a][b]=1;
        else DT[a][b]=f(a+1,b)+f(a,b+1);
    }
    return DT[a][b];
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%d\n", f(0,0));
    return 0;
}
*/

//하향식 재귀함수 + 메모이제이션
/*
#include <cstdio>

int n, m, DT[110][110];

bool Available(int a, int b)
{
    return (!b || (double)n/m<=(double)a/b);
}

int f(int a, int b)
{
    if(DT[a][b]==0)
    {
        if(a==0 && b==0) DT[a][b]=1;
        else if(!Available(a,b)) DT[a][b]=0;
        else DT[a][b]=f(a-1,b)+f(a,b-1);
    }
    return DT[a][b];
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%d\n", f(n,m));
    return 0;
}
*/

//상향식
/*
#include <cstdio>

int n, m =, DT[110][110];

bool Available(int a, int b)
{
    return (!b || (double)n/m<=(double)a/b);
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            if(i==0 && j==0) DT[i][j]=1;
            else if(!Available(i, j)) DT[i][j]=0;
            else DT[i][j]=DT[i-1][j]+DT[i][j-1];
    printf("%d\n", DT[n][m]);
    return 0;
}
*/