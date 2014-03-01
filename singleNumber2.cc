class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test cas
        if (!n) return 0;
        int ones = 0, twos = 0, _three = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i]; //add new bits which dup int ones and A[i] to twos 
            ones ^= A[i];//remove the bits in ones which dup with A[i] and add the bits only in A[i] to ones
            //delete the bits in both twos and ones
            //all bits in twos are the bits which show up twice and some of the added before this loop, so some bits in A[i] is dup 
            //with the bits in twos but not dup with the bits in ones, they got added to ones and we need use _three to remove them
            //if they are in ones so this is the 3rd time they show up, we should delete them.
            _three = ~(twos & ones);
            ones &= _three;
            twos &= _three;
        }
        return ones;
    }
    /*
     int singleNumber(int A[], int n) {
        if (!n) return 0;
        int ones = 0;
        int twos = 0;
        int threes = 0;
        for ( auto i = 0; i < n; ++i ) {
            twos |= ones & A[i];

            int tmp = ~(ones & A[i]);
            ones |= A[i];
            ones &= tmp; 
            // same as ones ^= A[i];
            threes = twos & ones;
            if (threes) {
                twos &= ~threes;
                ones &= ~threes;
            }
        }
        return ones;
    }
    */
};

