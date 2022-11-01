class CountOddNumbersinanIntervalRange
{
public:
    int countOdds(int low, int high)
    {
        // Check for last bit 1 or not, if 1 = OddNumber
        //  if 0 = event number;

        // difference = high-low
        // if high is ODD -> then there will be a difference+1 oddNubers

        if (high & 1 == 1 || low & 1 == 1)
            return ((high - low) / 2) + 1;
        else
            return (high - low) / 2;
    }
};