#include <cstdio>
#include <cmath>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int N;
    scanf("%d", &N);

    double lower = (sqrt(8 * N + 1) - 1) / 2;

    int row_number = (int)ceil(lower);
    int sum_of_row = (row_number - 1) * row_number / 2;
    bool reverse = row_number % 2 == 0;
    int remain = N - sum_of_row;
    
    int denominator = row_number - remain + 1;
    int nominator = remain;
    if (reverse)
        swap(denominator, nominator);
    
    printf("%d/%d\n", denominator, nominator);
    return 0;
}