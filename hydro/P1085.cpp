#include <cstdio>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int max_unhappy_value = 0;
    int unhappy_threshold = 8;
    int day_of_most_unhappy = 0;
    for (int _ = 0; _ < 7; _++) {
        int school_time, train_time;
        scanf("%d%d", &school_time, &train_time);
        int unhappy_value = school_time + train_time - unhappy_threshold;
        if (unhappy_value > max_unhappy_value) {
            max_unhappy_value = unhappy_value;
            day_of_most_unhappy = _ + 1;
        }
    }
    printf("%d\n", day_of_most_unhappy);
    return 0;
}