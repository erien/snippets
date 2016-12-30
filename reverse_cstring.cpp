// Write code to reverse a C-Style String.
// (C-String means that “abcd” is represented as five characters, including the null character.)

#include <iostream>

void reverseCstring(char *str) {
	char *end = str;
	char tmp;
	if (s) {
		// rewind
		while (*end) {
			++end;
		}
		--end; // before null
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

void printCstring(char * str) {

	while (*str) {
		std::cout << *str++;
	}
}
int main()
{
	std::cout << "reverse c-string test:" << std::endl;
	char test[] = { "test" };
	reverseCstring(test);
	printCstring(test);
}
