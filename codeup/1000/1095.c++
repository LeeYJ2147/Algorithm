#include <iostream>
using namespace std;

int main()
{
    int n, a, min = 23;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(min > a) min = a;
    }
    cout << min;
    return 0;
}
