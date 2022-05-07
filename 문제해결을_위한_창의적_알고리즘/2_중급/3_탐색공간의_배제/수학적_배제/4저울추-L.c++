#include <stdio.h>

int w[7] = {1, 3, 9, 27, 81, 243, 729}, thi[8], n, output[7];

void NoTwo(int num)
{
    output[num] = thi[num]%3;
    if(thi[num] > 1) thi[num+1]++;
    if(num==6) return;
    else
    {
        NoTwo(num+1);
        return;
    }
}

void solve(int num)
{
    int temp = num;
    for(int i=6; i>=0; i--)
    {
        thi[i] = temp/w[i];
        temp -= w[i] * thi[i];
    }
    NoTwo(0);

    printf("%d ", num);
    for(int i=0; i<7; i++) if(output[i] == 2) printf("%d ", w[i]);
    printf("0 ");
    for(int i=0; i<7; i++) if(output[i] == 1) printf("%d ", w[i]);    
}

int main()
{
    scanf("%d", &n);
    solve(n);
    return 0;
}

/*
#include <stdio.h>

int w[7] = {1, 3, 9, 27, 81, 243, 729};
int output[9];
int three[7];
int i, j, n, idx;

int chk2(void)
{
    for(int i=0; i<7; i++)
        if(three[i] == 2)
        {
            n = n+w[i];
            output[idx++] = w[i];
            return 2;
        }
    return 0;
}

int main(void)
{
    scanf("%d", &n);
    output[idx++] = n;

    do
        to3(n);
    while (chk2() == 2);

    idx++;
    for(i = 0; i<7; i++)
        if(three[i] == 1)
            output[idx++] = w[i];
    
    for(i=0; i<idx; i++)
        printf("%d ", output[i]);
    return 0;
}
*/






/*장난 / n을 입력하면 1부터 n까지 출력하는 코드
#include <stdio.h>

int w[7] = {1, 3, 9, 27, 81, 243, 729}, thi[8], n, output[7];

void NoTwo(int num)
{
    output[num] = thi[num]%3;
    if(thi[num] > 1) thi[num+1]++;
    if(num==6) return;
    else
    {
        NoTwo(num+1);
        return;
    }
}

void solve(int num)
{
    int temp = num;
    for(int i=6; i>=0; i--)
    {
        thi[i] = temp/w[i];
        temp -= w[i] * thi[i];
    }
    NoTwo(0);

    printf("%d ", num);
    for(int i=0; i<7; i++) if(output[i] == 2) printf("%d ", w[i]);
    printf("0 ");
    for(int i=0; i<7; i++) if(output[i] == 1) printf("%d ", w[i]);    
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("\nstart %d\n", i);
        solve(i);
        printf("\nend %d\n", i);
    }
    return 0;
}