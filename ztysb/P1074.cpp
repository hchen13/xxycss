#include <iostream>

using namespace std;

int prime_list[20000];
int prime_count = 0;

// 判断一个数是否是质数
bool is_prime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// 找出小于等于n的所有质数并存储在prime_list中
void find_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_list[prime_count++] = i;
        }
    }
}

// 获取一个数的最大质因数
int get_max_prime_factor(int number) {
    for (int i = prime_count - 1; i >= 0; i--) {
        if (prime_list[i] > number) {
            continue;
        }
        if (number % prime_list[i] == 0) {
            return prime_list[i];
        }
    }
    return 0;
}

int main() {
    find_primes(20000);
    int N;
    scanf("%d", &N);
    int best_serial_number = 0;
    int max_prime_factor = 0;
    for (int i = 0; i < N; i++) {
        int number;
        scanf("%d", &number);
        if (get_max_prime_factor(number) > max_prime_factor) {
            max_prime_factor = get_max_prime_factor(number);
            best_serial_number = number;
        }
    }
    printf("%d\n", best_serial_number);
    return 0;
}