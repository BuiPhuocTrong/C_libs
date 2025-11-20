#include "sortlib.h"
#include <stdlib.h>

/*---------------------------------------------------------
 * sortlib.c - Implementation of sorting algorithms
 *---------------------------------------------------------*/

/*====================== UTILITY =======================*/
/* Print array elements */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*====================== BUBBLE SORT =======================*/
/**
 * Bubble Sort
 * - So sánh từng cặp phần tử kề nhau và đổi chỗ nếu sai thứ tự.
 * - Time Complexity: O(n^2)
 * - Space Complexity: O(1)
 * - Nguyên lý: "nổi bong bóng" – phần tử lớn dần trồi lên cuối mảng.
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/*====================== SELECTION SORT =======================*/
/**
 * Selection Sort
 * - Mỗi lần chọn phần tử nhỏ nhất còn lại và đưa lên đầu.
 * - Time Complexity: O(n^2)
 * - Space Complexity: O(1)
 * - Nguyên lý: "chọn phần tử nhỏ nhất" đưa về vị trí đúng.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;
    }
}

/*====================== INSERTION SORT =======================*/
/**
 * Insertion Sort
 * - Xây dần dãy con đã sắp xếp bằng cách chèn từng phần tử vào đúng vị trí.
 * - Time Complexity: O(n^2)
 * - Space Complexity: O(1)
 * - Nguyên lý: "chèn phần tử vào đúng chỗ trong dãy con đã sắp".
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*====================== MERGE SORT =======================*/
/**
 * Merge Sort
 * - Chia đôi mảng liên tục, sắp xếp hai nửa rồi trộn lại.
 * - Time Complexity: O(n log n)
 * - Space Complexity: O(n)
 * - Nguyên lý: "chia để trị" (divide and conquer).
 */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/*====================== QUICK SORT =======================*/
/**
 * Quick Sort
 * - Chọn pivot, chia mảng thành 2 phần nhỏ hơn và lớn hơn pivot.
 * - Time Complexity: Trung bình O(n log n), Tệ nhất O(n^2)
 * - Space Complexity: O(log n)
 * - Nguyên lý: "chia để trị" – chia mảng theo pivot.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*====================== HEAP SORT =======================*/
/**
 * Heap Sort
 * - Xây dựng max heap, rồi liên tục hoán đổi phần tử lớn nhất về cuối mảng.
 * - Time Complexity: O(n log n)
 * - Space Complexity: O(1)
 * - Nguyên lý: "heapify" – sử dụng cấu trúc cây heap.
 */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

/*====================== COUNTING SORT =======================*/
/**
 * Counting Sort
 * - Đếm số lần xuất hiện của từng giá trị, rồi tính vị trí.
 * - Time Complexity: O(n + k)
 * - Space Complexity: O(k)
 * - Nguyên lý: "đếm phần tử" – chỉ dùng cho dữ liệu là số nguyên dương nhỏ.
 */
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int idx = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]--)
            arr[idx++] = i;
    free(count);
}

/*====================== RADIX SORT =======================*/
/**
 * Radix Sort
 * - Sắp xếp theo từng chữ số từ hàng đơn vị đến cao nhất.
 * - Time Complexity: O(n * k)
 * - Space Complexity: O(n + k)
 * - Nguyên lý: "sắp từng chữ số" – dùng counting sort cho mỗi chữ số.
 */
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSortByExp(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortByExp(arr, n, exp);
}

/*====================== sList() =======================*/
/**
 * sList()
 * - Hiển thị danh sách các thuật toán sắp xếp.
 * - Cho phép người dùng chọn để xem mô tả chi tiết.
 * - Nhập 0 để thoát.
 */
void sList(void) {
    int choice;
    do {
        printf("\n====== SORTING ALGORITHMS MENU ======\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Counting Sort\n");
        printf("8. Radix Sort\n");
        printf("0. Exit\n");
        printf("Choose a number to view details: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("\nBubble Sort: O(n^2) time, O(1) space - So sánh cặp kề, nổi phần tử lớn dần lên cuối.\n"); break;
            case 2: printf("\nSelection Sort: O(n^2) time, O(1) space - Chọn phần tử nhỏ nhất đưa về đầu.\n"); break;
            case 3: printf("\nInsertion Sort: O(n^2) time, O(1) space - Chèn phần tử vào đúng vị trí trong dãy con đã sắp.\n"); break;
            case 4: printf("\nMerge Sort: O(n log n) time, O(n) space - Chia để trị, trộn hai mảng con đã sắp.\n"); break;
            case 5: printf("\nQuick Sort: O(n log n) trung bình, O(n^2) tệ nhất, O(log n) space - Chia theo pivot.\n"); break;
            case 6: printf("\nHeap Sort: O(n log n) time, O(1) space - Dựa trên cấu trúc heap (cây nhị phân).\n"); break;
            case 7: printf("\nCounting Sort: O(n + k) time, O(k) space - Đếm số lượng phần tử, chỉ dùng cho số nhỏ.\n"); break;
            case 8: printf("\nRadix Sort: O(n * k) time, O(n + k) space - Sắp từng chữ số, dùng counting sort.\n"); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
}
