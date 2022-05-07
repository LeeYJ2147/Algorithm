#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    long long int sum;
    cin >> a >> b >> c;
    sum = a + b + c;
    cout << sum << endl;
    printf("%.1f", float(sum) / float(3));
    return 0;
}