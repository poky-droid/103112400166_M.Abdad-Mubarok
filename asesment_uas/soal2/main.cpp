#include "MLL.h"

int main() {
    ListParent LP;
    createListParent(LP);

    NodeParent *G001 = allocateParent("G001", "Action");
    NodeParent *G002 = allocateParent("G002", "Comedy");
    NodeParent *G003 = allocateParent("G003", "Horror");
    NodeParent *G004 = allocateParent("G004", "Romance");

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    insertLastChild(G001->childs,
        allocateChild("FA001","The Raid",101,2011,7.6));

    insertLastChild(G002->childs,
        allocateChild("FC001","Agak Laen",119,2024,8.0));
    insertLastChild(G002->childs,
        allocateChild("FC002","My Stupid Boss",108,2016,6.8));

    insertLastChild(G003->childs,
        allocateChild("FH001","Pengabdi Setan",107,2017,8.4));
    insertLastChild(G004->childs,
        allocateChild("FR001","Habibie & Ainun",118,2012,7.6));
    insertLastChild(G004->childs,
        allocateChild("FR002","Dilan 1990",110,2018,6.6));
    printAll(LP);

    cout << "\n=== SEARCH RATING 8.0 - 8.5 ===\n";
    searchFilmByRatingRange(G001->childs, 8.0, 8.5);
    
    cout << "\n=== DELETE PARENT G002 ===\n";
    deleteAfterParent(LP, G002);

    printAll(LP);

    return 0;
}