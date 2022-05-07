/* 내가 짠 코드, 정렬이 안 됨
#include <stdio.h>

int chk[7], zzit[7], v[721], prime[999999], check[1000000];
int n, k, t, z, c;
//n은 입력받을 숫자, k는 n의 자릿수, z는 v[]에 추가된 숫자 개수
//c는 소수를 출력했나 안 했나 확인
//zzit은 각 자릿수를 저장하는 배열, v[]는 재배열된 숫자들
//chk[]는 make에서 백트래킹하는데 쓰일 것
//prime은 isPrime에서 소수판별할 때 쓰일 것
//check는 그 숫자가 출력되었는지 확인

void make(int a, int b, int c)
{
    c += zzit[b];
    if(a == k)
    {
        v[z] = c;
        z++;
        return;
    }
    for(int i=0; i<k; i++)
        if( !chk[i] )
        {
            chk[i] = 1;
            make(a+1, i, c*10);
            chk[i] = 0;
        }
}

bool isPrime(int q)
{
    for(int i=2; i<=q; i++) prime[i] = 1;
    for(int i=2; i*i <= q; i++)
    {
        if( prime[i] )
        {
            if( !int(q%i) ) return false;
            for(int j=i*i; j<=q; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(k=0, t=n; t>0; k++)
    {
        zzit[k] = t%10;
        t /= 10;
    }
    for(int i=0; i<k; i++)
    {
        chk[i] = 1;
        make(1, i, 0);
        chk[i] = 0;
    }

    for(int i=0; i<z; i++)
    {
        if(isPrime(v[i]) && !check[v[i]])
        {
            c=1;
            printf("%d ", v[i]);
            check[v[i]] = 1;
        }
    }
    if(!c) printf("0");
    return 0;
}
*/




/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[6];
int allnum[2000], alli;

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int chk(int n)
{
    int i;
    if(n==1) return -1;

    for(i=2; i<n; i++) if(n%i == 0) return -1;
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a; *a=*b; *b = temp;
}
void P(int i, int last)
{
    int num = 0, j, k;
    if(i == last)
    {
        for(k=0; k<= last; k++)
            num+=a[k] * (int)pow((double)10, (double)k);
        allnum[alli++] = num;
    }
    else
        for(j = i; j<=last; j++)
        {
            swap(&a[i], &a[j]);
            P(i+1, last);
            swap(&a[i], &a[j]);
        }
}

int main()
{
    int n, i, last, prev = -1;
    scanf("%d", &n);
    for(i=0; i<6; i++)
        if( n!=0)
        {
            a[i] = n%10;
            n/=10;
            last = i;
        }
    
    P(0, last);
    qsort(allnum, alli, sizeof(int), compare);
    for(i=0; i<alli; i++)
    {
        if(chk(allnum[i]) == 0)
            if(prev != allnum[i])
            {
                printf("%d ", allnum[i]);
                prev = allnum[i];
            }
    }

    if(prev == -1)
        printf("0");
    
    return 0;
}
*/