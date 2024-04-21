// NumericOverflows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>     // std::cout
#include <limits>       // std::numeric_limits

/// <summary>
/// Template function to abstract away the logic of adding an increment to a start value for a specified number of steps,
/// with overflow detection. If overflow is detected at any step, the operation is halted, and the function returns false,
/// indicating the occurrence of an overflow. Otherwise, the addition continues, and the function returns true,
/// signaling successful addition without overflow.
/// </summary>
/// <typeparam name="T">A numeric type that supports basic arithmetic operations and comparison</typeparam>
/// <param name="start">The initial value to start with</param>
/// <param name="increment">The amount to add at each step</param>
/// <param name="steps">The number of times the increment is added to the start value</param>
/// <param name="result">Reference to store the result of the addition</param>
/// <returns>Boolean indicating whether the addition was successful without overflow</returns>

// Modified to include overflow detection and prevention
template <typename T>
bool add_numbers(T const& start, T const& increment, unsigned long int const& steps, T& result)
{
    result = start;
    for (unsigned long int i = 0; i < steps; ++i)
    {
        // Check for overflow before adding
        if ((increment > 0 && result > std::numeric_limits<T>::max() - increment) ||
            (increment < 0 && result < std::numeric_limits<T>::min() - increment))
        {
            return false; // Signal that overflow would occur
        }
        result += increment;
    }
    return true; // Successful addition without overflow
}

/// <summary>
/// Template function to abstract away the logic of subtracting a decrement from a start value a given number of steps,
/// with underflow detection. If underflow is detected, the operation is halted, and the function returns false.
/// Otherwise, the subtraction continues, and the function returns true, indicating successful subtraction without underflow.
/// </summary>
/// <typeparam name="T">A numeric type that supports basic math operations and comparison</typeparam>
/// <param name="start">The initial value to start with</param>
/// <param name="decrement">The amount to subtract in each step</param>
/// <param name="steps">The number of times the decrement is subtracted from the start value</param>
/// <param name="result">Reference to store the result of the subtraction</param>
/// <returns>Boolean indicating whether the subtraction was successful without underflow</returns>

// Modified to include underflow detection and prevention
template <typename T>
bool subtract_numbers(T const& start, T const& decrement, unsigned long int const& steps, T& result)
{
    result = start;
    for (unsigned long int i = 0; i < steps; ++i)
    {
        // Check for underflow before subtracting
        if ((decrement > 0 && result < std::numeric_limits<T>::min() + decrement) ||
            (decrement < 0 && result > std::numeric_limits<T>::max() + decrement))
        {
            return false; // Signal that underflow would occur
        }
        result -= decrement;
    }
    return true; // Successful subtraction without underflow
}


//  NOTE:
//    You will see the unary ('+') operator used in front of the variables in the test_XXX methods.
//    This forces the output to be a number for cases where cout would assume it is a character. 

template <typename T>
void test_overflow()
{
    // TODO: The add_numbers template function will overflow in the second method call
    //        You need to change the add_numbers method to:
    //        1. Detect when an overflow will happen
    //        2. Prevent it from happening
    //        3. Return the correct value when no overflow happened or
    //        4. Return something to tell test_overflow the addition failed
    //        NOTE: The add_numbers method must remain a template in the NumericFunctions header.
    //
    //        You need to change the test_overflow method to:
    //        1. Detect when an add_numbers failed
    //        2. Inform the user the overflow happened
    //        3. A successful result displays the same result as before you changed the method
    //        NOTE: You cannot change anything between START / END DO NOT CHANGE
    //              The test_overflow method must remain a template in the NumericOverflows source file
    //
    //  There are more than one possible solution to this problem. 
    //  The solution must work for all of the data types used to call test_overflow() in main().

    // START DO NOT CHANGE
    //  how many times will we iterate
    const unsigned long int steps = 5;
    // how much will we add each step (result should be: start + (increment * steps))
    const T increment = std::numeric_limits<T>::max() / steps;
    // whats our starting point
    const T start = 0;

    std::cout << "Overflow Test of Type = " << typeid(T).name() << std::endl;
    // END DO NOT CHANGE

    T result;
    if (add_numbers<T>(start, increment, steps, result)) {
        std::cout << "\tAdding Numbers Without Overflow: " << +result << std::endl;
    }
    else {
        std::cout << "\tOverflow detected!" << std::endl;
    }

    if (add_numbers<T>(start, increment, steps + 1, result)) {
        std::cout << "\tAdding Numbers With Overflow: " << +result << std::endl;
    }
    else {
        std::cout << "\tOverflow detected!" << std::endl;
    }
}

