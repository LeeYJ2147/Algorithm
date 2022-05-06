// / * 사실상 x변수는 필요없었음(f함수 안에서)
#include <stdio.h>

int n, G[11][11], chk[11], greed_chk[11], ans, howmany;

void greedy_scanf(void)
{
    for(int i=0; i<n; i++)
    {
        int tempr, small=0x7fffffff;
        for(int j=0; j<n; j++)
        {
            scanf("%d", &G[i][j]);
            if(G[i][j] < small && !greed_chk[j])
                tempr=j, small=G[i][j];
        }
        greed_chk[tempr] = 1;
        ans += G[i][tempr];
    }
}

void f(int y, int x, int count)
{
    if(count >= ans) return;
    howmany++;
    if(y == n-1)
    {
        if(ans > count) ans = count;
        return;
    }
    for(int i=0; i<n; i++) if(!chk[i])
    {
        chk[i] = 1;
        f(y+1, i, count+G[y+1][i]);
        chk[i] = 0;
    }
}

int main(void)
{
    scanf("%d", &n);
    greedy_scanf();
    /*
    ans = 0x7fffffff;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        scanf("%d", &G[i][j]);
    */
    for(int i=0; i<n; i++)
    {
        chk[i] = 1;
        f(0, i, G[0][i]);
        chk[i] = 0;
    }
    printf("%d\n탐색한 정점의 수 : %d\n", ans, howmany);
    return 0;
}
// * /



/* 배제, 그리디 X
#include <stdio.h>
int m[11][11];
int col_check[11];
int n, min_sol = 0x7fffffff;

void input(void)
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &m[i][j]);
}

void solve(int row, int score)
{
    if(socre > min_sol) return;
    if(row == n)
    {
        if(score < min_sol)
            min_sol=score;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(col_check[i] == 0)
        {
            col_check[i] = 1;
            solve(row+1, score+m[row][i]);
            col_check[i] = 0;
        }
    }
    return;
}

int main()
{
    input();
    solve(0, 0);
    printf("%d", min_sol);
    return 0;
}
*/







/* 단순탐욕법 추가
#include <stdio.h>
int m[11][11];
int col_check[11], greedy_chk[11];
int n, min_sol=0;
int counter;

void solve(int row, int score)
{
    if(score>min_sol) return;
    counter++;
    if(row==n)
    {
        if(score<min_sol) min_sol = score;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(col_check[i] == 0)
        {
            col_check[i] = 1;
            solve(row+1, score+m[row][i]);
            col_check[i] = 0;
        }
    }
    return;
}

void input(void)
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &m[i][j]);
}

void greedy_ans(int row)
{
    for(int i=row; i<n; i++)
    {
        int min=0x7fffffff, k;
        for(int j=0; j<n; j++)
            if(!greedy_chk[j] && min>m[i][j])
            {
                min = m[i][j];
                k=j;
            }
        min_sol += min;
        greedy_chk[k] = 1;
    }
}

int main()
{
    input();
    greedy_ans(0);
    solve(0, 0);
    printf("%d\n", min_sol);
    printf("탐색한 정점의 수 : %d\n", counter);
    return 0;
}
*/