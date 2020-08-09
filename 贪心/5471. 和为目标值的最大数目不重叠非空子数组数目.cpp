class Solution {
public:
    int maxNonOverlapping(vector<int> const & nums, int const target) {
        auto count = 0;

        auto pre_sum = std::unordered_set<int>();
        auto sum = 0;
        for (auto const num: nums) {
            pre_sum.insert(sum);
            sum += num;
            if (pre_sum.find(sum - target) != pre_sum.cend()) {
                pre_sum.clear();
                ++count;
            }
        }

        return count;
    }
};