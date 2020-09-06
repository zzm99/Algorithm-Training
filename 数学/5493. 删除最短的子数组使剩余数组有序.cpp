class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i=0; 
        for( ;i<n-1; i++ ) {
            if( arr[i] > arr[i+1] ) {
                break;
            }
        }
        int left = i;
        if( left == n-1 ) {
            return 0;
        }
        
        i = n-1;
        for( ;i>0; i-- ) {
            if( arr[i] < arr[i-1] ) {
                break;
            }
        }
        int right = i;
        
        if( right - left == n-1  ) {
            if( arr[right] >= arr[left] ) {
                return n-2;
            } else {
                return n-1;
            }
        }
        
        cout << left << ',' << right << endl;
        if( arr[left] <= arr[right] ) {
            return right-left-1;
        }

        int l = 0;
        int r = right;
        int cnt = 0;
        while( l<left+1 && r<n ) {
            if( arr[l] > arr[r] ) {
                cnt++;
                l++;
                r++;
            } else {
                l++;
            }
        }

        return right-left-1+cnt;
    }
};