#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

vector<string> makeVector(string word) {
  vector<string> anagrams;
  anagrams.push_back(word);
  return anagrams;
}

string buildAnagram(string word) {
  int chars[58] = {0};
  string anagram = "";
  int j;
  for(int i = 0; i < word.size(); i++) {
    if (word[i] - 0 > 96) {
      j = word[i] - 'a';
    } else {
      j = word[i] - 'A';
    }
    chars[j] += 1;
  }

  char letter;
  for(int i = 0; i < 26; i++) {
    if (chars[i] > 1) {
      letter = (char) ('a' + i);
      anagram += (letter + to_string(chars[i]));
    } else if(chars[i] > 0) {
      letter = (char) ('a' + i);
      anagram.push_back(letter);
    }
  }
  return anagram;
}

void buildAnagrams(string word, map<string, vector<string> > * anagrams)  {
  string anagram = buildAnagram(word);
  if(anagrams->count(anagram) == 0) {
    anagrams->insert(make_pair(anagram, makeVector(word)));
  } else {
    anagrams->operator[](anagram).push_back(word);
  }
}

int main() {
  map<string, vector<string> > * anagrams = new map<string, vector<string> >();
  string word;
  ifstream words ("words.txt");
  map<string, vector<string> >::iterator it;
  vector<string>::iterator it2;
  if(words.is_open()) {
    while (getline(words, word)) {
      /* cout << word << endl; */
      buildAnagrams(word, anagrams);
    }
    words.close();
  }
  do {
    cout << "-----------------------------------" << endl;
    cout << "Enter q to quit" << endl;
    cout << "Enter word to find all its anagrams: ";
    cin >> word;
    string anagram = buildAnagram(word);
    cout << "Looking for anagrams of " << anagram << endl;
    it = anagrams->find(anagram);
    if (it != anagrams->end()) {
      cout << word << ": ";
      vector<string> words = it->second;
      for(it2 = words.begin(); it2 != words.end(); it2++) {
        cout << *it2 << " ";
      }
      cout << endl;
    } else {
      cout << "Word not found" << endl;
    }
  } while(word != "q");
  return 0;
}
