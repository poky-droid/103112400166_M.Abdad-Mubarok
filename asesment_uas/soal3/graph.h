#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoType;
struct Node;
struct Edge;
typedef Node* adrNode;
typedef Edge* adrEdge;
struct Node {
    infoType info;
    bool aktif;          
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Edge {
    adrNode tujuan;
    adrEdge next;
};



struct Graph {
    adrNode first;
};

void createGraph(Graph &g);
adrNode createNode(infoType x);
void addNode(Graph &g, adrNode p);
void addEdge(Graph &g, infoType from, infoType to);
adrNode findNode(Graph g, infoType x);
void resetVisited(Graph &g);
void DFS(adrNode p);
bool isGraphConnectedAfterIgnore(Graph g, infoType ignoreNode);
void printConneksiGraph(Graph g);
#endif