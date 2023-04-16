
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

    while (vertices != NULL)
    {
        tempVert = vertices;
        vertices = vertices->nextVertex;

        while (tempVert->edgePtr != NULL)
        {
            tempEdge = tempVert->edgePtr;
            tempVert->edgePtr = tempVert->edgePtr->nextPtr;
            delete tempEdge;
        }

        delete tempVert;
    }
}


void Graph::AddVertex(string v)
// Adds vertex to graph assuming vertex not already present
{
    try
    {
        VertexNode* tempVert = new VertexNode;

        tempVert->vname = v;
        tempVert->mark = false;
        tempVert->edgePtr = NULL;
        tempVert->nextVertex = vertices;

        vertices = tempVert;
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
    try
    {
        VertexNode* VertSource = new VertexNode;
        VertexNode* VertDestin = new VertexNode;
        EdgeNode* IterEdge = new EdgeNode;

        IterEdge->weight = w;
        IterEdge->nextPtr = NULL;

        VertSource = WhereIs(s);
        VertDestin = WhereIs(d);

        IterEdge->nextPtr = VertSource->edgePtr;
        VertSource->edgePtr = IterEdge;
        IterEdge->destination = VertDestin;

        // if (VertSource->edgePtr == NULL)        // #1: no edges in vertex
        // {
        //     VertSource->edgePtr = IterEdge;
        //     IterEdge->nextPtr = NULL;
        // }
        // else                                    // #2: edge inserted at end of edge LList
        // {
            
        // }
    }
    catch(std::bad_alloc)
    {
        throw GraphFull();
    }
}


bool Graph::IsPresent(string v)
// Returns true if vertex V in graph, false otherwise
{
    VertexNode* IterVert = vertices;

    while (IterVert != NULL)                  // finds source vertex node
    {
        if (IterVert->vname == v)
        {
            return true;
        }

        IterVert = IterVert->nextVertex;
    }

    return false;
}


VertexNode* Graph::WhereIs(string v)
// Returns pointer to the vertex node that stores vertex v in the vertices linked list; 
// Throws GraphVertexNotFound if V is not present in the vertices list
{
    if (!(IsPresent(v)))
    {
        throw GraphVertexNotFound();
    }

    VertexNode* IterVert = vertices;

    while (IterVert->vname != v)
    {
        IterVert = IterVert->nextVertex;
    }

    return (IterVert);
}


int Graph::WeightIs(string s, string d)
// Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.
{
    if (!(IsPresent(s)) || !(IsPresent(d)))
    {
        throw GraphEdgeNotFound();
    }

    VertexNode* VertSource = WhereIs(s);
    VertexNode* VertDestin = WhereIs(d);
    EdgeNode* IterEdge = VertSource->edgePtr;

    // VertSource = WhereIs(s);
    // VertDestin = WhereIs(d);
    //IterEdge = VertSource->edgePtr;

    while(IterEdge->destination != NULL)//VertDestin)
    {
        IterEdge = IterEdge->nextPtr;
    }

    return (IterEdge->weight);
}


void Graph::ClearMarks()
// Clears all vertex marks
{
    VertexNode* IterVert = vertices;

    while (IterVert != NULL)
    {
        IterVert->mark = false;
        IterVert = IterVert->nextVertex;
    }

    return;
}


void Graph::MarkVertex(string v)
// Marks vertex V as visited
{
    VertexNode* IterVert = vertices;

    while (IterVert->vname != v)
    {
        IterVert = IterVert->nextVertex;
    }

    IterVert->mark = true;

    return;
}


bool Graph::IsMarked(string v)
// Returns true if vertex V is marked, false otherwise
{
    // if (!(IsPresent(v)))
    // {
    //     throw GraphVertexNotFound();
    // }

    VertexNode* IterVert = vertices;

    while (IterVert->vname != v)                  
    {
        IterVert = IterVert->nextVertex;
    }

    return (IterVert->mark);                    // ->mark is a bool, so return val is bool
}


void Graph::GetToVertices(string V, queue<string>& q)
// Returns queue Q of vertex names of those vertices adjacent to vertex V
// The queue here is from the Standard Template Library
{
    VertexNode* TempVert = new VertexNode;
    EdgeNode* TempEdge = new EdgeNode;

    TempVert = WhereIs(V);
    TempEdge = TempVert->edgePtr;

    while (TempEdge != NULL)
    {
        q.push(TempEdge->destination->vname);
        TempEdge = TempEdge->nextPtr;
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
    ClearMarks();

    stack<VertexNode*>vertexQ;
    queue<string>Queue;
    bool found = false;
    VertexNode* TempVert = new VertexNode;

    if (!IsPresent(startVertex) || !IsPresent(endVertex))
    {
        throw GraphVertexNotFound();
    }

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

