#include <stdio.h>

int min = 0xfffffff, p, f;
int P[12], F[11], visited[12];

int positive(int a)
{
    return(a<0 ? -a:a);
}

void solve(int so, int pum, int sum)
{
    sum += positive(F[so] - P[pum]);
    if(so == f-1)
    {
        if(sum < min) min = sum;
        return;
    }
    for(int i=0; i<p; i++) if(!visited[i])
    {
        visited[i] = 1;
        solve(so+1, i, sum);
        visited[i] = 0;
    }
}

int main()
{
    scanf("%d %d", &p, &f);
    for(int i=0; i<p; i++) scanf("%d", &P[i]);
    for(int i=0; i<f; i++) scanf("%d", &F[i]);
    for(int i=0; i<p; i++) solve(0, i, 0);
    printf("%d", min);
    return 0;
}




/*
#include <stdio.h>
int p, f, pp[10001], fp[100000], pv[100001], mh=0x7fffffff;

int min(int a, int b)
{
    return a>b ? b:a;
}

int abs(int a)
{
    return a>0 ? a:-a;
}

void g(int pt, int ft, int h)
{
    if(ft == f)
    {
        mh = min(mh, h);
        return;
    }
    for(int i=1; i<=p; i++)
    {
        if(pv[i] == 0)
        {
            pv[i] = 1;
            h+=abs(pp[i] - fp[ft+1]);
            g(i, ft+1, h);
            h-=abs(pp[i] - fp[ft+1]);
            pv[i] = 0;
        }
    }
}

int main()
{
    int i;
    scanf("%d %d", &p, &f);
    for(i=1; i <= p; i++)
        scanf("%d", &pp[i]);
    for(i = 1; i<=f; i++)
        scanf("%d", &fp[i]);
    g(0, 0, 0);
    printf("%d\n", mh);
    return 0;
}