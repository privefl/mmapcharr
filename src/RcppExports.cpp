// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// charSepXPtr
SEXP charSepXPtr(std::string path, int n, int m, int r);
RcppExport SEXP _mmapcharr_charSepXPtr(SEXP pathSEXP, SEXP nSEXP, SEXP mSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(charSepXPtr(path, n, m, r));
    return rcpp_result_gen;
END_RCPP
}
// decodeMat
IntegerMatrix decodeMat(const RawMatrix& source, const IntegerVector& code);
RcppExport SEXP _mmapcharr_decodeMat(SEXP sourceSEXP, SEXP codeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const RawMatrix& >::type source(sourceSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type code(codeSEXP);
    rcpp_result_gen = Rcpp::wrap(decodeMat(source, code));
    return rcpp_result_gen;
END_RCPP
}
// decodeVec
IntegerVector decodeVec(const RawVector& source, const IntegerVector& code);
RcppExport SEXP _mmapcharr_decodeVec(SEXP sourceSEXP, SEXP codeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const RawVector& >::type source(sourceSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type code(codeSEXP);
    rcpp_result_gen = Rcpp::wrap(decodeVec(source, code));
    return rcpp_result_gen;
END_RCPP
}
// extractVec
RawVector extractVec(RObject obj, const IntegerMatrix& elemInd);
RcppExport SEXP _mmapcharr_extractVec(SEXP objSEXP, SEXP elemIndSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type obj(objSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type elemInd(elemIndSEXP);
    rcpp_result_gen = Rcpp::wrap(extractVec(obj, elemInd));
    return rcpp_result_gen;
END_RCPP
}
// extractMat
RawMatrix extractMat(RObject obj, const IntegerVector& rowInd, const IntegerVector& colInd);
RcppExport SEXP _mmapcharr_extractMat(SEXP objSEXP, SEXP rowIndSEXP, SEXP colIndSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type obj(objSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type rowInd(rowIndSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type colInd(colIndSEXP);
    rcpp_result_gen = Rcpp::wrap(extractMat(obj, rowInd, colInd));
    return rcpp_result_gen;
END_RCPP
}
// nline_cpp
int nline_cpp(SEXP obj);
RcppExport SEXP _mmapcharr_nline_cpp(SEXP objSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type obj(objSEXP);
    rcpp_result_gen = Rcpp::wrap(nline_cpp(obj));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_mmapcharr_charSepXPtr", (DL_FUNC) &_mmapcharr_charSepXPtr, 4},
    {"_mmapcharr_decodeMat", (DL_FUNC) &_mmapcharr_decodeMat, 2},
    {"_mmapcharr_decodeVec", (DL_FUNC) &_mmapcharr_decodeVec, 2},
    {"_mmapcharr_extractVec", (DL_FUNC) &_mmapcharr_extractVec, 2},
    {"_mmapcharr_extractMat", (DL_FUNC) &_mmapcharr_extractMat, 3},
    {"_mmapcharr_nline_cpp", (DL_FUNC) &_mmapcharr_nline_cpp, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_mmapcharr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}