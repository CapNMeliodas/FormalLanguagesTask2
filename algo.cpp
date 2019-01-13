#include "algo.h"

bool Algo::verdict(const std::string& word, const Grammar& G) {
	//std::cout << D.size() << std::endl;
	DZeroInisialization(word, G);
	//std::cout << D.size() << std::endl;
	for (int j = 0; j < word.length() + 1; ++j) {
		scan(j, word, G);
		int currentDsize = D[j].size();
		while (true) {
			complete(j, word, G);
			predict(j, word, G);
			if (D[j].size() == currentDsize) {
				break;
			}
			else {
				currentDsize = D[j].size();
			}
		}
	}

	for (int i = 0; i < D.size(); ++i) {
		for (auto sit : D[i]) {
			std::cout << sit.ruleNumber << " " << sit.markerPosition << " " << sit.wordPosition << std::endl;
		}
		std::cout << std::endl;
	}

	//Situation final(0, 1, 0)
	for (auto sit : D[word.length()]) {
		if (sit.ruleNumber == 0 && sit.markerPosition == 1 && sit.wordPosition == 0) {
			return true;
		}
	}

	return false;
};

void Algo::scan(int j, const std::string& word, const Grammar& G) {
	if (j == 0) return;
	for (auto sit : D[j - 1]) {
		if (G.rules[sit.ruleNumber].right[sit.markerPosition] == word[j - 1]) {   //////////////////////////
			D[j].insert(sit);
		}
	}
};

void Algo::complete(int j, const std::string& word, const Grammar& G) {
	//Try to climb on our tree with sitLow rule
	//and read something in sitUp
	for (auto sitLow : D[j]) {
		int i = sitLow.wordPosition;
		for (auto sitUp : D[i]) {
			if (G.rules[sitUp.ruleNumber].right[sitUp.markerPosition] == G.rules[sitLow.ruleNumber].left) {
				Situation kek(sitUp.ruleNumber, sitUp.markerPosition + 1, sitUp.wordPosition);
				D[j].insert(kek);	//kek :)
			}
		}
	}
};

void Algo::predict(int j, const std::string& word, const Grammar& G) {
	for (auto sit : D[j]) {
		for (int i = 0; i < G.rules.size(); ++i) {
			if (G.rules[sit.ruleNumber].right[sit.markerPosition] == G.rules[i].left) {
				Situation sit(i, 0, j);
				D[j].insert(sit);
			}
		}
	}
};

void Algo::DZeroInisialization(const std::string& word, const Grammar& G) {
	D.resize(word.length() + 1);
	std::set<Situation> D0;
	Situation sit(0, 0, 0);
	D0.insert(sit);
	D[0] = D0;
}