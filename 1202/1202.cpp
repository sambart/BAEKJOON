// 1202.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>


using namespace std; 

const int MAX = 300000;
int N = 0;
int K = 0;
//int C[MAX];
multiset<int> bag;
long long maxScore = 0;

class Diamond
{
public:
	int weight = 0;
	int value = 0;

public:
	bool operator> (const Diamond &dst)const
	{
		bool ret = false;

		if (value == dst.value)
		{
			return weight > dst.weight;
		}

		return value > dst.value;
	}
};

struct compare
{
	bool operator()(const Diamond &a, const Diamond &b)
	{
		if (a.value == b.value)
			return a.weight > b.weight;
		return a.value < b.value;
	}
};

priority_queue<Diamond, vector<Diamond>, compare> vecDia;
//Diamond dia[MAX];

void solution()
{	
	//sort(vecDia.begin(), vecDia.end(), Cmp);
	//sort(C, C + K);

	maxScore = 0;

	multiset<Diamond>::iterator diaIter;
	while(vecDia.size())
	{
		int weight = vecDia.top().weight;
		int value = vecDia.top().value;
		vecDia.pop();
		auto it = bag.lower_bound(weight);
		if (it == bag.end())
		{
			continue;
		}
		bag.erase(it);
		maxScore += value;
	}
}

int main()
{
	scanf("%d %d", &N,&K);

	for (int i = 0; i < N; i++)
	{
		Diamond dd;
		scanf("%d", &dd.weight);
		scanf("%d", &dd.value);
		vecDia.push(dd);
	}

	for (int i = 0; i < K; i++)
	{
		int temp;
		scanf("%d", &temp);
		bag.insert(temp);
	}

	solution();

	printf("%lld", maxScore);
}
