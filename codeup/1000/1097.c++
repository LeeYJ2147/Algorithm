#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    int i, j;
    int baduk[20][20] = {};
    for(i = 1; i<20; i++)
    {
        for(j = 1; j<20; j++)
        {
            cin >> baduk[i][j];
        }
    }
    cin >> n;
    for(i = 0; i<n; i++)
    {
        cin >> x >> y;
        for(j = 1; j<20; j++)
        {
            if(baduk[j][y] == 0) baduk[j][y] = 1;
            else baduk[j][y] = 0;
        }
        for(j = 0; j<20; j++)
        {
            if(baduk[x][j] == 0) baduk[x][j] = 1;
            else baduk[x][j] = 0;
        }
    }

    for(i = 1; i < 20; i++)
    {
        for(j = 1; j < 20; j++)
        {
            cout << baduk[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
