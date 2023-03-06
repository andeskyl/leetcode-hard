class Solution {
public:
    string nums[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string nums_ten[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string nums_thousand[4] = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        string res = intToWords(num);
        return num > 0 ? res.substr(0, res.find_last_not_of(' ') + 1) : "Zero";
    }
    string intToWords(int num) {
        if (num == 0) return "";
        else if (num < 20) return nums[num] + " ";
        else if (num < 100) return nums_ten[num / 10] + " " + intToWords(num % 10);
        else if (num < 1000) return nums[num / 100] + " Hundred " + intToWords(num % 100);
        else {
            string output = "";
            for (int i = 0; i < 4; i++, num /= 1000) {
                if (num % 1000 > 0)
                    output = intToWords(num % 1000) + nums_thousand[i] + " " + output;
            }
            return output;
        }
    }
};