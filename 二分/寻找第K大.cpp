class Finder {
public:
    void quick(vector<int>& a, int left, int right, int k, int &data) {
        if(left >= right) {
            if(left+1 == k && left == right) {
                data = a[left];
                return;
            }
        }
        if(right+1 < k) return;
        if(left+1 > k) return;
        int l = left;
        int r = right;
        int temp = a[l];
        while(l < r) {
            while(a[r] <= temp && l < r) r--;
            a[l] = a[r];
            while(a[l] >= temp && l < r) l++;
            a[r] = a[l];
        }
        a[l] = temp;
        if(k == l+1) {
            data = a[l];
            return;
        }
        quick(a, left, l-1, k, data);
        quick(a, l+1, right, k, data);
    }
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int data = 0;
        quick(a, 0, n-1, K, data);
        return data;
    }
};