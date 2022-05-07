/* O(n^ 1/2)
#include <stdio.h>
int n, num, t, temp;

bool isPrime(int k)
{
    for(int i=2; i*i<=k; i++)
        if(k%i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    t = 2;
    while(num != n)
    {
        if(isPrime(t))
        {
            num++;
            temp = t;
        }
        t++;
    }
    printf("%d", temp);
    return 0;
}
*/ //100,000번째 소수 : 1,299,709

/*에라토스테네스의 체, n번째 소수 구하는 것이 목표
#include <stdio.h>
#define max 1299709

int chk[max+2];
int n, k, i=2, j=1;

int main()
{
    scanf("%d", &n);
    while(k != n)
    {
        if( !chk[i] )
        {
            for(j=2; i*j <= max; j++)
                chk[i*j] = 1;
            k++;
        }
        i++;
    }
    printf("%d", i-1);
    return 0;
}
*/






// /*에라토스테네스의 체, 정해진 범위 내의 소수 검출
#include <stdio.h>

int v[50000];
int n;

int main()
{
    scanf("%d", &n);

    for(int i=2; i*i <= n; i++)
    {
        if( !v[i] )
            for(int j=i*i; j <= n; j+=i)
                v[j] = 1;
    }
    for(int i=2; i<=n; i++)
        if( !v[i] ) printf("%d ", i);
    
    return 0;
}
// */