//
//@author Xiao Xu
//@create 2018-09-28 21:56
//Two Sum II - Input array is sorted
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            int left = i + 1, right = numbers.size() - 1;
            int temp = target - numbers[i];
            while(left <= right){
                int mid = (left + right) / 2;
                if(numbers[mid] == temp){
                    result.push_back(i + 1);
                    result.push_back(mid + 1);
                    return result;
                }else if(numbers[mid] > temp)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}

//vector<int> twoSum(vector<int>& numbers, int target) {
//    int left = 0, right = numbers.size()-1;
//    vector<int> answer; answer.resize(2);
//    while (left < right) {
//        if (numbers[left] + numbers[right] < target)
//            left++;
//        else if (numbers[left] + numbers[right] > target)
//            right--;
//        else {
//            answer[0] = left+1; answer[1] = right+1; return answer;
//        }
//
//    } return answer;
//}