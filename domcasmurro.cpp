#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;
int main() {
    unordered_map<string, int> dict;
    ifstream infile("DomCasmurro_utf8.txt");

    while(!infile.eof()) {
        string line;
        string word;
        getline(infile, line);
        stringstream readLine;
        readLine << line;
        while(readLine >> word) {
            if (dict.find(word) == dict.end()) {
                dict[word] = 1;
            } else {
                dict[word]++;
            }
            cout << word << " " << dict[word] << endl;
        }
    }
}
