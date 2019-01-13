#include "structs.h"
#include <set>
#include <iostream>
 
//Earley's parser
class Algo {
public:
	Algo() = default;

	//Earley's action list, where j is Situations list number that
	//we are currently filling
	void scan(int j, const std::string& word, const Grammar& G);
	void complete(int j, const std::string& word, const Grammar& G);
	void predict(int j, const std::string& word, const Grammar& G);
	void DZeroInisialization(const std::string& word, const Grammar& G);

	bool verdict(const std::string& word, const Grammar& G);
private:
	//Earley's lists of Situations
	std::vector<std::set<Situation>> D;
};
