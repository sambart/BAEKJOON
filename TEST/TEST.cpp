// BAEKJOON.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;


int N = 0;
int dR[1000] = { -1 };
int dG[1000] = { -1 };
int dB[1000] = { -1 };

int R[1000] = { -1 };
int B[1000] = { -1 };
int G[1000] = { -1 };

int Process()
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			dR[0] = R[0];
			dG[0] = G[0];
			dB[0] = B[0];

			continue;
		}
		dR[i] = min(dG[i - 1] + R[i], dB[i - 1] + R[i]);
		dG[i] = min(dR[i - 1] + G[i], dB[i - 1] + G[i]);
		dB[i] = min(dR[i - 1] + B[i], dG[i - 1] + B[i]);
	}

	int result = min(dR[N - 1], min(dG[N - 1], dB[N - 1]));
	return result;
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> R[i];
		cin >> G[i];
		cin >> B[i];

	}

	cout << Process();
	return 0;
}

