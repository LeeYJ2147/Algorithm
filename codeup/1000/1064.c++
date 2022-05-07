#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int min = a<b ? a:b;
    min = min<c ? min:c;
    printf("%d", min);
    return 0;
}