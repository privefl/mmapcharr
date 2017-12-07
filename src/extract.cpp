/******************************************************************************/

#include <mmapcharr/charsep-acc.h>

using namespace Rcpp;
using std::size_t;

/******************************************************************************/

// [[Rcpp::export]]
RawVector extractVec(RObject obj, 
                     const IntegerMatrix& elemInd) {
  
  XPtr<charSep> xpMat(obj);
  charSepAcc macc(xpMat);
  
  size_t K = elemInd.nrow();
  RawVector res(K);
  
  for (size_t k = 0; k < K; k++)
    res[k] = macc(elemInd(k, 0) - 1, elemInd(k, 1) - 1);
  
  return res;
}

/******************************************************************************/

// [[Rcpp::export]]
RawMatrix extractMat(RObject obj,
                     const IntegerVector& rowInd,
                     const IntegerVector& colInd) {
  
  XPtr<charSep> xpMat(obj);
  charSepAcc macc(xpMat);
  
  size_t n = rowInd.size();
  size_t m = colInd.size();
  
  IntegerVector rows = rowInd - 1;
  IntegerVector cols = colInd - 1;
  
  RawMatrix res(n, m);
  
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++)
      res(i, j) = macc(rows[i], cols[j]);
  
  return res;
}

/******************************************************************************/