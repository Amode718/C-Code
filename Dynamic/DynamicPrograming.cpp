//  Name: Andrei Modiga
//  Assignment number: 7
//  Assignment: Dynamic Programming
//  File name: dynamicProgram.cpp
//  Date last modified: December 06, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.
 
#include <iostream>
#include <vector>  // std::vector
#include <algorithm>  // std::min
 
int editDistance(std::string s1, std::string s2) {
   int m = s1.length();
   int n = s2.length();
 
   int dp[m + 1][n + 1];
  
   for(int i = 0; i <= m; i++) {
       for(int j = 0; j <= n; j++)  {
           //Base conditions
           if(i == 0)
               dp[i][j] = j;
           //Base conditions
           else if(j == 0)
               dp[i][j] = i;
            //solving the sub-problems
           else if(s1[i - 1] == s2[j - 1])
               dp[i][j] = dp[i - 1][j - 1];
           else
               // find the min of the numbers
               dp[i][j] = 1 + std::min(dp[i][j - 1],std::min(dp[i - 1][j],dp[i - 1][j - 1]));
       }
   }
   // return the number
   return dp[m][n];
}
 
 
void Loop() {
   // While loop to keep the program running
   while (true) {
       std::string s1;
       std::cout << "Enter the first string: ";
       getline(std::cin, s1);
 
       std::string s2;
       std::cout << "Enter the second string: ";
       getline(std::cin, s2);
 
       // Calculate moves/prints the result
       std::cout << editDistance(s1, s2) << std::endl;
 
       if (s1 == "exit" || s2 == "exit") {
           break;
       }
   }
}
 
int main()
{
   Loop();
   return 0;
}
