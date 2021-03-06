#Script asignación de proyectos
.libPaths(c("C:/Users/brand/Documents/R/win-library/3.4", .libPaths()))
args <- commandArgs(trailingOnly = TRUE)
if(length(args) != 3) {
	stop("Deben de ser 3 parámetros", call.=FALSE)
}

suppressMessages(suppressWarnings(require(jsonlite)))
suppressMessages(suppressWarnings(require(crossdes)))
treatments <- strtoi(args[1])
evaluators <- strtoi(args[2])
projectsPer <- strtoi(args[3])
set.seed(1)
#trt: Número de tratamientos, b = Número de evaluadores, k = Proyectos por evaluador
bib <- find.BIB(trt = treatments, b = evaluators, k = projectsPer)
result = toJSON(bib)
#Devuelve una matriz en donde las filas son los evaluadores y las columnas son los proyectos que le tocaron
print(result)