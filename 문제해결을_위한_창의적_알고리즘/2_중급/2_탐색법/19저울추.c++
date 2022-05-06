#include <stdio.h>
#include <math.h>

int n, v[8];

void solve(int now)
{
    printf("now is %d\n", now);
    if(now == 0) return;
    int sum = 0;
    if(now > 0)
        for(int i=0; i < 7; i++)
        {
            sum += pow(3, i);
            if(now <= sum && v[i] == 0)
            {
                v[i] = 2;
                solve(now - pow(3, i));
                return;
            }
        }
    sum = 0;
    if(now < 0)
        for(int i=0; i<7; i++)
        {
            sum += pow(3, i);
            if(-1 * now <= sum && v[i] == 0  && now != 0)
            {
                v[i] = 1;
                solve(now + pow(3, i));
                return;
            }
        }
}

int main()
{
    scanf("%d", &n);
    solve(n);
    printf("%d ", n);
    for(int i=0; i<7; i++) if(v[i] == 1)
        {
            int temp = pow(3, i);
            printf("%d ", temp);
        }
    printf("0 ");
    for(int i=0; i<7; i++) if(v[i] == 2)
        {
            int temp = pow(3, i);
            printf("%d ", temp);
        }
    return 0;
}





/* 전체탐색법 1(오른쪽) 2(왼쪽)
#include <stdio.h>
#include <stdlib.h>

int n, scale[8] = {1, 3, 9, 27, 81, 243, 729}, chk[8], end;

void solve(int n, int sum)
{
    if(end) return;
    if(sum == n)
    {
        for(int c=2; c>0; c--)
        {
            for(int i=0; i<7; i++)
                if(chk[i] == c) printf("%d ", scale[i]);
            if(c==2) printf("0 ");
        }
        end=1;
    }
    for(int i=0; i<7; i++)
    {
        if(chk[i]==0)
        {
            chk[i]=1, solve(n, sum+scale[i]);
            chk[i]=2, solve(n+scale[i], sum);
            chk[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    printf("%d ", n);
    solve(n, 0);
    return 0;
}
*/