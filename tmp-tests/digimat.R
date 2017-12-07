test_file <- system.file("testdata/test-windows.txt", package = "mmapcharr")

tmp <- dim_file(test_file)

rawToChar(as.raw(0:255), multiple = TRUE)[48:60]
code <- rep(NA_integer_, 256)
code[49:51] <- 0:2

test <- digimat(test_file, code)

test[, 1]
test[]
test[1, ]

dim(test)

test_file2 <- system.file("extdata/geno3pops.pcadapt", package = "pcadapt")

test2 <- digimat(test_file2, mmapcharr:::CODE_012)
test2[]


test_file3 <- system.file("extdata/geno3pops.lfmm", package = "pcadapt")

test3 <- digimat(test_file3, mmapcharr:::CODE_012)
test3[, 1:3]
