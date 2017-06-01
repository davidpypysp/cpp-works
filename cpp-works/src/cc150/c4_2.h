#include <unordered_map>
#include "../util/adjacent_list.h"

using namespace std;

class C4_2 {
	enum NodeState {
		Unvisited,
		Visiting,
		Visited
	};

	unordered_map<AdjacentNode*, int> map;

	bool search(AdjacentGraph &graph, AdjacentNode *start, AdjacentNode *end) {
		for (AdjacentNode &node : graph.nodes) {
			map[&node] = Unvisited;
		}
	}

	bool dfs(AdjacentNode *node, AdjacentNode *dest) {
		if (node == dest) {
			return true;
		}
		map[node] = Visiting;
		AdjacentEdge *e = node->edge;
		while (e) {
			if (map[e->node] == Unvisited) {
				if (dfs(e->node, dest) == true) return true;
			}
			e = e->next;
		}
		map[node] = Visited;
		return false;
	}
};