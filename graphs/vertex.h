#ifndef VERTEX_H_
#define VERTEX_H_

template<typename K = int>  
class Vertex{
    public:
        K element;
        // the predecessor
        Vertex* π;
        int d;
        // white represents undiscovered
        // grey represents the frontier between discovered and 
        // undiscovered 
        // black represents discovered
        enum color {WHITE, BLACK, GREY};

        Vertex(element=0, d=0, π=nullptr) : element{element}, d{d}, π{π} {}
        ~Vertex();
};

#endif