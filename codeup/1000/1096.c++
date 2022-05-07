#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    int baduk[20][20] = {};

    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        baduk[x][y] = 1;
    }

    for(int i = 1; i<=19; i++)
    {
        for(int j = 1; j<=19; j++)
        {
            cout << baduk[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
