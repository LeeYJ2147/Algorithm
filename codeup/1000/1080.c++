#include <iostream>
using namespace std;

int main() {
    int x, i = 1, sum = 0;
    cin >> x;

    while(sum+i < x)
    {
        sum = sum + i;
        i++;
    }
    cout << i;

    return 0;
}
