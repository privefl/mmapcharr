#include <mmapcharr/charsep-acc.h>
using namespace Rcpp;

// [[Rcpp::export]]
int nline(SEXP obj) {
  
  XPtr<charSep> xpMat(obj);
  const unsigned char* mat = xpMat->matrix();
  
  const unsigned char backslash_n = 10;

  return std::count(mat, mat + xpMat->nrow(), backslash_n);
}

/*** R
test_file3 <- system.file("extdata/geno3pops.lfmm", package = "pcadapt")
xptr <- mmapcharr:::charSepXPtr(test_file3, n = file.size(test_file3), m = 1, r = 0)
nline(xptr)
*/
