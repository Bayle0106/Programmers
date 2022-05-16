#include<string>
#include<vector>
#include<stack>
#include<set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	// n개의 길이만큼 'X'할당
	string answer(n, 'X');

	set<int> table;
	stack<int> removed;

	for (int i = 0; i < n; ++i)table.insert(i);
	auto iter = table.find(k);

	for (string str : cmd)
	{
		if (str[0] == 'U' || str[0] == 'D')
		{
			int num = stoi(str.substr(2));
			if (str[0] == 'U')
				while (num--)
					iter = prev(iter);
			else
				while (num--)
					iter = next(iter);
		}

		// 삭제
		else if (str[0] == 'C')
		{
			removed.push(*iter);

			// erase는 삭제 후 다음 반복자를 가리킴.
			iter = table.erase(iter);
			if (iter == table.end()) iter = prev(iter);
		}

		else if (str[0] == 'Z')
		{
			table.insert(removed.top());
			removed.pop();
		}
	}

	for (int i : table) answer[i] = 'O';
	return answer;
}