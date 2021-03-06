// 2579.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int dM[301] = { 0 };
int dJ[301] = { 0 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int stair = 0;
		cin >> stair;

		if (i < 1)
		{
			dM[0] = stair;
			continue;
		}

		else if (i == 1)
		{
			dM[i] = dM[i - 1] + stair;
			dJ[i] = stair;
			continue;
		}
		dM[i] = dJ[i - 1] + stair;

		dJ[i] = max(dM[i - 2] + stair, dJ[i-2] + stair);

	}
	int result = 0;
	result = max(dM[N-1], dJ[N-1]);
	cout << result;

    return 0;
}

