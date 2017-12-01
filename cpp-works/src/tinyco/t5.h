#include <vector>
#include <memory>
#include <queue>

using namespace std;

class Node : public enable_shared_from_this<Node> {
    shared_ptr<Node> parent{};
    vector<shared_ptr<Node>> children{};
    int value{};

    shared_ptr<Node> bfs(int searchValue) { // bfs method of getNode function
        queue<shared_ptr<Node>> q;
        q.push(shared_from_this());

        while(!q.empty()) {
            shared_ptr<Node> node = q.front();
            q.pop();
            for(shared_ptr<Node> next : node->children) {
                if(next->value == searchValue) return next; // found result
                q.push(next);
            }
        }
        return nullptr;
    }




public:
    Node(int a_value) : value(a_value) {}
    ~Node() {}

    int getValue() {
        return value;
    }

    shared_ptr<Node> addChilrd(const shared_ptr<Node> &child) {
        children.push_back(child);
        children.back()->parent = shared_from_this();
        return children.back();
    }

    shared_ptr<Node> dfs(int searchValue, shared_ptr<Node> node) { // dfs method of getNode function
        for(shared_ptr<Node> next : node->children) {
            if(next->value == searchValue) return next;
            shared_ptr<Node> result = dfs(searchValue, next);
            if(result != nullptr) return result;
        } 
        return nullptr;
    }
    
    shared_ptr<Node> getNode(int searchValue, bool includeThis = false) {
        // Handle includeThis here
        if(includeThis && this->value == searchValue) return shared_from_this();

        return dfs(searchValue, shared_from_this()); // dfs search for result
    }


    int getDepth() {
        int cnt = 0;
        shared_ptr<Node> node = shared_from_this();
        while(node->parent != nullptr) { // iteration to find the top parent
            node = node->parent;
            ++cnt;
        }
        return cnt;

    }


};