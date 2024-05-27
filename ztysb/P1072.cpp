#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


void clearBit(unsigned int* bitArray, unsigned int index) {
    bitArray[index / 32] &= ~(1U << (index % 32));
}

bool isBitSet(const unsigned int* bitArray, unsigned int index) {
    return bitArray[index / 32] & (1U << (index % 32));
}

int main() {
    unsigned int N;
    scanf("%u", &N);
    unsigned int SQRT_N = (unsigned int)(sqrt(N)) + 1;
    unsigned int arraySize = (N + 31) / 32;
    unsigned int* bitArray = (unsigned int*)malloc(arraySize * sizeof(unsigned int));

    for (unsigned int i = 0; i < arraySize; ++i) {
        bitArray[i] = 0xFFFFFFFF;
    }

    clearBit(bitArray, 0);
    clearBit(bitArray, 1);

    for (unsigned int p = 2; p <= SQRT_N; ++p) {
        if (isBitSet(bitArray, p)) {
            for (unsigned int multiple = p * p; multiple <= N; multiple += p) {
                clearBit(bitArray, (unsigned int)(multiple));
            }
        }
    }

    for (unsigned int i = 3; i + 2 <= N; i += 2) {
        if (isBitSet(bitArray, i) && isBitSet(bitArray, i + 2)) {
            printf("%u %u\n", i, i + 2);
        }
    }

    free(bitArray); 
    return 0;
}

// bool is_prime(int x) {
//     if (x < 2) return false;
//     for (int i = 2; i * i <= x; i++) {
//         if (x % i == 0) return false;
//     }
//     return true;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 3; i + 2 <= n; i += 2) {
//         if (is_prime(i) && is_prime(i + 2)) {
//             printf("%d %d\n", i, i + 2);
//         }
//     }
//     return 0;
// }
