#include <iostream>
#include <cstdio>
#include <vector>

struct Constraint {
private:
	static const int N = 5;
	int min[N], max[N];
	std::string names[N] = {
		"spades",
		"hearts",
		"diamonds",
		"clubs",
		"hcp"
	};
public:
	Constraint(const std::string &s) {
		sscanf(s.c_str(), "%d-%d,%d-%d,%d-%d,%d-%d,%d-%d", &min[0], &max[0],
			&min[1], &max[1], &min[2], &max[2], &min[3], &max[3], &min[4], &max[4]);
	}
	std::string toString(const std::string &player) const {
		std::string result = "(";
 		for (int i = 0; i < N; i++) {
			if (i != 0) {
				result += " && ";
			}
			if (min[i] == max[i]) {
					result += names[i] + "(" + player + ") == " + std::to_string(min[i]);
			} else {
				result += names[i] + "(" + player + ") >= " + std::to_string(min[i]);
				result += " && " + names[i] + "(" + player + ") <= " + std::to_string(max[i]);
			}
		}
		result += ")";
		return result;
	}
};

class ConstraintSet {
private:
	std::vector<Constraint> constraints;
public:
	ConstraintSet(const std::string &s) {
		int begin;
		for (unsigned i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				begin = i + 1;
			} else if (s[i] == ')') {
				std::string x(s.c_str() + begin, i - begin);
				constraints.push_back(x);
			}
		}
	}
	std::string toString(const std::string &player) const {
		std::string result{};
		result += "(";
		bool first = true;
		for (const auto &c : constraints) {
			if (!first) {
					result += " || ";
			}
			result += c.toString(player);
			first = false;
		}
		result += ")";
		return result;
	}
};

int main(int argc, char **argv) {
	std::string hand = argc > 1 ? std::string(argv[1]) : "north";
	std::string input;
	std::cin >> input;
	ConstraintSet c(input);
	std::cout << c.toString(hand) << std::endl;;
}
