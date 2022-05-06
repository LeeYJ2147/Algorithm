/* f(n)은 n을 역수취한 것
#include <stdio.h>
#include <cmath>

unsigned int f(unsigned int n)
{
    if(n<10) return n;
    printf("%d\n", n);
    return ( (n%10)*powf(10.0, (long long int)log10((double)n)) + f(n/10) );
}

int main()
{
    unsigned int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
*/

// / *f(n)은 맨 뒤와 앞을 바꾸고 중간은 f(m) 부르는 함수
#include <stdio.h>
#include <cmath>

int f(int n)
{
    if(n<10) return n;
    int T=(int)powf(10.0, ((int)log10(n)));
    return (n%10)*T+f((n%T)/10)*10+n/T;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
// * /