#include <cstdio>

char star[10001];

void f(int n)
{
    if(!n) return;
    f(n-1);
    star[n] = '*';
    puts(star + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}
/*f(n) : f(n-1), '*' n개 출력
#include <cstdio>

void f(int n)
{
    if(n==1)
        printf("*\n");
    else
    {
        f(n-1);
        for(int i=0; i<n; i++)
            printf("*");
        puts("");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}
*/






/* 위는 1일 때를 설정, 지금은 양수일 때로 설정
#include <cstdio>

void f(int n)
{
    if(n>0)
    {
        f(n-1);
        for(int i=0; i<n; i++)
            printf("*");
        puts("");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}
*/



/*printf를 축약시킨 버전
#include <cstdio>
#define MAXN 10000

char star[MAXN+1];

void f(int n)
{
    if(n>0)
    {
        f(n-1);
        star[n] = '*';
        puts(star+1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}
*/