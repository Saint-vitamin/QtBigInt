//#
//# Copyright (C) 2018-2019 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "bigint.h"
#include <limits>

// constructors
BigInt::BigInt() {
    mpz_init(data);
}

BigInt::BigInt(const BigInt &val):
    BigInt() {
    mpz_set(data, val.data);
}

BigInt::BigInt(const char *str, int base):
    BigInt() {

    mpz_set_str(data, str, base);
}

BigInt::BigInt(std::string imput, int base):
    BigInt(imput.c_str(), base) {
}

BigInt::BigInt(long val):
    BigInt() {
    mpz_set_si(data, val);
}

BigInt::BigInt(unsigned long val):
    BigInt() {
    mpz_set_ui(data, val);
}

BigInt::BigInt(double val):
    BigInt() {
    mpz_set_d(data, val);
}

std::string BigInt::getString(int base) const {
    char *str = mpz_get_str(nullptr, base, data);
    return str;
}

BigInt::~BigInt() {
    mpz_clear(data);
}

BigInt &BigInt::powm(const BigInt &pow, const BigInt &mod) {
    mpz_powm(data, data, pow.data, mod.data);
    return *this;
}

BigInt &BigInt::pow(unsigned long pow) {
    mpz_pow_ui(data, data, pow);
    return *this;
}

int BigInt::sizeBits() const {
    return sizeBytes() * 8;
}

int BigInt::sizeBytes() const {
    return static_cast<int>(mpz_size(data) * sizeof ((*data->_mp_d)));
}

BigInt BigInt::bigPow10(unsigned short pow) {
    return "1" + std::string(pow, '0');
}


BigInt &BigInt::operator =(const BigInt &val) {
    mpz_set(data, val.data);
    return *this;
}

//  add operators


BigInt operator +(BigInt left, long right) {
    if (right >= 0) {
        mpz_add_ui(left.data, left.data, static_cast<unsigned long>(right));
        return left;
    }

    return left -= std::abs(right);
}

BigInt operator +(BigInt left, const BigInt &right) {
    mpz_add(left.data, left.data, right.data);
    return left;
}

BigInt& operator +=(BigInt &left, long right) {
    if (right >= 0) {
        mpz_add_ui(left.data, left.data, static_cast<unsigned long>(right));
        return left;
    }
    return left -= std::abs(right);
}

BigInt& operator +=(BigInt &left, const BigInt &right) {
    mpz_add(left.data, left.data, right.data);
    return left;
}

//  sub operators

BigInt operator -(BigInt left, const BigInt &right) {
    mpz_sub(left.data, left.data, right.data);
    return left;
}

BigInt operator -(BigInt left, long right) {
    if (right >= 0) {
        mpz_sub_ui(left.data, left.data, static_cast<unsigned long>(right));
        return left;
    }
    return left += std::abs(right);
}

BigInt operator -(long left, BigInt right) {
    if (left >= 0) {
        mpz_ui_sub(right.data, static_cast<unsigned long>(left), right.data);
        return right;
    }
    return right += std::abs(left);
}

BigInt operator-(BigInt val) {
    mpz_neg(val.data, val.data);
    return val;
}

BigInt& operator -=(BigInt &left, const BigInt &right) {
    mpz_sub(left.data, left.data, right.data);
    return left;
}

BigInt& operator -=(BigInt &left, long right) {
    if (right >= 0) {
        mpz_sub_ui(left.data, left.data, static_cast<unsigned long>(right));
        return left;
    }
    return left += std::abs(right);
}

BigInt& operator -=(long left, BigInt & right) {
    if (left >= 0) {
        mpz_ui_sub(right.data, static_cast<unsigned long>(left), right.data);
        return right;
    }

    return right += std::abs(left);
}

//  div operators

BigInt operator /(BigInt left, const BigInt &right) {
    mpz_tdiv_q(left.data, left.data, right.data);
    return left;
}

