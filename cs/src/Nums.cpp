#include "../headers/Nums.h"



// bool IsNumber(const std::string& input) {
//     for (int i = 0; i < input.length(); i++) {
//         if(i==0 && input[i] == '-') continue;
//         if (input[i] < '0' || input[i] > '9') {
//             if ((i==0 || i==input.length()-1))return false;
//             if(!(input[i]==',')) return false;
//         }
//     }
//     return true;
// }

long long IntPow(const long long base, const long long exp) {
    if (exp==0) return 1;
    if (exp==1) return base;
    return base * IntPow(base, exp-1);
}