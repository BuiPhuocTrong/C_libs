#include <stdio.h>

void swap (int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;	
}

void printArr (int a[], int n){ 
	printf ("\nMang can in: \n");
	int i = 0;
	while (i < n){
		printf ("a[%d] = %d\n", i, a[i] );
		i++;
	}
}


void scanArr (int a[], int *n){
	printf ("Nhap vao so luong phan tu n: ");
	scanf ("%d", n);
	
	int i = 0;
	while (i < *n){
		printf ("a[%d] = ", i);
		scanf ("%d",  &a[i]);
		i++;
	}
}

void reverseArr (int a[], int n){
	for (int i = 0; i < n/2; i ++){
		swap (&a[n-1-i], &a[i]);
	}
}

int arrInsert(int a[], int n, int index, int value) {
    if (index < 0 || index > n) {
        return n; // không chèn được
    }

    for (int i = n; i > index; i--) {
        a[i] = a[i - 1];
    }

    a[index] = value;
    return n + 1; // kích thước mới
}


void arrAppend (int a[], int n1, int b[], int n2) {// mảng b nối sau mảng a
	for (int i = n1; i < n2 + n1; i ++){
		a[i] = b[i - n1];
	}
}


int arrArr(int a[], int n1, int b[], int n2) {
    for (int i = 0; i <= n1 - n2; i++) {
        int j = 0;
        while (j < n2 && a[i + j] == b[j]) {
            j++;
        }
        if (j == n2) {
            return i; // vị trí bắt đầu
        }
    }
    return -1; // không tìm thấy
}

//Cần check lại
int find_Kth_largest_distinct(int a[], int n, int k) {
    if (k <= 0) return -1;

    // Tạo mảng phụ để không thay đổi mảng gốc
    int b[1000];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    // Sắp xếp mảng phụ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] < b[j]) {
                swap(&b[i], &b[j]);
            }
        }
    }

    // Duyệt mảng đã sort để tìm bậc k
    int rank = 1;  // bậc hiện tại (bậc 1 bắt đầu tại b[0])

    for (int i = 1; i < n; i++) {

        // Khi gặp giá trị mới → tăng bậc
        if (b[i] != b[i - 1]) {
            rank++;
        }

        // Nếu bậc == k → trả về phần tử đó
        if (rank == k) {
            return b[i];
        }
    }

    // Không đủ bậc
    return -1;
}

//Cần check lại
int find_Kth_smallest(int a[], int n, int k) {
    if (k <= 0) return -1;

    // Tạo mảng phụ để không ảnh hưởng mảng gốc
    int b[1000];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    // Sắp xếp mảng phụ theo thứ tự tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {   // đảo chiều so với sắp xếp giảm dần
                swap(&b[i], &b[j]);
            }
        }
    }

    // Tìm phần tử nhỏ thứ k theo bậc
    int rank = 1;   // bậc nhỏ nhất = 1 (b[0])

    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            rank++;
        }

        if (rank == k) {
            return b[i];
        }
    }

    return -1; // không đủ bậc
}

int search (int a[], int n, int value){
	for (int i = 0; i < n; i++){
		if (a[i] == value) return i;
	}
	return -1; // không tìm được
}


int main() {
	int a[100] = {1, 3, 5, 6, 9, 7, 3, 5, 2};
	int b[3] = {3, 5, 2};
	int n1 = 9;
	return 0;
}