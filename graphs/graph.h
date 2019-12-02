#ifndef GRAPH_H_
#define GRAPH_H_
#include <unordered_set>
#include <vector>
#include <utility>
#include "vertex.h"

class Graph{
    public:
        std::unordered_set<Vertex<int>> vertices;
        std::unordered_set<std::pair<Vertex<int>,Vertex<int>>> edges;
        //adjacency-list
        std::vector<std::vector<Vertex<int>>> adj; 

        //constructor
        Graph();
        Graph(std::unordered_set<int> vertices, 
              std::unordered_set<std::pair<Vertex<int>,Vertex<int>>> edges) : 
              vertices{vertices}, edges{edges};
        ~Graph();
        void insert();
        void make_edge();
        Tree BFS(Vertex<int> source);
        Tree DFS(Vertex<int> source);
        bool has_cycle();
        void print_path(Vertex<int> from, Vertex<int> to);
};

#endif