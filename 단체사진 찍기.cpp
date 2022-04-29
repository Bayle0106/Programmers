//�̹� �������� while�� �ƴ� do~while�� ���� ����
// do ~ while�� ������ ���򰡹��� ������ ���.
// next_permutation�� ���� ���� ������ ��ȯ�ϴ� �޼ҵ��ε�
// while������ ���� ù��° ������ ���� �Ǵ��� ��ŵ��.

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool check(int distance, int opr, int diff) {

    // �Ʒ��� ���ó�� boolean �Լ��� ������ �� ����.
    if (opr == '=') return diff == distance;
    else if (opr == '>') return diff > distance;
    else if (opr == '<') return diff < distance;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());
    // friends�� ������������ �迭 : �ʱⰪ

    do
    {
        bool flag = true;
        for (int i = 0; i < data.size(); ++i)
        {
            //string.find: �ش� ������ �ִ� ��ġ�� ��ȯ
            int person1 = friends.find(data[i][0]);
            int person2 = friends.find(data[i][2]);
            int diff = abs(person1 - person2) - 1;

            // 0�� ASCII���� ���־� char data�� int�� ��ȯ
            int distance = data[i][4] - '0';

            if (check(distance, data[i][3], diff)) continue;
            flag = false;
            break;
        }
        if (flag) ++answer;
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}