//find index of all substring matches.
#include<iostream>
#include<vector>

std::vector<int> FindSubstringIndexes(const std::string& phrase, const std::string& subString) {
    std::vector<int> matches;
    
    for(int i = 0; i < phrase.length(); i++) {
            
            bool is_match = true;
            for (size_t j = 0; j < subString.length(); j++)
            {
                if(phrase[i + j] != subString[j]) {
                    is_match = false;
                    break; // breaks the current loop (j) and jumps to next iteration i. skips unecessary iteration.
                }
            }
            if(is_match)
                matches.push_back(i);
        }
    return matches;
}

int main() {
    std::string phrase;
    std::string subString;
    std::cout << "Enter the phrase: ";
    std::cin >> phrase;
    std::cout << "Enter the substring: ";
    std::cin >> subString;

    std::vector<int> matches = FindSubstringIndexes(phrase,subString);

    if(matches.empty())
        std::cout << "No matches found: " << std::endl;
    else 
        std::cout << "Matched Indexes: ";
        for(int x: matches) {
            std::cout << x << " ";
        }
    
    return 0;
}