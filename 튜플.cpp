#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
	vector<int> answer;

	map<int, int> m;

	string tmp = "";
	for (int i = 0; i < s.size(); ++i)
	{
		// 구분자와 만난 경우
		if (s[i] == '{' || s[i] == '}' || s[i] == ',')
		{
			// 구분자를 만났지만 tmp의 길이가 0이 아닌 경우
			if (tmp.size() != 0)
			{
				m[stoi(tmp)]++;
				tmp = "";
			}
		}
		// 구분자를 만나지 않은 경우
		else tmp += s[i];
	}

	// vector에 map의 정보를 저장
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		answer.push_back(v[i].first);


	return answer;
}