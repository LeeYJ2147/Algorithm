#include <stdio.h>

char target[11], dari[2][21];
int ans;

void solve(int num, int ud, int t)
{
    if(target[t] == '\0')
    {
        ans++;
        return;
    }
    if(dari[ud][num] == '\0') return;
    for(int i=num; dari[ud][i] != '\0'; i++)
    {
        if(dari[ud][i] == target[t]) solve(i+1, 1-ud, t+1);
    }
}

int main()
{
    scanf("%s %s %s", target, dari[0], dari[1]);
    solve(0, 0, 0);
    solve(0, 1, 0);
    printf("%d", ans);
    return 0;
}


/*
#include <stdio.h>

char r[11];
char b1[21];
char b2[21];

int f(int s, int n, int rp)
{
    int i, c=0;
    if(r[rp] == '\0') return 1;
    if(s==1)
    {
        for(i = n; b1[i]!='\0'; i++)
            if(b1[i] == r[rp])
                c+=f(2, i+1, rp+1);
    }
    if(s==2)
    {
        for(i=0; b2[i] != '\0'; i++)
            if(b2[i] == r[rp])
                c+=f(1, i+1, rp+1);
    }
    return c;
}

int main()
{
    scanf("%s %s %s", r, b1, b2);
    printf("%d\n", f(1, 0, 0) + f(2, 0, 0));
    return 0;
}
*/