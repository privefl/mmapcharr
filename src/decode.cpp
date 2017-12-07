/******************************************************************************/

#include <Rcpp.h>

using namespace Rcpp;
using std::size_t;

/******************************************************************************/

// [[Rcpp::export]]
IntegerMatrix decodeMat(const RawMatrix& source, const IntegerVector& code) {
  
  size_t n = source.nrow();
  size_t m = source.ncol();
  size_t i, j;
  
  IntegerMatrix res(n, m);
  
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      res(i, j) = code[source(i, j)];
  
  return res;
}

/******************************************************************************/

// [[Rcpp::export]]
IntegerVector decodeVec(const RawVector& source, const IntegerVector& code) {
  
  size_t n = source.size();
  
  IntegerVector res(n);
  
  for (size_t i = 0; i < n; i++)
    res[i] = code[source[i]];
  
  return res;
}

/******************************************************************************/