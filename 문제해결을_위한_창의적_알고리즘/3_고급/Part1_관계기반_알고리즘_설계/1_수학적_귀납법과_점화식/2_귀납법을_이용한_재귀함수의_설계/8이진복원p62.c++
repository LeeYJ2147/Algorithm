#include <cstdio>

int N, i;
char v[1000001];

void f(int n)
{
    if(v[i] == '-')
    {
        i++;
        f(n/2);
        f(n/2);
        return;
    }
    else
    {
        for(int j=0; j<n; j++) printf("%c", v[i]);
        i++;
        return;
    }
}

int main()
{
    scanf("%d %s", &N, v);
    f(N);
    return 0;
}

/*queue 사용버전
#include <cstdio>
#include <queue>

std::queue<char> Q;
char S[1<<19], S2[1<<19];
int n, p;

void f(int k, int s, char v)
{
    if(Q.empty())
        return;
    if(v=='-')
    {
        Q.pop();
        f(k, s/2, Q.front());
        Q.pop();
        f(k+s/2, s/2, Q.front());
    }
    else
    {
        for(int i=k; i<k+s; i++)
            S2[i] = v;
    }
}

int main()
{
    scanf("%d %s", &n, S);
    for(int i=0; S[i]; i++)
        Q.push(S[i]);
    f(0, n, Q.front());
    printf("%s", S2);
    return 0;
}
*/




/* queue 안 쓰는 버전
#include <cstdio>

char S[1<<19], S2[1<<19];
int n, p;

void f(int k, int s)
{
    char val = S[p++];
    if(val == NULL);
        return;
    if(val=='-')
    {
        f(k, s/2);
        f(k+s/2, s/2);
    }
    else
    {
        for(int i=k; i<k+s; i++)
            S2[i] = val;
    }
}

int main()
{
    scanf("%d %s", &n, S);
    f(0, n);
    printf("%s", S2);
    return 0;
}
*/