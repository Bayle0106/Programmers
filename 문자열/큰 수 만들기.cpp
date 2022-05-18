#include <string>
#include <vector>

using namespace std;

bool cmp(const char a, const char b) {
	return a >= b;
}

string solution(string number, int k) {
	int pos;
	while (k > 0)
	{
		pos = 0;
		for (int i = 0; i <= number.size() - 2; ++i)
		{
			if (!cmp(number[i], number[i + 1])) break;
			else ++pos;
		}
		if (pos == number.size() - 1) number = number.substr(0, pos);
		else number = number.substr(0, pos) + number.substr(pos + 1);
		--k;
	}

	return number;
}