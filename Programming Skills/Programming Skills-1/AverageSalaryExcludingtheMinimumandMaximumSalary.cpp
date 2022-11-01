
// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

class AverageSalaryExcludingtheMinimumandMaximumSalary
{
        
public:
    double FindAverage(vector<int> &salary)
    {
        int minSalary = 999999;

        int maxSalary = 0;

        int n = salary.size();

        int sumOfSalary = 0;

        for (int i = 0; i < n; i++)
        {
            int currentSal = salary[i];
            minSalary = min(minSalary, currentSal);
            maxSalary = max(maxSalary, currentSal);
            sumOfSalary += currentSal;
        }
        sumOfSalary -= (minSalary + maxSalary);

        return (sumOfSalary / (double)(n - 2));
    }
};

class Solution
{
public:
    double average(vector<int> &salary)
    {
        return AverageSalaryExcludingtheMinimumandMaximumSalary().FindAverage(salary);
    }
};