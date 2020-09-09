
#include <iostream>

using namespace std;

int compute(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char input[100];
	cin >> input;
	cout << "Hello Goorm! Your input is " << compute(1) << endl;
	return 0;
}

int compute(int n)
{
	return n;
}