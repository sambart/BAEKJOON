// 2455.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int inPerson[4];
int outPerson[4];
int curPerson = 0;
int maxPerson = 0;


int main()
{
	cin >> outPerson[0];
	cin >> inPerson[0];
	cin >> outPerson[1];
	cin >> inPerson[1];
	cin >> outPerson[2];
	cin >> inPerson[2];
	cin >> outPerson[3];
	cin >> inPerson[3];

	for (int i = 0; i < 4; i++)
	{
		curPerson += inPerson[i];
		curPerson -= outPerson[i];

		if (maxPerson < curPerson)
			maxPerson = curPerson;
	}

	cout << maxPerson;

}