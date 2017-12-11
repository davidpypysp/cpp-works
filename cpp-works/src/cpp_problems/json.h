#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <unordered_map>
#include <typeinfo>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class JsonObject {
public:
    JsonObject() : level(1), output_brace(true) {}
    virtual string str() = 0;
    virtual void output() = 0;
    int level;
    bool output_brace;
};
 
class JsonScalar: public JsonObject {
public: 
    JsonScalar(double value) : _value(value) {} 
    virtual string str() {
        return to_string(_value); 
    }

    void output() {
        cout << to_string(_value);
    }

private:
    double _value;
};
 
class JsonString: public JsonObject { 
public:
    JsonString(const string& str): _str(str) {}
    virtual string str() {
        return "\"" + _str + "\"";
    }
    void output() {
        cout << "\"" + _str + "\"";
    }
private: 
    string _str;
};

class JsonArray: public JsonObject {
public:
    JsonArray() {}
    JsonArray(const vector<JsonObject*> vec): _vec(vec) {}
    virtual string str() {
        string res = "[";
        int cnt = 0;
        for (auto p: _vec) {
            if (cnt) { 
                res += ", ";
            }
            res += p->str();
            cnt++;
        }
        res += "]";
        return res;
    }
    void add(JsonObject* object_p) {
        _vec.push_back(object_p);
        object_p->level = this->level + 1;
    }

    void output() {
        string space;
        for(int i = 0; i < level; i++) space += "  ";
        if(output_brace) cout << space + "[" << endl;
        int cnt = 0;
        for(auto p : _vec) {
            cout << space + "  ";
            p->output();
            if(++cnt < _vec.size()) cout << ",";
            cout << endl;
        }
        if(output_brace) cout << space + "]" << endl;
    }

private:
    vector<JsonObject*> _vec;
};


class JsonDict: public JsonObject {
public:
    JsonDict() : JsonObject() {
    }
    JsonDict(const unordered_map<string, JsonObject*> mp): _mp(mp) {
    }
    virtual string str() {
        string space = "";
        for(int i = 0; i < level; i++) space += "  ";


        string res = "{";
        int cnt = 0;
        for (auto pp: _mp) {
            if (cnt) {
                res += ", ";
            }
            auto key = pp.first; 
            auto value = pp.second;
            res += "\"" + key + "\"";
            res += ": ";
            res += value->str();
            cnt++;
        }
        res += space + "}";
        return res;
    }
 
    void add(const string& key, JsonObject* value) {
        _mp[key] = value;
        value->level = this->level + 1;
        value->output_brace = false;
    }
    
    void add(const char* key, JsonObject* value) {
        _mp[key] = value;
        value->level = this->level + 1;
        value->output_brace = false;
    }

    JsonObject* get(const string &key) {
        if(_mp.find(key) == _mp.end()) return nullptr;
        return _mp[key];
    }

    void output() {
        string space = "";
        for(int i = 0; i < level; i++) {
            space += "  ";
        }

        if(output_brace) cout << space + "{" << endl;

        int cnt = 0;
        for (auto pp: _mp) {
            string key = pp.first; 
            JsonObject* value = pp.second;
            cout << space + "  \"" + key + "\"" + ": "; 
            if(dynamic_cast<JsonScalar*>(value)) {
                value->output();
            }
            else if(dynamic_cast<JsonString*>(value)) {
                value->output();
            }
            else if(dynamic_cast<JsonDict*>(value)) {
                cout << "{" << endl;
                value->output();
                cout  << space + "  " + "}";
            }
            else if(dynamic_cast<JsonArray*>(value)) {
                cout << "[" << endl;
                value->output();
                cout << space + "  " + "]";
            }
            if(++cnt < _mp.size()) {
                cout << ",";
            }
            cout << endl;
        }
        if(output_brace) cout << space + "}" << endl;

    }
    
private:
    unordered_map<string, JsonObject*> _mp;
};

typedef JsonDict Json;


void C2() {
    Json json;
    json.add("winfo_id", new JsonScalar(1)); 
    json.add("unit_id",  new JsonScalar(2));
    json.add("plan_id",  new JsonScalar(3));
    json.add("user_id",  new JsonScalar(4));
    json.add("url", new JsonString("i am not a url"));
    json.add("bid", new JsonArray({
        new JsonScalar(1.1),
        new JsonScalar(1.2),
        new JsonString("nineteen")
    }));
    json.add("wiseapp", new JsonDict({
        {"Android", new JsonString("url for android")},
        {"iOS",     new JsonString("url for ios")},
        {"WP",      new JsonString("404 not found")}
    }));

    json.output();
}


