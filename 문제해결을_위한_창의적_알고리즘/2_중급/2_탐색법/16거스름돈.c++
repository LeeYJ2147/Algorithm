#include <stdio.h>
#include <queue>
using namespace std;

int goal, n, money[11], minimum = 0xfffffff;
struct VERTEX{int nowmoney, num, corrent;};
queue<VERTEX> q;

void solve()
{
    while(!q.empty())
    {
        VERTEX temp = q.front();
        q.pop();
        if(temp.nowmoney == goal)
        {
            if(minimum > temp.corrent) minimum = temp.corrent;
        }
        if( (temp.nowmoney <= goal) && (temp.corrent < minimum))
            for(int i=n-1; i >= 0; i--)
            {
                q.push( {temp.nowmoney + money[i], i, temp.corrent+1} );
            }
    }
}

int main()
{
    scanf("%d %d", &goal, &n);
    for(int i=0; i<n; i++) scanf("%d", money+i);
    for(int i=n-1; i>=0; i--) q.push({money[i], i, 1});
    solve();
    printf("%d", minimum);
    return 0;
}




/* 모범코드1 solve(mon, d) = "d개의 동전으로 mon원을 사용한 상태", 조금 느림
#include <stdio.h>

int m, n, coin[10], ans = 987654321;

void solve(int mon, int d)
{
    if(mon > m) return;
    if(mon == m)
    {
        if(d < ans) ans = d;
        return;
    }
    for(int i=0; i<n; i++)
        solve(mon+coin[i], d+1);
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
*/



/*모범코드2 solve(mon, k, cnt) = "k번재 이하의 동전을 cnt개 사용하여 mon원을 거슬러 준 상태"
#include <stdio.h>

int n, m, coin[10], ans = 987654321;

void solve(int mon, int k, int cnt)
{
    if(k==n || mon > m) return;
    if(mon == m)
    {
        if(ans > cnt) ans=cnt;
        return;
    }
    for(int i=0; mon+coin[k]*i <= m; i++)
        solve(mon+coin[k]*i, k+1, cnt+i);
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    solve(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
*/