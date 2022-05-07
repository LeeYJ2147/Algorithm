#include <iostream>
using namespace std;

int main() {
    int i;
    char word[21];
    cin >> word;
    for(i=0; word[i] != '\0'; i++)
    {
        cout<<'\''<<word[i]<<'\''<<'\n';
    }
    return 0;
}