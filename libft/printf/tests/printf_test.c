#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int ft_printf(const char *format, ...);

int main(void)
{
    int a = 1;
    int *b = &a;
    char c = '$';
    char *d = "hello";
    char *e = "%%hi%%hello%%";
    unsigned int max_uint = UINT_MAX;
    int max_int = INT_MAX, min_int = INT_MIN;
    char *null_string = NULL;

    // Basic tests
    printf("Test 1: Single character\n");
    int x = printf("%c\n", c);
    int y = ft_printf("%c\n", c);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 2: Pointer\n");
    x = printf("%p\n", (void *)b);
    y = ft_printf("%p\n", (void *)b);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 3: Mixed types (char, pointer, string, special string)\n");
    x = printf("%c, %p, %s, %s\n", c, (void *)b, d, e);
    y = ft_printf("%c, %p, %s, %s\n", c, (void *)b, d, e);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 4: NULL string\n");
    int null1 = printf("%s\n", null_string);
    int null2 = ft_printf("%s\n", null_string);
    printf("return expected: %d\nreturn result:   %d\n", null1, null2);

    printf("\nTest 5: Integer limits (INT_MIN and INT_MAX)\n");
    x = printf("INT_MIN: %d, INT_MAX: %d\n", min_int, max_int);
    y = ft_printf("INT_MIN: %d, INT_MAX: %d\n", min_int, max_int);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 6: Unsigned integer limits (UINT_MAX)\n");
    x = printf("UINT_MAX: %u\n", max_uint);
    y = ft_printf("UINT_MAX: %u\n", max_uint);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 7: Zero pointer\n");
    x = printf("zero: %p\n", (void *)0);
    y = ft_printf("zero: %p\n", (void *)0);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 8: Integer formatting (i and d specifiers)\n");
    x = printf("%i %d\n", 42, 43);
    y = ft_printf("%i %d\n", 42, 43);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 9: Unsigned integer and negative integer\n");
    x = printf("%u %i\n", -100, -100);
    y = ft_printf("%u %i\n", -100, -100);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 10: Hexadecimal formatting (x and X specifiers)\n");
    x = printf("%x, %X\n", 10, 11);
    y = ft_printf("%x, %X\n", 10, 11);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 11: NULL pointers in various formats\n");
    x = printf("NULL: %p, INT_MIN: %p, INT_MAX: %p\n", (void *)NULL, (void *)INT_MIN, (void *)INT_MAX);
    y = ft_printf("NULL: %p, INT_MIN: %p, INT_MAX: %p\n", (void *)NULL, (void *)INT_MIN, (void *)INT_MAX);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 12: Negative values\n");
    x = printf("%d, %i, %u\n", -42, -42, -42);
    y = ft_printf("%d, %i, %u\n", -42, -42, -42);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 13: Hexadecimal zero\n");
    x = printf("%x, %X\n", 0, 0);
    y = ft_printf("%x, %X\n", 0, 0);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 14: Multiple specifiers in one string\n");
    x = printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x, Pointer: %p\n", 'A', "test", 123, 456, 0xABC, (void *)b);
    y = ft_printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x, Pointer: %p\n", 'A', "test", 123, 456, 0xABC, (void *)b);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 15: Special characters (newlines, tabs, etc.)\n");
    x = printf("Hello\nWorld\t! %%\n");
    y = ft_printf("Hello\nWorld\t! %%\n");
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 16: Large numbers\n");
    x = printf("%d, %u, %x, %X\n", INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    y = ft_printf("%d, %u, %x, %X\n", INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 17: Consecutive format specifiers\n");
    x = printf("%%d: %d, %%i: %i, %%u: %u\n", 123, 456, 789);
    y = ft_printf("%%d: %d, %%i: %i, %%u: %u\n", 123, 456, 789);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 18: Mixed integers and strings\n");
    x = printf("Number: %d, String: %s, Hex: %x\n", 42, "example", 255);
    y = ft_printf("Number: %d, String: %s, Hex: %x\n", 42, "example", 255);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    printf("\nTest 19: Repeated format specifiers\n");
    x = printf("%d %d %d\n", 1, 2, 3);
    y = ft_printf("%d %d %d\n", 1, 2, 3);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    // Test 21: Multiple consecutive specifiers
    printf("\nTest 21: Multiple consecutive specifiers\n");
    x = printf("%s%s%s\n", "a", "b", "c");
    y = ft_printf("%s%s%s\n", "a", "b", "c");
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    // Test 22: Combination of all formats
    printf("\nTest 22: Combination of all formats\n");
    x = printf("%c %s %d %u %x %X %p\n", 'A', "test", 123, 456, 0xABC, 0xDEF, (void *)b);
    y = ft_printf("%c %s %d %u %x %X %p\n", 'A', "test", 123, 456, 0xABC, 0xDEF, (void *)b);
    printf("count expected = %i\n", x);
    printf("count result   = %i\n", y);

    // Edge cases with limits.h
    printf("\nTest 23: Edge cases with limits.h\n");

    printf("Test 23.1: CHAR_MIN and CHAR_MAX\n");
    int a231 = printf("CHAR_MIN: %d, CHAR_MAX: %d\n", CHAR_MIN, CHAR_MAX);
    int b231 = ft_printf("CHAR_MIN: %d, CHAR_MAX: %d\n", CHAR_MIN, CHAR_MAX);
    printf("printf:    %d\nft_printf: %d\n", a231, b231);

    printf("\nTest 23.2: SHRT_MIN and SHRT_MAX\n");
    int a232 = printf("SHRT_MIN: %d, SHRT_MAX: %d\n", SHRT_MIN, SHRT_MAX);
    int b232 = ft_printf("SHRT_MIN: %d, SHRT_MAX: %d\n", SHRT_MIN, SHRT_MAX);
    printf("printf:    %d\nft_printf: %d\n", a232, b232);

    printf("\nTest 23.8: Percent sign\n");
    int a238 = printf("100%% complete\n");
    int b238 = ft_printf("100%% complete\n");
    printf("printf:    %d\nft_printf: %d\n", a238, b238);

    printf("\nTest 15: Percent sign as the last character (\"123%%\")\n");
    int a15 = printf("123%");
    printf("\n");
    int b15 = ft_printf("123%");
    printf("\n");
    printf("printf:    %d\nft_printf: %d\n", a15, b15);
    return 0;
    

    return 0;
}

