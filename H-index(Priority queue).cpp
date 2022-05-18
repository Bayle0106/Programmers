#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		// a>b이면 swap 수행 -> 오름차순 배열 / 이번문제는 그냥 greater<int>쓰면댐
		return a > b;
	}
};

int solution(vector<int> citations) {
	int answer = 0;

	// 우선순위 큐는 중복값을 허용한다. + 작성한 compare 기준의 pq생성
	priority_queue<int, vector<int>, cmp> pq;

	// pq에 citation 정보 입력
	for (int tmp : citations) pq.push(tmp);
	answer = citations.size();

	while (!pq.empty())
	{
		if (pq.top() < answer) --answer;
		else break;
		pq.pop();
	}

	return answer;
}