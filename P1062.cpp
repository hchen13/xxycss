#include <stdio.h>
using namespace std;

int main() {
    int N, answer = 0;
    scanf("%d", &N);
    int height[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &height[i]);
    }
    for (int i = 0; i < N; i++) {
        int forward = 0, backward = 0;
        // 往前看
        for (int j = 0; j < i; j++) {
            if (height[j] > height[i])
                forward ++;
        }
        // 往后看
        for (int j = i + 1; j < N; j++) {
            if (height[j] > height[i])
                backward ++;
        }

        if (forward == backward)
            answer ++;
    }
    // 输出结果
    printf("%d\n", answer);
    return 0;
}