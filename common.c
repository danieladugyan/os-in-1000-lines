#include "common.h"

void putchar(char ch) { sbi_call(ch, 0, 0, 0, 0, 0, 0, 1); }

void printf(const char *fmt, ...) {
    va_list vargs;
    va_start(vargs, fmt);  // initializes va_list

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
                case '\0':  // '%' at the end of the format string
                    putchar('%');
                    goto end;
                    break;
                case '%':
                    putchar('%');
                    break;
                case 's': {  // print a NULL-terminated string
                    const char *s = va_arg(vargs, const char *);
                    while (*s) {
                        putchar(*s);
                        s++;
                    }
                    break;
                }
                case 'd': {  // print an integer in decimal
                    int value = va_arg(vargs, int);
                    if (value < 0) {
                        putchar('-');
                        value = -value;
                    }

                    int divisor = 1;
                    while (value / divisor > 9) divisor *= 10;

                    while (divisor > 0) {
                        putchar('0' + value / divisor);
                        value %= divisor;
                        divisor /= 10;
                    }

                    break;
                }
                case 'x': {
                    int value = va_arg(vargs, int);
                    for (int i = 7; i >= 0; i--) {
                        int nibble = (value >> (i * 4)) & 0xf;
                        putchar("0123456789abcdef"[nibble]);
                    }
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(*fmt);
        }

        fmt++;
    }

end:
    va_end(vargs);  // finalizes the va_list
}