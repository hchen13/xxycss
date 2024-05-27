#include "cstdio"
using namespace std;
int main() {
    int K, counter = 1, length = 0, sum = 0;
    scanf("%d", &K);
    while (length < K) {
        for (int i = 1; i <= counter; i++) {
            sum += counter;
            length++;
            if (length == K) {
                printf("%d\n", sum);
                break;
            }
        }
        counter++;
    }

}