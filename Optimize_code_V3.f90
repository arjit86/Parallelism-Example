! /*=====================================================================
! Author: Arjit Magar
! Date: 2024/11/17
! Description: A program that calculates the total number of happy . This is the 3rd version of my code and I have introduced new language (fortran)
! prime number between 1 and 1 Million	
! Input: No Input
! Output: Total number of happy prime number between 1 & 1 Million
! Compilation instructions: Should install fortran on computer 
! and use the command  
!  gfortran -fopenmp Optimize_code_V3.f90 -o Optimize_code_V3
! Usage:
! Modifications: Changed the programming language from C++ to Fortran 
! Date Comment:
! ---- ------------------------------------------------
! ======================================================================*/


program happy_primes
    use omp_lib
    implicit none
    integer:: limit = 1000000
    integer :: i, j, count, happyPrime, num, iterations, digit, sum
    real(8) :: start_time, end_time, execution_time

    happyPrime = 0

    ! Start timing
    start_time = omp_get_wtime()

    ! Parallel region
    !$omp parallel do reduction(+:happyPrime) private(i, j, count, num, iterations, sum, digit)
    do i = 2, limit
        count = 0
        if (mod(i, 2) /= 0) then
            do j = 2, int(sqrt(real(i)))
                if (mod(i, j) == 0) then
                    count = count + 1
                    exit
                end if
            end do

            if (count == 0) then
                num = i
                iterations = 0

                do while (num /= 1 .and. iterations < 100)
                    sum = 0
                    do while (num > 0)
                        digit = mod(num, 10)
                        sum = sum + digit * digit
                        num = num / 10
                    end do
                    num = sum
                    iterations = iterations + 1
                end do

                if (num == 1) then
                    happyPrime = happyPrime + 1
                end if
            end if
        end if
    end do
    !$omp end parallel do

    ! End timing
    end_time = omp_get_wtime()
    execution_time = end_time - start_time

    print *, "Total happy prime numbers up to ", limit, " are: ", happyPrime
    print *, "The execution time is: ", execution_time, " seconds"
end program happy_primes
