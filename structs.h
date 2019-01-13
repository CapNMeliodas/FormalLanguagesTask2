#include <string>
#include <vector>
#include <iostream>

//Rule type of N -> β, where β is a string
//consists of terminals and nonterminals
struct rule {
	rule(const char& l, const std::string& r) : left(l),
		right(r) {};

	char left;
	std::string right;
};

//Store the Grammar as a list of rules
//adding 0-rule Z -> S
struct Grammar {
	Grammar(const std::vector<rule>& r) : rules(r) {
		rule zero('Z', "S");
		rules.insert(rules.begin(), zero);
	};

	//std::cout << rules[0].left << " " << rules.size() << std::endl; 

	std::vector<rule> rules;
};

//Earley's parser Situation
//[A→α⋅Bβ,i]
struct Situation {
	Situation(int rN, int mP, int wP) : ruleNumber(rN), markerPosition(mP), 
		wordPosition(wP) {};

	bool operator<(const Situation& s) const {
		return (ruleNumber < s.ruleNumber);
	}

	int ruleNumber = 0;	//Rule that was a basement of the Situation
	int markerPosition = 0;	//Possitioned before the value
	int wordPosition = 0;	//Wanted letter position
};