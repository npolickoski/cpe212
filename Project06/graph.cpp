
#include "graph.h"

Graph::Graph()
// Constructor initializes vertices linked list to empty
{
    vertices = NULL;
}


Graph::~Graph()
// For each VertexNode in the vertices list, Destructor deallocates all EdgeNodes before
// deallocating the VertexNode itself
{
    VertexNode*	tempVert;
    EdgeNode* tempEdge;

    while (vertices != NULL)                                    // waits until the head vertex node points to nothing, meaning no other vertex nodes exist
    {
        tempVert = vertices;                                    // saves current vertex node
        vertices = vertices->nextVertex;                        // iterates and saves next vertex node

        while (tempVert->edgePtr != NULL)                       // waits until the head edge node points to null per each vertex vertex node
        {
            tempEdge = tempVert->edgePtr;                       // saves current edge node
            tempVert->edgePtr = tempVert->edgePtr->nextPtr;     // iterates and saves next edge node
            delete tempEdge;                                    // deallocates current edge node memory
        }

        delete tempVert;                                        // deallocates current vertex node memory
    }
}


void Graph::AddVertex(string v)
// Adds vertex to graph assuming vertex not already present
{
    try
    {
        VertexNode* tempVert = new VertexNode;              // creates new vertex node on the heap

        tempVert->vname = v;                                //
        tempVert->mark = false;                             // applies inputted attributes to new vertex node
        tempVert->edgePtr = NULL;                           //
        tempVert->nextVertex = vertices;                    //

        vertices = tempVert;                                // sets new vertex node as the top node in the vertex LList
    }
    catch(std::bad_alloc)
    {
        throw GraphFull();
    }
}


void Graph::AddEdge(string s, string d, int w)
// Adds edge from source S  to destination D with specified weight W.
// If there is not enough memory to add the edge, throw the GraphFull exception
{
    try                                                         //
    {                                                           //
        EdgeNode* test = new EdgeNode;                          // tests ability to add nodes to the stack as a separate area of the function (clean code practice)
        delete test;                                            //
    }                                                           //
    catch(std::bad_alloc)                                       //
    {                                                           //
        throw GraphFull();                                      //
    }                                                           //

    VertexNode* VertSource = new VertexNode;
    VertexNode* VertDestin = new VertexNode;
    EdgeNode* IterEdge = new EdgeNode;                          // allocates memory for new edge node

    VertSource = vertices;                                      // initializes source and destination vertex nodes at vertices so as to be used to iterate 
    VertDestin = vertices;                                      //

    IterEdge->weight = w;                                       // assigns edge node attributes from inputted values
    IterEdge->nextPtr = NULL;                                   // 

    VertSource = WhereIs(s);                                    // finds source vertex node
    VertDestin = WhereIs(d);                                    // finds destination vertex node

    IterEdge->nextPtr = VertSource->edgePtr;                    // moves the current edge node at tht top of the current vertex node's edge LList back
    VertSource->edgePtr = IterEdge;                             // moves the new edge node as the new top edge node in the edge node LList for the current vertex node
    IterEdge->destination = VertDestin;                         // assigns the destination attribute of the new edge node
}


bool Graph::IsPresent(string v)
// Returns true if vertex V in graph, false otherwise
{
    VertexNode* IterVert = vertices;                    // initializes iterated vertex node at head pointer (vertices)

    while (IterVert != NULL)                            // runs until end of vertex LList
    {
        if (IterVert->vname == v)                       // if the inputted vertex name is found --> true
        {
            return true;
        }

        IterVert = IterVert->nextVertex;                // iterates to next vertex node
    }

    return false;                                       // if vertex name is not found --> false
}


VertexNode* Graph::WhereIs(string v)
// Returns pointer to the vertex node that stores vertex v in the vertices linked list; 
// Throws GraphVertexNotFound if V is not present in the vertices list
{
    if (!(IsPresent(v)))                            //  excpetion handeler: if vertex name 'v' is not found iun the LList
    {                                               //
        throw GraphVertexNotFound();                //
    }                                               //

    VertexNode* IterVert = vertices;                // initializes iterated vertex node at head pointer (vertices)

    while (IterVert->vname != v)                    // assuming 'v' is present, runs until 'v' is found
    {
        IterVert = IterVert->nextVertex;            // // iterates to next vertex node
    }

    return (IterVert);
}


