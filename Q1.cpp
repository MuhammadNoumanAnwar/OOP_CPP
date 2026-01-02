//Write a program that counts the frequency of all unique alphabets in a given string.
#include<iostream>
#include<string>
using namespace std;
int main() {
    string input = "My name is M.Nouman"; 
    int freq[26] = {0};
    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        ch = tolower(ch);
        if(ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }
    cout << "Alphabet frequency: \n";
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            cout << char('a' + i) << ": " << freq[i] << endl;
        }
    }
    return 0;
}

