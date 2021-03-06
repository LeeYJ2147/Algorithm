#include <stdio.h>

int n, cnt;

int isprime(int x)
{
    for(int i=2; i*i <= x; i++)
        if(x%i == 0)
            return 0;
    return 1;
}

void f(int num, int len)
{
    if(len == n)
    {
        if(isprime(num))
        {
            cnt++;
            printf("%d\n", num);
        }
        return ;
    }
    else
    {
        if(isprime(num))
        {
            f(num*10+1, len+1);
            f(num*10+3, len+1);
            f(num*10+7, len+1);
            f(num*10+9, len+1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    f(2,1); f(3,1); f(5,1); f(7,1);
    printf("%d", cnt);
}