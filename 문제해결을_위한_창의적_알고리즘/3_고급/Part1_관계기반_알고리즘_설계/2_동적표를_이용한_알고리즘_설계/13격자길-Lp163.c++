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