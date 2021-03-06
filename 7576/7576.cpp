// 7576.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int cnt = 0;
int map[1001][1001] = { -1 };
bool visited[1001][1001];
const int RIPEN = 1;
const int EMPTY = -1;
const int NOT_RIPEN = 0;

//북,서,남,동
const int ROW_MOVE[4] = {-1, 0, 1, 0};
const int COL_MOVE[4] = {0, -1, 0, 1};


class Coord
{
public:
	int x;
	int y;
};
queue<Coord> bfsQ;

void Print()
{
	cout << "\n";
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void Process()
{
	bool cntCheck = true;
	int k = bfsQ.size();
	while (!bfsQ.empty())
	{	
		Coord tempCoord = bfsQ.front(); 
		tempCoord.x = bfsQ.front().x;
		tempCoord.y = bfsQ.front().y;
		bfsQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = tempCoord.y;
			int col = tempCoord.x;
			row = row + ROW_MOVE[i];
			col = col + COL_MOVE[i];

			if (visited[row][col])
				continue;

			if (row < 0 || col < 0)
			{
				continue;
			}

			if (row >= N || col >= M)
			{
				continue;
			}
			else if (map[row][col] == RIPEN || map[row][col] == EMPTY)
			{
				continue;
			}
			else
			{
				cntCheck = true;
				map[row][col] = RIPEN;
				visited[row][col] = true;
				Coord coord;
				coord.x = col;
				coord.y = row;
				bfsQ.push(coord);
			}
		}
		k--;

		if (k == 0)
		{
			k = bfsQ.size();
			if (cntCheck)
			{
				cnt++;
				cntCheck = false;
			}
	//		Print();
		}
	}
}

bool IsReturn()
{
	int retCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == NOT_RIPEN)
			{
				retCnt++;
			}
		}
	}
	if (retCnt == 0)
		return true;

	return false;
}


int main()
{
	cin >> M;
	cin >> N;
	memset(map, -1, sizeof(map));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == RIPEN)
			{
				Coord coord;
				coord.x = j;
				coord.y = i;
				bfsQ.push(coord);
				visited[i][j] = true;
			}
		}
	}


	if (IsReturn())
	{
		cout << 0;
		return 0;
	}

	Process();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == NOT_RIPEN)
			{
				cnt = -1;
				break;
			}
		}
	}
	cout << cnt;
    return 0;
}

