// 7569.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int M, N, H;
int map[101][101][101];
bool visited[101][101][101];
int cnt = 0;

const int RIPEN = 1;
const int EMPTY = -1;
const int NOT_RIPEN = 0;

//북,서,남,동, 위, 아래
const int BOX_MOVE[6] = { 0, 0, 0, 0, 1, -1 };
const int ROW_MOVE[6] = { -1, 0, 1, 0, 0, 0 };
const int COL_MOVE[6] = { 0, -1, 0, 1, 0, 0 };

class Coord
{
public:
	int x;
	int y;
	int z;
};
queue<Coord> bfsQ;

void Process()
{
	bool cntCheck = true;
	int k = bfsQ.size();
	while (!bfsQ.empty())
	{
		Coord tempCoord = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 6; i++)
		{
			int row = tempCoord.y;
			int col = tempCoord.x;
			int box = tempCoord.z;
			box = box + BOX_MOVE[i];
			row = row + ROW_MOVE[i];
			col = col + COL_MOVE[i];

			if (visited[box][row][col])
				continue;

			if (box < 0 || row < 0 || col < 0)
			{
				continue;
			}

			if (box >= H || row >= N || col >= M)
			{
				continue;
			}
			else if (map[box][row][col] == RIPEN || map[box][row][col] == EMPTY)
			{
				continue;
			}
			else
			{
				cntCheck = true;
				map[box][row][col] = RIPEN;
				visited[box][row][col] = true;
				Coord coord;
				coord.x = col;
				coord.y = row;
				coord.z = box;
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
	for (int z = 0; z < H; z++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[z][i][j] == NOT_RIPEN)
				{
					retCnt++;
				}
			}
		}
	}
	if (retCnt == 0)
		return true;

	return false;
}

int main()
{
	memset(map, -1, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> M >> N >> H;

	for (int z = 0; z < H; z++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[z][i][j];
				if (map[z][i][j] == RIPEN)
				{
					Coord coord;
					coord.z = z;
					coord.x = j;
					coord.y = i;
					bfsQ.push(coord);
					visited[z][i][j] = true;
				}
			}
		}
	}


	if (IsReturn())
	{
		cout << 0;
		return 0;
	}

	Process();

	for (int z = 0; z < H; z++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[z][i][j] == NOT_RIPEN)
				{
					cnt = -1;
					break;
				}
			}
		}
	}
	cout << cnt;

    return 0;
}

