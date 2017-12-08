#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void accessChar(CharacterVector x) {
  
  String A = x[0];
  
  Rcout << wrap(A) << std::endl;
  Rcout << as<CharacterVector>(A) << std::endl;
}


/*** R
accessChar(letters)
*/
