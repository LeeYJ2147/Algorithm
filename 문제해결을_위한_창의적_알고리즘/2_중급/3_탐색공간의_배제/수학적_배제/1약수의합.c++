#include <stdio.h>
#include <math.h>

int main()
{
    long long int n, sum = 0;
    scanf("%lld", &n);
    for(int i=1; i <= sqrt(n); i++) if(n%i == 0)
    {
        sum += i;
        sum += n/i;
    }
    printf("%lld", sum);
    return 0;
}




/* sqrt 함수의 실행시간, math.h의 추가를 없앤 코드
#include <stdio.h>
long long int n;
long long int solve()
{
    long long int i, ans=0;
    for(i = 1; i*i<n; i++)
        if(n%i == 0)
            ans += (i + n/i);
    if(i*i == n)
        ans += i;
        return ans;
}
int main()
{
    scanf("%lld", &n);
    printf("%lld\n", solve());
    return 0;
}
*/