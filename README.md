[![Travis-CI Build Status](https://travis-ci.org/privefl/mmapcharr.svg?branch=master)](https://travis-ci.org/privefl/mmapcharr)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/privefl/mmapcharr?branch=master&svg=true)](https://ci.appveyor.com/project/privefl/mmapcharr)
[![Coverage Status](https://img.shields.io/codecov/c/github/privefl/mmapcharr/master.svg)](https://codecov.io/github/privefl/mmapcharr?branch=master)
[![CRAN_Status_Badge](http://www.r-pkg.org/badges/version/mmapcharr)](https://cran.r-project.org/package=mmapcharr)


# mmapcharr

Memory-map text files of characters. 

## Installation

```r
# For the CRAN version
install.packages("mmapcharr")

# For the current development version
devtools::install_github("privefl/mmapcharr")
```

## Input format

As inputs, package **mmapcharr** uses text files of characters separated by another character.
Lines should be the same so that the file can be viewed as a matrix.
Files should end up with an empty line. 

You can play with the `code` parameter to access whatever you want instead of characters (see the example code below).

![An example of supported file](https://raw.githubusercontent.com/privefl/mmapcharr/master/example-file.png)

You can access files in such shape the same way as for R(cpp) matrices.

## Example code

```r
library(mmapcharr)

test_file <- system.file("testdata/test-windows.txt", package = "mmapcharr")
readLines(test_file)

# Create the memory-mapping object based on the text file
test <- mmapchar(test_file, code = mmapcharr:::CODE_012)
test[]
test[, 1:10]

# Underlying characters
(CHAR256 <- rawToChar(as.raw(0:255), multiple = TRUE))

# Change the code to access true characters
test2 <- test$copy(code = CHAR256)
test2[, 1:10]

# Change the code to access logicals (why not?)
test3 <- test$copy(code = rep(c(TRUE, FALSE), 256 / 2))
test3[, 1:10]
```


## Bug report / Help

Please open an issue if you find a bug.
