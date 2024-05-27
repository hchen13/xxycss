#include <cstdio>
using namespace std;

bool used[10] = {false};
int numbers[3];
int y_arr[3];
int z_arr[3];

int compose_number(int a, int b, int c) {
    return a * 100 + b * 10 + c;
}

void decompose_number(int num, int* arr) {
    arr[0] = num / 100;
    arr[1] = num / 10 % 10;
    arr[2] = num % 10;
}

void make_number(int position) {
    if (position == 3) {
        int x = compose_number(numbers[0], numbers[1], numbers[2]);
        int y = x * 2;
        int z = x * 3;
        if (y > 1000 || z > 1000) {
            return;
        }
        bool temp_used[10] = {false};
        for (int i = 1; i < 10; i++) {
            temp_used[i] = used[i];
        }
        int y_arr[3];
        int z_arr[3];
        decompose_number(y, y_arr);
        decompose_number(z, z_arr);
        for (int i = 0; i < 3; i++) {
            if (temp_used[y_arr[i]] || y_arr[i] == 0)
                return;
            temp_used[y_arr[i]] = true;
        }
        for (int i = 0; i < 3; i++) {
            if (temp_used[z_arr[i]] || z_arr[i] == 0)
                return;
            temp_used[z_arr[i]] = true;
        }
        printf("%d %d %d\n", x, y, z);
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (!used[i]) {
            used[i] = true;
            numbers[position] = i;
            make_number(position + 1);
            used[i] = false;
        }
    }
}

int main() {
    make_number(0);
    return 0;
}