#include<vector>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int main(){
	vector<int> data = { 1,2,3,9,10,12 };
	int answer = 0;
	int K = 7;
	bool goal = false;
	
	// 크기의 역순으로 priority queue 설정
	// 오름차순: priority_queue<int> pq ~~;
	priority_queue<int, vector<int>, greater<int>> pq(data.begin(), data.end());
	
	do
	{
		// top()은 우선순위가 가장 높은 원소를 가리킴. pop역시 동일
		int first = pq.top();
		pq.pop();

		if (first >= K)
		{
			goal = true;
			break;
		}

		int second = pq.top();
		pq.pop();
		pq.push(first + second * 2);
		++answer;
	} while (answer < data.size() - 1);
	// while loop이 최대한으로 돌았을 때 마지막 결과물 체크
	if (pq.top() >= K) goal = true;

	if (!goal) answer = -1;
	cout << "answer: " << answer << endl;
}