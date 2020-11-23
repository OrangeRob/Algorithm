#ifndef __UNION_FIND_4_H__
#define __UNION_FIND_4_H__

#include <cassert>

namespace UF4 {
    class UnionFind {
    private:
        int* parent;
        int* rank;  // rank[i] : i, is a root, contains how many layers of tree
        int capacity;

    public:
        UnionFind(int capacity) {
            parent = new int[capacity];
            rank = new int[capacity];
            for(int i = 0; i < capacity; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
            this->capacity = capacity;
        }

        ~UnionFind() {
            delete [] parent;
            delete [] rank;
        }

        int find(int index) {
            assert(index >= 0 && index < capacity);
            while(index != parent[index])
                index = parent[index];
            return index;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            if(rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }
            else if(rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
                rank[pRoot] += rank[qRoot];
            }
            else {
                parent[pRoot] = qRoot;
                rank[qRoot] +=1;
            }
        }
    };
} // namespace UF4

#endif //__UNION_FIND_4_H__
