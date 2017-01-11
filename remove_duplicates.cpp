// Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
// NOTE: One or two additional variables are fine. 
// An extra copy of the array is not.
// FOLLOW UP
// Write the test cases for this method.

#include <iostream>
#include <cstring>

void removeDuplicates(char * str) {

	if (str == NULL || strlen(str) < 2)
		return;

	int current = 1;

	for (int i = 1; i < strlen(str); ++i) {
		int j;
		for (j = 0; j < current; ++j) {
			if (str[i] == str[j])
				break;
		}
		if (current == j) 
			str[current++] = str[i];
	}
	str[current] = 0;
	printf("%s", str);
}



int main()
{
	std::cout << "remove duplicate chars from string test:" << std::endl;
	char test[] = { "aaabbbccabc" };
	removeDuplicates(test);
}