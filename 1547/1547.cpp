// 1547.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int ballPos = 1;
int cnt = 0;

int main()
{

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		if (ballPos == a)
			ballPos = b;
		else if (ballPos == b)
			ballPos = a;

	}
	cout << ballPos;
}
