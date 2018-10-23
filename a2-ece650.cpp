#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h> 
#include <regex>
using namespace std; 
/*****************************************************
Global Variable
******************************************************/
/*
// no. of vertices 
int v = 8; 
// array of vectors is used to store the graph 
// in the form of an adjacency list 
vector<int> adj[8]; 
*/
regex re("<.*?>");
regex num(R"(\d+)");
sregex_iterator reg_end;
// no. of vertices 
int v = 100; 
// array of vectors is used to store the graph 
// in the form of an adjacency list 
vector<int> adj[100]; 
vector<int> *node_list = new vector<int>[v];
/*****************************************************
Function Prototype
******************************************************/

// utility function to form edge between two vertices 
// source and dest 
void add_edge(vector<int> adj[], int src, int dest) 
{ 
	adj[src].push_back(dest); 
	adj[dest].push_back(src); 
} 

// a modified version of BFS that stores predecessor 
// of each vertex in array p 
// and its distance from source in array d 
bool BFS(vector<int> adj[], int src, int dest, int v, 
							int pred[], int dist[]) 
{ 
	// a queue to maintain queue of vertices whose 
	// adjacency list is to be scanned as per normal 
	// DFS algorithm 
	list<int> queue; 

	// boolean array visited[] which stores the 
	// information whether ith vertex is reached 
	// at least once in the Breadth first search 
	bool visited[v]; 

	// initially all vertices are unvisited 
	// so v[i] for all i is false 
	// and as no path is yet constructed 
	// dist[i] for all i set to infinity 
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 

	// now source is first to be visited and 
	// distance from source to itself should be 0 
	visited[src] = true; 
	dist[src] = 0; 
	queue.push_back(src); 

	// standard BFS algorithm 
	while (!queue.empty()) { 
		int u = queue.front(); 
		queue.pop_front(); 
		for (int i = 0; i < adj[u].size(); i++) { 
			if (visited[adj[u][i]] == false) { 
				visited[adj[u][i]] = true; 
				dist[adj[u][i]] = dist[u] + 1; 
				pred[adj[u][i]] = u; 
				queue.push_back(adj[u][i]); 

				// We stop BFS when we find 
				// destination. 
				if (adj[u][i] == dest) 
				return true; 
			} 
		} 
	} 

	return false; 
} 

// utility function to print the shortest distance 
// between source vertex and destination vertex 
void printShortestDistance(vector<int> adj[], int s, 
									int dest, int v) 
{ 
	// predecessor[i] array stores predecessor of 
	// i and distance array stores distance of i 
	// from s 
	int pred[v], dist[v]; 

	if (BFS(adj, s, dest, v, pred, dist) == false) 
	{ 
		cout << "Error: Given vetices not connected" << endl;
		return; 
	} 

	// vector path stores the shortest path 
	vector<int> path; 
	int crawl = dest; 
	path.push_back(crawl); 
	while (pred[crawl] != -1) { 
		path.push_back(pred[crawl]); 
		crawl = pred[crawl]; 
	} 

	// distance from source is in distance array 
	cout << "Shortest path length is : "
		<< dist[dest] << endl; 

	// printing path from source to destination 
	cout << "Path is::\n"; 
	for (int i = path.size() - 1; i >= 0; i--) 
		cout << path[i] << " "; 
	cout << endl;
} 


//test function
// utility function to form edge between two vertices 
// source and dest 
void add_edge_test(vector<int> *adj, int src, int dest) 
{ 
	adj[src].push_back(dest); 
	adj[dest].push_back(src); 
} 

// a modified version of BFS that stores predecessor 
// of each vertex in array p 
// and its distance from source in array d 
bool BFS_test(vector<int> *adj, int src, int dest, int v, 
							int pred[], int dist[]) 
{ 
	// a queue to maintain queue of vertices whose 
	// adjacency list is to be scanned as per normal 
	// DFS algorithm 
	list<int> queue; 

	// boolean array visited[] which stores the 
	// information whether ith vertex is reached 
	// at least once in the Breadth first search 
	bool visited[v]; 

	// initially all vertices are unvisited 
	// so v[i] for all i is false 
	// and as no path is yet constructed 
	// dist[i] for all i set to infinity 
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 

	// now source is first to be visited and 
	// distance from source to itself should be 0 
	visited[src] = true; 
	dist[src] = 0; 
	queue.push_back(src); 

	// standard BFS algorithm 
	while (!queue.empty()) { 
		int u = queue.front(); 
		queue.pop_front(); 
		for (int i = 0; i < adj[u].size(); i++) { 
			if (visited[adj[u][i]] == false) { 
				visited[adj[u][i]] = true; 
				dist[adj[u][i]] = dist[u] + 1; 
				pred[adj[u][i]] = u; 
				queue.push_back(adj[u][i]); 

				// We stop BFS when we find 
				// destination. 
				if (adj[u][i] == dest) 
				return true; 
			} 
		} 
	} 

	return false; 
} 

