
/*=====================================================================
Author: Arjit Magar
Date: 2024/11/17
Description: A program that calculates the total number of happy 
prime number between 1 and 1 Million	
Input: No Input
Output: Total number of happy prime number between 1 & 1 Million
Compilation instructions: Should use the command in the terminal
g++ -fopenmp Parallized_cpp code_V2 -o Parallized_code_V2
Usage:
Modifications:
Date Comment:
---- ------------------------------------------------
======================================================================*/#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main() 
{
   double start_time, end_time;
    start_time = omp_get_wtime();
    const int limit = 1000000;
    int happyPrime = 0;

    #pragma omp parallel for reduction(+ : happyPrime) 
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

                while ( num != 1 && itr < 20 ) 
            // itr makes iterations < 20 to avoid the infinite loop
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

    end_time = omp_get_wtime();
    cout << "The execution time is: " << end_time - start_time << endl;

    return 0;
}

