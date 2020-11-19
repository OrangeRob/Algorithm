#ifndef __UNION_FIND_1_H__
#define __UNION_FIND_1_H__

#include <cassert>

namespace UF1 {

    class UnionFind {
    private:
        int* id;
        int capacity;

    public:
        UnionFind(int capacity) {
            this->capacity = capacity;
            id = new int[capacity];
            for(int i = 0; i < capacity; i++)
                id[i] = i;
        }

        ~UnionFind() {
            delete [] id;
        }

        int find(int index) {
            assert(index >= 0 && index < capacity);
            return id[index];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);

            if(pID == qID)
                return;

            for(int i = 0; i < capacity; i++) {
               if(id[i] == pID)
                   id[i] = qID;
            }
        }
    };
} // namespace UF1

#endif // __UNION_FIND_1_H__
