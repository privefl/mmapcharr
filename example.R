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
