#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

map<string, int> car_time;
map<string, int> car_inOut;

int convertToMinute(string time) {
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3, 2));
	int result = (hour * 60) + minute;

	return result;
}



void caculateTimes(vector<int> fees, vector<string> records) {
	for (string record : records) {
		string time, carNumber, InorOut;
		stringstream stream;
		stream.str(record);
		stream >> time >> carNumber >> InorOut;

		int t = convertToMinute(time);

		// In인 경우.
		if (InorOut == "IN") {
			car_inOut[carNumber] = t;
		}

		// Out의 경우.
		else {
			if (!car_time.count(carNumber)) car_time[carNumber] = 0;
			car_time[carNumber] += t - car_inOut[carNumber];
			car_inOut[carNumber] = 9999;
		}
	}

	// 23:59까지 출차 안된 경우 확인
	for (auto tmp : car_inOut) {
		if (tmp.second != 9999) {
			car_time[tmp.first] += 1439 - tmp.second;
			tmp.second = 9999;
		}
	}
}

vector<int> calculateFees(vector<int> fees) {
	vector<int> ans;

	for (auto tmp : car_time) {
		int parkingTime = tmp.second;

		if (parkingTime <= fees[0]) {
			ans.push_back(fees[1]);
			continue;
		}

		int total_fee = fees[1] + ceil((float)(parkingTime - fees[0]) / fees[2]) * fees[3];
		ans.push_back(total_fee);
	}
	return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	caculateTimes(fees, records);
	answer = calculateFees(fees);

	return answer;
}