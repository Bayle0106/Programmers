#include <vector>

using namespace std;

int answer = -1;
int visited[8];

void DFS(vector<vector<int>> dungeons, int k, int pos, int dis) {
	k -= dungeons[pos][1];
	for (int i = 0; i < dungeons.size(); ++i)
	{
		// 다음 던전으로 이동 가능
		if (visited[i] == 0 && k >= dungeons[i][0])
		{
			visited[i] = 1;
			DFS(dungeons, k, i, dis + 1);
			visited[i] = 0;
		}
		else answer = max(answer, dis);
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	for (int i = 0; i < dungeons.size(); ++i)
	{
		fill_n(visited, 8, 0);
		visited[i] = 1;
		DFS(dungeons, k, i, 1);
	}
	return answer;
}