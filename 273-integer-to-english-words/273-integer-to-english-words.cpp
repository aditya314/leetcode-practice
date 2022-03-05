class Solution {
private:
    const int billion = 1e9, million = 1e6, thousand = 1e3, hundred = 1e2;
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string toWords(int n) {
        if (n >= billion) 
            return toWords(n / billion) + " Billion" + toWords(n % billion);
        if (n >= million) 
            return toWords(n / million) + " Million" + toWords(n % million);
        if (n >= thousand) 
            return toWords(n / thousand) + " Thousand" + toWords(n % thousand);
        if (n >= hundred) 
            return toWords(n / hundred) + " Hundred" + toWords(n % hundred);
        if (n >= 20) 
            return " " + tens[n / 10] + toWords(n % 10);
        if (n >= 1) 
            return " " + ones[n];
        return "";
    }
public:
    string numberToWords(int n) {
        return n ? toWords(n).substr(1) : "Zero";
    }
};
