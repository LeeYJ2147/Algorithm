// 하향식 설계
#include <cstdio>

int n, w, DT[102][10002], w[102], v[102];

int max(int a, int b) {return a>b?a:b;}

int f(int i, int r)
{
    if(DT[i][r] != -1) return DT[i][r];
    if(i == n+1) return DT[i][r] = 0;
    else if(r < w[i]) return DT[i][r] = f(i+1, r);
    else return DT[i][r] = max(f(i+1, r), f(i+1, r-w[i])+v[i]);
}

int main()
{
    scanf("%d %d", &n, &w);
    for(int i=1; i<n; i++) scanf("%d %d", &w[i], &v[i]);
    for(int i=0; i<=100; i++) for(int j=0; j<=10000; j++) DT[i][j] = -1;
    printf("%d", f(1, w));
    return 0;
}





/* 상향식 설계
#include <stdio.h>

int DT[102][10002];
int w[102], v[102], i, j, n, W;

int max(int a, int b) {return a>b?a:b;}

int main()
{
    scanf("%d %d", &n, &W);
    for(i=1; i<=n; i++) scanf("%d %d", &w[i], &v[i]);

    for(i=n; i>=1; i--)
    {
        for(j=0; j<=W; j++)
            if(j<w[i]) DT[i][j] = DT[i+1][j];
            else DT[i][j] = max(DT[i+1][j], DT[i+1][j-w[i]]+v[i]);
    }
    printf("%d", DT[1][W]);
    return 0;
}
*/