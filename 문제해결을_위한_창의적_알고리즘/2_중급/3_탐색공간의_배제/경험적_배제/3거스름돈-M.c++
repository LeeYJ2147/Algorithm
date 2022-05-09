/*
#include <stdio.h>

int m, n, v[11], min=0x7fffffff, count, howmany;

void greedy_ans(void)
{
    int temp=m; // greedy_ans(int mon), while(mon)하면 temp 선언 안 해도 됨
    for(int i=n-1; i>=0; i--)
        while(temp >= v[i])
        {
            count++;
            temp -= v[i];
        }
}

void f(int quantity, int howmoney)
{
    if(quantity >= count) return;
    if(howmoney > m) return;
    howmany++;
    if(howmoney == m)
    {
        count = quantity;
        return;
    }
    for(int i=n-1; i>=0; i--)
        f(quantity+1, howmoney+v[i]);
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    greedy_ans();
    for(int i=n-1; i>=0; i--)
        f(1, v[i]);
    printf("%d\nI visited : %d\n", count, howmany);
    return 0;
}
*/



/*현재까지의 사용한 동전의 수 > 지금까지 구해둔 최소 동전의 수
#include <stdio.h>

int m, n, coin[10], ans=987654321;

void solve(int mon, int d)
{
    if(d>ans) return;
    if(mon>m) return;
    if(mon == m)
    {
        if(d<ans) ans = d;
        return;
    }
    for(int i=0; i<n; i++)
        solve(mon+coin[i], d+1);
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
*/

//단순탐욕법 추가
#include <stdio.h>

int m, n, coin[10], ans=987654321;
int counter;

void greedy_ans(int mon)
{
    ans = 0;
    while(mon)
    {
        for(int i=n-1; i>=0; i--)
        {
            ans+= mon/coin[i];
            mon%=coin[i];
        }
    }
}

void solve(int mon, int d)
{
    if(d>ans) return;
    if(mon>m) return;
    counter++;
    if(mon == m)
    {
        if(d<ans) ans=d;
        return;
    }
    for(int i=0; i<n; i++)
        solve(mon+coin[i], d+1);
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    greedy_ans(m);
    solve(0, 0);
    printf("%d\n", ans);
    printf("탐색한 정점의 수 %d\n", counter);
    return 0;
}