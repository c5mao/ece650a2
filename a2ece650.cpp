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
    unsigned int i;

    while(1){
        try{
            //Read input  
            getline(cin, line);
            if(!cin){
               if(cin.eof())
               cout << "Error: EOF\n";
            else
                cout << "Error: other failure\n";
            break;
            }
            command = parse_line(line);
            cout << "parse line done" << endl;
            unsigned int n = command.size();
            cout << "length of the command:" << n << endl;

            for(i=0;i<n;i++){
        	cout << command[i] << endl;
            }
       } catch (const char* msg){
            cerr << msg <<endl;
       }
    }

    cout << "Error: empty input, exit" << endl;
    return 0;

}
