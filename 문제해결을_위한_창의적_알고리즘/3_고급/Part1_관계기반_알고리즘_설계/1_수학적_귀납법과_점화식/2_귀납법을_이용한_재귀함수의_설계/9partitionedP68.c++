#include <cstdio>

char S[32];

void f(int left, int pre, int n)
{
    S[n] = pre;
    if(left <= 0)
    {
        for(int i=1; i<=n; i++) printf("%d ", S[i]);
        printf("\n");
        return;
    }
    else
    {
        for(int i=pre; i>0; i--)
            if(left >= i) f(left-i, i, n+1);
        return;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n, n, 0);
    return 0;
}



/*
#include <stdio.h>

int a[30], cnt;

int min(int a, int b)
{
    return a>b ? b:a;
}

void solve(int n, int k)
{
    if(n==0)
    {
        for(int i=0; i<cnt; i++)
            printf("%d ", a[i]);
        puts("");
        return;
    }
    for(int i=min(n, k); i>=1; i--)
    {
        a[cnt++] = i;
        solve(n-1, i);
        cnt--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(n, n);
    return 0;
}