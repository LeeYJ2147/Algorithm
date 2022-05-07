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
