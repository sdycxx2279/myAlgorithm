//
//@author Xiao Xu
//@create 2018-03-24 11:03
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int position1 = 0;
        int position2 = 0;
        int positionOfMedian = (m+n)/2;
        bool odd = (m+n)%2 == 1;
        if(m == 0 && n == 0)
            return 0.0;
        else if(m == 0){
            if(odd){
                return nums2[positionOfMedian] / 1.0;
            }else{
                return (nums2[positionOfMedian] + nums2[positionOfMedian-1]) / 2.0;
            }
        }else if(n == 0){
            if(odd){
                return nums1[positionOfMedian] / 1.0;
            }else{
                return (nums1[positionOfMedian] + nums1[positionOfMedian-1]) / 2.0;
            }
        }
        for(int i=0;i<m+n;i++){
            if(position1<m&&position2<n){
                if(i == positionOfMedian){
                    if(odd){
                        return min(nums1[position1],nums2[position2]) / 1.0;
                    }else{
                        if(position1 == 0){
                            return (nums2[position2-1] + min(nums1[position1],nums2[position2])) / 2.0;
                        }else if(position2 == 0){
                            return (nums1[position1-1] + min(nums1[position1],nums2[position2])) / 2.0;
                        }else{
                            return (max(nums1[position1-1],nums2[position2-1]) + min(nums1[position1],nums2[position2])) / 2.0;
                        }
                    }
                }
                if(nums1[position1] < nums2[position2])
                    position1++;
                else
                    position2++;
            }else if(position1 >= m){
                if(i == positionOfMedian){
                    if(odd){
                        return nums2[position2] / 1.0;
                    }else{
                        return (max(nums1[position1-1],nums2[position2-1]) + nums2[position2]) / 2.0;
                    }
                }
                position2++;
            }else if(position2 >= n){
                if(i == positionOfMedian){
                    if(odd){
                       return nums1[position1] / 1.0;
                    }else{
                        return (max(nums1[position1-1],nums2[position2-1]) + nums1[position1]) / 2.0;
                    }
                }
                position1++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> s1,s2;
//    s1.push_back(1);
//    s1.push_back(1);
    s2.push_back(10);
    s2.push_back(11);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    s1.push_back(5);
    s1.push_back(6);
    s1.push_back(7);

    cout<<s.findMedianSortedArrays(s1,s2);
    return 0;
}

