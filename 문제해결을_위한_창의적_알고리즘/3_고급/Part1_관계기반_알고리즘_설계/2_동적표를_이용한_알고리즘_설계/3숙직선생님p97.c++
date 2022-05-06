#include <stdio.h>

int DT[1001], v[3], k;

int min(int a, int b, int c)
{
    return (a<b ? a : b) < c ? (a<b ? a:b) : c;
}

int f(int n)
{
    if(n == k) return 0;
    else if(n > k) return 10000;
    else if(!DT[n])
        DT[n] = min(f(n+v[0])+1 , f(n+v[1])+1 , f(n+v[2])+1 );
    return DT[n];
}

int main()
{
    int n;
    scanf("%d %d", &n, &k);
    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    if(f(n) >= 10000) printf("-1\n");
    else printf("%d\n", f(n));
    return 0;
}


/*
#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int d[1200];

int main()
{
    int a, b, able[3];
    scanf("%d%d", &a, &b);
    for(int i=0; i<3; i++)
        scanf("%d", &able[i]);
    q.push(a);
    while(!q.empty())
    {
        int value=q.front();
        if(value == b)
        {
            printf("%d", d[value]);
            return 0;
        }
        q.pop();
        for(int i=0; i<3; i++)
        {
            int temp = value+able[i];
            if(temp <= b && !d[temp])
            {
                q.push(temp);
                d[temp] = d[value]+1;
            }
        }
    }
    printf("-1");
    return 0;
}
*/



/*
#include <stdio.h>
#define MIN(a, b) ((a) > (b) ? (b):(a))
int a, b, able[3], d[1001];
int main()
{
    scanf("%d%d", &a, &b);
    for(int i=0; i<3; i++)
        scanf("%d", &able[i]);
    
    if(a==b) printf("0");
    else
    {
        for(int i=a; i<=b; i++)
            d[i] = 123456789;
        d[a] = 0;

        for(int i=a+1; i<=b; i++)
        {
            int temp = 123456789;
            for(int k=0; k<3; k++)
            {
                if(k-able[k] >= a)
                    temp = MIN(temp, d[i-able[k]]+1);
            }
            d[i] = temp;
        }

        if(d[b] != 123456789) printf("%d", d[b]);
        else printf("-1");
    }
    return 0;
}
*/