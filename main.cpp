#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <fstream>
using namespace std;
pair<int, int> countVowelsAndConsonants(const string &word) {
    int vowels = 0, consonants = 0;
    string vowelsList = "AEIOUaeiou";
    for (char ch : word) {
        if (isalpha(ch)) {
            if (vowelsList.find(ch) != string::npos)
                vowels++;
            else
                consonants++;
        }
    }
    return {vowels, consonants};
}

void processCppString(const string &word) {
    cout << "Word: " << word << endl;

    cout << "Uppercase: ";
    for (char ch : word)
        cout << (char)toupper(ch);
    cout << endl;

    cout << "Lowercase: ";
    for (char ch : word)
        cout << (char)tolower(ch);
    cout << endl;

    cout << "Total characters: " << word.size() << endl;
    cout << "First character: " << word.front() << endl;
    cout << "Last character: " << word.back() << endl;

    auto [vowels, consonants] = countVowelsAndConsonants(word);
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
}

bool customComparator(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    vector<string> words;

    string fileName;
    cout << "Enter a filename (or press Enter to skip): ";
    getline(cin, fileName);

    if (!fileName.empty()) {
        ifstream inputFile(fileName);
        if (inputFile.is_open()) {
            string word;
            while (inputFile >> word)
                words.push_back(word);
            inputFile.close();
        } else {
            cerr << "Failed to open file. Proceeding with manual input.\n";
        }
    }

    if (words.empty()) {
        string firstWord, secondWord;
        cout << "Enter the first word: ";
        cin >> firstWord;
        cout << "Enter the second word: ";
        cin >> secondWord;
        words.push_back(firstWord);
        words.push_back(secondWord);
    }

    cout << "\nWord Details:\n";
    for (const string &word : words)
        processCppString(word);

    cout << "\nComparison:" << endl;
    if (words[0] == words[1])
        cout << "The two words are the same." << endl;
    else
        cout << "The two words are not the same." << endl;

    cout << "\nAlphabetical Order:\n";
    sort(words.begin(), words.end());
    for (const string &word : words)
        cout << word << endl;

    cout << "\nCustom Sorting (by length, then alphabetically):\n";
    sort(words.begin(), words.end(), customComparator);
    for (const string &word : words)
        cout << word << endl;

    return 0;
}
