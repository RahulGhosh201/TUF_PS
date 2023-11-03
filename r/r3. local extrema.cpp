#include <iostream>
#include <vector>
#include <cmath>

class ExtremaCalculator
{
public:
    ExtremaCalculator(const std::vector<int> &data) : arr(data) {}

    int calculateLocalExtrema()
    {
        int count = 0;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (isExtrema(arr[i - 1], arr[i], arr[i + 1]))
            {
                count++;
            }
        }
        return count;
    }

private:
    std::vector<int> arr;

    bool isExtrema(int num1, int num2, int num3)
    {
        return (isMax(num1, num2, num3) || isMin(num1, num2, num3));
    }

    bool isMax(int num1, int num2, int num3)
    {
        return (num2 > num1 && num2 > num3);
    }

    bool isMin(int num1, int num2, int num3)
    {
        return (num2 < num1 && num2 < num3);
    }
};

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 1, 2, 1, 2, 1};
    ExtremaCalculator calculator(data);
    int result = calculator.calculateLocalExtrema();
    std::cout << "Number of local extrema: " << result << std::endl;
    return 0;
}
