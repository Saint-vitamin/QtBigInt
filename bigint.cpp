//#
//# Copyright (C) 2018-2019 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "bigint.h"

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

BigInt::BigInt(int val):
    BigInt() {
    mpz_set_si(data, val);
}

BigInt::BigInt(unsigned int val):
    BigInt() {
    mpz_set_ui(data, val);
}

BigInt::BigInt(double val):
    BigInt() {
    mpz_set_d(data, val);
}

std::string BigInt::getString(int base) const {
    char *str = nullptr;
    mpz_get_str(str, base, data);

    return str;
}

BigInt::~BigInt() {
    mpz_clear(data);
}

//  add operators
BigInt operator +(BigInt left, unsigned int right) {
    mpz_add_ui(left.data, left.data, right);
    return left;
}

BigInt operator +(BigInt left, int right) {
    if (right > 0) {
        return left + static_cast<unsigned int>(right);
    }

    return left - right;
}

BigInt operator +(BigInt left, const BigInt &right) {
    mpz_add(left.data, left.data, right.data);
    return left;
}

BigInt& operator +=(BigInt &left, unsigned int right) {
    mpz_add_ui(left.data, left.data, right);
    return left;
}

BigInt& operator +=(BigInt &left, int right) {
    if (right > 0) {
        return left += static_cast<unsigned int>(right);
    }
    return left -= right;
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

BigInt operator -(BigInt left, unsigned int right) {
    mpz_sub_ui(left.data, left.data, right);
    return left;
}

BigInt operator -(unsigned int left, BigInt right) {
    mpz_ui_sub(right.data, left, right.data);
    return right;
}

BigInt operator -(BigInt left, int right) {
    if (right > 0) {
        return left - static_cast<unsigned int>(right);
    }
    return left + right;
}

BigInt operator -(int left, BigInt right) {
    if (right > 0) {
        return static_cast<unsigned int>(left) - right;
    }
    return right + left;
}

BigInt& operator -=(BigInt &left, const BigInt &right) {
    mpz_sub(left.data, left.data, right.data);
    return left;
}

BigInt& operator -=(BigInt &left, unsigned int right) {
    mpz_sub_ui(left.data, left.data, right);
    return left;
}

BigInt& operator -=(BigInt &left, int right) {
    if (right > 0) {
        return left -= static_cast<unsigned int>(right);
    }
    return left += right;
}

BigInt& operator -=(int left, BigInt & right) {
    if (left > 0) {
        return static_cast<unsigned int>(left) -= right;
    }

    return right =  right + left;
}

BigInt& operator -=(unsigned int left, BigInt & right) {
    return right = left - right;
}

//  div operators

BigInt operator /(BigInt left, const BigInt &right) {
    mpz_fdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt operator /(BigInt left, unsigned int right) {
    mpz_fdiv_r_ui(left.data, left.data, right);
    return left;
}

BigInt operator /(BigInt left, int right) {
    if (right > 0) {
        return left / static_cast<unsigned int>(right);
    }
    return 0 - (left / static_cast<unsigned int>(right));
}

BigInt& operator /=(BigInt &left, const BigInt &right) {
    mpz_fdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt& operator /=(BigInt &left, unsigned int right) {
    mpz_fdiv_r_ui(left.data, left.data, right);
    return left;
}

BigInt& operator /=(BigInt &left, int right) {
    if (right > 0) {
        return left /= static_cast<unsigned int>(right);
    }
    return 0 -= (left /= static_cast<unsigned int>(right));
}

// mul operators



BigInt operator *(BigInt left, const BigInt &right) {
    mpz_mul(left.data, left.data, right.data);
    return left;
}

BigInt operator *(BigInt left, int right) {
    if (right > 0) {
        return left * static_cast<unsigned int>(right);
    }
    return 0 - (left * static_cast<unsigned int>(right));
}

BigInt operator *(BigInt left, unsigned int right) {
    mpz_mul_ui(left.data, left.data, right);
    return left;
}

BigInt& operator *=(BigInt &left, const BigInt &right) {
    mpz_mul(left.data, left.data, right.data);
    return left;
}

BigInt& operator *=(BigInt &left, int right) {
    if (right > 0) {
        return left *= static_cast<unsigned int>(right);
    }
    return 0 -= (left *= static_cast<unsigned int>(right));
}

BigInt& operator *=(BigInt &left, unsigned int right) {
    mpz_mul_ui(left.data, left.data, right);
    return left;
}

//mod operations
BigInt operator %(BigInt left, const BigInt &right) {
    mpz_mod(left.data, left.data, right.data);
    return left;
}

BigInt operator %(BigInt left, unsigned int right) {
    mpz_mod_ui(left.data, left.data, right);
    return left;
}

BigInt operator %(BigInt left, int right) {
    if (right > 0) {
        return left % static_cast<unsigned int>(right);
    }

    throw " mod with negativ value  not sopported";
}

BigInt& operator %=(BigInt& left, const BigInt &right) {
    mpz_mod(left.data, left.data, right.data);
    return left;
}

BigInt& operator %=(BigInt& left, unsigned int right) {
    mpz_mod_ui(left.data, left.data, right);
    return left;
}

BigInt& operator %=(BigInt& left, int right) {
    if (right > 0) {
        return left %= static_cast<unsigned int>(right);
    }
    throw " mod with negativ value  not sopported";
}

BigInt &BigInt::operator--() {
    *this -= 1;
    return *this;
}

BigInt &BigInt::operator++() {
    *this += 1;
    return *this;
}

bool operator!(const BigInt &val) {
    return val == 0;
}


bool operator == (const BigInt& left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) == 0;
}

bool operator != (const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) != 0;
}

bool operator < ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) < 0;
}

bool operator > ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) > 0;
}

bool operator <= ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) <= 0;
}

bool operator >= ( const BigInt &left, const BigInt& right) {
    return mpz_cmp(left.data, right.data) >= 0;
}

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
               static_cast<unsigned int>(right));
    return left;
}

BigInt& operator >>=(BigInt &left, unsigned int right) {
    mpn_rshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               static_cast<unsigned int>(right));
    return left;
}

BigInt& operator <<=(BigInt &left, unsigned int right) {
    mpn_lshift(left.data->_mp_d,
               left.data->_mp_d,
               left.data->_mp_size,
               static_cast<unsigned int>(right));
    return left;
}


BigInt operator >>(BigInt left, int right) {
    if (right > 0) {
        return left >> static_cast<unsigned int> (right);
    }

    return left << right;
}

BigInt operator <<(BigInt left, int right) {
    if (right > 0) {
        return left << static_cast<unsigned int> (right);
    }

    return left >> right;
}

BigInt& operator >>=(BigInt &left, int right) {
    if (right > 0) {
        return left >>= static_cast<unsigned int>(right);
    }

    return left <<= right;
}

BigInt& operator <<=(BigInt &left, int right) {
    if (right > 0) {
        return left <<= static_cast<unsigned int>(right);
    }

    return left >>= right;
}
