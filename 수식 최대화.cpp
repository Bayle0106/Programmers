#include <string>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long operate(long long a, long long b, char op) {
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

long long solution(string expression) {
	long long answer = 0;

	vector<long long> num;
	vector<char> exp, location;

	string tmp = "";
	for (int i = 0; i < expression.size(); ++i)
	{
		if (expression[i] > 46) tmp += expression[i];
		else
		{
			num.push_back(stoi(tmp));
			tmp = "";

			if (find(exp.begin(), exp.end(), expression[i]) == exp.end()) exp.push_back(expression[i]);
			location.push_back(expression[i]);
		}
	}

	num.push_back(stoi(tmp));

	// 현재 파일에 있는 operator를 sorting -> next_permutation 사용하기 위해.
	sort(exp.begin(), exp.end());

	do
	{
		vector<long long> num_ = num;
		vector<char> loc_ = location;

		// 모든 연산자 loop
		for (int i = 0; i < exp.size(); ++i)
		{
			// 연산자 vector의 경우 계산
			for (int j = 0; j < loc_.size(); ++j)
			{
				if (loc_[j] == exp[i])
				{
					// 계산의 결과값을 j번째에 저장
					num_[j] = operate(num_[j], num_[j + 1], loc_[j]);
					num_.erase(num_.begin() + j + 1);
					loc_.erase(loc_.begin() + j);
					--j;
				}
			}
		}
		if (abs(num_[0]) > answer) answer = abs(num_[0]);
	} while (next_permutation(exp.begin(), exp.end()));

	return answer;
}