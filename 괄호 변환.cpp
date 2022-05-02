#include <string>
#include <vector>

using namespace std;

string solution(string str) {
	int sum = 0;
	int pos = 0;
	bool check = true; 

	//입력받은 str이 빈 경우
	if (str.size() == 0) return "";

	//균형잡힌으로 분리
	for (char tmp : str)
	{
		if (tmp == '(') ++sum;
		else if (tmp == ')') --sum;
		++pos;

		if (sum < 0) check = false;
		if (sum == 0) break;
	}
	string u, v;
	u = str.substr(0, pos);
	v = str.substr(pos, str.size() - pos);

	// 올바른 경우
	if (check) return u + solution(v);

	// 올바른 x 경우
	else
	{
		string tmp;
		tmp += '(' + solution(v) + ')';
		if (u.size() > 2)
			for (int i = 1; i < u.size() - 1; ++i)
			{
				if (u[i] == '(') tmp += ')';
				else if (u[i] == ')') tmp += '(';
			}
		return tmp;
	}
}