class Solution {
public:
    map<int, vector<int>> prereq;
    unordered_set<int> coursesDone;
    
    bool dfs (int course, unordered_set<int> currentPath) {
        if (currentPath.find(course) != currentPath.end())
            return false;
        
        if (coursesDone.find(course) != coursesDone.end())
            return true;
        
        currentPath.insert(course);
        
        auto v = prereq[course];
        
        for (int n : v) {
            if (dfs(n, currentPath) == false)
                return false;
        }
        
        coursesDone.insert(course);
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {  
        unordered_set<int> currentPath;  
        currentPath.clear();
        
        for (auto v : prerequisites) {
            (prereq[v[0]]).push_back(v[1]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (coursesDone.find(i) != coursesDone.end())
                continue;

            if (dfs(i, currentPath) == false) return false;
        }
        
        return true;
    }
};
