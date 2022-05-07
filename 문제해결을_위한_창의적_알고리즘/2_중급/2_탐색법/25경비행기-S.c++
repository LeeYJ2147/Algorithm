#include <stdio.h>
#include <math.h>

int n, k, v[11], dmin=2000000000;

struct air {int x;  int y;} a[11];
int max(int a, int b) {return a>b ? a:b;}

int dist(int p1, int p2)
{
    return(a[p1].x - a[p2].x) * (a[p1].x-a[p2].x) + (a[p1].y-a[p2].y) * (a[p1].y - a[p2].y);
}

void f(int p, int c, int d)
{
    if(c == k)
    {
        d = max(d, dist(p, n+1));
        if(d < dmin) dmin = d;
        return;
    }
    
}