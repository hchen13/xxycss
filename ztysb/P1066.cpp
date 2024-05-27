/*
 n个信息学选手站在一排，每个选手的位置依次用l~n表示,第i个信息学选手的编程能力用一个整数Hi表示。
 每个信息学选手都希望找一个编程能力比自己高但又与自己编程能力最接近的选手学习,如果有多个符合条件
 的选手则选择位置在最前面的选手学习。请编程输出每位选手学习对象的位置,如果没有学习对象,则输出0。
*/

#include <cstdio>
using namespace std;

const int MAX_N = 1000000;

int main() {
    int n;
    scanf("%d", &n);
    int H[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &H[i]);
    }

    for (int current_student = 0; current_student < n; current_student++) {
        int target = -1;
        int min_diff = MAX_N;
        int current_skill = H[current_student];
        for (int i = 0; i < n; i++) {
            if (current_student == i) 
                continue;
            if (H[i] > current_skill && H[i] - current_skill < min_diff) {
                target = i;
                min_diff = H[i] - current_skill;
            }
        }
        printf("%d\n", target + 1);
    }

    return 0;
}
