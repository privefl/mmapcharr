#include <mmapcharr/charsep-acc.h>
using namespace Rcpp;

// [[Rcpp::export]]
void get_text(SEXP obj) {
  
  XPtr<charSep> xpMat(obj);
  charSepAcc macc(xpMat);
  size_t n = macc.nrow();
  size_t m = macc.ncol();
  size_t i, j;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      Rcout << macc(i, j) << " ";
    }
    Rcout << std::endl;
  }
}



/*** R
test_file <- system.file("testdata/test-windows.txt", package = "mmapcharr")
d <- dim_file(test_file)
xptr <- mmapcharr:::charSepXPtr(test_file, d[["nrow"]], d[["ncol"]], d[["nextra"]])
get_text(xptr)
readLines(test_file)
*/
