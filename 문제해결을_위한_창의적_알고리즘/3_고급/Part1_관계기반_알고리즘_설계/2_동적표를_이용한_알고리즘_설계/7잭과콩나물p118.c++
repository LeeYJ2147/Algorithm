#include <stdio.h>

int n, m, a, b, X, Y, p[501];
int DT[501][101];

int positive(int a) {return a>0 ? a:-a;}

int min(int a, int b) {return a>b ? b:a;}

int f(int i, int s)
{
    if(!DT[i][s])
    {
        if(i == m) DT[i][s] = positive(s-b)*Y;
        else if(p[i] == s)
            DT[i][s] = min( f(i+1, s+1), f(i+1, s) + X);
        else if(p[i+1] == s)
            DT[i][s] = min( f(i+1, s-1), f(i+1, s) + X);
        else
            DT[i][s] = f(i+1, s);
    }
    return DT[i][s];
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &X, &Y);
    for(int i=0; i<m; i++) scanf("%d", &p[i]);
    printf("%d\n", f(0, a));
    return 0;
}