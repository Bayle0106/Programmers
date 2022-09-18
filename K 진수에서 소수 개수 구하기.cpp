#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int answer = 0;

// �Ҽ� �Ǵ�
bool checkPN(string currentNum) {
	if (currentNum.length() == 0) return false;
	long long tmp = stoll(currentNum);

	if (tmp < 2) return false;
	int sq = sqrt(tmp) + 1; // int�� ��ȯ�Ҷ� sqrt�� ������ ������ ���� -> +1�� �� �����.

	for (int i = 2; i < sq; ++i) {
		if (tmp % i == 0) return false;
	}

	return true;
}

// k���� ��ȯ
string convertK(int inputNum, int k) {
	int tmp;
	string result = "";

	while (inputNum != 0) {
		tmp = inputNum % k;
		inputNum = inputNum / k;
		result += to_string(tmp);
	}
	reverse(result.begin(), result.end());
	return result;
}

// string �Ǵ�
void findout(string num) {
	int idx = 0;
	string tmp;

	do {
		for (int i = idx; i < num.length(); ++i) {
			// 0�� ���� ���.
			if (num[i] == '0') break;

			// 0�� �ƴ� ���.
			else tmp += num[i];
		}

		if (checkPN(tmp)) answer++;

		idx += tmp.length() + 1;
		tmp = "";
	} while (idx < num.length());
}

int solution(int n, int k) {
	string convertedN = convertK(n, k);
	findout(convertedN);

	return answer;
}