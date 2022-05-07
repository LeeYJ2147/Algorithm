#include <iostream>
using namespace std;

int main() {
    int w, h, b;
    cin >> w >> h >> b;
    double res = (double)w * (double)h * (double)b / 8 / 1024 / 1024;
    printf("%.2lf MB", res);
}