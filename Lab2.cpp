#include <set>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
		vector<string> tokens;
		list<string> lst;
    set <string> unique;
		string filename = argv[1];
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
						lst.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of list words "<<lst.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
		map<string, string> wordmap;
		string last="";
		for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
  		wordmap[last]=*it;
  		last = *it;
		}

		ofstream setfile(filename+"_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        setfile << ' ' << *it << endl;
		}
		ofstream vectorfile(filename+"_vector.txt");
		for (int i = 0; i<tokens.size(); i++){
        vectorfile<<' '<<tokens.at(i)<<endl;
		}
		ofstream mapfile(filename+"_map.txt");
    for (map<string,string>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it){
        mapfile << it->first<<','<<' '<< it->second<<endl ;
		}

		string state = "";
		for(int i = 0; i < 100; i++){
  		cout << wordmap[state] << " ";
  		state = wordmap[state];
		}
		cout<<endl;

		map<string, vector<string>> wordmap2;
		string state2 = "";
		for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
  		wordmap2[state2].push_back(*it);
  		state2 = *it;
		}	
		
	
		 for(map<string,vector<string>>::iterator it=wordmap2.begin(); it!=wordmap2.end(); ++it) {
			string key = it->first;
			if (key== "Adam"){
				vector<string> value = wordmap2[key];
				cout<< value.size() <<endl;
				for(int i = 0; i<value.size(); i++){
					cout<< value.at(i) << " " << endl;
				}
				break;
			} 
		}
		srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
		state = "";
		for (int i = 0; i < 100; i++) {
  		int ind = rand() % wordmap2[state].size();
  		cout << wordmap2[state][ind] << " ";
  		state = wordmap2[state][ind];
		}
		cout<<endl;
		cout<<endl;



		map<list<string>, vector<string>> wordmap3;
  	list<string> state3;
		
		const int M = 2;

  	for (int i = 0; i < M; i++) {
    	state3.push_back("");
  	}
                        
  	for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
    	wordmap3[state3].push_back(*it);
    	state3.push_back(*it);
    	state3.pop_front();
  	}

		state3.clear();
  	for (int i = 0; i < M; i++) {
    	state3.push_back("");
  	}
  	for (int i = 0; i < 150; i++) {
    	int ind = rand() % wordmap3[state3].size();
    	cout << wordmap3[state3][ind]<<" ";
    	state3.push_back(wordmap3[state3][ind]);
    	state3.pop_front();
  	}

    cout << endl;

}