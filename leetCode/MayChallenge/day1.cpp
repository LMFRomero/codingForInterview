// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1) == true)
            return 1;
        
        long long mid, lo = 1, hi = n;
        
        while (hi >= lo) {
            mid = (lo+hi)/2;
            if (isBadVersion(mid) == true) {
                if (isBadVersion(mid-1) == false) {
                    return mid;
                }
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        
        return 0;
    }
};
