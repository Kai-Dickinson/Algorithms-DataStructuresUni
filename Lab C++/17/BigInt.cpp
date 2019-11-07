#include "BigInt.hpp"

BigInt::BigInt(size_t _ndigits) {
    ndigits = _ndigits;
    data = new unsigned char[ndigits];
}

BigInt::BigInt(std::string s) :BigInt(s.length()){
    
    for (int i = 0; i < ndigits; ++i) {
        data[i] = s[ndigits - i - 1] - '0';
    }
    
}

BigInt::~BigInt() {
}

unsigned char BigInt::get(size_t i) {
    if (i >= ndigits) {
        return 0;
    } else {
        return data[i];
    }
}

BigInt *BigInt::Add(BigInt *y) {
    char carry = 0;
    BigInt* result = new BigInt(0);
    
    if (y->ndigits > ndigits) {
        result->data = new unsigned char[y->ndigits + 1];
        result->ndigits = y->ndigits + 1;
    } else {
        result->data = new unsigned char[ndigits + 1];
        result->ndigits = ndigits + 1;
    }
    
    for (int i = 0; i < result->ndigits; ++i) {
        char temp = y->data[i] + data[i] + carry;
        if (temp < 10) {
            result->data[i] = temp;
            carry = 0;
        } else {
            result->data[i] = temp - 10;
            carry = 1;
        }
    }
    
  return result;
}

BigInt *BigInt::Sub(BigInt *y) {
    BigInt *end = new BigInt(ndigits);
    char borrow = 0;
    
    for (int i = 0; i < ndigits; ++i) {
        char temp = data[i] - y->data[i] - borrow;
        if (temp >= 0) {
            end->data[i] = temp;
            borrow = 0;
        } else {
            end->data[i] = temp + 10;
            borrow = 1;
        }
    }
    
  return end;
}

BigInt *BigInt::Shift(size_t n) {
    BigInt* shifted = new BigInt(ndigits + n);
    
    for (int k = 0; k < n; ++k) {
        shifted->data[k] = 0;
    }
    
    for (int i = n; i < shifted->ndigits; ++i) {
        shifted->data[i] = data[i-n];
    }
  return shifted;
}

BigInt *BigInt::MulByDigit(unsigned char c) {
    char carry = 0;
    BigInt* multied = new BigInt(ndigits + 1);
    
    for (int i = 0; i < multied->ndigits; ++i) {
        char temp = data[i] * c + carry;
        if (temp < 10) {
            multied->data[i] = temp;
            carry = 0;
        } else {
            multied->data[i] = temp % 10;
            carry = temp / 10;
        }
    }
    
  return multied;
}

BigInt *BigInt::Mul(BigInt *y) {
    BigInt* bigMult = new BigInt(ndigits);
    BigInt* temp = new BigInt(ndigits);
    
    for (int i = 0; i < y->ndigits; ++i) {
        temp = MulByDigit(y->data[i]);
        temp = temp->Shift(i);
        bigMult = bigMult->Add(temp);
        
    }
    
  return bigMult;
}

BigInt *BigInt::Div(BigInt *y) {
    BigInt *result = new BigInt(ndigits);


  return result;
}

// 5 / 34

BigInt *BigInt::Rem(BigInt *y) {
  return this;
}
