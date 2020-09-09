
#include <iostream>
using namespace std;


int lotto[6];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 6; i++)
	{
		cin >> lotto[i];
		if (i > 0)
		{
			if (lotto[i - 1] >= lotto[i])
			{
				cout << "false";
				return 0;
			}
		}
	}

	cout << "true";

	return 0;

}
