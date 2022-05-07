#include <iostream>
using namespace std;

int main() {
    int a, r, n;
    long long int res = 1;
    cin >> a >> r >> n;
    for(int i = 0; i<n-1; i++)
    {
        res = res*r;
    }
    res = res*a;
    cout << res;
}
