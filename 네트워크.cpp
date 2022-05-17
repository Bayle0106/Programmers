// https://programmers.co.kr/learn/courses/30/lessons/43162
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int visited[201];

void DFS(vector<vector<int>> cpu, int st) {
	stack<int>s;
	visited[st] = 1;
	s.push(st);

	while (!s.empty())
	{
		int a = s.top();
		s.pop();
		for (int i = 0; i < cpu.size(); ++i)
		{
			if (i == a)continue;

			// 경로 존재 + 미방문
			if (cpu[a][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				s.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	memset(visited, 0, sizeof(visited));
	int S = computers.size();

	for (int i = 0; i < S; ++i)
	{
		for (int j = 0; j < S; ++j)
		{
			if (visited[i] == 0)
			{
				DFS(computers, i);
				++answer;
			}
		}
	}
	return answer;
}