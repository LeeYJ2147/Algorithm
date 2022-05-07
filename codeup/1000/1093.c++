#include <iostream>
using namespace std;

int main() {
    int a[24] = {};
    int n, che;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> che;
        a[che] ++;
    }
    for(int i = 0; i < 23; i++)
    {
        cout << a[i+1] << ' ';
    }
}
