#Script calificar proyectos con el modelo de bloques incompletos balanceados
.libPaths(c("C:/Users/brand/Documents/R/win-library/3.4", .libPaths()))
args <- commandArgs(trailingOnly = TRUE)
if(length(args) != 4) {
	stop("Deben de ser  parámetros", call.=FALSE)
}

suppressWarnings(require(jsonlite))
suppressWarnings(require(ibd))
suppressWarnings(require(crossdes))
suppressWarnings(require(ggplot2))
suppressWarnings(require(dplyr))
suppressWarnings(require(tidyr))
suppressWarnings(require(readr))
suppressWarnings(require(emmeans))
suppressWarnings(require(nlme))

#Projects
t <- strtoi(args[1])
#Evaluators
b <- strtoi(args[2])
#ProjectsPerEvaluator
k <- strtoi(args[3])

#Ordenadas por evaluador index y a su vez por proyecto index
grades <- fromJSON(args[6])

set.seed(1)
bib <- find.BIB(trt = t, b = b, k = k)

bloq <- 1:b
Eval_Proyect <- as.data.frame(bib) %>%
  gather(columna, trt) %>%  ## Unir todas las columnas en una sola columna
  mutate(evaluator_Index = rep(bloq,k),  # Asignar evaluador
         project_Index = trt) %>% # Asignar proyecto a revisar
  select(evaluator_Index, project_Index) %>%  # Extraer solo las columnas mencionadas
  arrange(evaluator_Index) # Ordenar en base al evaluador

Eval_Proyect$Calificacion <- grades
datos <- Eval_Proyect

modelo <- lme(Calificacion~project_Index, random = ~ 1 | evaluator_Index, data = datos)

summ  <-summary(modelo)

Ajuste <- emmeans(modelo, ~project_Index)
adjusted.means <- cld(Ajuste, alpha = .05)


# aov <- anova(modelo)
print(toJSON(summ, pretty = T))