class Solution {
public:
    double sum;
    int length;
    vector<double> prob;
    
    Solution(vector<int>& w) {
        length = w.size();
        sum = 0;
        
        for (int n : w)
            sum += n;
        
        prob.push_back(w[0]/sum);
        
        for (int i = 1; i < length; i++)
            prob.push_back((w[i]/sum)+prob[i-1]);
        
        for (double d : prob)
            cout << d << " ";
        cout << endl;
    }
    
    int pickIndex() {
        double r = (rand()%100)/(double)100;
        double p;
        int i = 0;
        
        for (; i < length; i++) {
            if (prob[i] > r)
                return i;
        }
        
        return i-1;
    }
};
