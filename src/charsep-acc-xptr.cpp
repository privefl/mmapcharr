/******************************************************************************/

#include <mmapcharr/charsep-acc.h>

/******************************************************************************/

charSep::charSep(std::string path, int n, int m, int r) : n(n), m(m), r(r) {
  
  try {
    this->file = file_mapping(path.c_str(), read_only);
  } catch(interprocess_exception& e) {
    throw std::runtime_error("File not found.");
  }
  
  this->file_region = mapped_region(this->file, read_only);
  this->file_data = 
    static_cast<const unsigned char*>(this->file_region.get_address());
}

/******************************************************************************/

// [[Rcpp::export]]
SEXP charSepXPtr(std::string path, int n, int m, int r) {
  
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