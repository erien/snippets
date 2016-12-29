// Implement an algorithm to determine if a string has all unique characters. 
// What if you can not use additional data structures?

#include <iostream>
#include <vector>
#include <algorithm>

bool hasAllUniqueChars(std::string s) {
	int chars[256] = {0};
	for (auto c : s) {
		chars[c]++;
		if (chars[c] > 1)
			return false;
	}
	return true;
}

bool hasAllUniqueCharsTwo(std::string s) {
	unsigned checker = 0;
	for (auto c : s) {
		unsigned val = c - 'a';
		if ((checker & (1 << val)) > 0)
			return false;
		checker |= (1 << val);
	}
	return true;
}

int main()
{
	std::cout << "hasAllUniqueChars test:" << std::endl;
	std::cout << hasAllUniqueChars("test") << std::endl;
	std::cout << hasAllUniqueCharsTwo("test") << std::endl;
}
