#include <iostream>
using namespace std;

int main()
{
    int gami[10][10] = {};
    int i, j, x, y, che = 0;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            cin >> gami[i][j];
        }
    }

    x = 1;
    y = 1;

    while(true)
    {
        int ny = gami[x][y+1];
        int nx = gami[x+1][y];
        if(gami[x][y] == 2)
        {
            gami[x][y] = 9;
            break;
        }

        gami[x][y] = 9;
        if(ny == 1)
        {
            if(nx == 1) break;
            else x++;
        }
        else y++;
}

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            cout << gami[i][j] << ' ';
        }
        cout << '\n';
    }
}
