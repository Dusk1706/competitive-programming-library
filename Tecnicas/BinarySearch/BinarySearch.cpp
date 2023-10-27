#include<bits/stdc++.h>
using namespace std;

/* Binary Search */
int binarySearch(vector<int>array, int target){
    int low = 0, high = array.size() - 1;
    while (low <= high){
        int middle = (low + high) / 2;
        if (array[middle] == target)
            return middle;
        else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

/* Binary Search finding the first occurence of target */
int binarySearchFirst(vector<int>array, int target){
    int low = 0, high = array.size() - 1;
    int first = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (array[mid] == target){
            first = mid;
            high = mid - 1;
        }else if (array[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

/* Binary Search finding the last occurence of target */
int binarySearchLast(vector<int>array, int target){
    int low = 0, high = array.size() - 1;
    int last = -1;
    while (low <= high){
        int middle = (low + high) / 2;
        if (array[middle] == target){
            last = middle;
            low = middle + 1;
        }else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return last;
}

int main(){

}
