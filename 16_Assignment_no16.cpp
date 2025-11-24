#include <iostream>
#include <string>
using namespace std;


class GNode {
public:
    bool isAtom;       
    string data;       
    GNode* next;       
    GNode* down;       

    GNode(bool atom = true, string val = "") {
        isAtom = atom;
        data = val;
        next = down = NULL;
    }
};

void display(GNode* node) {
    cout << "{";
    while (node != NULL) {
        if (node->isAtom)
            cout << node->data;  
        else
            display(node->down); 

        if (node->next != NULL)
            cout << ", ";
        node = node->next;
    }
    cout << "}";
}


GNode* createSublist() {
    // Sublist: {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1}
    GNode* r = new GNode(true, "r");
    GNode* s = new GNode(true, "s");
    GNode* t = new GNode(true, "t");
    GNode* emptySet = new GNode(false); // {}
    emptySet->down = NULL;

    GNode* u = new GNode(true, "u");
    GNode* v = new GNode(true, "v");
    u->next = v;
    GNode* uv = new GNode(false);
    uv->down = u;

    
    GNode* y = new GNode(true, "y");
    GNode* z = new GNode(true, "z");
    y->next = z;
    GNode* yz = new GNode(false);
    yz->down = y;

    GNode* w = new GNode(true, "w");
    GNode* x = new GNode(true, "x");
    GNode* a1 = new GNode(true, "a1");
    GNode* b1 = new GNode(true, "b1");

    
    r->next = s;
    s->next = t;
    t->next = emptySet;
    emptySet->next = uv;
    uv->next = w;
    w->next = x;
    x->next = yz;
    yz->next = a1;
    a1->next = b1;

    GNode* sublist = new GNode(false);
    sublist->down = r;
    return sublist;
}

int main() {
    
    GNode* p = new GNode(true, "p");
    GNode* q = new GNode(true, "q");
    GNode* sublist = createSublist();

    p->next = q;
    q->next = sublist;

    
    GNode* S = new GNode(false);
    S->down = p;

    cout << "Set S = ";
    display(S->down);
    cout << endl;

    return 0;
}
