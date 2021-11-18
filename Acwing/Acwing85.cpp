class Solution {
public:
    int add(int num1, int num2){
        while(num2) {   // 不断循环直到没有进位
            int sum = num1 ^ num2;  // 先算不进位的加法结果
            int carry = (num1 & num2) << 1; //  算加法进位的结果
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};