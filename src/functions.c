#include "functions.h"

int str_to_int(char *str) {
    int result = 0;
    char neg = (str[0] == '-') ? 1 : 0;
    while (*str){
        char c = *str;
        if ((int) c >= 48 && (int) c <= 57) result = result * 10 + (c - 48);
        str++;
    }
    if (neg) result = -result;
    return result;
}

char *int_to_str(int n) {
    static char result[13] = "";
    int i = 0;
    char neg = (n < 0) ? 1 : 0;
    if(neg) n = -n;
    while(n > 0 && i < 13) {
        result[i++] = n % 10 + '0';
        n /= 10;
    }
    if (neg) result[i++] = '-';

    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

char is_number(char *str) {
    char is_num = 1;
    while (*str && is_num) {
        char c = *str;
        if (!(c >= '0' && c <= '9')) is_num = 0;
        str++;
    }
    return is_num;
}
