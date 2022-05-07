#include <iostream>
using namespace std;

int main() {
    int a[5];
    int j = 10000;
    for(int i=0; i<5; i++) scanf("%1d", &a[i]);
    for(int i=0; i<5; i++)
    {
        cout << "[" << a[i] * j << "]" << endl;
        j /= 10;
    }
    return 0;
}