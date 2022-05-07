#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    if(score >= 90) cout << "A";
    else if(score >= 70) cout << "B";
    else if(score >= 40) cout << "C";
    else cout << "D";

    return 0;
}
