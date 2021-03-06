// 15806.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;


class Tile
{
public:
	int x;
	int y;
};

const int ROW_MOVE[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int COL_MOVE[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool map[301][301];
bool prevMap[301][301];
Tile cleans[100000];

//방크기
int N = 0;
//곰팡이 개수
int M = 0;
//청소 검사 개수
int K = 0;
//청소일자
int t = 0;

queue<Tile> dustQ;

bool CleanTest()
{
	for (int i = 0; i < K; i++)
	{
		int x = cleans[i].x;
		int y = cleans[i].y;

		//청소해야됨
		if (map[y][x] == true)
			return false;
	}

	return true;
}

void Process()
{
	queue<Tile> retQ;
	bool swapMap[301][301];
	memcpy(swapMap, prevMap, sizeof(map));
	memcpy(prevMap, map, sizeof(map));
	memcpy(map, swapMap, sizeof(map));

	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = false;
		}
	}*/


	while (!dustQ.empty())
	{
		Tile tempTIle = dustQ.front();
		int x = tempTIle.x;
		int y = tempTIle.y;
		dustQ.pop();

		for (int i = 0; i < 8; i++)
		{
			int moveX = x;
			int moveY = y;		

			moveY += ROW_MOVE[i];
			moveX += COL_MOVE[i];

			if (map[moveY][moveX])
				continue;

			if (moveX < 0 || moveY < 0)
			{
				continue;
			}

			if (moveX >= N || moveY >= N)
			{
				continue;
			}


			map[moveY][moveX] = true;
			Tile moveTile;
			moveTile.x = moveX;
			moveTile.y = moveY;
			retQ.push(moveTile);
		}
	}

	dustQ = retQ;
//	return retQ;
}

int main()
{
	memset(map, false, sizeof(map));
	memset(prevMap, false, sizeof(prevMap));

	cin >> N >> M >> K >> t;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		Tile tile;
		tile.x = x - 1;
		tile.y = y - 1;
		map[y][x] = true;
		dustQ.push(tile);
	}
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		Tile tile;
		tile.x = x - 1;
		tile.y = y - 1;
		cleans[i] = tile;
	}

	for (int i = 0; i < t; i++)
	{
		 Process();
	//	 memcpy(prevMap, map, sizeof(map));
	}

	if (!CleanTest())
		cout << "YES";
	else
		cout << "NO";
    return 0;
}

