#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

typedef std::vector<std::string> StringVec;

int main() {
	std::unordered_map<std::string, StringVec* > map{};

	std::ifstream dictionary ("dictionary.txt");

	std::string word{};

	/* std::cout << dictionary.is_open() << '\n'; */

	int count{0};
	int limit{1000000};

	if (dictionary.is_open()) {
		while (dictionary.good() && count < limit) {
			std::getline(dictionary, word);
			std::string sortedWord = word;
			std::sort(sortedWord.begin(), sortedWord.end());

			StringVec* matches = map[sortedWord];

			if (matches) {
				/* std::cout << "A match!\n"; */
				matches->push_back(word);
			} else {
				/* std::cout << "no match.\n"; */
				map[sortedWord] = new StringVec { word };
			}

			count++;
		}
	} else {
		std::cout << "Couldn't open file\n";
	}
	
	std::ofstream output;

	output.open("anagrams.txt");

	if (!output) {
		std::cerr << "Error: output file could not be opened!";
	}

	for (const auto& [_, anagrams] : map) {
		long unsigned int size = anagrams->size();
		if (size == 1) continue;

		/* output << "key: " << n.first; */
		/* output << " values: "; */

		for (long unsigned int i = 0; i < size; i++) {
			output << (*anagrams)[i] << ' ';
		}
		output << '\n';
	}

	output.close();
	return 0;
}
