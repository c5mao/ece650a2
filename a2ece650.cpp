#include <iostream>
#include <vector>
#include <string>


using namespace std;

class line{
  public:
    unsigned int srt; //srt vertex of line
    unsigned int dst; //dst vertex of line
};

class line_db{
  public:
    unsigned int no_of_vertices;
    line edge[];
};

vector<string> parse_line(string line){
    vector<string> parsed_line;
    line_db db;
    cout << line[0] << endl;
    if (line[0]=='V'){
    	// Find position of ':' using find() 
        int pos = line.find(" "); 
        // Copy substring after pos 
        string value = line.substr(pos + 1); 
        cout << value << endl;
        parsed_line.push_back(value);
        db.no_of vertices = 2;
        db.edge[0].srt = 0;
        db.edge[0].dst = 1;
        cout << "The edge is from %d to %d", db.edge[0].src, db.edge[0].dst <<endl
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
