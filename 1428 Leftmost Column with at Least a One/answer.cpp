class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int cols = dimensions[1];
        int i = 0, j = cols-1;
        while (i < rows && j >= 0){
            if (binaryMatrix.get(i,j)) --j;
            else ++i;
        }
        return j == cols-1 ? -1 : j+1;
    }
};
