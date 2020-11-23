#ifndef __UNION_FIND_TESTHELPER_H__
#define __UNION_FIND_TESTHELPER_H__

#include <iostream>
#include <ctime>
#include <chrono>

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"

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
        std::cout << "UF1 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000000.0 << " s" << std::endl;
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
        std::cout << "UF2 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000000.0 << " s" << std::endl;
    }

    void testUF3(int n) {
        std::srand(time(NULL));
        UF3::UnionFind uf = UF3::UnionFind(n);
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
        std::cout << "UF3 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000000.0 << " s" << std::endl;
    }

    void testUF4(int n) {
        std::srand(time(NULL));
        UF4::UnionFind uf = UF4::UnionFind(n);
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
        std::cout << "UF4 : " << 2 * n << " ops, " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() / 1000000.0 << " s" << std::endl;
    }
} // namespace UnionFindTestHelper

#endif //__UNION_FIND_TESTHELPER_H__
