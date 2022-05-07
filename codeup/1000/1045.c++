#include <iostream>
using namespace std;

int main() {
    int a, b;
    long long int c;
    cin >> a >> b;
    c = a + b;
    cout << c << '\n' << a-b << endl;
    c = a * b;
    cout << c << '\n' << a/b << '\n' << a%b << endl;
    printf("%.2f", float(a) / float(b));
    return 0;
}