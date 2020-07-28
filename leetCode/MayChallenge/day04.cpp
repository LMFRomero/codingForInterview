class Solution {
public:
    int findComplement(int num) {
        long long answer = 0;
        
        for (int i = 0; (1LL << i) <= num; i++) {
            long long a = 1LL << i, b = num << i;
            cout << a << endl;
            if (num & (1LL << i)) {
            
            }
            else
                answer ^= 1LL << 1;
        }
        return answer;
    }
};
