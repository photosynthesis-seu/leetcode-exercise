/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int peak = FindMountainPeak(mountainArr,0,len-1);
        int res;
        res = SearchForwardArray(target,mountainArr,0,peak);
        if(res != -1){
            return res;
        }
        return SearchReverseArray(target,mountainArr,peak,len-1);
    }
    int FindMountainPeak(MountainArray& mountainArr,int left,int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    int SearchForwardArray(int target,MountainArray& mountainArr,int left,int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid)<target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if(mountainArr.get(left)==target){
                return left;
            }
        return -1;
    }
     int SearchReverseArray(int target,MountainArray& mountainArr,int left,int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid)>target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if(mountainArr.get(left)==target){
                return left;
            }
        return -1;
    }
};
