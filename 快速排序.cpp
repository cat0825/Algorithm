#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 快速排序的分区函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // 选择第一个元素作为枢纽元素
    int i = low + 1;  // i 表示大于枢纽元素的边界

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);  // 将小于枢纽元素的元素交换到右侧
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);  // 将枢纽元素放到正确的位置上
    return i - 1;  // 返回枢纽元素的索引
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);  // 对数组进行分区，获取枢纽元素的索引

        quickSort(arr, low, pivotIndex - 1);  // 对枢纽元素左侧的子数组进行快速排序
        quickSort(arr, pivotIndex + 1, high);  // 对枢纽元素右侧的子数组进行快速排序
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
