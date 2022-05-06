#include <stdio.h>

int n, visited[21], ans;
struct w{int can; int jump;} sp[21];

void come(int num)
{
    if(num == 0)
    {
        ans++;
        return;
    }
    if(num < 0) return;
    for(int i=1; i<=sp[num].can && num-i>=0; i++)
    {
        if(!visited[num-i] && sp[num-i].can && sp[num-i].jump)
        {
            visited[num-i] = 1;
            come(num-i);
            visited[num-i] = 0;
        }
    }
}

void go(int num)
{
    if(num == 15)
    {
        come(15);
        return;
    }
    if(num > 15) return;
    for(int i=1; i<=sp[num].can && num+i<=15; i++)
        if(!visited[num+i] && sp[num+i].can)
        {
            visited[num+i] = 1;
            go(num+i);
            visited[num+i] = 0;
        }
}

int main()
{
    int temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        scanf("%d %d", &sp[temp].can, &sp[temp].jump);
    }
    go(0);
    printf("%d", ans%1000);
    return 0;
}





/* 이해가 잘...ㅜㅠㅠ
#include <stido.h>
int n, m = 1000;
int p[500], d[500], g[500];
bool ca(int a, int k)
{
    return p[k] <= p[a] + d[a];
}

bool cb(int b, int k)
{
    return (p[k] <= p[b] + d[k]) && g[k];
}

int f(int a, int b, int k)
{
    int c = 0;
    if(k == n-1)
    {
        if(ca(a, k) && cb(b, k)) c = 1;
        else c = 0;
    }
    else
    {
        if(ca(a, k)) c+= f(k, b, k+1)%m;
        if(cb(b, k)) c+= f(a, k, k+1)%m;
        c += f(a, b, k+1)%m;
    }
    return c;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d %d", &p[i], &d[i], &g[i]);
    printf("%d\n", f(0, 0, 1));
    return 0;
}
*/