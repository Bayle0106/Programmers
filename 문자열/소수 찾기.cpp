#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

bool check(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0) return false;
	return true;
}

int solution(string numbers) {
	int answer = 0;
	set<int> s;
	sort(numbers.begin(), numbers.end());
	do
	{
		for (int i = 1; i <= numbers.size(); ++i)
		{
			string tmp = numbers.substr(0, i);
			s.insert(stoi(tmp));
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	set<int>::iterator it = s.begin();
	while (!s.empty())
	{
		if (check(*it)) ++answer;
		s.erase(it++);
	}
	return answer;
}