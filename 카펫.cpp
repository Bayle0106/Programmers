#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	for (int i = 1; i <= sqrt(yellow); ++i)
	{
		if (yellow % i != 0) continue;

		int w, h;
		w = yellow / i;
		h = i;

		if (2 * (w + h + 2) == brown)
		{
			answer.push_back(w + 2);
			answer.push_back(h + 2);
			break;
		}
	}
	sort(answer.begin(), answer.end(), greater<int>());

	return answer;
}