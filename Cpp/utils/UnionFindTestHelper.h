#ifndef __UNION_FIND_TESTHELPER_H__
#define __UNION_FIND_TESTHELPER_H__

#include <iostream>
#include <ctime>
#include <chrono>

#include "UnionFind1.h"
#include "UnionFind2.h"

namespace UnionFindTestHelper {
    void testUF1(int n) {
        std::srand(time(NULL));
        UF1::UnionFind uf = UF1::UnionFind(n);
        auto startTime = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < n; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for(int i = 0; i < n; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        std::cout << "UF1 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000 << " ms" << std::endl;
    }

    void testUF2(int n) {
        std::srand(time(NULL));
        UF2::UnionFind uf = UF2::UnionFind(n);
        auto startTime = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < n; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for(int i = 0; i < n; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        std::cout << "UF2 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000 << " ms" << std::endl;
    }
} // namespace UnionFindTestHelper

#endif //__UNION_FIND_TESTHELPER_H__
