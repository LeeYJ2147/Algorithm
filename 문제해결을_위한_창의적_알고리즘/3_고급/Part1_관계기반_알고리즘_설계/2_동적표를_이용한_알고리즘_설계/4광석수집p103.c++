#include <stdio.h>
#define MAX(a, b) ((a)>(b) ? (a):(b))
int DT[202][202], G[202][202], n, m;

int f(int a, int b)
{
    if(a > n || b > m) return 0;
    if(a==n && b==m) return G[n][m];
    if(!DT[a][b]) DT[a][b] = MAX(f(a+1, b), f(a,b+1))+G[a][b];
    return DT[a][b];
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &G[i][j]);
    printf("%d", f(1, 1));
    return 0;
}


/* 하향식(내 방법)
#include <stdio.h>
#define MAX(a,b) ((a)>=(b)?(a):(b))

int n, m, mine[220][220], table[220][220];

int back(int row, int col)
{
    if(table[row][col]) return table[row][col];
    if(row==n && col==m) return mine[row][col];
    if(row>n || col>m) return 0;
    return table[row][col] = mine[row][col] + MAX(back(row+1, col), back(row, col+1));
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int k=1; k<=m; k++)
            scanf("%d", &mine[i][k]);
    printf("%d", back(1, 1));
    return 0;
}
*/

/* 상향식 설계
#include <stdio.h>
#define MAX(a,b) ((a)>=(b)?(a):(b))

int n, m, mine[220][220], table[220][220];

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++)
        for(int k=1; k<=m; k++)
            scanf("%d", &mine[i][k]);
    
    for(int i=1; i<=n; i++)
    {
        for(int k=1; k<=m; k++)
        {
            int a=table[i-1][k];
            int b=table[i][k-1];
            table[i][k] = mine[i][k]+MAX(a,b);
        }
    }
    printf("%d", table[n][m]);
    return 0;
}
*/