// Write a method to replace all spaces in a string with ‘%20’.

#include <iostream>
#include <cstring>

void replaceSpace(char * str)
{
	if (str == NULL)
		return;

	int count = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == ' ') ++count;
	}

	int len = strlen(str) + 2 * count;

	str[len] = 0;

	for (int i = strlen(str) - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			//assign replacement
			str[len - 1] = '0';
			str[len - 2] = '2';
			str[len - 3] = '%';
			len -= 3;
		}
		else {
			str[--len] = str[i];
		}
	}
	printf("%s", str);
}

int main() {
	// your code goes here
	char test[] = { " abc " };
	replaceSpace(test);

	return 0;
}