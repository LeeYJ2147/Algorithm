#include <stdio.h>

char a[81] = '12131214121312151213121412131216121312141213121512131214121312171213121412131215';

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        printf("%d", a[i]);
    return 0;
}







/*
#include <stdio.h>
int s[81];
int n, end=0;

bool same(int a, int b)
{
    int i;
    for(i=a; i<b; i++)
        if(s[i]!=s[i+b-a])
            break;
    return (a==b ? false:i==b);
}

int good(int m)
{
    int i, j;
    for(i = m-1, j=m; i>0; i-=2, j-=1)
        if(same(i, j))
            return 0;
    return 1;
}

void solve(int k)
{
    if(end) return;
    if(k>n)
    {
        end = 1;
        for(int i=1; i<=n; i++)
            printf("%d", s[i]);
        return;
    }
    for(int i=1; i<=3; i++)
    {
        s[k]=i;
        if(good(k)) solve(k+1);
        s[k] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    solve(1);
    return 0;
}