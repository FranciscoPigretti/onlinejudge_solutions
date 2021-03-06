

/* 
The main innovation of this data structure is in choosing a representative ‘parent’ item to represent a set.
The representative ‘parent’ item can be used as a sort of identifier for the set.
To achieve this, the Union-Find Disjoint Set creates a tree structure where the disjoint sets form a forest of trees.

Each tree corresponds to a disjoint set.

Thus, the representative set identifier for an item can be obtained simply
by following the chain of parents to the root of the tree, and since a tree can only have one
root, this representative item can be used as a unique identifier for the set.

To do this efficiently, we...
    1. store the index of the parent item (vi p)
    2. store (the upper bound of) the height of the tree of each set (vi rank).

*/

#include <iostream>  // cin, cout
#include <vector>

using namespace std;

class UnionFind { // OOP style
    private: 
        vector<int> parent_of, rank_of; // remember: vi is vector<int>
    
    public:
    
    UnionFind(int N) { 
        rank_of.assign(N, 0);
        parent_of.assign(N, 0); for (int i = 0; i < N; i++) parent_of[i] = i; 
    }

    int findSet(int i) { return (parent_of[i] == i) ? i : (parent_of[i] = findSet(parent_of[i])); }
    
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank_of[x] > rank_of[y]) {
                parent_of[y] = x; // rank keeps the tree short
            } else { 
                parent_of[x] = y;
                if (rank_of[x] == rank_of[y]) rank_of[y]++; 
            }
        } 
    }
};


int main() {
  UnionFind my_union_find(5);

  cout << my_union_find.isSameSet(1,2);
  cout << my_union_find.isSameSet(1,1);
} 
