#include <cstdio>

int f(int a, int b)
{
    if(a==b) return 0;
    else if(a>b) return (f(a/2, b)+1);
    else return (f(a, b/2)+1);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", f(a, b));
    return 0;
}