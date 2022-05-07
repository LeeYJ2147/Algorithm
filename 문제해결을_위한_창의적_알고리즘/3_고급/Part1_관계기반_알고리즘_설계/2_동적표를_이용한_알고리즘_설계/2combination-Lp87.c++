#include <stdio.h>

int DT[31][31];

int f(int n, int k)
{
    if(n == k || !k) return 1; // return 1 말고 DT[n][k] = 1
    else if(k == 1) return n; // return n 말고 DT[n][k] = n
    else if(!DT[n][k])
        DT[n][k] = f(n-1, k) + f(n-1, k-1);
    return DT[n][k];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", f(n, k));
    return 0;
}



/* 재귀함수 + 동적표
#include <cstdio>

int DT[31][31];

int f(int n, int k)
{
    if(k==n) DT[n][k] = 1;
    else if(k==1) DT[n][k] = n;
    else
    {
        if(!DT[n][k])
            DT[n][k] = f(n-1, k-1) + f(n-1, k);
    }
    return DT[n][k];
}

int main()
{
    int n, kl;
    scanf("%d %d", %n, %k);
    printf(%d\n", f(n, k));
    return 0;
}
*/

/* 반복문 + 동적표
#include <cstdio>

int DT[31][31];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k && j<=i; j++)
        {
            if(i==j) DT[i][j] = 1;
            else if(j==1) DT[i][j] = i;
            else DT[i][j] = DT[i-1][j-1] + DT[i-1][j];
        }
    }
    printf("%d\n", DT[n][k]);
    return 0;
}
*/


/* 상향식 (다이나미컬 백트래킹)
#include <cstdio>

int N, K, DT[31][31];

int f(int n, int k)
{
    if(k==K) return 1;
    if(n==N) return 0;
    if(!DT[n][k])
        DT[n][k] = f(n+1, k+1) + f(n+1, k);
    return DT[n][k];
}

int main()
{
    scanf("%d %d", &N, &K);
    printf("%d\n", f(0, 0));
    return 0;
}
*/