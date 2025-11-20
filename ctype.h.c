#include <stdio.h>

// 1. Các hàm kiểm tra ký tự
int isalpha(int c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int isalnum(int c) {
    return isalpha(c) || isdigit(c);
}

int islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int isspace(int c) {
    // Gồm: khoảng trắng, tab, newline, formfeed, vertical tab, carriage return
    return (c == ' '  || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

int ispunct(int c) {
    // Dấu câu: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
    return (c >= '!' && c <= '/') ||
           (c >= ':' && c <= '@') ||
           (c >= '[' && c <= '`') ||
           (c >= '{' && c <= '~');
}

int isprint(int c) {
    // Ký tự in được: 32–126
    return (c >= 32 && c <= 126);
}

int iscntrl(int c) {
    // Ký tự điều khiển: 0–31 và 127
    return (c < 32 || c == 127);
}

int isxdigit(int c) {
    // Hệ 16 gồm 0–9, A–F, a–f
    return (isdigit(c) ||
           (c >= 'A' && c <= 'F') ||
           (c >= 'a' && c <= 'f'));
}

// 2. Các hàm chuyển đổi chữ hoa ↔ chữ thường
int tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

int toupper(int c) {
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}


int main() {
    char c = 'A';
    printf("isalpha('%c') = %d\n", c, isalpha(c));
    printf("isdigit('%c') = %d\n", c, isdigit(c));
    printf("tolower('%c') = %c\n", c, tolower(c));
    printf("toupper('b') = %c\n", toupper('b'));
    printf("isspace(' ') = %d\n", isspace(' '));
    printf("isxdigit('F') = %d\n", isxdigit('F'));
    return 0;
}
