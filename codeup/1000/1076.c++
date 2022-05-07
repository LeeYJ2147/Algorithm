#include <iostream>
using namespace std;

int main() {
    char x, t = 'a';
    cin >> x;
    do
    {
        cout << t << ' ';
        t ++;
    }while(t <= x);
    return 0;
}
