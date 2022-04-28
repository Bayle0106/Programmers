#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>

using namespace std;

string in = "���� ���Խ��ϴ�.";
string out = "���� �������ϴ�.";

int main() {
	vector<string> answer;

	vector<string> record = { "Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" };
	
	vector<vector<string>> records; // 2���� vector�� ���� �� ����
	map<string, string> user; // tree��� �����

	for (int i = 0; i < record.size(); ++i)
	{
		stringstream str(record[i]); // i��° string�� ss�� �Է�
		string act, uid, name;
		str >> act >> uid >> name;
		// ���� ���ó�� �������� string�� streamline�� ������ �� ����.

		vector<string> tmp;
		tmp.push_back(act);
		tmp.push_back(uid);
		tmp.push_back(name);
		records.push_back(tmp);

		if (act == "Enter" || act == "Change")
			user[uid] = name; // map�� �� �Ҵ�.
		// ������ map�� <string, string>���� �̷��� �ְ�
		// uid�� key, name�� value�̴�.
	}

	cout << "records size: " << records.size() << endl;
	// 2���� vector�� ���� ���� ������ ��Ÿ��.

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