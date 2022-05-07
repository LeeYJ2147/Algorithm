#include <stdio.h>
#include <algorithm>

int n, GiftV[16], A, B, C, chk;

int comp(int a, int b)
{
    return a>b;
}

void solve(int a, int b, int c, int num)
{
    if(num < n && !chk)
    {
        solve(a, b, c+GiftV[num], num+1);
        solve(a, b+GiftV[num], c, num+1);
        solve(a+GiftV[num], b, c, num+1);
    }
    else if(a >= b && b >= c && !chk)
    {
        A = a, B = b, C = c;
        chk = 1;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &GiftV[i]);
    std::sort(GiftV, GiftV+n, comp);
    solve(0, 0, 0, 0);
    printf("%d %d %d\n", A, B, C);
    return 0;
}




/*
#include <stdio.h>
#include <algorithm>

int gift[30], chk[30], A, B, C, n, S;

int comp(int a, int b)
{
    return a>b;
}

void solve(int no, int a, int b, int c)
{
    if(no<n)
    {
        solve(no+1, a, b, c+gift[no]);
        solve(no+1, a, b+gift[no], c);
        solve(no+1, a+gift[no], b, c);
    }
    else if(a >= b && b >= c)
    {
        A = a, B = b, C = c;
        printf("number updated : %d %d %d\n", A, B, C);
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0; i<n; S+=gift[i++])
        scanf("%d", &gift[i]);
    std::sort(gift, gift+n, comp);
    solve(0, 0, 0, 0);
    printf("%d %d %d\n", A, B, C);
    return 0;
}
*/