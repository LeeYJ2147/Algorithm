//O(2 ^n)
#include <stdio.h>

int n, M, m[101], c[101], DT[101][101];

int min(int a, int b) {return a<b?a:b;}

int f(int i, int r)
{
    if(i == n)
    {
        if(r <= 0) return 0;
        else return 987654321;
    }
    else if(r < 0) return 0;
    else
    {
        if(!DT[i][r]) DT[i][r] = min(f(i+1, r), f(i+1, r-m[i])+c[i]);
        return DT[i][r];
    }
}

int main()
{
    scanf("%d %d", &n, &M);
    for(int i=0; i<n; i++) scanf("%d", &m[i]);
    for(int i=0; i<n; i++) scanf("%d", &c[i]);
    printf("%d", f(0, M));
    return 0;
}

/*O(n ^2)
#include <stdio.h>

int n, M, m[101], c[101];
int DT[101][10001];
int max(int a, int b) {return a>b ? a:b;}
int main()
{
    int i, j, res = 100000;
    scanf("%d %d", &n, &M);
    for(i=1; i<=n; i++) scanf("%d", &m[i]);
    for(i=1; i<=n; i++) scanf("%d", &c[i]);

    for(i=1; i<=n; i++)
        for(j=0; j<=100*n; j++)
            if(j>=c[i])
                DT[i][j] = max(DT[i-1][j], DT[i-1][j-c[i]]+m[i]);
            else
                DT[i][j]=DT[i-1][j];
    
    for(j=0; j<=100*n; j++)
        if(DT[n][j]>=M && res > j)
            res = j;
    
    printf("%d", res);
    return 0;
}
*/