//find index of all substring matches. and replace them
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

std::vector<int> ReplaceAllSubstrings( std::string& phrase, std::string& subString, std::string& newString) {
    std::vector<int> matches =  FindSubstringIndexes(phrase,subString);
    
    if(matches.size() != 0) {
        int lengthDifference = newString.size() - subString.size();
        int timesLooped = 0;
        for(auto index: matches) {
        std::cout << subString.size() << " lengthdifference: " << lengthDifference << "Times Looped: " << timesLooped << std::endl;
            phrase.replace(index + (timesLooped * lengthDifference),//finds the next index for replacement 
            subString.size(), newString);

            timesLooped++;
        }
    }
    return matches;
}

int main() {
    std::string phrase;
    std::string subString;
    std::string newString;
    std::cout << "Enter the phrase: ";
    std::cin >> phrase;
    std::cout << "Enter the substring: ";
    std::cin >> subString;
    std::cout << "Enter the newstring: ";
    std::cin >> newString;

    std::vector<int> matches = FindSubstringIndexes(phrase,subString);

    ReplaceAllSubstrings(phrase,subString,newString);

    if(matches.empty())
        std::cout << "No matches found: " << std::endl;
    else {
     std::cout << "Matched Indexes: ";
        for(int x: matches) {
            std::cout << x << " ";
        }   
    }

    std::cout << phrase << std::endl;

    return 0;
}