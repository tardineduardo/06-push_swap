#include <unistd.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

	int b = 0;
	int a = 0x02500;
	while (a++ < 0x025FF)
    b = wprintf(L"%lc ", a);
    return 0;
	wprintf(L"%i", b);

}

 