//답은 나오지만 한정적인 조건에서만 가능한 코드
#include <stdio.h>

int A[101], count[101], B[101], n, sum, max, ans;

void check(int s)
{
    sum = 0;
    for(int i=0; i<n; i++)
    {
        if( (A[s] < i && B[i] < B[s]) || (A[s] > i && B[i] > B[s]))
            count[s]++;
        sum += count[s];
    }
    if(count[s] > count[max]) max = s;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &A[i], &B[i]);
    while(true)
    {
        max = 0;
        for(int i=0; i<n; i++)
            check(i);
        ans++;
        if(sum == 0) break;
        else
        {
            for(int i=0; i<n; i++)
            {
                count[i] = 0;
                if(i >= max)
                    A[max] = A[max+1], B[max] = B[max+1];
            }
            n--;
        }
    }

    printf("%d", ans);
}






/*
#include <stdio.h>
#include <algorithm>

struct w {int a; int b;} d[10001];
int n;
bool cmp(w x, w y) {return x.a < y.a;}
int max(int p, int q) {return p>q ? p:q;}

int solve(int k)
{
    int count = 1;
    for(int i=k-1;  i>=1; i--)
        if(d[k].b > d[i].b) count = max(count, solve(i) + 1);
    return count;
}

int main()
{
    int i, t, m=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &d[i].a, &d[i].b);
    std::sort(d+1, d+n+1, cmp);
    for(int i = 1; i <= n; i++)
    {
        t = solve(i);
        if(m<t) m=t;
    }
    printf("%d\n", n-m);
    return 0;
}
*/

/* LIS의 길이찾는 방향을 거꾸로 한 코드
#include <stdio.h>
#include <algorithm>

struct w{int a; int b;} de[100001];
int n;
bool cmp(w x, w y) {return x.a < y.a};
int max(int p, int q) {return p>q ? p:q;}

int solve(int k)
{
    int i, count = 1;
    for(i = k+1; i<=n; i++)
        if(d[k].b < d[i].b) count = max(count, solve(i)+1);
    return count;
}

int main()
{
    int i, t, m = 0;
    sscanf("%d", &n);
    for(i = 1; i<=n; i++)
        scanf("%d %d", &d[i].a, &d[i].b);
    std::sort(d+1, d+n+1, cmp);
    for(i = 1; i<=n; i++)
    {
        t = solve(i);
        if(m < t) m = t;
    }
    printf("%d\n", n-m);
    return 0;
}
*/