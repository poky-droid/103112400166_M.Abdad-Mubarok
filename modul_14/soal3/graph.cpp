#include "graph.h"
#include <iostream>
void createGraph(Graph &G ){
    G.first = NULL;
}

adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(Graph &G , infoGraph start ,infoGraph end){
    adrNode P = G.first;
    while (P != NULL && P->info != start){
        P = P->next;
    }
    if (P != NULL){
        adrNode Q = G.first;
        while (Q != NULL && Q->info != end){
            Q = Q->next;
        }
        if (Q != NULL){
            adrEdge E = new ElmEdge;
            E->Node = Q;
            E->next = NULL;
            if (P->firstEdge == NULL){
                P->firstEdge = E;
            } else {
                adrEdge F = P->firstEdge;
                while (F->next != NULL){
                    F = F->next;
                }
                F->next = E;
            }
        }
    }
}
void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->Node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void penulusuranBFS(Graph &G, adrNode P){
    if (P == NULL) return;

    queue<adrNode> Q;

    P->visited = true;
    Q.push(P);

    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();

        cout << current->info << " ";

        adrEdge E = current->firstEdge;
        while (E != NULL) {
            adrNode nextNode = E->Node;
            if (!nextNode->visited) {
                nextNode->visited = true;
                Q.push(nextNode);
            }
            E = E->next;
        }
    }
}


void resetVisited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = false;
        P = P->next;
    }
}

