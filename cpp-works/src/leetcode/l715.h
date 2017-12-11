#include <iostream>

using namespace std;


class RangeModule {
public:
    RangeModule() {
        root = new Interval(0, 50);
    }
    
    void addRange(int left, int right) {
        root->add(left, right-1);
    }
    
    bool queryRange(int left, int right) {
        return root->query(left, right-1);
    }
    
    void removeRange(int left, int right) {
        root->remove(left, right-1);
    }
private:
struct Interval {
    int left;
    int right;
    int mid;
    bool track;
    
    Interval *l, *r;
    
    Interval(int left, int right) : left(left), right(right) {
        mid = (left + right) / 2;
        track = false;
        l = nullptr;
        r = nullptr;
    }
    
    void add(int left, int right) {
        if(left == this->left && right == this->right) {
            this->track = true;
            if(this->l) {
                this->l->remove(this->left, this->mid);
                delete this->l;
                this->l = nullptr;
            }
            if(this->r) {
                this->r->remove(this->mid+1, this->right);
                delete this->r;
                this->r = nullptr;
            }
            return;
        }
        
        this->track = false;
        if(right <= this->mid) {
            if(!l) {
                l = new Interval(this->left, this->mid);
            }
            l->add(left, right);
        }
        else if(left > this->mid) {
            if(!r) {
                r = new Interval(this->mid+1, this->right);
            }
            r->add(left, right);
        }
        else {
            if(!l) {
                l = new Interval(this->left, this->mid);
            }  
            if(!r) {
                r = new Interval(this->mid+1, this->right);
            }
            l->add(left, this->mid);
            r->add(this->mid+1, right);
        }
    }
    
    bool query(int left, int right) {
        if(this->track == true) return true;
        if(left == this->left && right == this->right) {
            return this->track;
        }
        
        if(right <= this->mid) {
            if(!this->l) {
                return false;
            }
            else {
                return l->query(left, right);
            }
        }
        else if(left > this->mid) {
            if(!this->r) {
                return false;
            }
            else {
                return r->query(left, right);
            }
        }
        else {
            if(!this->l || !this->r) return false;
            return this->l->query(left, this->mid) && this->r->query(this->mid+1, right);
        }
    }
    
    
    void remove(int left, int right) {
        this->track = false;
        if(left == this->left && right == this->right) {
            if(this->l) {
                this->l->remove(this->left, this->mid);
                delete this->l;
                this->l = nullptr;
            }
            if(this->r) {
                this->r->remove(this->mid+1, this->right);
                delete this->r;
                this->r = nullptr;
            }
            return;
        }
        
        if(right <= this->mid) {
            if(this->l) {
                this->l->remove(left, right);
                if(left == this->left && right == this->mid) {
                    delete this->l;
                    this->l = nullptr;
                }
            }
            if(!this->r) {
                this->r = new Interval(this->mid+1, this->right);
                this->r->track = true;
            }
        }
        else if(left > this->mid) {
            if(this->r) {
                this->r->remove(left, right);
                if(left == this->mid+1 && right == this->right) {
                    delete this->r;
                    this->r = nullptr;
                }
            }
            if(!this->l) {
                this->l = new Interval(this->left, this->mid);
                this->l->track = true;
            }
        }
        else {
            if(this->l) {
                this->l->remove(left, this->mid);
            }
            if(this->r) {
                this->r->remove(this->mid+1, right);
            }
        }
    }
    
};

    
    
    
    Interval *root;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */