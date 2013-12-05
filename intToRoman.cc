#include<iostream>
#include<string>
using namespace std;

    class Solution {
    public:
        /*string intToRoman(int num) {
            string ret("");
    		if (!num)
				return ret;
			int base = 10;
			while ((num % base) == 0) base *= 10;
			// for the number only the first digit is not 0
			if (base > num) {
				string one;
				string ten;
				string five;

				if (base == 10) {
					one = 'I';
					five = 'V';
					ten = 'X';
				} else if (base == 100) {
					one = 'X';
					five = 'L';
					ten = 'C';
				} else if (base == 1000) {
					one = 'C';
					five = 'D';
					ten = 'M';
				} else {
					one = 'M'; // because input < 3999
				}

				int first = (num / (base / 10) )% 10;
				switch(first) {
				case 1:
					return one;
				case 2: 
					return one + one;
				case 3:
					return one + one + one;
				case 4:
					return one + five;
				case 5:
					return five;
				case 6:
					return five + one;
				case 7:
					return five + one + one;
				case 8: 
					return five + one + one + one;
				case 9:
					return one + ten;
				}
			} else {
				int cur = num % base;
				int pre = num - cur;
				return intToRoman(pre) + intToRoman(cur);
			}*/
		//iterative way.
		string intToRoman(int num) {
        if (!num) return "";
        int base = 1000;
        string ret = "";
        while (base > 0) {
            int cur = num / base;
            num -= cur * base;
            string one, five, ten;
            
            switch (base) {
                case 1:
                    one = "I";
                    five = "V";
                    ten = "X";
                    break;
                case 10:
                    one = "X";
                    five = "L";
                    ten = "C";
                    break;
                case 100:
                    one = "C";
                    five = "D";
                    ten = "M";
                    break;
                case 1000:
                    one = "M";
                    break;
            }
            
            if (cur <= 3) {
                for (int i = 0; i < cur; i++) ret += one;
            } else if (cur == 4) {
                ret += one + five;
            } else if (cur < 9) {
                ret += five;
                for (int i = 0; i < cur - 5; i++) ret += one;
            } else {
                ret += one + ten;
            }
            base /= 10;
        }
        return ret;
        }
    };
