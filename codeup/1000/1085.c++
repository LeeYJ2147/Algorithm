#include <stdio.h>

int main() {
   int h, b, c, s;
   scanf("%d %d %d %d", &h, &b, &c , &s);
   double a;
   a = (double)h * (double)b * (double)c * (double)s / 8 / 1024 / 1024;
   printf("%.1lf MB", a);
}
