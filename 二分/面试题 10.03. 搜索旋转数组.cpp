class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        while(n > 1 && arr[n-1] == arr[0]) n--;
        int l = 0, r = n-1;
        while(l < r) {
            int mid = (l+r) >> 1;
            if(arr[mid] <= arr[r]) r = mid;
            else l = mid+1;
        }
        r = l + n - 1;
        if(target < arr[l]) return -1;
        while(l < r) {
            int mid = (l+r) >> 1;
            if(arr[mid%n] >= target) r = mid;
            else l = mid+1;
        }
        if(arr[l%n] == target) return l%n;
        return -1;
    }
};