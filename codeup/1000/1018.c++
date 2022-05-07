#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin>>h;
	cin.ignore(100, ':');
	cin>>m;
	cout<<h<<':'<<m<<endl;
}
