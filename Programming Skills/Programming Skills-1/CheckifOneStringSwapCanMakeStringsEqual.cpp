// You are given two strings s1 and s2 of equal length.
// A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings.
// Otherwise, return false.

class CheckifOneStringSwapCanMakeStringsEqual
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        bool equalPossible = false;

        // Store the index value at which charector of s1 is not equal to s2
        // then it's just a matter of checking the length of indiffrent count.
        vector<int> indices;

        int length = s2.length();

        for (int i = 0; i < length; i++)
        {
            if (s1[i] != s2[i])
                indices.push_back(i);
        }
        int count = indices.size();

        if (count == 0)
            equalPossible = true;
        else if (count == 1 || count > 2) // greater than 2 imposible as only 1 swap allowed
            equalPossible = false;
        else
        {
            // example : bank and knab
            // Check s1[0] == s2[3] &&
            // s1[3] == s2[0]
            if (s1[indices[0]] == s2[indices[1]] && s2[indices[0]] == s1[indices[1]])
                equalPossible = true;
        }
        return equalPossible;
    }
};

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        return CheckifOneStringSwapCanMakeStringsEqual().areAlmostEqual(s1, s2);
    }
};