#include<vector>
#include<queue>

using namespace std;

bool visited[100][100] = { false };
int route[100][100] = { 10000 };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;

void BFS(vector<vector<int>> maps) {
    queue<pair<int, int>> q;

    int dis = 1;
    visited[0][0] = true;
    route[0][0] = dis;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        int size = q.size();
        while (size > 0)
        {
            int y = q.front().first;
            int x = q.front().second;

            q.pop();
            --size;

            for (int i = 0; i < 4; ++i)
            {
                int y_ = y + dy[i];
                int x_ = x + dx[i];

                if (0 <= y_ && y_ < N && 0 <= x_ && x_ < M && !visited[y_][x_] && maps[y_][x_] == 1)
                {
                    visited[y_][x_] = true;
                    route[y_][x_] = dis + 1;

                    if (y_ == N - 1 && x_ == M - 1) return;
                    else q.push(make_pair(y_, x_));
                }
            }
        }
        ++dis;
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    N = maps.size();
    M = maps[0].size();

    BFS(maps);
    if (route[N - 1][M - 1] == 0) return -1;
    answer = route[N - 1][M - 1];

    return answer;
}