int Graph::WeightIs(string s, string d)
// Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.
{
    VertexNode* VertSource = new VertexNode;                // allocates memory for new source vertex node
    VertexNode* VertDestin = new VertexNode;                // allocates memory for new destination vertex node
    EdgeNode* IterEdge = new EdgeNode;                      // allocates memory for new edge node to be iterrated

    VertSource = WhereIs(s);                                // finds vertex node from source vertex name
    VertDestin = WhereIs(d);                                // finds vertex node from destination vertex name
    IterEdge->nextPtr = VertSource->edgePtr;                // initalizes edge pointer to be iterated at head node of edge LList of current vertex node ('source' in this case)

    while(IterEdge->destination != VertDestin)              // runs until the destination attribute of the iterated edge node is the destination vertex node
    {
        IterEdge = IterEdge->nextPtr;                       // iterates next edge node

        if ((IterEdge->nextPtr == NULL) && (IterEdge->destination != VertDestin))   // exception handler: if edge LList reaches the end and destination node isn't found
        {                                                                           //
            throw GraphEdgeNotFound();                                              //
        }                                                                           //
    }

    return (IterEdge->weight);
}


void Graph::ClearMarks()
// Clears all vertex marks
{
    VertexNode* IterVert = vertices;        // initializes vertex node to be iterated at head node (vertices)

    while (IterVert != NULL)                // runs until vertex node LList reaches the end
    {
        IterVert->mark = false;             // changes mark attribute of the vertex node to unflagged
        IterVert = IterVert->nextVertex;    // iterates to next vertex node in the LList    
    }

    return;
}


void Graph::MarkVertex(string v)
// Marks vertex V as visited
{
    VertexNode* IterVert = vertices;        // initializes vertex node to be iterated at head node (vertices)

    while (IterVert->vname != v)            // runs until vertex node to flag is found
    {
        IterVert = IterVert->nextVertex;    // iterates to next vertex node
    }

    IterVert->mark = true;                  // flags mark attribute of the vertex node

    return;
}


bool Graph::IsMarked(string v)
// Returns true if vertex V is marked, false otherwise
{
    VertexNode* IterVert = vertices;        // initializes vertex node to be iterated at head node (vertices)

    while (IterVert->vname != v)            // runs until vertex name 'v' is found  
    {
        IterVert = IterVert->nextVertex;    // iterates to next vertex node
    }

    return (IterVert->mark);                // ->mark is a bool, so return val is bool
}


void Graph::GetToVertices(string V, queue<string>& q)
// Returns queue Q of vertex names of those vertices adjacent to vertex V
// The queue here is from the Standard Template Library
{
    VertexNode* TempVert = new VertexNode;          // allocates memory for new vertex node
    EdgeNode* TempEdge = new EdgeNode;              // allocates memory for new edge node

    TempVert = WhereIs(V);                          // finds vertex node with name 'V'
    TempEdge = TempVert->edgePtr;                   // assigns the edge node as the head node of the edge LList of the vertex node

    while (TempEdge != NULL)                        // runs until end of edge LList of current vertex node is found
    {
        q.push(TempEdge->destination->vname);       // pushes vertex name of the destination vertex node of each edge node in the edge LList of current vertex node into queue 'q'
        TempEdge = TempEdge->nextPtr;               // iterates to next vertex node
    }   

    return;
}


void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
// Uses the DFS algorithm from the CPE 212 textbook to determine a path from the
// startVertex to the endVertex.  If a path is found, the path vertices should
// be in the path queue.  If no path is found, the path queue should be emptied
// as a signal to the client code that no path exists between the start and
// end vertices.
{
    // NOTE: algorithm found in book, so idk how it works. Will comment exception handling as that was done by me  //

    ClearMarks();

    stack<VertexNode*>vertexQ;
    queue<string>Queue;
    bool found = false;
    VertexNode* TempVert = new VertexNode;

    if (!(IsPresent(startVertex)) || !(IsPresent(endVertex)))   // exception handler: if the starting and ending vertex nodes don't exist
    {                                                           //
        throw GraphVertexNotFound();                            //
    }                                                           //

    string vertex;
    string item;

    vertexQ.push(WhereIs(startVertex));

    do
    {
        TempVert = vertexQ.top();
        vertexQ.pop();

        if (TempVert->vname == endVertex)
        {
            path.push(TempVert->vname);
            found = true;
        }
        else
        {
            if (!IsMarked(TempVert->vname))
            {
                MarkVertex(TempVert->vname);
                path.push(TempVert->vname);
                GetToVertices(TempVert->vname, Queue);

                while (!Queue.empty())
                {
                    item = Queue.front();
                    Queue.pop();

                    if (!IsMarked(item))
                    {
                        vertexQ.push(WhereIs(item));
                    }
                }
            }
        }

    } while (!vertexQ.empty() && !found);

    if (!found)
    {
        while (!path.empty())
        {
            path.pop();
        }
    }
    
    return;
}

