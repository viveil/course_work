#include <vector>
#include <algorithm>
#include <iostream>



int trap(std::vector<int>& height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    std::vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = std::max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = std::max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += std::min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}

void printVector(std::vector<int> height ) {
    for (int i = 0; i < height.size(); i++)
        std::cout << height[i] << ' ';
    std::cout << std::endl;
}
int main()
{
    {
        std::vector<int> vector = { 0,1,0,2,1,0,1,3,2,1,2,1 };
        std::cout << "input: ";
        printVector(vector);
        std::cout << "output: " << trap(vector) << std::endl << std::endl;
    }

    {
        std::vector<int> vector = { 4,2,0,3,2,5 };
        std::cout << "input: ";
        printVector(vector);
        std::cout << "output: " << trap(vector) << std::endl << std::endl;
    }
}