// utility function to print the shortest distance 
// between source vertex and destination vertex 
void printShortestDistance_test(vector<int> *adj, int s, 
									int dest, int v) 
{ 
	// predecessor[i] array stores predecessor of 
	// i and distance array stores distance of i 
	// from s 
	int pred[v], dist[v]; 

	if (BFS_test(adj, s, dest, v, pred, dist) == false) 
	{ 
		cout << "Error: Given vetices not connected" << endl;
		return; 
	} 

	// vector path stores the shortest path 
	vector<int> path; 
	int crawl = dest; 
	path.push_back(crawl); 
	while (pred[crawl] != -1) { 
		path.push_back(pred[crawl]); 
		crawl = pred[crawl]; 
	} 

	// distance from source is in distance array 
	cout << "Shortest path length is : "
		<< dist[dest] << endl; 

	// printing path from source to destination 
	cout << "Path is::\n"; 
	for (int i = path.size() - 1; i >= 0; i--) 
		cout << path[i] << " "; 
	cout << endl;
} 
///////////////////////
int parse_line(string line){
    int error=0;
    unsigned int i;
    cout << line[0] << endl;
    if (line[0]=='V'){
    	// Find position of ':' using find() 
        int pos = line.find(" "); 
        // Copy substring after pos 
        string value = line.substr(pos + 1); 
        v = stoi(value);
        vector<int> *new_node_list = new vector<int>[v]; 
        delete [] node_list;
        node_list = new_node_list;
        error = 1;
    }else if (line[0]=='E'){
    	// Find position of ':' using find() 
        int pos = line.find(" "); 
        // Copy substring after pos 
        string str = line.substr(pos + 1); 
        regex_token_iterator<string::iterator> rend;
        try {

            sregex_iterator it(str.begin(), str.end(), re);
            int vertices[2]={0,0};
            for (; it != reg_end; ++it) {
            	i=0;
            	string s=it->str();
            	cout << s << endl;
            	sregex_iterator iter(s.begin(), s.end(), num);
                while(iter != reg_end){
                	if (i >= 2){
                		vector<int> *new_node_list = new vector<int>[v]; 
                        delete [] node_list;
                        node_list = new_node_list;
                		return 0;
        	        }
                	vertices[i]= stoi((*iter)[0]);
                	if(vertices[i] >= v){
                		vector<int> *new_node_list = new vector<int>[v]; 
                        delete [] node_list;
                        node_list = new_node_list;
                		return 0;
                	}
                    i++;
                    ++iter;
                }
                cout << vertices[0] << "," << vertices[1] << endl;
                add_edge(adj, vertices[0], vertices[1]);
                add_edge_test(node_list, vertices[0], vertices[1]);
            }             
        } catch (regex_error& e) {
            // Syntax error in the regular expression
            cout << "Error: unexpect errors" << endl;
            error = 0;
        }
        error = 1;

    }else if (line[0]=='s'){
    	// Find position of ':' using find() 
        int pos = line.find(" "); 
        // Copy substring after pos 
        string str = line.substr(pos + 1); 
    	i=0;
    	int vertices[2]={0,0};
        sregex_iterator iter(str.begin(), str.end(), num);
        while(iter != reg_end){
        	if (i >= 2){
        		return 0;
        	}
            vertices[i]= stoi((*iter)[0]);
            if(vertices[i] >= v){
                return 0;
            }
            i++;
            ++iter;
        }
        cout << vertices[0] << "," << vertices[1] << endl;
    	int source = vertices[0], dest = vertices[1]; 
    	printShortestDistance(adj, source, dest, v);
    	printShortestDistance_test(node_list, source, dest, v);
    	error = 1;
    }else{
    	error = -1;
    }

    return error;

}

int main(){

	string line;
	int error;



	while(1){

	    getline(cin, line);
        if(!cin){
           if(cin.eof())
             cout << "EOF\n";
           else
             cout << "other failure\n";
           
           break;

        }
        error = parse_line(line);
        if (error == 0){
        	cout << "Error: invalid input" << endl;
        }else if (error == -1){
        	cout << "Error: invalid command" << endl;
        }else if (error == 1){
        	cout << "Error: parsing success" << endl;
        }

	}

	cout << "Error: empty input, exit" << endl;



    adj[0].clear();
    adj[1].clear();
    adj[2].clear();
    adj[3].clear();
    adj[4].clear();
    adj[5].clear();
    adj[6].clear();
    adj[7].clear();
	// Creating graph given in the above diagram. 
	// add_edge function takes adjacency list, source 
	// and destination vertex as argument and forms 
	// an edge between them. 
	add_edge(adj, 0, 1); 
	add_edge(adj, 0, 3); 
	add_edge(adj, 1, 2); 
	add_edge(adj, 3, 4); 
	add_edge(adj, 3, 7); 
	add_edge(adj, 4, 5); 
	add_edge(adj, 4, 6); 
	add_edge(adj, 4, 7); 
	add_edge(adj, 5, 6); 
	add_edge(adj, 6, 7); 
	int source = 1, dest = 7; 
	printShortestDistance(adj, source, dest, v); 

	return 0;

}