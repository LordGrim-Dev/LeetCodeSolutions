// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// Note:

// Note that in some languages, such as Java, there is no unsigned integer type. 
//      In this case, the input will be given as a signed integer type. 
//      It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.


class NumberofOneBits
{
    
public:
    int GetHammingWeight(uint32_t n)
    {

        // uint32_t count =0;
        // while(n)
        // {
        //     count+=(n&1);
        //     n = (n>>1);
        // }
        // return count;

        return __builtin_popcount(n);
    }
};

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return NumberofOneBits().GetHammingWeight(n);
    }
};