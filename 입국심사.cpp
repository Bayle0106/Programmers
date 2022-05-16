// 1. 이분탐색 방법은 초기의 최소와 최대의 값을 설정한다.
// 2. 기준이 되는 변수를 지정한다. : 이 문제의 경우는 time
// 3. 중간값을 통해 얻은 값이 목표치와의 크기 증감을 통해 새로 설정
// 4. min > max가 될때까지 반복 


#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long human = 0;
	sort(times.begin(), times.end());

	// 최소: 시간이 1이 걸리는 사람들이 다 검사
	long long Min_Time = 1;
	long long Max_Time = (long long)n * times[times.size() - 1];

	while (Min_Time <= Max_Time)
	{
		long long mid = (Min_Time + Max_Time) / 2;
		for (int t : times) human += mid / t;

		// mid 수행결과 목표치 이상이 나온 경우: 왼쪽 영역
		if (human >= n)
		{
			answer = mid;
			Max_Time = mid - 1;
		}

		// mid 수행결과 목표치 이하가 나온 경우: 오른쪽 영역
		else Min_Time = mid + 1;

		human = 0;
	}

	return answer;
}