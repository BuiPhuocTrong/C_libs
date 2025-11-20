#include <stdio.h>

/*-------------------------------------------------------
  1. strlen()
  Trả về độ dài chuỗi (không tính ký tự '\0')
  Tham số:
    str: con trỏ đến chuỗi ký tự
  Trả về:
    Số lượng ký tự trước '\0'
-------------------------------------------------------*/
size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/*-------------------------------------------------------
  2.1. strcpy()
  Sao chép toàn bộ chuỗi src vào dest (bao gồm '\0')
  Tham số:
    dest: vùng nhớ đích
    src:  chuỗi nguồn
  Trả về:
    Con trỏ đến dest
-------------------------------------------------------*/
char *strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while ((*ptr++ = *src++) != '\0');
    return dest;
}

/*-------------------------------------------------------
  2.2. strncpy()
  Sao chép n ký tự từ src vào dest.
  Nếu src ngắn hơn n, phần còn lại sẽ được điền '\0'
  Tham số:
    dest: vùng nhớ đích
    src:  chuỗi nguồn
    n: số ký tự tối đa để sao chép
  Trả về:
    Con trỏ đến dest
-------------------------------------------------------*/
char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

/*-------------------------------------------------------
  3.1. strcat()
  Nối chuỗi src vào cuối chuỗi dest.
  dest phải đủ lớn để chứa kết quả.
  Tham số:
    dest: chuỗi đích
    src: chuỗi nguồn
  Trả về:
    Con trỏ đến dest
-------------------------------------------------------*/
char *strcat(char *dest, const char *src) {
    char *ptr = dest + strlen(dest);
    while ((*ptr++ = *src++) != '\0');
    return dest;
}

/*-------------------------------------------------------
  3.2. strncat()
  Nối tối đa n ký tự từ chuỗi src vào cuối chuỗi dest.
  Sau khi nối, luôn thêm một ký tự '\0' ở cuối kết quả.
  dest phải đủ lớn để chứa chuỗi kết quả sau khi nối.

  Nếu src < n ký tự, hàm chỉ sao chép đến hết src rồi dừng lại (vẫn thêm một ký tự '\0' để kết thúc).
  Nếu src >= n, chỉ n ký tự đầu tiên được nối (vẫn thêm một ký tự '\0' để kết thúc).

  Tham số:
    dest: chuỗi đích (đã có sẵn nội dung ban đầu)
    src:  chuỗi nguồn cần nối thêm
    n:    số ký tự tối đa được nối từ src

  Trả về:
    Con trỏ đến dest
-------------------------------------------------------*/

char *strncat(char *dest, const char *src, size_t n) {
    char *ptr = dest + strlen(dest);
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        ptr [i] = src[i];
    }
    for (; i < n; i++) {
        ptr[i] = '\0';
    }
    return dest;
}

/*-------------------------------------------------------
  4.1. strcmp()
  So sánh hai chuỗi.
  Trả về:
    0 nếu giống nhau
    <0 nếu s1 < s2
    >0 nếu s1 > s2
-------------------------------------------------------*/
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++; 
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/*-------------------------------------------------------
  4.2. strncmp()
  So sánh tối đa n ký tự đầu tiên của hai chuỗi s1 và s2.
  Trả về:
    0  nếu giống nhau (hoặc giống nhau trong n ký tự đầu)
    <0 nếu s1 < s2
    >0 nếu s1 > s2
-------------------------------------------------------*/
int strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    while (i < n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        i++;
    }

    if (i == n) return 0; // đã so sánh đủ n ký tự, coi như bằng nhau

    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/*-------------------------------------------------------
  5.1. strchr() - hỗ trợ cho strtok()
  Tìm ký tự đầu tiên trong chuỗi.
  Tham số:
    str: chuỗi để tìm
    c: ký tự cần tìm
  Trả về:
    Con trỏ đến vị trí ký tự đầu tiên nếu tìm thấy
    NULL nếu không có
-------------------------------------------------------*/
char *strchr(const char *str, int c) {
    while (*str) {
        if (*str == (char)c) return (char *)str;
        str++;
    }
    return NULL;
}

/*-------------------------------------------------------
  5.2. strrchr()
  Tìm ký tự xuất hiện cuối cùng trong chuỗi.
  Tham số:
    str: chuỗi để tìm
    c: ký tự cần tìm
  Trả về:
    Con trỏ đến vị trí ký tự cuối cùng nếu tìm thấy
    NULL nếu không có
-------------------------------------------------------*/
char *strrchr(const char *str, int c) {
    const char *last = NULL;
    while (*str) {
        if (*str == (char)c) {
            last = str;
        }
        str++;
    }
    return (char *)last;
}

/*-------------------------------------------------------
  6. strstr()
  Tìm chuỗi con (substring) trong chuỗi chính.
  Tham số:
    haystack: chuỗi cha
    needle: chuỗi con cần tìm
  Trả về:
    Con trỏ đến vị trí xuất hiện đầu tiên của needle
    NULL nếu không tìm thấy
-------------------------------------------------------*/
char *strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack;
    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) return (char *)haystack;
    }
    return NULL;
}

/*-------------------------------------------------------
  7. strtok()
  Tách chuỗi thành các token dựa vào tập ký tự phân tách.
  Tham số:
    str: chuỗi đầu vào (hoặc NULL để tiếp tục tách)
    delim: chuỗi chứa các ký tự là dấu hiệu để phân tách
  Trả về:
    Con trỏ đến token tiếp theo, hoặc NULL nếu hết
-------------------------------------------------------*/
char *strtok(char *str, const char *delim) {
    static char *last;
    
    if (str) last = str; // lần đầu tách chuỗi mới
    if (!last) return NULL; // không còn chuỗi nào để tách → trả về NULL

    // Bỏ qua ký tự phân tách ở đầu
    while (*last && strchr(delim, *last)) last++;
    if (!*last) return NULL;

    char *token = last;
    while (*last && !strchr(delim, *last)) last++;
    if (*last) *last++ = '\0';
    return token;
}


/*-------------------------------------------------------
  Ví dụ kiểm tra
-------------------------------------------------------*/
int main() {
    char a[100] = "Hello";
    char b[] = "World";
    char c[100];

    //printf("strlen(a) = %zu\n", strlen(a));
    //printf("strcpy(c, a) = %s\n", strcpy(c, a));
    //printf("strcat(a, b) = %s\n", strcat(a, b));
    printf("strncat(a, b, 3) = %s\n", strncat(a, b, 3));
    printf("strcmp(a, \"HelloWorld\") = %d\n", strcmp(a, "HelloWorld"));
    printf("strrchr(a, 'l') = %s\n", strrchr(a, 'l'));
    printf("strstr(a, \"loW\") = %s\n", strstr(a, "loW"));

    char str[] = "one,two,three";
    char *token = strtok(str, ",");
    while (token) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
