/**
 * Title: Efficient Palindrome and Integer Slicing
 * Author: Sohel Ahmed Jony
 * Date: Fri Jul  2 08:42:53 AM +06 202
 * Origin: http://jony-blog.github.io/
 *
**/

#include <stdio.h>
#include <math.h>
int sizeof_int(int *n)
{
    return (int)floor(log10(*n) + 1);
}

int integerSlicer(int *number, int *first_part, int *second_part)
{
    //size of this number.
    int sizeof_number = sizeof_int(number);
    //trimming for odd number :)
    int range = sizeof_number - sizeof_number % 2;
    *first_part = floor(*number / pow(10, sizeof_number - (range / 2)));
    *second_part = *number % (int)pow(10, range / 2);
    return 0;
}

int digit_reverser(int digit, int size_of_digit)
{
    if (size_of_digit <= 1)
        return digit;

    int local_significant_position = floor(pow(10, size_of_digit - 1));
    int data = floor(digit % 10) * local_significant_position;
    return data + digit_reverser(floor(digit / 10), (size_of_digit - 1));
}
int main(int argc, char const *argv[])
{
    int digit = 1233113331;
    int first_part, other_part;
    integerSlicer(&digit, &first_part, &other_part);

    if (first_part == digit_reverser(other_part, sizeof_int(&other_part)))
        printf("It's a palindrome!\n");
    else
        printf("It's not a palindrome!\n");

    return 0;
}
