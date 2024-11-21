/*=====================================================================
Author: Arjit Magar
Date: 2024/11/17
Description: A program that calculates the total number of happy. This is the first version of my program.
prime numbers between 1 and 1 Million
Input: No Input
Output: Total number of happy prime number between 1 & 1 Million
Compilation instructions: Just Compile and run it .
Date Comment:
---- ------------------------------------------------
======================================================================*/
#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int main() 
{
    auto start = chrono::high_resolution_clock::now();
    const int limit = 1000000;
    int happyPrime = 0;

    for ( int i = 2; i <= limit; i++ )               
    {
        int primeCount = 0; 

        if ( i % 2 != 0)
        {
            //begining with 2 because every number is divisible by 1
            for ( int j = 2 ; j <= sqrt(i) ; j++ )     
            {                                          
                if ( i % j == 0 )                     
                { 
                    primeCount++; 
                    //  Prime count increases if a divisor is found                                                  
                }
            }
            
            if ( primeCount == 0 ) 
            // If any number is Prime Number[]                         
            {
                int num = i;
                int itr = 0;

                while ( num != 1 && itr < 8 ) 
            // itr makes iterations < 20 to  avoid the infinite loop
                { 
                    int sum = 0;                       

                    while ( num > 0 )                 
                    {
                        int digit = num % 10;          
                        sum = sum + digit * digit;    
                        num = num / 10;               
                    }                                  
                    num = sum;                        
                    itr++;
                }
                if ( num == 1 )                       
                {
                    happyPrime++;                           
                }
            }
        }
    }

    cout << endl
         << "The total happy prime numbers up to 1 Million " << " are: " << happyPrime << endl
         << endl ;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    return 0;
}
