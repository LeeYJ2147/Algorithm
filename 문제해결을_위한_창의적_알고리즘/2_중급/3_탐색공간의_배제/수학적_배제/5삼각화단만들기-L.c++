#include <stdio.h>

int n, ans;

int main()
{
    scanf("%d", &n);
    for(int c=n/3; c<=n/2; c++)
        for(int a=1; a<=n/3; a++)
        {
            int b = n-c-a;
            if((a+b > c) && a<=b && b<=c) ans++;
        }
    printf("%d", ans);
    return 0;
}



/*
#include <stdio.h>

int main(void)
{
    int n, a, b, c, count = 0;
    scanf("%d", &n);
    for(c=n/3; c<=n/2; c++)
        for(a=1; a<=n/3; a++)
        {
            b=n-(a+c);
            if(a+b>c && (a<=b && b <= c)) count++;
        }
    printf("%d\n", count);
    return 0;
}
*/