template <typename T>
void test_underflow()
{
    // TODO: The subtract_numbers template function will underflow in the second method call
    //        You need to change the subtract_numbers method to:
    //        1. Detect when an underflow will happen
    //        2. Prevent it from happening
    //        3. Return the correct value when no underflow happened or
    //        4. Return something to tell test_underflow the subtraction failed
    //        NOTE: The subtract_numbers method must remain a template in the NumericFunctions header.
    //
    //        You need to change the test_underflow method to:
    //        1. Detect when an subtract_numbers failed
    //        2. Inform the user the underflow happened
    //        3. A successful result displays the same result as before you changed the method
    //        NOTE: You cannot change anything between START / END DO NOT CHANGE
    //              The test_underflow method must remain a template in the NumericOverflows source file
    //
    //  There are more than one possible solution to this problem. 
    //  The solution must work for all of the data types used to call test_overflow() in main().

    // START DO NOT CHANGE
    //  how many times will we iterate
    const unsigned long int steps = 5;
    // how much will we subtract each step (result should be: start - (increment * steps))
    const T decrement = std::numeric_limits<T>::max() / steps;
    // whats our starting point
    const T start = std::numeric_limits<T>::max();

    std::cout << "Underflow Test of Type = " << typeid(T).name() << std::endl;
    // END DO NOT CHANGE

    T result;
    if (subtract_numbers<T>(start, decrement, steps, result)) {
        std::cout << "\tSubtracting Numbers Without Underflow: " << +result << std::endl;
    }
    else {
        std::cout << "\tUnderflow detected!" << std::endl;
    }

    if (subtract_numbers<T>(start, decrement, steps + 1, result)) {
        std::cout << "\tSubtracting Numbers With Underflow: " << +result << std::endl;
    }
    else {
        std::cout << "\tUnderflow detected!" << std::endl;
    }
}

void do_overflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Overflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/
    // signed integers
    test_overflow<char>();
    test_overflow<wchar_t>();
    test_overflow<short int>();
    test_overflow<int>();
    test_overflow<long>();
    test_overflow<long long>();

    // unsigned integers
    test_overflow<unsigned char>();
    test_overflow<unsigned short int>();
    test_overflow<unsigned int>();
    test_overflow<unsigned long>();
    test_overflow<unsigned long long>();

    // real numbers
    test_overflow<float>();
    test_overflow<double>();
    test_overflow<long double>();
}

void do_underflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Undeflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/
    // signed integers
    test_underflow<char>();
    test_underflow<wchar_t>();
    test_underflow<short int>();
    test_underflow<int>();
    test_underflow<long>();
    test_underflow<long long>();

    // unsigned integers
    test_underflow<unsigned char>();
    test_underflow<unsigned short int>();
    test_underflow<unsigned int>();
    test_underflow<unsigned long>();
    test_underflow<unsigned long long>();

    // real numbers
    test_underflow<float>();
    test_underflow<double>();
    test_underflow<long double>();
}

/// <summary>
/// Entry point into the application
/// </summary>
/// <returns>0 when complete</returns>
int main()
{
    //  create a string of "*" to use in the console
    const std::string star_line = std::string(50, '*');

    std::cout << "Starting Numeric Underflow / Overflow Tests!" << std::endl;

    // run the overflow tests
    do_overflow_tests(star_line);

    // run the underflow tests
    do_underflow_tests(star_line);

    std::cout << std::endl << "All Numeric Underflow / Overflow Tests Complete!" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debuggin