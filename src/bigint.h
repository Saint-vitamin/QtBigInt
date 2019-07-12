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
    BigInt(const std::string &imput, int base = 10);
//    BigInt(const char * str, int base = 10);
    BigInt(long val);

    std::string getString(int base = 10) const;
    ~BigInt();

    BigInt& powm(const BigInt &pow, const BigInt &mod);
    BigInt& pow(unsigned long pow);
    int sizeBits() const;
    int sizeBytes() const;

    /**
     * @brief bigPow10
     * @param pow
     * @return number 10 ^ pow
     */
    static BigInt bigPow10(unsigned short pow);

    BigInt& operator = (const BigInt& val);
    BigInt& operator = (const std::string &imput);
    BigInt& operator = (long val);
//    BigInt& operator = (const BigInt& val);

    friend BigInt operator + ( BigInt left, const BigInt& right);
    friend BigInt operator + ( BigInt left, const std::string &right);
    friend BigInt operator + ( BigInt left, long right);

    friend BigInt operator + ( long left, BigInt right);

    friend BigInt& operator += ( BigInt &left, long right);
    friend BigInt& operator += ( BigInt &left, const BigInt& right);
    friend BigInt& operator += ( BigInt &left, const std::string &right);

    friend BigInt operator - ( BigInt left, const BigInt& right);
    friend BigInt operator - ( BigInt left, long right);
    friend BigInt& operator - ( BigInt left, const std::string &right);

    friend BigInt operator - ( long right, BigInt left);

    friend BigInt operator-(BigInt val);

    friend BigInt& operator -= ( BigInt &left, long right);
    friend BigInt& operator -= ( long left, BigInt & right);
    friend BigInt& operator -= ( BigInt &left, const BigInt& right);
    friend BigInt& operator -= ( BigInt &left, const std::string &right);

    friend BigInt operator / ( BigInt left, const BigInt& right);
    friend BigInt operator / ( BigInt left, const std::string &right);
    friend BigInt operator / ( BigInt left, long right);
    friend BigInt operator / ( long left, BigInt right);

    friend BigInt& operator /= ( BigInt &left, long right);
    friend BigInt& operator /= ( BigInt &left, const std::string &right);
    friend BigInt& operator /= ( BigInt &left, const BigInt& right);

    friend BigInt operator * ( BigInt left, const BigInt& right);
    friend BigInt operator * ( BigInt left, const std::string &right);
    friend BigInt operator * ( BigInt left, long right);

    friend BigInt operator * ( long left, BigInt right);

    friend BigInt& operator *= ( BigInt &left, const BigInt& right);
    friend BigInt& operator *= ( BigInt &left, long right);
    friend BigInt& operator *= ( BigInt &left, const std::string &right);

    friend BigInt operator % ( BigInt left, const BigInt& right);
    friend BigInt operator % ( BigInt left, const std::string &right);
    friend BigInt operator % ( BigInt left, long right);

    friend BigInt operator % ( long left, BigInt right);

    friend BigInt& operator %= ( BigInt &left, long right);
    friend BigInt& operator %= ( BigInt &left, const std::string &right);

    friend BigInt& operator %= ( BigInt &left, const BigInt& right);

    friend BigInt operator << ( BigInt left, int right);
    friend BigInt operator >> ( BigInt left, int right);

    friend BigInt& operator <<= ( BigInt &left, int right);
    friend BigInt& operator >>= ( BigInt &left, int right);

    friend bool operator == ( const BigInt& left, const BigInt& right);
    friend bool operator == ( const BigInt& left, long right);
    friend bool operator == ( const BigInt& left, const std::string& right);
    friend bool operator == ( const std::string&  left, const BigInt&  right);


    friend bool operator != ( const BigInt& left, const BigInt& right);
    friend bool operator != ( const BigInt& left, long right);
    friend bool operator != ( const BigInt& left, const std::string& str);
    friend bool operator != ( const std::string&  left, const BigInt&  right);

    friend bool operator < ( const BigInt& left, const BigInt& right);
    friend bool operator < ( const BigInt& left, long right);
    friend bool operator < ( const BigInt& left, const std::string& str);
    friend bool operator < ( const std::string&  left, const BigInt&  right);

    friend bool operator > ( const BigInt& left, const BigInt& right);
    friend bool operator > ( const BigInt& left, long right);
    friend bool operator > ( const BigInt& left, const std::string& str);
    friend bool operator > ( const std::string&  left, const BigInt&  right);

    friend bool operator <= ( const BigInt& left, const BigInt& right);
    friend bool operator <= ( const BigInt& left, long right);
    friend bool operator <= ( const BigInt& left, const std::string& str);
    friend bool operator <= ( const std::string&  left, const BigInt&  right);

    friend bool operator >= ( const BigInt& left, const BigInt& right);
    friend bool operator >= ( const BigInt& left, long right);
    friend bool operator >= ( const BigInt& left, const std::string& str);
    friend bool operator >= ( const std::string&  left, const BigInt&  right);

    friend bool operator!(const BigInt& val);

    BigInt& operator-- ();
    BigInt& operator++ ();

    BigInt operator-- (int);
    BigInt operator++ (int);


    friend BigInt operator~ (BigInt val);

    friend BigInt operator| (BigInt left, const BigInt& right);
    friend BigInt operator| (const BigInt &left, long right);

    friend BigInt& operator|= (BigInt &left, const BigInt& right);
    friend BigInt& operator|= (BigInt &left, long right);

    friend BigInt operator& (BigInt left, const BigInt& right);
    friend BigInt operator& (const BigInt &left, long right);

    friend BigInt& operator&= (BigInt &left, const BigInt& right);
    friend BigInt& operator&= (BigInt &left, long right);

    friend BigInt operator^ (BigInt left, const BigInt& right);
    friend BigInt operator^ (const BigInt &left, long right);

    friend BigInt& operator^= (BigInt &left, const BigInt& right);
    friend BigInt& operator^= (BigInt &left, long right);

};

#endif // BIGINT_H
