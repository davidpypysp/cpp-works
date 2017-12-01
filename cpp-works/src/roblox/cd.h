#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class Path
{
public:
	Path(std::string path)
	{
		currentPath = path;
	}

	std::string getPath() const
	{
		return currentPath;
	}

	Path cd(std::string newPath) const
	{
        vector<string> currentList;
        if(newPath.size() > 0 && newPath[0] != '/') 
            currentList = getDirs(currentPath);
        
        vector<string> newList = getDirs(newPath);
        for(string dir : newList) {
            if(dir == "..") currentList.pop_back();
            else currentList.push_back(dir);
        }
        string result = "";
        for(string dir : currentList) {
            result += '/' + dir;
        }
        return Path(result);
	}

private:
	std::string currentPath;
    
    static vector<string> getDirs(string s) {
        if(s[s.size()-1] != '/') s += '/';
        string dir = "";
        vector<string> result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '/') {
                if(i == 0) continue;
                result.push_back(dir);
                dir = "";
            }
            else {
                dir += s[i];
            }
        }
        return result;
    }
    
};

/*int main(int argc, const char* argv[])
{
	Path path("/a/b/c/d");
	std::cout << path.cd("../x").getPath();
}*/