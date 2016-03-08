// Created by Marcello Martins on Monday, October 26, 2015
// Last modified on Monday, October 26, 2015
// Simple Spell Checker using Hash Tables

/** @file SpellCheck.cpp */

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "stdlib.h"
#include <algorithm>
#include <sstream>
#include "QuadraticProbing.h"
using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) 
  {
    cout << "Usage: " << argv[0] << " <documentfile> <dictionaryfile>" << endl;
    return 0;
  }

  string document_filename(argv[1]);
  string dictionary_filename(argv[2]);
  cout << "I will run " << argv[0] << " with parameters " << document_filename << ", " << dictionary_filename << endl;

  string document_word, dictionary_word;
  ifstream document_file(document_filename); 
  ifstream dictionary_file(dictionary_filename);
  if (document_file.is_open() && dictionary_file.is_open()) 
  {

    //Fill hash table with dictionary file
    HashTableQuadratic<string> quadratic_probing_table;
    map< string, set<string> > misspelledWords;
    while(dictionary_file >> dictionary_word)
      quadratic_probing_table.insert(dictionary_word);

    while (document_file >> document_word)
    {

      stringstream ss(document_word);
      while (getline(ss, document_word, '-') ) 
      {
        transform(document_word.begin(), document_word.end(), document_word.begin(), ::tolower);
        document_word.erase(remove_if( document_word.begin(), document_word.end(), ::isdigit), document_word.end());
        if( document_word.find('\'') == string::npos )
          document_word.erase(remove_if( document_word.begin(), document_word.end(), ::ispunct), document_word.end());
        if( document_word.end() == document_word.begin() )
          continue;
        if( !quadratic_probing_table.contains(document_word) )
        {
          misspelledWords[document_word];
          char abc[] = "abcdefghijklmnopqrstuvwxyz";
          string tmp = document_word;
          for( unsigned int j = 0; j < tmp.length(); j++)
          {
            for(int i = 0; i < 26; ++i)
            {
              string s;
              s = abc[i];
              tmp.insert(j,s);
             if(quadratic_probing_table.contains(tmp))
                misspelledWords[document_word].insert(tmp);
              tmp.erase(j, 1);
            }
          }          for( unsigned int i = 0; i < tmp.length(); ++i)
          {
            string tmp2 = tmp;
            tmp2.erase(i,1);
            if(quadratic_probing_table.contains(tmp2))
              misspelledWords[document_word].insert(tmp2);
          }
          for ( unsigned int i = 1; i < tmp.length(); ++i)
          {
            string tmp2 = tmp;
            swap(tmp[i], tmp[i-1]);
            if(quadratic_probing_table.contains(tmp2))
              misspelledWords[document_word].insert(tmp2);
          }
        }
      }
    }

    for ( auto itr : misspelledWords)
    {
      cout << itr.first << " -> ";
      for( auto itr2 : itr.second)
      {
        cout << itr2 << " ";
      }
      cout << endl;
    } 
  }

  else
  {
    cout << "Could not open files, please check file name, and try again." << endl;
  }

  return 0;
}
