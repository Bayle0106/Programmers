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
	
	// ũ���� �������� priority queue ����
	// ��������: priority_queue<int> pq ~~;
	priority_queue<int, vector<int>, greater<int>> pq(data.begin(), data.end());
	
	do
	{
		// top()�� �켱������ ���� ���� ���Ҹ� ����Ŵ. pop���� ����
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
	// while loop�� �ִ������� ������ �� ������ ����� üũ
	if (pq.top() >= K) goal = true;

	if (!goal) answer = -1;
	cout << "answer: " << answer << endl;
}