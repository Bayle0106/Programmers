#include<vector>
#include<string>
#include<map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer(2, 0);
	int head = 0;
	int tail = 0;
	int len = 987654321;
	map<string, int> m;
	for (string str : gems)
	{
		// 새로운 값: answer 초기화
		if (m.find(str) == m.end()) len = 987654321;

		++m[str];
		++tail;

		// head가 가리키는 원소의 개수가 여러개
		while (m[gems[head]] > 1) --m[gems[head++]];

		if (tail - head < len)
		{
			len = tail - head;
			answer[0] = head + 1;
			answer[1] = tail;
		}
	}
	return answer;
}