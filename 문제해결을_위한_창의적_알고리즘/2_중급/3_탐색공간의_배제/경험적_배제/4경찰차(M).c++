#include <stdio.h>

int n, w, count, howmany;
int c[18];

int positive(int a) { return a>0 ? a : -a; }

void greedy_ans(void)
{
    int fir=0, sec=1;
    for(int i=2; i<w+2; i++)
    {
        if(positive(c[i] - c[fir]) < positive(c[i] - c[sec]))
        {
            count += positive(c[i] - c[fir]);
            fir = i;
        }
        else
        {
            count += positive(c[i] - c[sec]);
            sec = i;
        }
    }
}

void solve(int Num1, int Num2, int dis, int num)
{
    howmany++;
    if(dis >= count)
    {
        printf("back traking\n\n");
        return;
    }
    printf("몇번째 사건 : %d\n총 이동거리 : %d\n\n", num, dis);
    if(num == w+2)
    {
        count = dis;
        return;
    }
    printf("출동경찰차 : 1번\n");
    solve(num+1, Num2, dis + positive(c[num+1] - c[Num1]), num+1);
    printf("출동경찰차 : 2번\n");
    solve(Num1, num+1, dis + positive(c[num+1] - c[Num2]), num+1);
}

int main()
{
    int x, y;
    scanf("%d%d", &n ,&w);
    c[0] = 2, c[1] = 2*n;
    for(int i=2; i<w+2; i++)
    {
        scanf("%d %d", &x, &y);
        c[i] = x+y;
    }
    greedy_ans();
    printf("greedy_ans : %d\n", count);
    printf("출동경찰차 : 1번\n");
    solve(2, 1, positive(c[2] - c[0]), 2);
    printf("출동경찰차 : 2번\n");
    solve(0, 2, positive(c[2] - c[1]), 2);
    printf("%d\nI visited : %d\n", count, howmany);
    return 0;
}

/* 현재까지의 이동 거리 > 현재까지의 최소 거리, 단순탐욕법 적용 X
#include <stdio.h>

int E[1010][2], n, m, ans=987654321;

int min(int a, int b)
{
    return a>b ? b:a;
}
int abs(int a)
{
    return a>0?a:-a;
}
int dis(int a, int b)
{
    return abs(E[a][0] - E[b][0]) + abs(E[a][1] - E[b][1]);
}

void solve(int a, int b, int d)
{
    int next = (a>b ? a:b)+1;
    if(d>ans) return;
    if(next > m+2)
    {
        if(d<ans) ans=d;
        return;
    }
    solve(next, b, d+dis(a, next));
    solve(a, next, d+dis(b, next));
}

int main()
{
    scanf("%d %d", &n, &m);
    E[0][0] E[0][1] = 1;
    E[1][0] E[1][1] = n;
    for(int i=2; i<m+2; i++)
        scanf("%d%d", &E[i][0], &E[i][1]);
    solve(0, 1, 0);
    printf("%d", ans);
    return 0;
}
*/

/* 단순탐욕법 적용
#include <stdio.h>

int E[1010][2], n, m, ans=9877=654321;
//int counter;

int min(int a, int b)
{
    return a>b?b:a;
}
int abs(int a)
{
    return a>0 ? a:-a;
}
int dis(int a, int b)
{
    return abs(E[a][0] - E[b][0]) + abs(E[a][1] - E[b][1]);
}

void greedy_ans(int a, int b)
{
    ans = 0;
    for(int i=2; i<m+2; i++)
    {
        if(dis(i, a) > dis(i, b))
            ans += dis(i, b), b=i;
        else
            ans += dis(i, a), a=i;
    }
}

void solve(int a, int b, int c)
{
    int next = (a>b ? a:b) +1;
    if(d>ans) return;
    //counter++;
    if(next >= m+2)
    {
        if(d<ans) ans=d;
        return;
    }
    solve(next, b, d+dis(a, next));
    solve(a, next, d+dis(b, next));
}

int main()
{
    scanf("%d%d", &n, &m);
    E[0][0] = E[0][1] = 1;
    E[1][0] = E[1][1] = n;
    for(int i=2; i<m+2; i++)
        scanf("%d%d", &E[i][0], &E[i][1]);
    greedy_ans(0, 1);
    solve(0, 1, 0);
    printf("%d\n", ans);
    //printf("I visited : %d\n", counter);
    return 0;
}
*/