//���̵��:
// stack�� ����� ���ڰ� ���� ���ڿ� ���ٸ� pop�ϰ�
// Ʋ���ٸ� push���Ѵ�.
// string�� ���� ���������� stack�� ����ִٸ� 1 / �ƴ϶�� 0


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
		// stack�� ����ִ� ��쵵 ������ �������� ���
		if (buffer.empty()) buffer.push(s[i]);

		// ���� ���ڿ� ���ٸ� pop / �ٸ��ٸ� push
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