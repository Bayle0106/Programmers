#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 우선순위 큐의 compare 함수 설정
struct compare {
	bool operator()(vector<int> a, vector<int> b) {

		// a[1] > b[1]일때 true를 반환하고 swap을 진행 -> 오름차순으로 정렬됨.
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	// 우선순위 큐를 오름차순으로 정렬 
	// 2차원 vector의 priority queue 설정과 compare함수 설정
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	// jobs 정렬
	sort(jobs.begin(), jobs.end());

	int current_time = 0;
	int pos = 0;

	while (pos < jobs.size() || !pq.empty())
	{
		// 현재의 job이 current_time보다 작을 때
		if (pos < jobs.size() && jobs[pos][0] <= current_time)
		{
			pq.push(jobs[pos++]);
			continue;
		}

		// pq에 값이 있을 때 = current_time 기준으로 할 작업이 있는 경우.
		if (!pq.empty())
		{
			current_time += pq.top()[1];
			answer += current_time - pq.top()[0];
			pq.pop();
		}

		else
		{
			current_time = jobs[pos][0];
		}
	}

	return answer / jobs.size();
}