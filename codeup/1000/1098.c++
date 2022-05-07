#include <iostream>
using namespace std;

int main()
{
    int h, w, n, l, d, x, y;
    int baduk[100][100] = {};

    cin >> h >> w >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> d >> x >> y;
        if(d == 0)
        {
            for(int j = y; j < y+l; j++) baduk[x][j] = 1;
        }
        else
        {
            for(int j = x; j < x+l; j++) baduk[j][y] = 1;
        }
    }

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cout << baduk[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
