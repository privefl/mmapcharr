#ifndef CHAR_SEP_ACC_H
#define CHAR_SEP_ACC_H

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/noncopyable.hpp>
#include <Rcpp.h>

using namespace boost::interprocess;
using namespace Rcpp;
using std::size_t;

class charSep : private boost::noncopyable {
public:
  charSep(const std::string path, int n, int m, int r);
  
  const unsigned char* matrix() const { return file_data; }
  size_t nrow() const { return n; }
  size_t ncol() const { return m; }
  size_t nextra() const { return r; }
  
private:
  boost::interprocess::file_mapping file;
  boost::interprocess::mapped_region file_region;
  const unsigned char* file_data;
  size_t n;
  size_t m;
  size_t r;
};


template <typename T, int RTYPE>
class charSepAcc {
public:
  charSepAcc(const charSep * charSepPtr, Vector<RTYPE> code) {
    
    _pMat = charSepPtr->matrix();
    n = charSepPtr->nrow();
    m = charSepPtr->ncol();
    l = (2 * m - 1) + charSepPtr->nextra();
    _code = code;
  };
  
  size_t nrow() const { return n; }
  size_t ncol() const { return m; }
  
  inline T operator() (size_t i, size_t j) {
    return _code[_pMat[i * l + 2 * j]];
  }
  
private:
  const unsigned char* _pMat;
  size_t n;
  size_t m;
  size_t l;
  Vector<RTYPE> _code;
};


template <typename T, int RTYPE>
class charSepAccTranspose : public charSepAcc<T, RTYPE> {
public:
  charSepAccTranspose(const charSep * charSepPtr, Vector<RTYPE> code) 
    : charSepAcc<T, RTYPE>(charSepPtr, code) {}
  
  size_t nrow() const { return charSepAcc<T, RTYPE>::ncol(); }
  size_t ncol() const { return charSepAcc<T, RTYPE>::nrow(); }
  
  inline const unsigned char operator() (size_t i, size_t j) {
    return charSepAcc<T, RTYPE>::operator()(j, i);
  }
};

#endif // CHAR_SEP_ACC_H