#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string word;
  	ifstream document_file(document1_short.txt); 
  	if (document_file.is_open())
  	{
  		while(document_file >> word)
  		{
  			cout << word << end;
  		}
  	}

	/*
	map< string, vector<string> > families;

	// add new families
	families["Jones"];
	families["Smith"];
	families["Doe"];

	// add children
	families["Jones"].push_back( "Jane" );
	families["Jones"].push_back( "Jim" );

	families["Smith"].push_back( "Agent" );
	families["Smith"].push_back( "Sam" );

	families["Doe"].push_back( "Jane" );
	families["Doe"].push_back( "John" );

	for ( auto itr : families)
	{
		cout << itr.first << " -> ";
		for( auto itr2 : itr.second)
		{
			cout << itr2 << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}