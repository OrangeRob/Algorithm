#ifndef __UNION_FIND_3_H__
#define __UNION_FIND_3_H__

#include <cassert>

namespace UF3 {
    class UnionFind {
    private:
        int* parent;
        int* sz;    // sz[i] : i, is a root, contains how many elements
        int capacity;

    public:
        UnionFind(int capacity) {
            parent = new int[capacity];
            sz = new int[capacity];
            this->capacity = capacity;
            for(int i = 0; i < capacity; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind() {
            delete [] parent;
            delete [] sz;
        }

        int find(int index) {
            assert(index >= 0 && index < capacity);

#if 0       /** Path Compression - version 1 */
            while( index != parent[index]) {
                parent[index] = parent[parent[index]];
                index = parent[index];
            }
            return index;
#endif
            /** Path Compression - version 2 */
            if(index != parent[index]) {
                parent[index] = find(parent[index]);
            }
            return parent[index];

        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            if(sz[pRoot] < sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
} // namespace UF3

#endif //__UNION_FIND_3_H__
