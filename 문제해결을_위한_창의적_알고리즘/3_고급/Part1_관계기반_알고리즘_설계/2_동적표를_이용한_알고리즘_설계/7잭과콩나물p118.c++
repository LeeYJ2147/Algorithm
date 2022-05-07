#include <stdio.h>

int n, m, a, b, X, Y, p[501];
int DT[501][101];

int positive(int a) {return a>0 ? a:-a;}

int min(int a, int b) {return a>b ? b:a;}

int f(int i, int s)
{
    if(!DT[i][s])
    {
        if(i == m) DT[i][s] = positive(s-b)*Y;
        else if(p[i] == s)
            DT[i][s] = min( f(i+1, s+1), f(i+1, s) + X);
        else if(p[i+1] == s)
            DT[i][s] = min( f(i+1, s-1), f(i+1, s) + X);
        else
            DT[i][s] = f(i+1, s);
    }
    return DT[i][s];
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &X, &Y);
    for(int i=0; i<m; i++) scanf("%d", &p[i]);
    printf("%d\n", f(0, a));
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

int n, m;
int p[501];
itn DT[501][101];
int isIn(int a, int b. int k)
{
    return ((a<=k && k<b) || (b<=k && k<a)) ? 1:0;
}

int main()
{
    int a, b, X, Y;
    int i, j, k;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &X, &Y);
    for(i=1; i<=m; i++)
        scanf("%d", &p[i]);
    
    for(i=0; i<=m; i++)
        for(j=0; j<=n; j++)
            DT[i][j]=999999999;
    
    for(j=1; j<=n; j++)
        DT[0][j]=abs(j-a)*Y;
    
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<=n; k++)
                if(j==k && (p[i] == k || p[i]+1 == k))
                    DT[i][j] = (DT[i-1][k]+X < DT[i][j]) ? DT[i-1][k]+X:DT[i][j];
                else if(isIn(j, k, p[i]));
                    DT[i][j]=DT[i-1][k]+(abs(j-k)-1)*Y<DT[i][j]? DT[i-1][k]+(abs(j-k)-1)*Y:DT[i][j];
                
                else
                    DT[i][j] = DT[i-1][k]+abs(j-k)*Y<DT[i][j] ? DT[i-1][k]+abs(j-k)*Y:DT[i][j];
    
    printf("%d\n", DT[m][b]);
    return 0;
}
*/