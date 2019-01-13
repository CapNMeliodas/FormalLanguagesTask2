//Сделать правильный компаратор
#include <iostream>
#include "algo.h"

int main() {
	//Reading Grammar
	int rulesNumber = 0;
	std::vector<rule> rules;
	std::cin >> rulesNumber;

	for (int i = 0; i < rulesNumber; ++i) {
		char left;
		std::string right;
		std::cin >> left >> right;

		rules.emplace_back(left, right);
	}
	Grammar G(rules);

	//Reading word
	std::string word;
	std::cin >> word;

	//Define the word affiliation
	Algo earleyParser;
	if (earleyParser.verdict(word, G)) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
}
