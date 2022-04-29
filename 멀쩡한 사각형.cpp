using namespace std;

// 유클리드 호제법을 사용한 최대 공약수
int gcd(int a, int b) {
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h;
    int t = gcd(w, h); // 최대 공약수

    // 가장 작은 단위로 나눴을때 선이 지나는 사각형의 개수는
    // 너비 + 높이 - 1
    long long useless = t * (long long)(w / t + h / t - 1);
    answer -= useless;

    return answer;
}