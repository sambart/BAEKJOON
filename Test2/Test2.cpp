// Test2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
}

#define FOR(i,n) for(int i=0; i< (n);  ++i)

bool hasDuplicate(const vector<int>& array)
{
	FOR(i, array.size())
		FOR(j, i)
		if (array[i] == array[j])
			return true;
	return false;
}
