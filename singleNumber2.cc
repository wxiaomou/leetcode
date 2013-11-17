class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!n) return 0;
        int ones = 0, twos = 0, _three = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i]; //add new bits which dup int ones and A[i] to twos 
            ones ^= A[i];//remove the bits in ones which dup with A[i] and add the bits in A[i] to ones
            //delete the bits in both twos and ones
            //all bits in twos are the bits which show up twice and some of the added before this loop, 
            //if they are in ones so this is the 3rd time they show up, we should delete them.
            _three = ~(twos & ones);
            ones &= _three;
            twos &= _three;
        }
        return ones;
    }
};