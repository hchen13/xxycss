/*
 某次科研调查时得到了n个自然数，每个数均不超过1500000000。已知不相同的数不超过10000个,
 现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

void merge(int* arr, int first, int mid, int last) {
    int left_length = mid - first + 1;
    int right_length = last - mid;
    int left_array[left_length];
    int right_array[right_length];
    for (int i = first; i <= mid; i++) {
        left_array[i - first] = arr[i];
    }
    for (int i = mid + 1; i <= last; i++) {
        right_array[i - mid - 1] = arr[i];
    }

    int left_index = 0, right_index = 0;
    int array_index = first;
    while (array_index <= last) {
        if (left_index >= left_length)
            arr[array_index] = right_array[right_index++];
        else if (right_index >= right_length)
            arr[array_index] = left_array[left_index++];
        else if (left_array[left_index] < right_array[right_index]) {
            arr[array_index] = left_array[left_index++];
        } else {
            arr[array_index] = right_array[right_index++];
        }
        array_index++;
    }
}

void merge_sort(int* arr, int first, int last) {
    if (first >= last)
        return ;
    int mid = (first + last) / 2;
    merge_sort(arr, first, mid);
    merge_sort(arr, mid + 1, last);
    merge(arr, first, mid, last);
}

// 打印数组
void abc(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n = 10;
    // scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        // scanf("%d", &numbers[i]);
        numbers[i] = rand() % 100 + 1;
    }

    merge_sort(numbers, 0, n - 1);

    int current_number = numbers[0];
    int count[10000] = {0};
    int map[10000] = {0};
    int count_index = 0;
    map[0] = current_number;
    count[count_index] = 1;
    for (int i = 1; i < n; i++) {
        if (numbers[i] == current_number) {
            count[count_index]++;
        } else {
            current_number = numbers[i];
            count_index++;
            map[count_index] = current_number;
            count[count_index]++;
        }
    }
    for (int i = 0; i <= count_index; i++) {
        printf("%d %d\n", map[i], count[i]);
    }

    return 0;
}