//상향식 알고리즘
#include <stdio.h>
#include <math.h>

int DT[50001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        if(i<10)
            DT[i] = i;
        else
            DT[i] = DT[i/10] + (i%10)*(int)pow(10, (int)log10(i));
    }
    printf("%d\n", DT[n]);
    return 0;
}


//하향식 알고리즘
/*
#include <cstdio>
#include <cmath>

int DT[50001];

int f(int n)
{
    if(n<10)
        return n;
    if(!DT[n]) // DT에 n이 기록되지 않았다면 채움
        DT[n] = f(n/10) + (n%10)*powf(10.0, (int)log10((double)n));
    return DT[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
*/