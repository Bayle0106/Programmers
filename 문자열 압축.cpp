#include<iostream>
#include<string>
using namespace std;

int main() {
	/*
	string str1 = "abcdefghi";

	// string�� 2��° ���� ���� ����
	string sub1 = str1.substr(2);
	cout << sub1 << endl;

	cout << str1.size() << endl;

	// string�� 3��° ���� 6���� ������ ���
	string sub2 = str1.substr(3, 6);
	cout << sub2 << endl;


	//vector ���� -> �ڵ��� str�� vector�� �Ҵ��ص� �ȴ�.
	vector<string> a;
	string str = "hello";

	a.push_back(str);

	cout << a[0] << endl;

	string str1 = "world";
	a.push_back(str1);

	cout << a[1] << endl;

*/
	string str;
	cin >> str;
	cout << str << endl;
	int size = str.size();
	int answer = size;
	
	for (int num = 1; num <= size / 2; ++num)
	{
		int cnt = 1;
		string tmp = "";
		string a = "";

		a = str.substr(0, num);
		for (int i = num; i < size; i += num)
		{
			if (str.substr(i, num) == a) cnt++;
			else
			{
				if (cnt > 1)tmp += to_string(cnt);
				tmp += a;
				a = str.substr(i, num);
				cnt = 1;
			}
		}
		if (cnt > 1)tmp += to_string(cnt);
		tmp += a;

		//if (tmp.size() < answer) answer = tmp.size();
		answer = tmp.size() < answer ? tmp.size() : answer;
	}
	cout << "answer: " << answer << endl;
	return answer;
}