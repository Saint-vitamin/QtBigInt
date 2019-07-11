//#
//# Copyright (C) 2018-2019 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef BIGINT_H
#define BIGINT_H
#include "mini-gmp.h"
#include <string>
#include <vector>
#include "minigmp_global.h"

/**
 * @brief The BigInt class - c++ minigmp wrapper
 */

class MINIGMPSHARED_EXPORT BigInt
{
    mpz_t data;
public:
    BigInt();
    BigInt(const BigInt& val );
    BigInt(long long val );
    BigInt(unsigned long long val );
    BigInt(const char *str, int base = 10);
    BigInt(std::string imput, int base = 10);
    BigInt(int val);
    BigInt(unsigned int val);
    BigInt(double val);

    std::string getString(int base = 10) const;
    ~BigInt();

    BigInt& powm(BigInt& pow, BigInt &mod);
    BigInt& pow(unsigned int pow);

    /**
     * @brief bigPow10
     * @param pow
     * @return number 10 ^ pow
     */
    static BigInt bigPow10(unsigned int pow);

    BigInt& operator = (const BigInt& val);

    friend BigInt operator + ( BigInt left, const BigInt& right);
    friend BigInt operator + ( BigInt left, unsigned int right);
    friend BigInt operator + ( BigInt left, int right);

    friend BigInt& operator += ( BigInt &left, unsigned int right);
    friend BigInt& operator += ( BigInt &left, int right);
    friend BigInt& operator += ( BigInt &left, const BigInt& right);

    friend BigInt operator - ( BigInt left, const BigInt& right);
    friend BigInt operator - ( unsigned int right, BigInt left);
    friend BigInt operator - ( BigInt left, unsigned int right);
    friend BigInt operator - ( BigInt left, int right);
    friend BigInt operator - ( int right, BigInt left);
    friend BigInt operator-(BigInt val);

    friend BigInt& operator -= ( BigInt &left, unsigned int right);
    friend BigInt& operator -= ( BigInt &left, int right);
    friend BigInt& operator -= ( int left, BigInt & right);
    friend BigInt& operator -= ( unsigned int left, BigInt & right);

    friend BigInt& operator -= ( BigInt &left, const BigInt& right);

    friend BigInt operator / ( BigInt left, const BigInt& right);
    friend BigInt operator / ( BigInt left, unsigned int right);
    friend BigInt operator / ( BigInt left, int right);

    friend BigInt& operator /= ( BigInt &left, unsigned int right);
    friend BigInt& operator /= ( BigInt &left, int right);
    friend BigInt& operator /= ( BigInt &left, const BigInt& right);

    friend BigInt operator * ( BigInt left, const BigInt& right);
    friend BigInt operator * ( BigInt left, unsigned int right);
    friend BigInt operator * ( BigInt left, int right);
    friend BigInt& operator *= ( BigInt &left, unsigned int right);
    friend BigInt& operator *= ( BigInt &left, const BigInt& right);
    friend BigInt& operator *= ( BigInt &left, int right);


    friend BigInt operator % ( BigInt left, const BigInt& right);
    friend BigInt operator % ( BigInt left, unsigned int right);
    friend BigInt operator % ( BigInt left, int right);


    friend BigInt& operator %= ( BigInt &left, unsigned int right);
    friend BigInt& operator %= ( BigInt &left, int right);
    friend BigInt& operator %= ( BigInt &left, const BigInt& right);


    friend BigInt operator << ( BigInt left, int right);
    friend BigInt operator >> ( BigInt left, int right);

    friend BigInt& operator <<= ( BigInt &left, int right);
    friend BigInt& operator >>= ( BigInt &left, int right);

    friend BigInt operator << ( BigInt left, unsigned int right);
    friend BigInt operator >> ( BigInt left, unsigned int right);

    friend BigInt& operator <<= ( BigInt &left, unsigned int right);
    friend BigInt& operator >>= ( BigInt &left, unsigned int right);

    friend bool operator == ( const BigInt& left, const BigInt& right);
    friend bool operator == ( const BigInt& left, unsigned int right);
    friend bool operator == ( const BigInt& left, int right);

    friend bool operator != ( const BigInt& left, const BigInt& right);
    friend bool operator != ( const BigInt& left, unsigned int right);
    friend bool operator != ( const BigInt& left, int right);


    friend bool operator < ( const BigInt& left, const BigInt& right);
    friend bool operator < ( const BigInt& left, unsigned int right);
    friend bool operator < ( const BigInt& left, int right);

    friend bool operator > ( const BigInt& left, const BigInt& right);
    friend bool operator > ( const BigInt& left, unsigned int right);
    friend bool operator > ( const BigInt& left, int right);


    friend bool operator <= ( const BigInt& left, const BigInt& right);
    friend bool operator <= ( const BigInt& left, unsigned int right);
    friend bool operator <= ( const BigInt& left, int right);

    friend bool operator >= ( const BigInt& left, const BigInt& right);
    friend bool operator >= ( const BigInt& left, unsigned int right);
    friend bool operator >= ( const BigInt& left, int right);

    friend bool operator!(const BigInt& val);

    BigInt& operator-- ();
    BigInt& operator++ ();

    BigInt operator-- (int);
    BigInt operator++ (int);


    friend BigInt operator~ (BigInt val);

    friend BigInt operator| (BigInt left, const BigInt& right);
    friend BigInt operator| (const BigInt &left, int right);
    friend BigInt operator| (const BigInt &left, unsigned int right);

    friend BigInt& operator|= (BigInt &left, const BigInt& right);
    friend BigInt& operator|= (BigInt &left, int right);
    friend BigInt& operator|= (BigInt &left, unsigned int right);

    friend BigInt operator& (BigInt left, const BigInt& right);
    friend BigInt operator& (const BigInt &left, int right);
    friend BigInt operator& (const BigInt &left, unsigned int right);

    friend BigInt& operator&= (BigInt &left, const BigInt& right);
    friend BigInt& operator&= (BigInt &left, int right);
    friend BigInt& operator&= (BigInt &left, unsigned int right);

    friend BigInt operator^ (BigInt left, const BigInt& right);
    friend BigInt operator^ (const BigInt &left, int right);
    friend BigInt operator^ (const BigInt &left, unsigned int right);

    friend BigInt& operator^= (BigInt &left, const BigInt& right);
    friend BigInt& operator^= (BigInt &left, int right);
    friend BigInt& operator^= (BigInt &left, unsigned int right);

};

#endif // BIGINT_H
