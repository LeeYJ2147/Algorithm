#include <iostream>
using namespace std;

int main() {
    int n, num;
    cin >> n;

    pri:
    cin >> num;
    cout << num << endl;
    if(--n > 0) goto pri;

    return 0;
}
