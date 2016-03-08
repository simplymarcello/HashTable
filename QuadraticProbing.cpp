// Created by Marcello Martins on Monday, October 26, 2015
// Last modified on Monday, October 26, 2015
// QuadraticProbing interal method implentation file

/** @file QuadraticProbing.cpp */

#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "DoubleProbing.h"
#include <iostream>
using namespace std;

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 ) {};

    return n;
}

/**
 * Internal method to return a prime number at most as large as n.
 * Assumes n > 0.
 */
int prevPrime( int n )
{
    if( n % 2 == 0 )
        --n;

    for ( ; !isPrime(n); n -= 2 ) {};

    return n;
}
