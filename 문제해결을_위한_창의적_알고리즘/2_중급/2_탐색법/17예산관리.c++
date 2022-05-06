#include <stdio.h>

int max, visited[22], B, n, arr[22];

void solve(int sum)
{
    for(int i=0; i<n; i++)
    {
        if(sum > B) return;
        if(visited[i] == 0)
        {
            visited[i] = 1;
            solve(sum + arr[i]);
            visited[i] = 0;
        }
        if(sum > max && sum <= B) max = sum;
    }
}

int main()
{
    scanf("%d %d", &B, &n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    solve(0);
    printf("%d", max);
    return 0;
}










/*f(i, sum) = i번째 활동을 고려할 때, i-1까지 활동비용의 합계가 sum인 경우
#include <stdio.h>

int B, n, act[23], res;

void f(int i, int sum)
{
    if(i == n+1)
    {
        if(sum<=B && sum>res)
            res = sum;
        return;
    }
    f(i+1, sum+act[i]);
    f(i+1, sum);
}

int main()
{
    int i;
    scanf("%d %d", &B, &n);
    for(i=1; i<=n; i++)
        scanf("%d", &act[i]);
    f(1, 0);
    printf("%d", res);
    return 0;
}
*/