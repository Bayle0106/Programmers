#include<iostream>
#include<string>
using namespace std;

int main() {
	/*
	string str1 = "abcdefghi";

	// string의 2번째 성분 부터 추출
	string sub1 = str1.substr(2);
	cout << sub1 << endl;

	cout << str1.size() << endl;

	// string의 3번째 부터 6개의 성분을 출력
	string sub2 = str1.substr(3, 6);
	cout << sub2 << endl;


	//vector 예제 -> 코드의 str을 vector로 할당해도 된다.
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