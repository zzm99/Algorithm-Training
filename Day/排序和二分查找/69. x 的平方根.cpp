class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        double A = x, x0 = x;
        while(true) {
            double xi = 0.5 * (x0 + A/x0);
            if(fabs(x0-xi) < 1e-7) {
                break;
            }
            x0 = xi;
        } 
        return int(x0);
    }
};


/// 

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while(l <= r) {
            int mid = l + ((r-l) >> 1);
            if((long long)mid * mid <= x) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};