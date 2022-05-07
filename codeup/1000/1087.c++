#include <iostream>
using namespace std;

int main() {
    int n, i, sum = 0;
    cin >> n;
    for(i = 1; ; i++)
    {
        sum = sum + i;
        if(sum >= n) break;
    }
    cout << sum;
}
