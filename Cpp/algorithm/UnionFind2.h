#ifndef __UNION_FIND_2_H__
#define __UNION_FIND_2_H__

#include <cassert>

namespace UF2 {
    class UnionFind {
    private:
        int* parent;
        int capacity;

    public:
        UnionFind(int capacity) {
            parent = new int[capacity];
            this->capacity = capacity;
            for(int i = 0; i < capacity; i++)
                parent[i] = i;
        }

        ~UnionFind() {
            delete [] parent;
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

            parent[pRoot] = qRoot;
        }


    };

} // UF2

#endif //__UNION_FIND_2_H__
