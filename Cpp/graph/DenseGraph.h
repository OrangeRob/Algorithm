#ifndef __DENSEGRAPH_H__
#define __DENSEGRAPH_H__

#include <vector>
#include <cassert>

/** Adjucency Matrix */
class DenseGraph {
private:
    /**
     * n : Vertex
     * m : Edge
     * directed : false : Undirected ; true : Directed Graph
     * g : both vertexes are connected?
     */
    int n, m;
    bool directed;
    std::vector<std::vector<bool>> g;

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;

        /** n by n matrix */
        for(int i = 0; i < n; i++)
            g.push_back(std::vector<bool>(n, false));
    }

    ~DenseGraph() {

    }

    int V() { return n; }
    int E() { return m; }

    void addEdge(int v, int w) {
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        if(hasEdge(v, w))
            return;

        g[v][w] = true;     // connect v - w
        if( !directed )
            g[w][v] = true;

        m++;
    }

    bool hasEdge(int v, int w) {
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        return g[v][w];
    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for(index += 1; index < G.V(); index++)
                if(G.g[v][index])
                    return index;
            return -1;
        }

        bool end() {
            return index >= G.V();
        }
    };
};

#endif //__DENSEGRAPH_H__
