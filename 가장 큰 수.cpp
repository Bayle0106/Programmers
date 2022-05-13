#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;

    for (int i : numbers) tmp.push_back(to_string(i));

    sort(tmp.begin(), tmp.end(), cmp);

    for (string i : tmp) answer += i;

    if (answer[0] == '0') answer = "0";
    return answer;
}