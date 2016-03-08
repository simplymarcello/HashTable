// Created by Marcello Martins on Monday, October 26, 2015
// Last modified on Monday, October 26, 2015
// Hash Testing file

/** @file CreateAndTestHash.cpp */

#include <iostream>
#include <fstream> 
#include <string>
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "DoubleProbing.h"
using namespace std;

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) 
{
  cout << endl;

  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;

  cout << endl;

  string words_line, query_line;
  ifstream words_file(words_filename); 
  ifstream query_file(query_filename);
  if (words_file.is_open() && query_file.is_open()) 
  {
    while (words_file >> words_line)
      hash_table.insert(words_line);
    while (query_file >> query_line)
    {
      if(hash_table.contains(query_line))
        cout << query_line << " Found" << endl;
      else
        cout << query_line << " Not Found" << endl;
    }
  }

  else
  {
    cout << "Could not open files, please check file name, and try again." << endl;
    return;
  }

  double N = hash_table.totalElements();
  double T = hash_table.tableSize();
  double C = hash_table.totalCollisions();

  cout << endl;

  cout << "Total elements, (N) = " << N  << endl;
  cout << "Table size, (T) = " << T  << endl;
  cout << "Load factor (N/T) = " << N/T << endl;
  cout << "Total collisions, (C) = " << C << endl;
  cout << "Average collisions, (C/N) = " << C/N << endl;

  cout << endl;
}

// Sample main for program CreateAndTestHash
int main(int argc, char **argv) 
{
  if (argc != 4) 
  {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  cout << endl;
  cout << "Input words file is " << words_filename << ", and query file is " << query_filename << endl;
  if (param_flag == "linear") 
  {
    cout << "I will run the linear Hash code " << endl;
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } 

  else if (param_flag == "quadratic") 
  {
    cout << "I will run the quadratic Hashing code " << endl;
    HashTableQuadratic<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } 

  else if (param_flag == "double") 
  {
    cout << "I will run the double Hashing code " << endl;
    HashTableDouble<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } 

  else 
    cout << "Uknown hash type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;

  return 0;
}
