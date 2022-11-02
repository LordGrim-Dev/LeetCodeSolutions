//    You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
// Slope of line formed by 

// two points (y2, y1), (x2, x1)

// Slope of Line = y2 - y1
//                ---------
//                 x2 - x1

// ---------------------------------------------------------------------------------------
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true
// ---------------------------------------------------------------------------------------

class CheckIfItIsAStraightLine
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        bool isStright = true;
        int length = coordinates.size();

        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        int dy = (y1 - coordinates[0][1]);
        int dx = (x1 - coordinates[0][0]);

        // cout<<" \n ";
        for (int i = 1; i < length; i++)
        {
            int j = 1;

            int y = (coordinates[i][1]);
            int x = (coordinates[i][0]);

            if (dy * (x - x1) != dx * (y - y1))
            {
                isStright = false;
                break;
            }
        }
        return isStright;
    }
};

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        return CheckIfItIsAStraightLine().checkStraightLine(coordinates);
    }
};