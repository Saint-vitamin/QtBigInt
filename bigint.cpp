#include "bigint.h"

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

BigInt operator +(BigInt left, unsigned int right) {
    mpz_add_ui(left.data, left.data, right);
    return left;
}

BigInt operator +(BigInt left, const BigInt &right) {
    mpz_add(left.data, left.data, right.data);
    return left;
}

BigInt& operator +=(BigInt &left, unsigned int right) {
    mpz_add_ui(left.data, left.data, right);
    return left;
}

BigInt& operator +=(BigInt &left, const BigInt &right) {
    mpz_add(left.data, left.data, right.data);
    return left;
}

BigInt operator *(BigInt left, const BigInt &right) {
    mpz_mul(left.data, left.data, right.data);
    return left;
}

BigInt operator *(BigInt left, int right) {
    mpz_mul_si(left.data, left.data, right);
    return left;
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
    mpz_mul_si(left.data, left.data, right);
    return left;
}

BigInt& operator *=(BigInt &left, unsigned int right) {
    mpz_mul_ui(left.data, left.data, right);
    return left;
}

BigInt operator /(BigInt left, const BigInt &right) {
    mpz_fdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt operator /(BigInt left, unsigned int right) {
    mpz_fdiv_r_ui(left.data, left.data, right);
    return left;
}

BigInt& operator /=(BigInt &left, const BigInt &right) {
    mpz_fdiv_r(left.data, left.data, right.data);
    return left;
}

BigInt& operator /=(BigInt &left, unsigned int right) {
    mpz_fdiv_r_ui(left.data, left.data, right);
    return left;
}

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

BigInt& operator -=(BigInt &left, const BigInt &right) {
    mpz_sub(left.data, left.data, right.data);
    return left;
}

BigInt& operator -=(BigInt &left, unsigned int right) {
    mpz_sub_ui(left.data, left.data, right);
    return left;
}

BigInt operator %(BigInt left, const BigInt &right) {
    mpz_mod(left.data, left.data, right.data);
    return left;
}

BigInt operator %(BigInt left, unsigned int right) {
    mpz_mod_ui(left.data, left.data, right);
    return left;
}

BigInt& operator %=(BigInt& left, const BigInt &right) {
    mpz_mod(left.data, left.data, right.data);
    return left;
}

BigInt& operator %=(BigInt& left, unsigned int right) {
    mpz_mod_ui(left.data, left.data, right);
    return left;
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
