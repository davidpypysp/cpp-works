#ifndef ADJACENT_LIST_H_
#define ADJACENT_LIST_H_

#include <iostream>
#include <vector>

using namespace std;

struct AdjacentEdge;


struct AdjacentNode {
	int val;
	AdjacentEdge *edge;

	AdjacentNode(int val = 0, AdjacentEdge *edge = nullptr) : val(val), edge(edge) {
	}

};

struct AdjacentEdge {
	AdjacentNode *node;
	AdjacentEdge *next;

	AdjacentEdge(AdjacentNode *node = nullptr, AdjacentEdge *next = nullptr) : node(node), next(next) {
	}

};


struct AdjacentGraph {
	vector<AdjacentNode> nodes;
};



#endif