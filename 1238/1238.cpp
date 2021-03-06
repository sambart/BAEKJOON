#include "pch.h"

#include <vector>
#include <iostream>
#include <list>
#include <limits.h>
#include <memory.h>
#include <list>

using namespace std;

class Vertex
{
public:
	int time[1001];
	int edgeCnt = 0;
	int dTime[1001];
	int visited[1001];

public:
	Vertex(int idx)
	{
		memset(visited, false, sizeof(visited));
		memset(time, -1, sizeof(time));
		for (int i = 0; i < 1001; i++)
		{
			dTime[i] = INT_MAX;
		}
		time[idx] = 0;
		dTime[idx] = 0;
	}

	void AddEdge(int idx, int a_time)
	{
		time[idx] = a_time;
		//	dTime[idx] = a_time;
		if (edgeCnt < idx + 1)
			edgeCnt = idx + 1;
	}

};

class Graph
{
public:
	Vertex* vertexList[1001];
	int vertexCnt = 1;

public:
	Graph(int vertexNum)
	{
		for (int i = 1; i < vertexNum + 1; i++)
		{
			Vertex *tempVer = new Vertex(i);
			vertexList[i] = tempVer;
			vertexCnt++;
		}
	}
	void AddEdge(int from, int to, int time)
	{
		vertexList[from]->AddEdge(to, time);
	}

	int Search(int from, int to)
	{
		Vertex *fromVer = vertexList[from];

		int min = INT_MAX;
		int idx = from;
		Vertex *currentVer = fromVer;


		while (true)
		{
		//	if (!currentVer->isVisted)
		//	{
				//1. dTime 계산
				for (int i = 0; i < currentVer->edgeCnt; i++)
				{
					if (currentVer->time[i] == -1)
						continue;


					if (currentVer->time[i] + fromVer->dTime[idx] < fromVer->dTime[i])
						fromVer->dTime[i] = currentVer->time[i] + fromVer->dTime[idx];
				}
			//	currentVer->isVisted = true;
		//	}

		//	if (notVisited.empty())
		//		return fromVer->dTime[to];

			//2.dTime가장 작은곳, Q에 있는 곳 탐색
			int min = INT_MAX;
			for (int i = 0; i < fromVer->edgeCnt; i++)
			{
				if (fromVer->dTime[i] == -1)
					continue;

				if (fromVer->dTime[i] < min)
				{
					if (!fromVer->visited[i])
					{
						min = fromVer->dTime[i];
						idx = i;
						fromVer->visited[i] = true;
						break;
					}
				}
			}
			if (min == INT_MAX)
				return fromVer->dTime[to];

			//3. Q제거

			//4. 반복
			currentVer = vertexList[idx];

	//		if (idx == to)
	//			return fromVer->dTime[to];
		}
	}
};
int N = 0;
int M = 0;
int X = 0;

int main()
{
	cin >> N >> M >> X;
	Graph graph(N);
	Graph reverse(N);

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		graph.AddEdge(from, to, time);
		reverse.AddEdge(to, from, time);
	}

	int max = -1;
	graph.Search(X, X);
	reverse.Search(X, X);

	for (int i = 1; i < graph.vertexCnt; i++)
	{
		int cost = 0;
		cost += graph.vertexList[X]->dTime[i];
		cost += reverse.vertexList[X]->dTime[i];

		if (max < cost)
			max = cost;
	}

	cout << max;
}