//맞앗지롱 ㅋㅋㅋㅋㅋ
#include <stdio.h>

int visited[101], arr[101], n, max=0;

//just calculate score, not make max
int solve(int num, int score)
{
    if(num >= n) return score;
    else
    {
        if(solve(num+1, score+arr[num]) > score) return solve(num+1, score+arr[num]);
        else return score;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++)
        if(max < solve(i, 0)) max = solve(i, 0);
    
    printf("%d", max);
    return 0;
}








/*선형으로 전체탐색
#include <stdio.h>

int n, A[110], ans;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", A+i);
    for(int s=0; s<n; s++)
    {
        for(int e=s, sum; e<n; e++)
        {
            sum=0;
            for(int k=s; k<=e; k++)
                sum += A[k];
            ans = ans<sum ? sum:ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/ 