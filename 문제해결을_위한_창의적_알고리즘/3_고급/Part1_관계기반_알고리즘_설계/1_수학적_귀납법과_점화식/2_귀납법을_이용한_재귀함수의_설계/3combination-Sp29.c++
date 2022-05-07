#include <cstdio>

int f(int n, int k)
{
    if(k==n) return 1;
    else if(k==1) return n;
    else return f(n-1, k-1)+f(n-1,k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n, k));
    return 0;
}



/* f(n, k)와 f(n, k-1)의 관계를 수학적 정의에 입각해 일반화
#include <cstdio>

int f(int n, int k)
{
    if(k==n) return 1;
    else if(k==1) return n;
    else return (n-k+1)/k*f(n, k-1); //f(n, k-1) * (n-k+1)/k는 오버플로우를 일으킬 수 있음
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n, k));
    return 0;
}
*/