#include <cstdio>
#include <cstdlib>
using namespace std;

class Student {
    public:
        int score;
        int grade;
    
        bool operator>(const Student& other) {
            if (score > other.score)
                return true;
            if (score == other.score && grade < other.grade)
                return true;
            return false;
        }
};

void merge(Student* arr, int first, int mid, int last) {
    int left_length = mid - first + 1;
    int right_length = last - mid;
    Student left_array[left_length];
    Student right_array[right_length];
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
        else if (left_array[left_index] > right_array[right_index]) {
            arr[array_index] = left_array[left_index++];
        } else {
            arr[array_index] = right_array[right_index++];
        }
        array_index++;
    }
}

void merge_sort(Student* arr, int first, int last) {
    if (first >= last)
        return ;
    int mid = (first + last) / 2;
    merge_sort(arr, first, mid);
    merge_sort(arr, mid + 1, last);
    merge(arr, first, mid, last);
}

int main() {
    int n = 8;
    scanf("%d", &n);
    Student students[n];
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &students[i].score, &students[i].grade);
    merge_sort(students, 0, n - 1);

    int grade_count[7] = {0};
    for (int i = 0; i < n; i++) {
        int better_and_younger = 0;
        for (int g = 1; g < students[i].grade; g++) {
            better_and_younger += grade_count[g];
        }
        printf("%d\n", better_and_younger);
        grade_count[students[i].grade]++;
    }
    return 0;
}