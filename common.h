#pragma once

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

#define true 1
#define false 0
#define NULL ((void *)0)
// returns `value` aligned up to the next multiple of `align`
#define align_up(value, align) __builtin_align_up(value, align)
// returns whether `value` is aligned to a multiple of `align`
#define is_aligned(value, align) __builtin_is_aligned(value, align)
// calculates the offset (in bytes) to a given member of the given type
#define offsetof(type, member) __builtin_offsetof(type, member)

#define va_list __builtin_va_list
// initializes va_list
#define va_start __builtin_va_start
// finalizes the va_list
#define va_end __builtin_va_end
// returns next variadic arg
#define va_arg __builtin_va_arg

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);

void printf(const char *fmt, ...);