#include <iostream>
#include <cmath>

using namespace std;

double S0(const double N) {
    double s, i;
    s = 0;
    for (i = N; i <= 22; i++) {
        s += sqrt(i * i + N * N) / i;
    }
    return s;
}

double S1(const double N, const double i) {
    if (i > 22)
        return 0;
    else
        return sqrt(i * i + N * N) / i + S1(N, i + 1);
}

double S2(const double N, const double i) {
    if (i < N)
        return 0;
    else
        return sqrt(i * i + N * N) / i + S2(N, i - 1);
}

double S3(const double N, const double i, double t) {
    t = t + sqrt(i * i + N * N) / i;
    if (i >= 22)
        return t;
    else
        return S3(N, i + 1, t);
}

double S4(const double N, const double i, double t) {
    t = t + sqrt(i * i + N * N) / i;
    if (i <= N)
        return t;
    else
        return S4 (N, i - 1, t);
}

int main()
{
    double N;
    cout << "N = "; cin >> N;

    cout << "(iter)        S0 = " << S0(N) << endl;
    cout << "(rec up ++)   S1 = " << S1(N, N) << endl;
    cout << "(rec up --)   S2 = " << S2(N, 22) << endl;
    cout << "(rec down ++) S3 = " << S3(N, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, 22, 0) << endl;

    system("pause");
    cin.get();
    return 0;
}
