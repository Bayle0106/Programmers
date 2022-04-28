#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>

using namespace std;

string in = "님이 들어왔습니다.";
string out = "님이 나갔습니다.";

int main() {
	vector<string> answer;

	vector<string> record = { "Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" };
	
	vector<vector<string>> records; // 2차원 vector를 통해 값 저장
	map<string, string> user; // tree라고 보면댐

	for (int i = 0; i < record.size(); ++i)
	{
		stringstream str(record[i]); // i번째 string을 ss에 입력
		string act, uid, name;
		str >> act >> uid >> name;
		// 위의 방식처럼 여러개의 string을 streamline에 저장할 수 있음.

		vector<string> tmp;
		tmp.push_back(act);
		tmp.push_back(uid);
		tmp.push_back(name);
		records.push_back(tmp);

		if (act == "Enter" || act == "Change")
			user[uid] = name; // map에 값 할당.
		// 설정한 map은 <string, string>으로 이뤄져 있고
		// uid가 key, name이 value이다.
	}

	cout << "records size: " << records.size() << endl;
	// 2차원 vector의 경우는 행의 개수를 나타냄.

	for (int i = 0; i < records.size(); ++i)
	{
		if (records[i][0] == "Enter")
			answer.push_back(user[records[i][1]] + in);
		else if (records[i][0] == "Leave")
			answer.push_back(user[records[i][1]] + out);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

	return 0;
}