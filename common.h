#pragma once

#define va_list __builtin_va_list
// initializes va_list
#define va_start __builtin_va_start
// finalizes the va_list
#define va_end __builtin_va_end
// returns next variadic arg
#define va_arg __builtin_va_arg

void printf(const char *fmt, ...);