//아이디어:
// stack에 저장된 문자가 다음 문자와 같다면 pop하고
// 틀리다면 push를한다.
// string의 끝에 도달했을때 stack이 비어있다면 1 / 아니라면 0


#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	string s = "cdcd";
	stack<char> buffer;
	int answer;

	buffer.push(s[0]);
	for (int i = 1; i < s.length(); ++i)
	{
		// stack이 비어있는 경우도 있으니 기저조건 고려
		if (buffer.empty()) buffer.push(s[i]);

		// 다음 문자와 같다면 pop / 다르다면 push
		else
		{
			if (buffer.top() == s[i]) buffer.pop();
			else buffer.push(s[i]);
		}
	}
	if (!buffer.empty()) answer = 0;
	else answer = 1;

	cout << "answer: " << answer << endl;
}