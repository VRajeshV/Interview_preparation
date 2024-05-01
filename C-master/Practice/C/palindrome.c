// C program to check whether a 
// string is palindrome or not. 
#include <stdio.h> 
#include <string.h> 
  
// Palindrome function to check 
// whether a string is palindrome 
// or not 
void Palindrome(char s[]) 
{ 
    // Start will start from 0th index 
    // and end will start from length-1  
    int start = 0; 
    int end = strlen(s) - 1; 
  
    // Comparing characters until they 
    // are same  
    while (end > start) { 
        if (s[start++] != s[end--]) { 
            printf("%s is not a Palindrome \n", s); 
            return; 
        } 
    } 
    printf("%s is a Palindrome \n", s); 
} 
  
// Driver code 
int main() 
{ 
    Palindrome("abba"); 
    return 0; 
}