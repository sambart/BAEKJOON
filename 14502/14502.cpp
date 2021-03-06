// 14502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

const int BLANK = 0;
const int WALL = 1;
const int VIRUS = 2;

//동서남북
const int ROW_MOVE[4] = { 0, 0, 1, -1 };
const int COL_MOVE[4] = { 1, -1, 0, 0 };

int N, M;
int map[9][9];
int dfsMap[9][9];
bool visited[9][9];
int maxCnt = 0;

class Coord
{
public:
	int x = 0;
	int y = 0;
};
queue<Coord> bfsQ;

void SpreadBFS(int a_map[9][9], queue<Coord> a_bfsQ)
{
	while (!a_bfsQ.empty())
	{
		Coord curCoord = a_bfsQ.front();
		a_bfsQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int curX = curCoord.x;
			int curY = curCoord.y;

			curX += COL_MOVE[i];
			curY += ROW_MOVE[i];

			if (curX < 0 || curY < 0)
				continue;

			if (curX >= M || curY >= N)
				continue;

			if (a_map[curY][curX] == BLANK)
			{
				a_map[curY][curX] = VIRUS;
				Coord pushCoord;
				pushCoord.x = curX;
				pushCoord.y = curY;
				a_bfsQ.push(pushCoord);
			}
		}
	}
}

void InitDFS()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dfsMap[i][j] = map[i][j];
			visited[i][i] = false;
		}
	}
}

void PrintMap(int a_map[9][9])
{
	cout << "\n";
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << a_map[i][j]<<" ";
		}
		cout << "\n";
	}
}

void WallDFS(int pos, int cnt, int a_map[9][9])
{
	if (cnt == 3)
	{
		SpreadBFS(a_map, bfsQ);
		int safeCnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (a_map[i][j] == BLANK)
					safeCnt++;
			}
		}
		if (maxCnt < safeCnt)
		{
			maxCnt = safeCnt;
		//	PrintMap(a_map);
		}

		return;
	}

	for (int i = pos; i < N*M ; i++)
	{
		int curY = i / M;
		int curX = i % M;

		int tempMap[9][9];
		//MAP 생성
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				tempMap[i][j] = a_map[i][j];
			}
		}

		if (tempMap[curY][curX] == BLANK)
		{
			tempMap[curY][curX] = WALL;
			WallDFS(i, cnt + 1, tempMap);
		//	PrintMap();
		}
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == VIRUS)
			{
				Coord pushCoord;
				pushCoord.x = j;
				pushCoord.y = i;
				bfsQ.push(pushCoord);
			}
		}
	}
	WallDFS(0, 0, map);

	cout << maxCnt;
	//SpreadBFS(bfsQ);
	//PrintMap();
}
