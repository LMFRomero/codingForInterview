class Solution {
public:
    string str1, str2;
    map <pair<int, int>, int> m;
    
    int f (int i, int j) {
        if (min(i, j) == 0)
            return max(i,j);
        
        if (m.find(make_pair(i, j)) != m.end())
            return m[make_pair(i, j)];
        
        int tmp;
        
        if (str1[i-1] == str2[j-1])
            tmp = f(i-1, j-1);
        
        else {
            tmp = f(i-1, j-1)+1;
            tmp = min (tmp, f(i-1, j)+1);
            tmp = min (tmp, f(i, j-1)+1);
        }
        
        m[make_pair(i, j)] = tmp;
        
        return tmp;
    }
    
    int minDistance(string word1, string word2) {
        str1 = word1;
        str2 = word2;
        return f (word1.length(), word2.length());
    }
};
