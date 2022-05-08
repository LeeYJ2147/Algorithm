//구하는 값은 f(n)이 아니라 0<=k<n인 k에 대해 f(k)의 최대값이므로 이건 일부 코드에서만 작동됨
#include <cstdio>

int n, DT[100001];

int max(int a, int b) {return a>b?a:b;}

int main()
{
    scanf("%d", &n);
    int temp;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &temp);
        DT[i] = max(DT[i-1]+temp,temp);
    }
    printf("%d\n", DT[n]);
    return 0;
}

/*
#include <cstdio>
#define INF 987654321

int S[100000], n, ans=-INF;
int DT[100000];

int max(int a, int b)
{
    return a>b ? a:b;
}

int f(int k)
{
    if(k==0) return DT[k]=S[0];
    else if(!DT[k]) DT[k]=max(f(k-1)+S[k], S[k]);
    return DT[k];
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", S+i);
    for(int i=0; i<n; i++)
        ans=max(ans, f(i));
    
    printf("%d\n", ans);
    return 0;
}
*/