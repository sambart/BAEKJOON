// 1932.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

int N = 0;
int dMap[500][500];

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int temp;
			cin >> temp;
			
			dMap[i][j] = max(dMap[i - 1][j] + temp, dMap[i][j]);

			if (j == 0)
				continue;

			dMap[i][j] = max(dMap[i - 1][j - 1] + temp, dMap[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result = max(dMap[N - 1][i], result);
	}
	cout << result;

    return 0;
}

