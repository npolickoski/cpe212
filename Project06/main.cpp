//
// main.cpp  2010 Fall CPE 212 - Project06 - Graphs and STL
//
// Driver program for Graph class -- The text files (read by this code) contain a series 
// of commands that will help you test your Graph ADT code by triggering various class methods.
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include "graph.h"
#include <stack>				// For STL stack class
#include <queue>				// For STL queue class

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputs;			// Input file for commands
	char op, ch;				// Hold operation and optional char input
	Graph* gPtr = NULL;			// Will point to Graph object
	int num;					// Holds number of graph nodes
	string v1, v2;				// Vertex names input from file
	int w;						// Edge weight input from file
	queue<string> path;			// Computed path
	string  comment;            // Comment input from file
	
	// Output usage message if one input file name is not provided
	if (argc != 2)
	{
		cout << "Usage:\n  project07  <inputfile>\n";
		return 1;
	}
	
	// Attempt to open input file -- terminate if file does not open
	inputs.open(argv[1]);
	if (!inputs)
	{
		cout << "Error - unable to open input file" << endl;
		return 1;
	}
	
	cout << endl;
	
	// Process commands from input file
	getline(inputs, comment);
	cout << comment << endl;
	
	inputs >> op;			// Attempt to input number of vertices
	while (inputs)
	{		
		switch (op)
		{
			case '#':   // Comment
				getline(inputs, comment);
				cout << comment << endl;
				break;
				
			case 'c':	// Add vertex
				cout << "Constructor()" << endl;
				gPtr = new Graph();
				break;
				
			case 'v':	// Add vertex
				inputs >> v1;
				cout << "AddVertex(" << v1 << ")" << endl;
				gPtr->AddVertex(v1);
				break;
				
			case 'd':	// Add directed edge
				inputs >> v1 >> v2 >> w;
				cout << "AddEdge(" << v1 << ", " << v2 << ", " << w << ")" << endl;
				gPtr->AddEdge(v1, v2, w);
				break;
				
			case 'u':	// Add undirected edge
				inputs >> v1 >> v2 >> w;
				cout << "AddEdge(" << v1 << ", " << v2 << ", " << w << ")" << endl;
				gPtr->AddEdge(v1, v2, w);
				cout << "AddEdge(" << v2 << ", " << v1 << ", " << w << ")" << endl;
				gPtr->AddEdge(v2, v1, w);
				break;
				
			case '?':	// IsPresent()
				inputs >> v1;
				if (gPtr->IsPresent(v1))
					cout << "IsPresent(" << v1 << ") -- true" << endl;
				else
					cout << "IsPresent(" << v1 << ") -- false" << endl;
				break;
				
			case 'w':	// WeightIs()
				inputs >> v1 >> v2;
				try
				{
					cout << "WeightIs(" << v1 << ", " << v2 << ") -- ";
					w = gPtr->WeightIs(v1, v2);
					cout << w << endl;
				}
				catch ( GraphVertexNotFound )
				{
				cout << "Error: vertex not found" << endl;
				}
				catch ( GraphEdgeNotFound )
				{
					cout << "Error: edge not found" << endl;
				}
				break;
				
			case 's':	// Perform Depth-First Search
				inputs >> v1 >> v2;		// Input v1-start and v2-end vertices
				
				cout << "DFS( " << v1 << ", " << v2 << " ) -- ";
				try
				{
					gPtr->DepthFirstSearch(v1, v2, path);
				

					if (path.empty())
						cout << "No path found" << endl;
					else
					{
						cout << " { ";
						while (!path.empty())
						{
							cout << path.front() << " ";
							path.pop();
						}
						cout << "}" << endl;
					}
				}
				catch ( GraphVertexNotFound )
				{
				  cout << "Error: vertex not found" << endl;
				}
				
				while (!path.empty())
					path.pop();

				break;
				
			case 'p':	// Print Graph
				gPtr->Print();
				break;
				
			case '~':	// Destructor
				delete gPtr;
				gPtr = NULL;
				cout << "Destructor()" << endl << endl;
				break;
				
			default:	// Error
				cout << "Error - unrecognized operation '" << op << "'" << endl;
				cout << "Terminating now..." << endl;
				return 1;
				break;
		}
		
		inputs >> op;	// Attempt to input next command
	}
	
	
  return 0;
}

