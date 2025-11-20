#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
----Danh sách tính năng----

	1.1. Hàm viết hoa
	1.2. Hàm viết hoa
	2. Hàm đảo ngược string
	3. Hàm xóa khoảng trắng ở cả đầu và cuối
	4. Hàm đếm từng từ
	5. Hàm kiểm tra từ đối xứng

---------------------------
*/


/* 
  1.1. Hàm viết hoa
	Biến các chữ cái thường trong string thành chữ cái hoa
	Không tính kí tự khác ngoài chữ cái
	Tham số: mảng cần xử lí
*/
void toUpperCase (char *str){
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] >= 'a' && str[i] <= 'z') str[i] = toupper(str[i]);
	}
}


/* 
  1.2. Hàm viết hoa
	Biến các chữ cái thường trong string thành chữ cái hoa
	Không tính kí tự khác ngoài chữ cái
	Tham số: mảng cần xử lí
*/
void toLowerCase (char *str){
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = tolower(str[i]);
	}
}


/* 
  2. Hàm đảo ngược string
	Đảo đối xứng từng cặp từ 2 bên vào giữa dần
	Tham số: mảng cần xử lí
*/
void reverseString (char *str){
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++){
		char temp = str [i];
		str [i] = str [len - 1 - i];
		str [len - 1 - i] = temp;	
	}
}


/* 
  3. Hàm xóa khoảng trắng ở cả đầu và cuối
	Tham số: mảng cần xử lí
*/
void trimWSpace(char *str) {
    char *start = str;
    char *end;

    // Bỏ khoảng trắng ở đầu
    while (isspace((unsigned char)*start)) start++;

    // Nếu chuỗi toàn khoảng trắng
    if (*start == '\0') {
        *str = '\0';
        return;
    }

    // Bỏ khoảng trắng ở cuối
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0'; // Kết thúc chuỗi mới sau ký tự cuối cùng hợp lệ

    // Sao chép phần còn lại về đầu chuỗi (bằng vòng while)
    char *dst = str;
    while (*start != '\0') {
        *dst++ = *start++;  
    }
    *dst = '\0'; // Đặt ký tự kết thúc chuỗi
}

/* 
  4. Hàm đếm từng từ
    Hàm đếm số từ (cách nhau giữa các space), không phải số chữ cái
    Hàm không cần phải xử lí dấu cách trước đó 
	Tham số: mảng cần xử lí
*/
int countWords(char *str) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }

    return count;
}


/* 
  5. Hàm kiểm tra từ đối xứng
	Tham số: mảng cần xử lí
*/
int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0;  // Not a palindrome
        }
        left++;
        right--;
    }
    return 1;  // Is a palindrome
}


int main() {
	char str [] = "HelLo VieTNaM";
	toLowerCase (str);
	puts (str);
	reverseString (str);
	puts (str);
	
	char text[] = "   Hello World!   ";
	trimWSpace(text);
	printf("'%s'\n", text);
}