//
// graph.h  2010 Fall CPE 212 - Project06 - Graphs and STL
//
// Specification file for Graph class
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#ifndef GRAPH_H

#define GRAPH_H

#include <cstddef>
#include <new>
#include <iostream>
#include <iomanip>
#include <stack>									// For STL stack
#include <queue>									// For STL queue
#include <string>
using namespace std;


class GraphPathNotFound {  };                       // Exception class represents path-not-found condition

class GraphEdgeNotFound {  };                       // Exception class represents edge-not-found condition

class GraphVertexNotFound {  };                     // Exception class represents vertex-not-found condition

class GraphFull	{  };                             // Exception class represents graph-full condition

struct VertexNode;                                  // Forward declaration of VertexNode type

struct EdgeNode                                     // Structure representing an edge
{
  VertexNode*   destination;                        // Pointer to destination vertex
  int           weight;                             // Edge weight
  EdgeNode*     nextPtr;                            // Pointer to next edge
};

struct VertexNode									          // Structure representing a vertex
{
  string        vname;                              // Name of vertex
  bool          mark;                               // Marked flag
  EdgeNode*     edgePtr;                            // Pointer to list of outgoing edges
  VertexNode*   nextVertex;                         // Pointer to next vertex in vertices list
};


class Graph											// Graph ADT using adjacency list representation
{
 private:		//***** Private class members below *****//
  VertexNode*	vertices;						// Linked list of vertex nodes

 public:		   //***** Public members below *****//
  Graph();									
  // Graph()
  // Constructor initializes vertices linked list to empty
	
  ~Graph();	
  // ~Graph()
  // For each VertexNode in the vertices list, Destructor deallocates all EdgeNodes before
  // deallocating the VertexNode itself
	
  void AddVertex(string v);		
  // AddVertex()
  // Adds vertex to graph assuming vertex not already present

  void AddEdge(string s, string d, int w);		
  // AddEdge()
  // Adds edge from source S  to destination D with specified weight W.
  // If there is not enough memory to add the edge, throw the GraphFull exception
	
  bool IsPresent(string v);	
  // IsPresent()
  // Returns true if vertex V in graph, false otherwise
	
  VertexNode*  WhereIs(string v);		/* Note: This function replaces IndexIs */
  // WhereIs()
  // Returns pointer to the vertex node that stores vertex v in the vertices linked list; 
  // Throws GraphVertexNotFound if V is not present in the vertices list
	
  int  WeightIs(string s, string d);    
  // WeightIs()
  // Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.
	
  void ClearMarks();		
  // ClearMarks()
  // Clears all vertex marks
	
  void MarkVertex(string v);	
  // MarkVertex()
  // Marks vertex V as visited
	
  bool IsMarked(string v);		
  // IsMarked()
  // Returns true if vertex V is marked, false otherwise

  void GetToVertices(string V, queue<string>& q);	
  // GetToVertices()
  // Returns queue Q of vertex names of those vertices adjacent to vertex V
  // The queue here is from the Standard Template Library
	
  void DepthFirstSearch(string startVertex, string endVertex, queue<string>& path);
  // DepthFirstSearch()
  // Uses the DFS algorithm from the CPE 212 textbook to determine a path from the
  // startVertex to the endVertex.  If a path is found, the path vertices should
  // be in the path queue.  If no path is found, the path queue should be emptied
  // as a signal to the client code that no path exists between the start and
  // end vertices.
  //
  // Notes:
  // (1) This algorithm is flawed in that as it searches for a path, it may
  // output some additional vertices that it visited but were not part
  // of the actual path.  Implement the algorithm just as it appears in the textbook.
  // 
  // (2) This algorithm requires use of the stack and queue containers from the
  // Standard Template Library.  The STL stack and queue interfaces may require
  // minor modifications to the DFS code from the textbook.

		
	// Print -- write graph to stdout.  DO NOT MODIFY THIS FUNCTION!!!
	void Print()
	{
		EdgeNode* eptr;
        VertexNode* vptr = vertices;
		const int FIELDWIDTH = 6;
		string STARS = "**********";
		STARS = STARS + STARS + STARS; 
		
		cout << endl << STARS << endl;
		
		cout << setw(FIELDWIDTH) << "Vertex" << " : " << "Adjacent Vertices" << endl;
		cout << "------------------------------" << endl;
		
        while(vptr != NULL)
		{
			cout << setw(FIELDWIDTH) << vptr->vname << " : ";
			
			eptr = vptr->edgePtr;
			while (eptr != NULL)
			{
				cout << eptr->destination->vname << eptr->weight << " ";
				eptr = eptr->nextPtr;
			}
			cout << endl;
            vptr = vptr->nextVertex;
		}
		cout << STARS << endl << endl;
	} // Graph::Print()
}; 

#endif


