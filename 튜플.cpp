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
		// �����ڿ� ���� ���
		if (s[i] == '{' || s[i] == '}' || s[i] == ',')
		{
			// �����ڸ� �������� tmp�� ���̰� 0�� �ƴ� ���
			if (tmp.size() != 0)
			{
				m[stoi(tmp)]++;
				tmp = "";
			}
		}
		// �����ڸ� ������ ���� ���
		else tmp += s[i];
	}

	// vector�� map�� ������ ����
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		answer.push_back(v[i].first);


	return answer;
}