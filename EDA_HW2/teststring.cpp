#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main() {
    vector<std::string> patterns;
    ifstream ifs("input3.txt", std::ios::in);
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
        return 1; // EXIT_FAILURE
    }

    string pattern;
	string save = 0;
    while (ifs >> pattern) {
		if(strcmp(pattern, ''))
        cout << pattern << "\n";
        patterns.push_back(pattern);
    }
    ifs.close();
    return 0;
}