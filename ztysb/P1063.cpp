#include <cstdio>
#include <cstdlib>
using namespace std;

void print_array(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool verify(int* arr, int length) {
    for (int i = 1; i < length; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

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

int main() {
    int n = 1000000;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
        // height[i] = rand() % 50 + 150;
    }
    // print_array(height, n);

    merge_sort(height, 0, n - 1);

    print_array(height, n);

    // if (verify(height, n))
    //     printf("SUCCESS\n");
    // else
    //     printf("FAILED\n");
    return 0;
}