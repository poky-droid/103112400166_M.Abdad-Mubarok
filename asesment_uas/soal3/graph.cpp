#include "graph.h"

void createGraph(Graph &g) {
    g.first = NULL;
}

adrNode createNode(infoType x) {
    adrNode p = new Node;
    p->info = x;
    p->aktif = true;
    p->visited = false;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

void addNode(Graph &g, adrNode p) {
    if (g.first == NULL) {
        g.first = p;
    } else {
        adrNode q = g.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

adrNode findNode(Graph g, infoType x) {
    adrNode p = g.first;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

void addEdge(Graph &g, infoType from, infoType to) {
    adrNode pFrom = findNode(g, from);
    adrNode pTo   = findNode(g, to);
    if (pFrom != NULL && pTo != NULL) {
        adrEdge e = new Edge;
        e->tujuan = pTo;
        e->next = pFrom->firstEdge;
        pFrom->firstEdge = e;
    }
}

void resetVisited(Graph &g) {
    adrNode p = g.first;
    while (p != NULL) {
        p->visited = false;
        p = p->next;
    }
}

void DFS(adrNode p) {
    if (p == NULL || !p->aktif || p->visited)
        return;
    p->visited = true;
    adrEdge e = p->firstEdge;
    while (e != NULL) {
        DFS(e->tujuan);
        e = e->next;
    }
}

bool isGraphConnectedAfterIgnore(Graph g, infoType ignoreNode) {
    adrNode p = g.first;
    while (p != NULL) {
        if (p->info == ignoreNode)
            p->aktif = false;
        p = p->next;
    }
    resetVisited(g);
    adrNode start = NULL;
    p = g.first;
    while (p != NULL && start == NULL) {
        if (p->aktif)
            start = p;
        p = p->next;
    }
    DFS(start);
    bool connected = true;
    p = g.first;
    while (p != NULL) {
        if (p->aktif && !p->visited) {
            connected = false;
            break;
        }
        p = p->next;
    }

    p = g.first;
    while (p != NULL) {
        p->aktif = true;
        p = p->next;
    }

    return connected;
}

void printConneksiGraph(Graph g) {
    adrNode p = g.first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->tujuan->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}