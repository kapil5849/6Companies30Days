

// 2179. Count Good Triplets in an Array...

class Solution {
public:
    inline int lastOne(int x) {
        return x & (-x);
    }
    void updateFenwickTree(vector<int>& fenwickTree, int index, int delta) {
        for(;index < fenwickTree.size(); index += lastOne(index)) {
            fenwickTree[index] += delta; 
        }
    }
    int getPrefixSum(vector<int>& fenwickTree, int index) {
        int prefixSum = 0; 
        for(;index;index -= lastOne(index)) {
            prefixSum += fenwickTree[index];
        }
        return prefixSum; 
    }
    int getRangeSum(vector<int>& fenwickTree, int startIndex, int endIndex) {
        return getPrefixSum(fenwickTree,endIndex) - (startIndex == 1?0:getPrefixSum(fenwickTree,startIndex-1));
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int vectorSize = nums1.size(); 
        vector<int> indexPositions(vectorSize);
        for(int i = 0; i < vectorSize; i++) {
            indexPositions[nums1[i]] = i;
        }
        long long goodTripletCount = 0; 
        vector<int> fenwickTree(vectorSize + 5);
        vector<int> smallerElementsToRight(vectorSize);
        for(int i = vectorSize - 1; i >= 0; i--) {
            int index = indexPositions[nums2[i]];
            smallerElementsToRight[nums2[i]] = getRangeSum(fenwickTree,index + 1,vectorSize + 1);
            // update the Fenwick tree at index j + 1
            updateFenwickTree(fenwickTree,index + 1,1);
        }
        fenwickTree.assign(vectorSize + 5,0);
        for(int i = 0; i < vectorSize; i++) {
            int index = indexPositions[nums2[i]];
            long long smallerElementsBefore = getPrefixSum(fenwickTree,index);
            goodTripletCount += smallerElementsBefore * smallerElementsToRight[nums2[i]];
            updateFenwickTree(fenwickTree,index + 1,1);
        }
    return goodTripletCount;
    }
};
