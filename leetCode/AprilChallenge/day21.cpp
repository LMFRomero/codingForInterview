/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
class Solution {
public:
    int binarySearch (BinaryMatrix b, int i, const int maxJ) {
        int lo = 0, hi=maxJ-1;
        int j;
        int num;
        
        while (lo <= hi) {
            j = (lo+hi)/2;
            num = b.get(i, j);
            if (num == 0) {
                if (j != maxJ-1) {
                    if (b.get(i, j+1) == 1) return j+1;
                    else lo = j+1;
                }
                else break;
            }
            else {
                if (j == 0 or b.get(i, j-1) == 0) return j;
                else hi = j-1;
            }
        }
        
        return -1;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row, column, minCol = -1;
        int tmp;
        row = binaryMatrix.dimensions()[0];
        column = binaryMatrix.dimensions()[1];
        
        for (int i = 0; i < row; i++) {
            tmp = binarySearch(binaryMatrix, i, column);
            if (tmp == -1 and minCol != -1) continue;
            if (minCol == -1) minCol = tmp;
            else minCol = min(minCol, tmp);
        }
        
        return minCol;
    }
};
