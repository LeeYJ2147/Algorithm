#include <stdio.h>

int H, W, ans;

bool issafe(int x, int y)
{
    double limy = double(x) * double(H) / double(W);
    return( limy <= y && x <= W && y <= H);
}

void solve(int x, int y)
{
    if(x == W && y == H)
    {
        ans ++;
        return;
    }
    if(issafe(x+1, y)) solve(x+1, y);
    if(issafe(x, y+1)) solve(x, y+1);
}

int main()
{
    scanf("%d %d", &H, &W);
    solve(0, 0);
    printf("%d", ans);
    return 0;
}

/* H/W <= h/(w+1)
#include <stdio.h>

int H, W, ans;

void solve(int h, int w)
{
    if(h>H || w>W) return;
    if(h==H && w==W)
    {
        ans++;
        return;
    }
    solve(h+1, w);
    if((double)H/W <= (double)h/(w+1))
        solve(h, w+1);
}

int main()
{
    scanf("%d %d", &H, &W);
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
*/