BigInt operator /(BigInt left, long right) {
    mpz_tdiv_q_ui(left.data, left.data, static_cast<unsigned long>(std::abs(right)));

    if (right >= 0) {
        return left;
    }
    return -left;
}

BigInt& operator /=(BigInt &left, const BigInt &right) {
    mpz_tdiv_q(left.data, left.data, right.data);
    return left;
}


BigInt& operator /=(BigInt &left, long right) {
    mpz_tdiv_q_ui(left.data, left.data, static_cast<unsigned long>(std::abs(right)));

    if (right >= 0) {
        return left;
    }
    return 0 -= left ;
}

// mul operators
// TO-DO
BigInt operator *(BigInt left, const BigInt &right) {
    mpz_mul(left.data, left.data, right.data);
    return left;
}

BigInt operator *(BigInt left, long right) {
    if (right >= 0) {
        return left * static_cast<unsigned long>(right);
    }
    return 0 - (left * static_cast<unsigned long>(std::abs(right)));
}

BigInt operator *(BigInt left, unsigned long right) {
    mpz_mul_ui(left.data, left.data, right);
    return left;
}

BigInt& operator *=(BigInt &left, const BigInt &right) {
    mpz_mul(left.data, left.data, right.data);
    return left;
}

BigInt& operator *=(BigInt &left, long right) {
    if (right >= 0) {
        return left *= static_cast<unsigned long>(right);
    }
    return 0 -= (left *= static_cast<unsigned long>(std::abs(right)));
}

BigInt& operator *=(BigInt &left, unsigned long right) {
    mpz_mul_ui(left.data, left.data, right);
    return left;
}

//mod operations
BigInt operator %(BigInt left, const BigInt &right) {
    mpz_tdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt operator %(BigInt left, unsigned long right) {
    mpz_tdiv_r_ui(left.data, left.data, right);
    return left;
}

BigInt operator %(BigInt left, long right) {
    return left % static_cast<unsigned long>(std::abs(right));
}

BigInt& operator %=(BigInt& left, const BigInt &right) {
    mpz_tdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt& operator %=(BigInt& left, unsigned long right) {
    mpz_tdiv_r_ui(left.data, left.data, right);
    return left;
}

BigInt& operator %=(BigInt& left, long right) {
    return left %= static_cast<unsigned long>(std::abs(right));
}


// incriment and dicriment
BigInt &BigInt::operator--() {
    *this -= 1;
    return *this;
}

BigInt &BigInt::operator++() {
    *this += 1;
    return *this;
}

BigInt BigInt::operator--(int) {
    BigInt temp(*this);
    --*this;
    return temp;
}

BigInt BigInt::operator++(int) {
    BigInt temp(*this);
    ++*this;
    return temp;
}

// move operators

BigInt operator >>(BigInt left, unsigned int right) {
    mpn_rshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               right);
    return left;
}

BigInt operator <<(BigInt left, unsigned int right) {
    mpn_lshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               right);
    return left;
}

BigInt& operator >>=(BigInt &left, unsigned int right) {
    mpn_rshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               right);
    return left;
}

BigInt& operator <<=(BigInt &left, unsigned int right) {
    mpn_lshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               right);
    return left;
}


BigInt operator >>(BigInt left, int right) {
    if (right >= 0) {
        return left >> static_cast<unsigned int> (right);
    }

    return left << static_cast<unsigned int>(std::abs(right));
}

BigInt operator <<(BigInt left, int right) {
    if (right >= 0) {
        return left << static_cast<unsigned int> (right);
    }

    return left >> static_cast<unsigned int>(std::abs(right));
}

BigInt& operator >>=(BigInt &left, int right) {
    if (right >= 0) {
        return left >>= static_cast<unsigned int>(right);
    }

    return left <<= static_cast<unsigned int>(std::abs(right));
}

BigInt& operator <<=(BigInt &left, int right) {
    if (right >= 0) {
        return left <<= static_cast<unsigned int>(right);
    }

    return left >>= static_cast<unsigned int>(std::abs(right));
}

