[![Travis-CI Build Status](https://travis-ci.org/privefl/mmapcharr.svg?branch=master)](https://travis-ci.org/privefl/mmapcharr)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/privefl/mmapcharr?branch=master&svg=true)](https://ci.appveyor.com/project/privefl/mmapcharr)
[![Coverage Status](https://img.shields.io/codecov/c/github/privefl/mmapcharr/master.svg)](https://codecov.io/github/privefl/mmapcharr?branch=master)
[![CRAN_Status_Badge](http://www.r-pkg.org/badges/version/mmapcharr)](https://cran.r-project.org/package=mmapcharr)


# mmapcharr

Memory-map text files of characters. 

## Installation


```r
# For the CRAN version
## Coming soon!

# For the current development version
devtools::install_github("privefl/mmapcharr")
```

## Input format

As inputs, package **mmapcharr** uses text files of characters separated by another character.
Lines should be the same so that the file can be viewed as a matrix.
Files should end up with an empty line. 

![An example of supported file](example-file.png)

You can access files in such shape the same way as for R(cpp) matrices.


## Bug report / Help

Please open an issue if you find a bug.


## Code of conduct

Please note that this project is released with a [Contributor Code of Conduct](https://github.com/privefl/mmapcharr/blob/master/code_of_conduct.md). 
By participating in this project you agree to abide by its terms.
