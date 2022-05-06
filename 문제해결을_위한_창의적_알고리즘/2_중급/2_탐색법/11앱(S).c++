#include <stdio.h>
#define MAXV 999999

int n, M;
//n은 실행되는 앱의 수, M은 목표 바이트 수
int m[101], c[101];
//m은 각 앱의 바이트 수, c는 비활성화 비용
int check[101];
//check는 반복할 때 왔는지 확인, min은 최소비용-답-
int byte=0;

int min(int a, int b) { return a<b ? a:b;}

void input(void)
{
    scanf("%d %d", &n, &M);
    for(int i=0; i<n; i++) scanf("%d", &m[i]);
    for(int i=0; i<n; i++) scanf("%d", &c[i]);
}

int solve(int i, int r)
{
    if(i == 0)
    {
        if(r <= 0) return 0;
        else return MAXV;
    }
    else if(r < 0)
        return f(i-1, r);
    else
        return min(f(i-1, r), f(i-1, r-m[i]) + c[i]);
}

int main()
{
    input();
    printf("%d", solve(n, M));
    return 0;
}