// #include <bits/stdc++.h>
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> bits(num+1,0);
//         for(int i=1;i<=num;i++)
//         {
//             bits[i]+=bits[i&(i-1)]+1;
//         }
//         return bits;
//     }
// };