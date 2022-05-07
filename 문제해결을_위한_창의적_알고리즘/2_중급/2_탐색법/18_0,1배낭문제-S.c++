#include <stdio.h>

int n, w, wi[101], vi[101], max;

void f(int i, int ws, int vs)
{
    if(ws > w) return;
    if(i == n && ws <= w)
    {
        if(max < vs) max = vs;
        return;
    }
    f(i+1, ws + wi[i], vs + vi[i]);
    f(i+1, ws, vs);
}

int main()
{
    scanf("%d %d", &n, &w);
    for(int i=0; i<n; i++)
        scanf("%d %d", &wi[i], &vi[i]);
    f(0, 0, 0);
    printf("%d", max);
    return 0;
}




/*
#include <stdio.h>

int W, n, i, j, w[102], v[102];

int max(int a, int b) {return a>b ? a:b;}

int f(int i, int r)
{
    if(i==n+1)
        return 0;
    else if(r<w[i])
        return f(i+1, r);
    else
        return max(f(i+1, r), f(i+1, r-w[i]) +v[i] )
}

int main()
{
    scanf("%d %d", &n, &W);
    for(int i=1; i<=n; i++)
        scanf("%d%d", &w[i], &v[i]);
    printf("%d"< f(1, W));
    return 0;
}