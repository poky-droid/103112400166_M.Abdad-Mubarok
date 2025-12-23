#include "graph.h"

int main() {
    Graph g;
    createGraph(g);
    addNode(g, createNode('A'));
    addNode(g, createNode('B'));
    addNode(g, createNode('C'));
    addNode(g, createNode('D'));
    addNode(g, createNode('E'));
    addEdge(g,'A','B'); addEdge(g,'B','A');
    addEdge(g,'B','E'); addEdge(g,'E','B');
    addEdge(g,'B','C'); addEdge(g,'C','B');
    addEdge(g,'C','D'); addEdge(g,'D','C');
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    printConneksiGraph(g);
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";
    adrNode p = g.first;
    while (p != NULL) {
        if (!isGraphConnectedAfterIgnore(g, p->info)) {
            cout << "[PERINGATAN] Kota " << p->info << " adalah KOTA KRITIS!\n";
            cout << "- Jika " << p->info << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << p->info << " aman (redundansi oke).\n";
        }
        p = p->next;
    }
    return 0;
}