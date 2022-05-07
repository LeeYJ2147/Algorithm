#include <iostream>
using namespace std;

int main() {
    int a, r, d, n;
    cin >> a >> r >> d >> n;
    long long int res = a;
    for(int i = 0; i < n-1; i++)
    {
        res *= r;
        res += d;
    }
    cout << res;
    return 0;
}
