#include <stdio.h>

int m, n, coin[10];
int DT[10001];

int f(int mon)
{
    if(!mon) return 0;
    if(mon<0) return 987654321;
    if(DT[mon]==987654321)
        for(int i=0; i<n; i++)
            if(DT[mon]>f(mon-coin[i])+1) DT[mon]=f(mon-coin[i])+1;
    return DT[mon];
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    for(int i=0; i<=m; i++) DT[i]=987654321;
    printf("%d\n", f(m));
    return 0;
}


//중급편 문제에서 void형인 solve를 int형인 f로 변형, DT 추가
/*
#include <stdio.h>

int m, n, coin[10], DT[10001];

int min(int a, int b) {return a>b?b:a;}

int f(int c)
{
    if(c==m) return DT[c]=0;
    if(DT[c]==0)
    {
        DT[c]=987654321;
        for(int i=0; i<n; i++)
            if(c+coin[i]<=m)
                DT[c]=min(DT[c], f(c+coin[i])+1);
    }
    return DT[c];
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    printf("%d", f(0));
    return 0;
}
*/

//동적계획법, 함수 f 사용
/*
#include <cstdio>

int DT[10001], coin[10], n, m;

int min(int a, int b) {return a>b?b:a;}

int f(int c)
{
    for(int i=0; i<n; i++)
        if(coin[i]==c) return 1;
    if(DT[c]==0)
    {
        DT[c]=987654321;
        for(int i=0; i<n; i++)
            if(c-coin[i]>0)
                DT[c]=min(DT[c], f(c-coin[i])+1);
        return DT[c];
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    printf("%d\n", f(m));
    return 0;
}
*/
//동적계획법, 반복문 사용
/*
#include <cstdio>

int DT[10001], coin[10], n, m;

int min(int a, int b) {return a>b?b:a;}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i), DT[coin[i]]=1;
    for(int i=coin[0]; i<=m; i++)
    {
        if(DT[i]==0)
        {
            DT[i]=987654321;
            for(int j=0; j<n; j++)
                if(i-coin[j]>0)
                    DT[i] = min(DT[i], DT[i-coin[j]]+1);
        }
    }
    printf("%d\n", DT[m]);
    return 0;
}
*/