test_file <- system.file("testdata/test-windows.txt", package = "mmapcharr")

bigstatsr:::get_nline

f2 <- function(file) {
  scan(text = system(paste('find /c /v ""', file), intern = TRUE),
       what = 1L, n = 1, quiet = TRUE)
}

f2(file)
system(paste('find /c /v ""', file), intern = TRUE)

# https://superuser.com/a/959037/850826
lapply(list.files(include.dirs = FALSE), function(file) {
  system(paste('find /c /v ""', file), intern = TRUE)
})


tmp <- system(paste('find /c /v ""', test_file), intern = TRUE)
tmp
stopifnot(identical(tmp[[1]], ""))
sub(glue:::glue("---------- {toupper(test_file)}: ([0-9]+)"), "\\1", tmp[[2]])
    
library(stringr) 
as.integer(tail(str_extract_all(tmp[[2]], boundary("word"))[[1]], 1))


files <- list.files("C:/Users/Florian/Documents/R/win-library/3.4/pcadapt/extdata/",
                    full.names = TRUE)
file.info(files)

sapply(files, nline)
