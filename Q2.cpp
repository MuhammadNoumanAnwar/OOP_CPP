//Given two strings, check if both are anagrams of eachother. (anagram: a word, phrase, or name formed
//by rearranging the letters of another, such as spar, formed from rasp)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string str1 = "listen";
    string str2 = "silent";
    if(str1.length() != str2.length()) {
        cout << "Strings are not anagrams." << endl;
        return 0;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1 == str2) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}

