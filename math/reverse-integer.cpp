class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        return reverse_num(&x, &reversed);
    }

    int reverse_num(int* x, int* reversed) {
        // base case 1: overflow
        if (*reversed > INT_MAX / 10) { // rev * 10 > max
            return 0;
        }
        if (*x > 0 && *reversed * 10 > INT_MAX - *x % 10) { // rev * 10 + num % 10 > max
            return 0;
        }
        if (*reversed < INT_MIN / 10) { // rev * 10 < min
            return 0;
        }
        if (*x < 0 && *reversed * 10 < INT_MIN - *x % 10) { // rev * 10 - num % 10 < min
            return 0;
        }
        if (*x / 10 == 0) { // base case 2: End of number
            return *reversed * 10 + *x;
        } else { // continue reversing (multiply prev by 10 then add last digit)
            *reversed = *reversed * 10 + *x % 10;
            *x /= 10;
            return reverse_num(x, reversed);
        }
    }
};