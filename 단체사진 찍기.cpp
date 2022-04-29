//이번 문제에서 while이 아닌 do~while을 쓰는 이유
// do ~ while은 선실행 후평가문의 성격을 띈다.
// next_permutation의 경우는 다음 순열을 반환하는 메소드인데
// while문으로 들어가면 첫번째 순열에 대한 판단이 스킵됨.

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool check(int distance, int opr, int diff) {

    // 아래의 방식처럼 boolean 함수를 리턴할 수 있음.
    if (opr == '=') return diff == distance;
    else if (opr == '>') return diff > distance;
    else if (opr == '<') return diff < distance;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());
    // friends를 오름차순으로 배열 : 초기값

    do
    {
        bool flag = true;
        for (int i = 0; i < data.size(); ++i)
        {
            //string.find: 해당 성분이 있는 위치를 반환
            int person1 = friends.find(data[i][0]);
            int person2 = friends.find(data[i][2]);
            int diff = abs(person1 - person2) - 1;

            // 0의 ASCII값을 빼주어 char data를 int로 변환
            int distance = data[i][4] - '0';

            if (check(distance, data[i][3], diff)) continue;
            flag = false;
            break;
        }
        if (flag) ++answer;
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}