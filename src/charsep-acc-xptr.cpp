/******************************************************************************/

#include <mmapcharr/charsep-acc.h>

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

/******************************************************************************/

// [[Rcpp::export]]
SEXP charSepXPtr(const std::string path, int n, int m, int r) {
  
  // http://gallery.rcpp.org/articles/intro-to-exceptions/
  try {
    /* Create a pointer to a charSepAcc object and wrap it as an external pointer
    http://dirk.eddelbuettel.com/code/rcpp/Rcpp-modules.pdf */
    XPtr<charSep> ptr(new charSep(path, n, m, r), true);
    // Return the external pointer to the R side
    return ptr;
  } catch(std::exception &ex) {
    forward_exception_to_r(ex);
    return 0;
  }
}

/******************************************************************************/