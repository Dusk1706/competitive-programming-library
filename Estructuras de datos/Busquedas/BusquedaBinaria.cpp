#include <bits/stdc++.h>

using namespace std;

 int busquedaBinaria(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
        int mid = left + floor((right-left+1)/2);
        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid; 
        }
    }
    if(nums[left]==target){
        return left;
    }else{
        return -1;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int>nums;
    busquedaBinaria(nums,5);

    return 0;
}