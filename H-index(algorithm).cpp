#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations) {
	int answer = 0;

	// 오름차순 배열
	sort(citations.begin(), citations.end());

	answer = citations.size();
	for (int tmp : citations)
	{
		if (tmp < answer) --answer;
		else break;
	}

	return answer;
}