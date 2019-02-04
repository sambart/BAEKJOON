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

public:
	char arr[3][3];

	Myun *upM;
	Myun *downM;
	Myun *leftM;
	Myun *rightM;

	//시계방향
	void RollW()
	{
		char tempArr[3];
		tempArr[0] = upM->arr[2][0];
		tempArr[1] = upM->arr[2][1];
		tempArr[2] = upM->arr[2][2];

		upM->arr[2][0] = leftM->arr[0][2];
		upM->arr[2][1] = leftM->arr[1][2];
		upM->arr[2][2] = leftM->arr[2][2];

		leftM->arr[0][2] = downM->arr[0][0];
		leftM->arr[1][2] = downM->arr[0][1];
		leftM->arr[2][2] = downM->arr[0][2];

		downM->arr[0][0] = rightM->arr[0][0];
		downM->arr[0][1] = rightM->arr[1][0];
		downM->arr[0][2] = rightM->arr[2][0];

		rightM->arr[0][0] = tempArr[0];
		rightM->arr[1][0] = tempArr[1];
		rightM->arr[2][0] = tempArr[2];
	}

	//반시계 방향
	void RollR()
	{
		char tempArr[3];
		tempArr[0] = upM->arr[2][0];
		tempArr[1] = upM->arr[2][1];
		tempArr[2] = upM->arr[2][2];

		upM->arr[2][0] = rightM->arr[0][0];
		upM->arr[2][1] = rightM->arr[1][0];
		upM->arr[2][2] = rightM->arr[2][0];

		rightM->arr[0][0] = downM->arr[0][0];
		rightM->arr[1][0] = downM->arr[0][1];
		rightM->arr[2][0] = downM->arr[0][2];

		downM->arr[0][0] = leftM->arr[0][2];
		downM->arr[0][1] = leftM->arr[1][2];
		downM->arr[0][2] = leftM->arr[2][2];

		leftM->arr[0][2] = tempArr[0];
		leftM->arr[1][2] = tempArr[1];
		leftM->arr[2][2] = tempArr[2];
	}

};

class Cube
{
public:
	char colorArr[6] = { 'w', 'r', 'y', 'o', 'g', 'b' };
	Myun listM[6];

	Cube()
	{
		//색 초기화
		for (int i = 0; i < 6; i++)
		{
			Myun tempM;
			for (int j = 0; j < 3; j++)
			{
				for (int z = 0; z < 3; z++)
				{
					tempM.arr[j][z] = colorArr[i];
				}
			}

			listM[i] = tempM;
		}

		//w
		listM[0].upM = &(listM[3]);
		listM[0].downM = &(listM[1]);
		listM[0].leftM = &(listM[4]);
		listM[0].rightM = &(listM[5]);

		//r
		listM[1].upM = &(listM[0]);
		listM[1].downM = &(listM[2]);
		listM[1].leftM = &(listM[4]);
		listM[1].rightM = &(listM[5]);

		//y
		listM[2].upM = &(listM[1]);
		listM[2].downM = &(listM[3]);
		listM[2].leftM = &(listM[4]);
		listM[2].rightM = &(listM[5]);

		//o
		listM[3].upM = &(listM[2]);
		listM[3].downM = &(listM[0]);
		listM[3].leftM = &(listM[4]);
		listM[3].rightM = &(listM[5]);

		//g
		listM[4].upM = &(listM[0]);
		listM[4].downM = &(listM[2]);
		listM[4].leftM = &(listM[3]);
		listM[4].rightM = &(listM[1]);

		//b
		listM[5].upM = &(listM[0]);
		listM[5].downM = &(listM[2]);
		listM[5].leftM = &(listM[1]);
		listM[5].rightM = &(listM[3]);

	}

	void Rotate(char myun, char foward)
	{
		int idx = 0;
		switch (myun)
		{
		case 'U':
			idx = 0;
			break;
		case 'F':
			idx = 1;
			break;
		case 'D':
			idx = 2;
			break;
		case 'B':
			idx = 3;
			break;
		case 'L':
			idx = 4;
			break;
		case 'R':
			idx = 5;
			break;

		default:
			break;
		}

		if (foward == '+')
			listM[idx].RollW();
		else
			listM[idx].RollR();
	}
};

int main()
{
	Cube mainCube;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			char myun;
			char foward;

			cin >> myun >> foward;

			mainCube.Rotate(myun, foward);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int z = 0; z < 3; z++)
			{
				cout << mainCube.listM[i].arr[j][z];
			}
			cout << "\n";
		}
	}
}
