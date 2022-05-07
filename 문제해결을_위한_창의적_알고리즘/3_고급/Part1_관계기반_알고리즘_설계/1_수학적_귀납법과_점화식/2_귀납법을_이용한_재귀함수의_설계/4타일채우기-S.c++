#include <cstdio>

int n, m;

int f(int i)
{
    if(i<2) return 1;
    else return( (2*f(i-2) + f(i-1)) % m );
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%d", f(n));
    return 0;
}



/* 내 방법과 동일
#include <cstdio>

int n, m;

int f(int k)
{
    if(k<=1) return 1%m;
    else return( (f(k-1)+2*f(k-2)) % m );
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%d", f(n));
    return 0;
}
*/


/*
// 반을 나눠서 그 양 옆의 경우를 곱의법칙으로 계산
// 제곱이 들어가 값이 커지기 마련이므로 long long int 사용
#include <cstdio>

int n, m;

long long int f(int k)
{
    if(k<=1) return 1%m;
    else if(k%2) return(f(k/2) * f(k/2+1) + 2*f(k/2)*f(k/2-1))%m;
    else return (f(k/2)*f(k/2) + 2*f(k/2-1)*f(k/2-1))%m;
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%lld\n", f(n));
    return 0;
}
*/