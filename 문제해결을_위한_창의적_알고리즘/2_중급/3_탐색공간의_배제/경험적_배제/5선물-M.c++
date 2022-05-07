#include <stdio.h>
#include <algorithm>

int ans[3], v[16], n, S, count;

int comp(int a, int b)
{
    return a<b;
}

void greedy_ans()
{
    for(int i=0; i<n; i++)
    {
        if(ans[2] + v[i] <= ans[1]) ans[2]+=v[i];
        else if(ans[1] + v[i] <= ans[0]) ans[1] += v[i];
        else ans[0] += v[i];
    }
    printf("greedy : %d %d %d\n", ans[0], ans[1], ans[2]);
    return;
}

void solve(int a, int b, int c, int num)
{
    if(b>S/2 || c>S/3) return;

    if((S - b - c < b) || (S - a - c < c)) return;

    count++;

    if(num >= n)
    {
        if(a<b || b<c) return;
        if(ans[0] - ans[2] > a-c)
            ans[0] = a, ans[1] = b, ans[2] = c;
        else if(ans[0] - ans[2] == a-c && ans[2] > c)
            ans[0] = a, ans[1] = b, ans[2] = c;
        return;
    }
    solve(a + v[num], b, c, num+1);
    solve(a, b + v[num], c, num+1);
    solve(a, b, c + v[num], num+1);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
        S+=v[i];
    }
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\nS : %d\n", S);
    std::sort(v, v+n, comp);
    greedy_ans();
    solve(0, 0, 0, 0);
    printf("ans : %d %d %d", ans[0], ans[1], ans[2]);
    printf("I visited : %d\n", count);
    return 0;
}

/* S/3 >= C, S/2 >= B
#include <stdio.h>
#include <algorithm>

int girt[30], chk[30], DIF = 0x7fffffff, A, B, C, n, S;

int comp(int a, int b)
{
    return a>b;
}

void solve(int no, int a, int b, int c)
{
    if(c > S/3 || b > S/2) return;
    if(no < n)
    {
        solve(no+1, a, b, c+gift[no]);
        solve(no+1, a, b+gift[no], c);
        solve(no+1, a+gift[no], b, c);
    }
    else if((a>=b && b>=c) && a-c && a-c<DIF)
    {
        DIF = a-c, A=a, B=b, C=c;
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0; i<b; S+=gift[i])
        scanf("%d", &gift[i]);
    std::sort(gift, gift+n, comp);
    solve(0, 0, 0, 0);
    printf("%d %d %d\n", A, B, C);
    return 0;
}
*/

/*
// S - (a+b+c) + a < b
// S - (a+b+c) + b < c
#include <stdio.h>
#include <algorithm>

int gift[30], chk[30], DIF=0x7fffffff, A, B, C, n, S;

int comp(int a, int b)
{
    return a>b;
}

void solve(int no, int a, int b, int c)
{
    if(c>S/3 || b>S/2) return;
    int rest = S-(a+b+c);
    if(a+rest<b || b+rest<c) return;
    if(no<n)
    {
        solve(no+1, a, b, c+gift[no]);
        solve(no+1, a, b+gift[no], c);
        solve(no+1, a+gift[no], b, c);
    }
    else if((a>=b && b>=c) && a-c && a-c<DIF)
    {
        DIF = a-c, A=a, B=b, C=c;
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0; i<n; S+=gift[i++])
        scanf("%d", &gift[i]);
    std::sort(gift, gift+n, comp);
    solve(0, 0, 0, 0);
    printf("%d %d %d\n", A, B, C);
    return 0;
}
*/





/* A-(C + rest) > DIF
#include <stdio.h>
#include <algorithm>

int gift[30], chk[30], DIF=0x7fffffff, A, B, C, n, S;
int counter;

int comp(int a, int b)
{
    return a>b;
}

void solve(int no, int a, int b, int c)
{
    if(c>S/3 || b>S/2) return;
    int rest = S-(a+b+c);
    if(a+rest<b || b+rest<c) return;
    if(a-(c+rest) > DIF) return;
    counter++;
    if(no<n)
    {
        solve(no+1, a, b, c+gift[no]);
        solve(no+1, a, b+gift[no], c);
        solve(no+1, a+gift[no], b, c);
    }
    else if((a>=b && b>=c) && a-c && a-c<DIF)
    {
        DIF = a-c, A=a, B=b, C=c;
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0; i<n; S+=gift[i++])
        scanf("%d", &gift[i]);
    std::sort(gift, gift+n, comp);
    solve(0, 0, 0, 0);
    printf("%d %d %d\n", A, B, C);
    printf("탐색 중 방문한 노드의 수는 %d입니다.\n", counter);
    return 0;
}
*/