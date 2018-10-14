#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<string> parse_line(string line){
    vector<string> parsed_line;

    cout << line[0] << endl;
    if (line[0]=='V'){
    	// Find position of ':' using find() 
        int pos = line.find(" "); 
        // Copy substring after pos 
        string value = line.substr(pos + 1); 
        cout << value << endl;
        parsed_line.push_back(value);
    }



    return parsed_line;

}

int main(){

	string line;
	vector<string> command;
	uint i;

	while(1){

	    getline(cin, line);
	    cout << line << endl;
        if(!cin){
           if(cin.eof())
             cout << "EOF\n";
           else
             cout << "other failure\n";
           
           break;

        }
        command = parse_line(line);
        cout << "parse line done" << endl;
        uint n = command.size();
        cout << "length of the command:" << n << endl;

        for(i=0;i<n;i++){
        	cout << command[i] << endl;
        }



	}

	cout << "Error: empty input, exit";

	return 0;

}