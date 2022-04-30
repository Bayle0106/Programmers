#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main() {
	vector<int> progress = { 93, 30 ,55 };
	vector<int> speeds = { 1, 30, 5 };
	vector<int> answer;

	// day: 경과 일수, done: 끝난 총 작업 수
	int day = 0, done = 0;
	int size = progress.size();

	while (1)
	{
		if (done == size) break;

		int t = 1;
		day += (100 - progress[done]) / speeds[done];
		if (progress[done] + speeds[done] * day < 100) ++day;

		++done;
		for (int i = done; i < size; ++i)
		{
			if (progress[done] + speeds[done] * day >= 100)
			{
				++done;
				++t;
			}
			else break;
		}
		answer.push_back(t);
	}
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
}
