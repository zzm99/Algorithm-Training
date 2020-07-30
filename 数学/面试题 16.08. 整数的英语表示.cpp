class Solution {
public:
	const int N[31] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 
			100, 1000, 1000000, 1000000000};
	const string S[31] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
			"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
			"Hundred", "Thousand", "Million", "Billion"};
    const int K = 90;
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 30;
        while (i >= 0 && N[i] > num) --i;
        string res;
        if (N[i] <= K) {
            res += S[i];
        } else {
            res += numberToWords(num / N[i]) + " " + S[i];
        }
        if (num % N[i] > 0) res += " " + numberToWords(num % N[i]);
        return res;
    }
};
