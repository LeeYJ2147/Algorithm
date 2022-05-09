#include <stdio.h>

int DT[100001], DT2[100001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    DT[0] = DT[1]=1, DT[2]=3;
    DT2[0] = DT2[1]=1, DT2[2]=9;
    for(int i=3; i<=n; i++)
    {
        if(i%2) //홀수
            DT[i] = DT2[i/2]+4*DT[i/2-1]*DT[i/2];
        else
            DT[i] = DT2[i/2]+2*DT2[i/2-1];
        DT2[i] = DT[i]*DT[i];
    }
    printf("%d\n", DT[n]%m);
    return 0;
}


//f(n) = f(n-1) + 2f(n-2)
/*
#include <cstdio>

int DT[100001], m;

int f(int n)
{
    if(n==1) return DT[n]=1%m;
    else if(n==2) return DT[n]=3%m;
    else
    {
        if(DT[n] == 0)
            DT[n]=(f(n-1)+2*f(n-2))%m;
        return DT[n];
    }
}

int main()
{
    int n;
    scanf("%d %d", &n, &m);
    printf("%d\n", f(n));
    return 0;
}
*/
//위를 반복문으로
/*
#include <cstdio>

int DT[100001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    DT[1]=1%m, DT[2]=3%m;
    for(int i=3; i<=n; i++)
        DT[i]=(DT[i-1]+2*DT[i-2])%m;
    printf("%d\n", DT[n]);
    return 0;
}
*/


//내 방법 + 함수추가
/*
#include <cstido>

int n, m, DT[100001];

long long int f(int k)
{
    if(k<=1) return DT[k]=1%m;
    else
    {
        if(DT[k]==0)
        {
            if(k%2) DT[k]=(f(k/2)*f(k/2+1)+2*f(k/2)*f(k/2-1))%m;
            else DT[k]=(f(k/2)*f(k/2)+2*f(k/2-1)*f(k/2-1))%m;
        }
        return DT[k];
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    printf("%lld\n", f(n));
    return 0;
}
*/