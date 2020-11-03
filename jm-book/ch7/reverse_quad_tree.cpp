#include <iostream>

using namespace std;

struct QuadTree {
    char me;
    QuadTree *q;
    QuadTree *w;
    QuadTree *e;
    QuadTree *r;

    QuadTree(char me)
        : me(me), q(nullptr), w(nullptr), e(nullptr), r(nullptr) {}
};

QuadTree *input() {
    char c;
    cin >> c;
    QuadTree *root = new QuadTree(c);

    if (c == 'x') {
        root->q = input();
        root->w = input();
        root->e = input();
        root->r = input();
    }

    return root;
}

void reverse(QuadTree *root) {
    if (root == nullptr) {
        return;
    }

    if (root->me == 'w' || root->me == 'b') {
        return;
    }

    reverse(root->q);
    reverse(root->e);
    swap(root->q, root->e);

    reverse(root->w);
    reverse(root->r);
    swap(root->w, root->r);
}

void print(const QuadTree *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->me;
    print(root->q);
    print(root->w);
    print(root->e);
    print(root->r);
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        QuadTree *root = input();
        reverse(root);
        print(root);
        cout << '\n';
    }
}
