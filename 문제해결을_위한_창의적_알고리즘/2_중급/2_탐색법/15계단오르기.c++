//꽤 비슷하게 맞음!!!!!!!!
#include <stdio.h>

int n, ans=0;

void solve(int num, int now)
{
    if(now == n)
        ans ++;
    else if(now > n) return;
    else
    {
        solve(1, now+1);
        solve(2, now+2);
    }
}

int main()
{
    scanf("%d", &n);
    solve(1, 1);
    solve(2, 2);

    printf("%d\n", ans);
    return 0;
}



/*모범코드
#include <stdio.h>

int n, ans;

void solve(int v)
{
    if(v>n) return;
    if(v==n)
    {
        ans++;
        return;
    }
    solve(v+1);
    solve(v+2);
}

int main()
{
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans);
}
*/