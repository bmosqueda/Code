args <- commandArgs(trailingOnly = FALSE)
if (length(args) == 0) {
  stop("At least one argument must be supplied.n", call.=FALSE)
}

print(args)
# suppressWarnings(require(jsonlite))
# asaltos <- fromJSON(args[1])
# mes <- fromJSON(args[2])
# tipo <- fromJSON(args[3])
# print(asaltos)