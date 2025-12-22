#include "graph.h"
#include <iostream>

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');
    cout << "Graph conection list:" << endl;
    printGraph(G);

    cout << "\nDFS Traversal mulai node A:" << endl;
    adrNode startNode = G.first; // Node A
    penulusuranDFS(G, startNode);
    cout << endl;

    resetVisited(G); 
    cout << "\nDFS Traversal mulai node C:" << endl;
    startNode = G.first->next->next; // Node C
    penulusuranDFS(G, startNode);
    cout << endl;

    return 0;
}