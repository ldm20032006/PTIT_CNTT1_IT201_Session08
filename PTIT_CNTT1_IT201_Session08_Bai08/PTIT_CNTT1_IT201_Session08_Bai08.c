#include <stdio.h>

// Hàm sắp xếp bằng Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Di chuyển các phần tử lớn hơn key về sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Trả về chỉ số
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm nhị phân (trên mảng đã sắp xếp)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Không tìm thấy
}

int main() {
    int n;

    // Nhập số phần tử
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    // Nhập mảng
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // In mảng ban đầu
    printf("\nMang ban dau: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sắp xếp mảng
    insertionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep (Insertion Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    int target;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    int resultLinear = linearSearch(arr, n, target);
    if (resultLinear != -1)
        printf("Tim kiem tuyen tinh: Tim thay tai vi tri %d\n", resultLinear);
    else
        printf("Tim kiem tuyen tinh: Khong tim thay.\n");

    int resultBinary = binarySearch(arr, 0, n - 1, target);
    if (resultBinary != -1)
        printf("Tim kiem nhi phan: Tim thay tai vi tri %d\n", resultBinary);
    else
        printf("Tim kiem nhi phan: Khong tim thay.\n");

    return 0;
}
