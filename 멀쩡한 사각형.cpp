using namespace std;

// ��Ŭ���� ȣ������ ����� �ִ� �����
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
    int t = gcd(w, h); // �ִ� �����

    // ���� ���� ������ �������� ���� ������ �簢���� ������
    // �ʺ� + ���� - 1
    long long useless = t * (long long)(w / t + h / t - 1);
    answer -= useless;

    return answer;
}