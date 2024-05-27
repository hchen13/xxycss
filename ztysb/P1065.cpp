#include <cstdio>
using namespace std;

int main() {
    // 定义、输入数据
    int n;
    scanf("%d", &n);
    int score[n], grade[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &score[i], &grade[i]);
    }
    // 同时对成绩、年级、学号进行冒泡排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (score[i] < score[j] || (score[i] == score[j] && grade[i] > grade[j])) {
                // 交换成绩
                int tmp = score[i];
                score[i] = score[j];
                score[j] = tmp;
                // 交换年级
                tmp = grade[i];
                grade[i] = grade[j];
                grade[j] = tmp;
            }
        }
    }
    // 排序后按成绩从高到低输出每个学生对应的更优秀人数
    for (int i = 0; i < n; i++) {
        int better = 0;
        for (int j = 0; j < i; j++) if (grade[j] < grade[i]) 
            better ++;
        printf("%d\n", better);
    }
    return 0;
}
