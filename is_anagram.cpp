// Write a method to decide if two strings are anagrams or not.

#include <iostream>

bool isAnagram(std::string s, std::string t) {
	int chars[256] = { 0 };

	if (s.size() != t.size())
		return false;

	for (auto c : s)
		++chars[c];

	for (auto c : t) {
		--chars[c];
	}

	for (auto c : chars)
		if (c != 0)
			return false;

	return true;
}

int main()
{
	std::cout << "isAnagram test:" << std::endl;
	std::cout << isAnagram("test", "tset") << std::endl;
	std::cout << isAnagram("test", "ttst") << std::endl;
}