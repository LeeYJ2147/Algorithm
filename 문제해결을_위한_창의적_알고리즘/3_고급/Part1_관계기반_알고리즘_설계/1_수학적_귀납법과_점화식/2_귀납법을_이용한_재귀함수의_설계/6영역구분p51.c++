#include <cstdio>

int S[1<<7][1<<7];
int N, white, gray;

void f(int x, int y, int n)
{
    bool isOne = 1;
    for(int i=x; i<n+x; i++)
        for(int j=y; j<n+y; j++)
        {
            if(S[x][y] != S[i][j]) isOne=0;
            break;
        }
    if(isOne)
    {
        if(S[x][y]) white++;
        else gray++;
        return;
    }
    else
    {
        f(x, y, n/2);
        f(x+n/2, y, n/2);
        f(x, y+n/2, n/2);
        f(x+n/2, y+n/2, n/2);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &S[i][j]);
    f(0, 0, N);
    printf("%d\n%d\n", gray, white);
    return 0;
}
/* f(a, b, c, 0 or 1) 0은 하얀색 종이, 1은 회색 종이
#include <cstdio>

int P[1<<7][1<<7], n;

bool isOne(int a, int b, int s, int v)
{
    for(int i=a; i<a+s; i++)
        for(int j=b; j<b+s; j++)
            if(P[i][j] != v) return false;
    return true;
}

int f(int a, int b, int s, int v)
{
    if(s==1) return P[a][b] == v;
    if(isOne(a, b, s, v)) return 1;
    return f(a, b, s/2, v)+f(a+s/2, b, s/2, v)+f(a, b+s/2, s/2, v)+f(a+s/2, b+s/2, s/2, v);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &P[i][j]);
    printf("%d\n%d\n", f(0, 0, n, 0), f(0, 0, n, 1));
}
*/