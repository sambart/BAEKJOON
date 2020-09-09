// 3015.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i = 0;
	cin >> i;
	if ((i % 2) == 0)
		cout << "odd";
	else
		cout << "even";
}
