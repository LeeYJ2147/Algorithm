#include <cstdio>

int v[1<<18];

void f(int i, int n)
{
    for(int j=i; j<n+i; j++)
    {
        if(v[i] != v[j])
        {
            printf("-");
            f(i, n/2);
            f(i+n/2, n/2);
            return;
        }
    }
    printf("%d", v[i]);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%1d", &v[i]);
    f(0, n);
    return 0;
}

/*
#include <cstdio>

char S[1<<19];
int n;

void f(int k, int s)
{
    int sum=0;
    if(s==1)
    {
        printf("%c", S[k]);
        return;
    }
    for(int i=k; i<k+s; i++)
        sum += (S[i]-'0');
    if(sum == 0 || sum==s)
        printf("%d", (bool)sum);
    else
    {
        printf("-");
        f(k, s/2);
        f(k+s/2, s/2);
    }
}

int main()
{
    scanf("%d %s", &n, S);
    f(0, n);
    return 0;
}
*/