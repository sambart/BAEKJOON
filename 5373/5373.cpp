// 5373.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int n;

// 0 - 윗면 U
// 1 - 앞면 F
// 2 - 아랫면 D
// 3 - 뒷면 B
// 4 - 왼면 L
// 5 - 오른면 R
char cube[3][3][3];

class Myun
{
	char arr[3][3];

	Myun *upM;
	Myun *downM;
	Myun *leftM;
	Myun *rightM;

	void Roll()
	{
		upM[0][0][1];
	}
};

class Cube
{
	Myun listM[6];

	Cube()
	{

	}
};

void Roll(char myun, char foward)
{

}

int main()
{
    std::cout << "Hello World!\n"; 
}
