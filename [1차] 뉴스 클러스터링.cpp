#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> init_string(string str) {
	int flag = 0;
	vector<string> str1;

	for (int i = 0; i < str.size() - 1; ++i)
	{
		string tmp = "";

		char a1 = str[i];
		char a2 = str[i + 1];

		a1 = (a1 >= 97) ? a1 - 32 : a1;
		a2 = (a2 >= 97) ? a2 - 32 : a2;

		if (a1 >= 65 && a1 <= 90 && a2 >= 65 && a2 <= 90)
		{
			tmp += a1;
			tmp += a2;
			str1.push_back(tmp);
		}
	}
	return str1;
}

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> t1, t2;

	t1 = init_string(str1);
	t2 = init_string(str2);

	int size_1 = t1.size();
	int size_2 = t2.size();

	if (size_1 == 0 && size_2 == 0) return 65536;

	int same = 0;
	for (int i = 0; i < size_1; ++i)
	{
		// vector의 find
		auto a = find(t2.begin(), t2.end(), t1[i]);
		if (a != t2.end())
		{
			++same;

			// vector에서 특정 위치 삭제하는 법.
			// vector.erase(vector.begin() + index);
			t2.erase(a);
		}
	}

	answer = ((float)same / (float)(size_1 + size_2 - same)) * 65536;
	return answer;
}