// other bin operators
BigInt operator ~(BigInt left) {
    mpz_com(left.data, left.data);
    return left;
}

BigInt operator |(BigInt left, const BigInt &right) {
    mpz_ior(left.data, left.data, right.data);
    return left;
}

BigInt operator |(const BigInt &left, long right) {
    return left | BigInt(right);
}

BigInt operator |(const BigInt &left, unsigned long right) {
    return left | BigInt(right);
}

BigInt& operator |=(BigInt &left, const BigInt &right) {
    mpz_ior(left.data, left.data, right.data);
    return left;
}

BigInt& operator |=(BigInt &left, long right) {
    return left |= BigInt(right);
}

BigInt& operator |=(BigInt &left, unsigned long right) {
    return left |= BigInt(right);
}

BigInt operator &(BigInt left, const BigInt &right) {
    mpz_and(left.data, left.data, right.data);
    return left;
}

BigInt operator &(const BigInt &left, long right) {
    return left & BigInt(right);
}

BigInt operator &(const BigInt &left, unsigned long right) {
    return left & BigInt(right);
}

BigInt& operator &=(BigInt &left, const BigInt &right) {
    mpz_and(left.data, left.data, right.data);
    return left;
}

BigInt& operator &=(BigInt &left, long right) {
    return left &= BigInt(right);
}

BigInt& operator &=(BigInt &left, unsigned long right) {
    return left &= BigInt(right);
}

BigInt operator ^(BigInt left, const BigInt &right) {
    mpz_xor(left.data, left.data, right.data);
    return left;
}

BigInt operator ^(const BigInt &left, long right) {
    return left ^ BigInt(right);
}

BigInt operator ^(const BigInt &left, unsigned long right) {
    return left ^ BigInt(right);
}

BigInt& operator ^=(BigInt &left, const BigInt &right) {
    mpz_xor(left.data, left.data, right.data);
    return left;
}

BigInt& operator ^=(BigInt &left, long right) {
    return left ^= BigInt(right);
}

BigInt& operator ^=(BigInt &left, unsigned long right) {
    return left ^= BigInt(right);
}


// logic operators

bool operator!(const BigInt &val) {
    return val == 0;
}

bool operator == (const BigInt& left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) == 0;
}

bool operator == (const BigInt& left, unsigned long right) {
    return mpz_cmp_ui(left.data, right) == 0;
}

bool operator == (const BigInt& left, long right) {
    return mpz_cmp_si(left.data, right) == 0;
}

bool operator != (const BigInt &left, const BigInt& right) {
    return !(left == right);
}

bool operator != (const BigInt &left, unsigned long right) {
    return !(left == right);
}

bool operator != (const BigInt &left, long right) {
    return !(left == right);
}

bool operator < ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) < 0;
}

bool operator < ( const BigInt &left, unsigned long right) {
    return mpz_cmp_ui(left.data, right) < 0;
}

bool operator < ( const BigInt &left, long right) {
    return mpz_cmp_si(left.data, right) < 0;
}

bool operator > ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) > 0;
}

bool operator > ( const BigInt &left, unsigned long right) {
    return mpz_cmp_ui(left.data, right) > 0;
}

bool operator > ( const BigInt &left, long right) {
    return mpz_cmp_si(left.data, right) > 0;
}


bool operator <= ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) <= 0;
}

bool operator <= ( const BigInt &left, unsigned long right) {
    return mpz_cmp_ui(left.data, right) <= 0;
}

bool operator <= ( const BigInt &left, long right) {
    return mpz_cmp_si(left.data, right) <= 0;
}

bool operator >= ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) >= 0;
}

bool operator >= ( const BigInt &left, unsigned long right) {
    return mpz_cmp_ui(left.data, right) >= 0;
}

bool operator >= ( const BigInt &left, long right) {
    return mpz_cmp_si(left.data, right) >= 0;
}

//// cast operations

//BigInt::operator bool() const {
//    return *this != 0;
//}
