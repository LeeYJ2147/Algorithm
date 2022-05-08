/*
1
f(a, b) : a번째를 탐색중이고, b개의 색을 고른 경우라고하면
f(a, b) = f(a+2,b+1) + f(a+1, b)라는 관계가 성립하므로
visit, visited가 필요없어짐
+ 동적표 추가가 가능해져서 시간절약도 됨

2
f(n, k) =
0 (k > n/2) // 조건에 성립 X
n (k=1) // n개를 전부 1번씩 고르면 되기 때문
f(n-2, k-1) + f(n-1, k) (otherwise) // (n번째 선택, 고를 개수-1) + (n번째 선택X, 고를개수 그대로)
*/
#include <stdio.h>
#define MAX 1000000003

int visited[1002], n, ans=0;

void visit(int x, int a)
{
    if(x>1 && x<n)
    {
        visited[x-1] += a;
        visited[x+1] += a;
    }
    else if(x == 1)
    {
        visited[2] += a;
        visited[n] += a;
    }
    else
    {
        visited[1] += a;
        visited[n-1] += a;
    }
    return;
}

void solve(int s, int k)
{
    if(!k)
    {
        printf("ans update at : %d %d\n", s, k);
        ans++;
        return;
    }
    if(s == n) return;
    for(int i=s+1; i<=n; i++)
        if(!visited[i])
        {
            visit(i, 1);
            solve(i, k-1);
            visit(i, -1);
        }
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        visit(i, 1);
        solve(i, k-1);
        visit(i, -1);
    }
    printf("%d\n", ans);
    return 0;
}


/* 1. 다이내미컬 백트래킹
#include <cstdio>
#include <memory.h>
#define MOD 1000000003

int n, k;
int DT[1001][1001][2];

int f(int a, int b)
{
    if(a>=n || b==k)
        return (int)(b==k);
    else if(DT[a][b] == -1)
        DT[a][b]=(f(a+1,b)+f(a+2,b+1))%MOD;
    return DT[a][b];
}

int main()
{
    memset(DT, -1, sizeof(DT));
    scanf("%d %d", &n, &k);
    printf("%d\n", (f(1, 0)+f(3, 1))%MOD);
    return 0;
}
*/


/* 2-1. 재귀함수만 적용
#include <cstdio>
#define MOD 1000000003

int f(int n, int k)
{
    if(k>n/2) return 0;
    else if(k==1) return n;
    else return (f(n-2,k-1)+f(n-1,k))%MOD;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n,k));
    return 0;
}
*/

/* 2-2. 동적표 적용
#include <cstdio>
#define MOD 1000000003

int DT[1001][1001];

int f(int n, int k)
{
    if(k>n/2) DT[n][k]=0;
    else if(k==1) DT[n][k]=n;
    else
    {
        if(!DT[n][k])
            DT[n][k]=(f(n-2,k-1)+f(n-1,k))%MOD;
    }
    return DT[n][k];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n,k));
    return 0;
}
*/

/* 2-3 상향식 알고리즘
#include <cstdio>
#define MOD 1000000003

int DT[1001][1001]

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=2; i<=n; i++) //i=1이면 j<=1/2, j까지 안 가므로 애초에 2부터 실행
        for(int j=1; j<=n/2; j++) //k>n/2이면 0을 반환하므로 애초에 j<=n/2까지만 반복하게 함
            if(j==1) DT[i][j]=i;
            else DT[i][j]=(DT[i-2][j-1]+DT[i-1][j])%MOD;
    printf("%d\n", DT[n][k]);
    return 0;
}
*/