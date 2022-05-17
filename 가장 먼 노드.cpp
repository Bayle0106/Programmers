#include <vector>

using namespace std;

// 20000 X 0의 벡터 공간 할당
vector<vector<int>> graph(20001, vector<int>(0));
int dp[20001];

void DFS(int s_node, int distance) {
	dp[s_node] = distance;

	for (int n : graph[s_node])
		if (distance + 1 < dp[n]) DFS(n, distance + 1);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	fill_n(dp, n + 1, 987654321);

	// graph에 값 할당
	for (int i = 0; i < edge.size(); ++i)
	{
		int a = edge[i][0];
		int b = edge[i][1];

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 0);

	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] == max) ++answer;
		else if (dp[i] > max)
		{
			answer = 1;
			max = dp[i];
		}
	}

	return answer;
}