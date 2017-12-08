################################################################################

#' Class digimat
#'
#' A reference class for storing and accessing matrix-like data stored on disk 
#' in files containing only characters (digits) separated by a character.
#'
#' @examples
#' test_file <- system.file("testdata/test-windows.txt", package = "mmapcharr")
#' test <- digimat(test_file, code = mmapcharr:::CODE_012)
#' test[, 1:3]
#' test[]
#' readLines(test_file)
#' 
#' @exportClass digimat
#'
digimat_RC <- methods::setRefClass(
  
  "digimat",
  
  fields = list(
    extptr = "externalptr",
    nrow = "integer",
    ncol = "integer",
    nextra = "integer",
    backingfile = "character",
    code = "integer",
    
    address = function() {
      if (identical(.self$extptr, new("externalptr"))) { # nil
        .self$extptr <- charSepXPtr(.self$backingfile,
                                    .self$nrow,
                                    .self$ncol,
                                    .self$nextra)
      }
      .self$extptr
    }
  ),
  
  methods = list(
    initialize = function(file, code) {
      
      if (length(code) != 256) stop2("Parameter 'code' must be of length 256.")
      
      d <- dim_file(file)
      
      .self$backingfile <- file
      .self$nrow        <- d[["nrow"]]
      .self$ncol        <- d[["ncol"]]
      .self$nextra      <- d[["nextra"]]
      .self$code        <- code
      
      .self$address  # connect once
    },
    
    show = function() {
      cat(sprintf("A digimat with %d rows and %d columns.",
                  .self$nrow, .self$ncol))
      invisible(.self)
    }
  )
)
digimat_RC$lock("backingfile", "nrow", "ncol", "nextra")

################################################################################

#' Wrapper constructor for class `digimat`.
#'
#' @param file Path of the file.
#' @param code Integer vector of size 256 to access integers instead of
#'   `rawToChar(as.raw(0:255), multiple = TRUE)`. 
#'   See `mmapcharr:::CODE_012` and `mmapcharr:::CODE_DIGITS`.
#'
#' @rdname digimat-class
#'
#' @export
#'
digimat <- function(file, code) {
  new(Class = "digimat", file = file, code = code)
}

################################################################################

#' Methods for the digimat class
#'
#' @name digimat-methods
#'
#' @rdname digimat-methods
NULL

#' Accessor methods for class `digimat`. You can use positive and negative indices,
#' logical indices (that are recycled) and also a matrix of indices (but only
#' positive ones).
#'
#' @param x A [digimat][digimat-class] object.
#' @param i A vector of indices (or nothing). You can use positive and negative
#'   indices, logical indices (that are recycled) and also a matrix of indices
#'   (but only positive ones).
#' @param j A vector of indices (or nothing). You can use positive and negative
#'   indices, logical indices (that are recycled).
#' @param ... Not used. Just to make [nargs] works.
#' @param drop Whether to delete the dimensions of a matrix which have
#'   one dimension equals to 1.
#'
#' @rdname digimat-methods
#'
#' @include extract.R
#'
#' @export
#'
setMethod(
  '[', signature(x = "digimat"),
  Extract(
    extract_vector = function(x, i) extractVec(x$address, i),
    extract_matrix = function(x, i, j) extractMat(x$address, i, j)
  )
)

################################################################################

#' Dimension and type methods for class `digimat`.
#'
#' @rdname digimat-methods
#' @export
setMethod("dim",    signature(x = "digimat"), function(x) c(x$nrow, x$ncol))

#' @rdname digimat-methods
#' @export
setMethod("length", signature(x = "digimat"), function(x) prod(dim(x)))

################################################################################