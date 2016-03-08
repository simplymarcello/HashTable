#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	string w;
  	ifstream document_file("document1.txt"); 
  	if (document_file.is_open())
  	{
  		while(document_file >> w)
  		{
  			stringstream ss(w);
  			while (getline(ss, w, '-') ) 
  			{
  				transform(w.begin(), w.end(), w.begin(), ::tolower);
	  			w.erase(remove_if( w.begin(), w.end(), ::isdigit), w.end());
  				if( w.find('\'') == string::npos )
	  				w.erase(remove_if( w.begin(), w.end(), ::ispunct), w.end());
	  			if( w.end() == w.begin() )
	  				continue;
	  			cout << w << endl;
  			}
  		}
  	}
  	else
  	{ }

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