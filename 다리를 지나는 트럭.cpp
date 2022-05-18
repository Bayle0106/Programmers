#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int cur_weight = 0;
	int pos = 0;

	queue<int> q;
	while (1)
	{
		// 기저조건: 전부 다 지나감
		if (pos == truck_weights.size())
		{
			answer += bridge_length;
			break;
		}

		// queue의 크기가 꽉찬 경우: front가 0이면 오는중 아니면 도착
		if (q.size() == bridge_length)
		{
			cur_weight -= q.front();
			q.pop();
		}

		if (cur_weight + truck_weights[pos] <= weight)
		{
			cur_weight += truck_weights[pos];
			q.push(truck_weights[pos++]);
		}

		else q.push(0);

		++answer;

	}

	return answer;
}