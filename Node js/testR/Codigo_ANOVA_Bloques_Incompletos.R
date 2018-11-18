##### LIBRERIAS REQUERIDAS
library(ibd)
library(crossdes)
library(ggplot2)
library(dplyr)
library(tidyr)
library(readr)
library(emmeans)
library(nlme)

theme_set(theme_bw()) # white background

################# PRIMER EJEMPLO ###################
set.seed(1)
bib <- find.BIB(trt = 10, b = 5, k = 6)
bib

design_to_N(bib)

######## DISEÑO BIB en formato de datos ordenados
bloq <- 1:5
k <- 6
Eval_Proyect <- as.data.frame(bib) %>%
  gather(columna, trt) %>%  ## Unir todas las columnas en una sola columna
  mutate(Id_Evaluador = paste("Evaluador", as.factor(rep(bloq,k))),  # Asignar evaluador
         Id_Articulo = paste("Articulo",as.factor(trt))) %>% # Asignar articulo a revisar
  select(Id_Evaluador, Id_Articulo) %>%  # Extraer solo las columnas mencionadas
  arrange(Id_Evaluador) # Ordenar en base al evaluador

head(Eval_Proyect)

####### SIMULACIÓN DE EVALUACIONES
set.seed(1)
Z <- model.matrix(~0+Eval_Proyect$Id_Evaluador)
X <- model.matrix(~0+Eval_Proyect$Id_Articulo)
Betas <- c(round(rnorm(10,6,.75),0))
us <- rnorm(dim(Z)[2],sd=2)
y <- X%*%Betas+Z%*%us+rnorm(dim(X)[1],sd=0.2)

y[which(y>10)] <- 10

Eval_Proyect$Calificacion <- round(y[1:length(y),],0)
datos <- Eval_Proyect
head(datos)

#### MODELO
modelo <- lme(Calificacion~Id_Articulo, random = ~ 1 | Id_Evaluador, data = datos)
summary(modelo)
anova(modelo)

# Ajuste de los promedios
Ajuste <- emmeans(modelo, ~Id_Articulo)

# Obtención de los contrastes
contrast(emmeans(modelo, pairwise ~ Id_Articulo))$contrasts

# Obtención de los contrastes en una gráfica
plot(Ajuste, comparisons = TRUE, alpha = .05)

# Ajuste de los promedios con agrupación
adjusted.means <- cld(Ajuste, alpha = .05)

# Promedio sin ajustar
noadjusted.means <- Eval_Proyect %>%
   group_by(Id_Articulo) %>%
   summarise(Promedio = mean(Calificacion), DS = sd(Calificacion))

# Comapración de los promedios ajustados contra el promedio convencional
merge(x = adjusted.means, y = noadjusted.means, by = "Id_Articulo", all = TRUE)

qqnorm(residuals(modelo))
qqline(residuals(modelo))

shapiro.test(residuals(modelo))


#### Ejemplo 2
set.seed(1)
bib <- find.BIB(trt = 5, b = 5, k = 3)
bib

design_to_N(bib)

######## DISEÑO BIB en formato de datos ordenados
bloq <- 1:5
k <- 3
Terreno <- as.data.frame(bib) %>%
  gather(columna,trt) %>%
  mutate(Finca = paste("Finca", as.factor(rep(bloq,k))), Fertilizante=paste("Fertilizante",as.factor(trt))) %>%
  select(Finca, Fertilizante) %>%
  arrange(Finca)

head(Terreno)

####### SIMULACIÓN DE EVALUACIONES
set.seed(1)
Z <- model.matrix(~0+Terreno$Finca)
X <- model.matrix(~0+Terreno$Fertilizante)
Betas <- c(round(rnorm(5,2,.75),0))
us <- rnorm(dim(Z)[2],sd=2)
y <- X%*%Betas+Z%*%us+rnorm(dim(X)[1],sd=0.2)

y[which(y<0)] <- 0

Terreno$Rendimiento <- round(y[1:length(y),],0)


datos <- Terreno

head(datos)

#### MODELO
modelo <- lme(Rendimiento~Fertilizante, random = ~ 1 | Finca, data = datos)

summary(modelo)
anova(modelo)


Ajuste <- emmeans(modelo, ~Fertilizante)

contrast(emmeans(modelo, pairwise ~ Fertilizante))$contrasts

plot(Ajuste, comparisons = TRUE, alpha = .05)

adjusted.means <- cld(Ajuste, alpha = .05)

noadjusted.means <- Terreno %>%
  group_by(Fertilizante) %>%
  summarise(Promedio = mean(Rendimiento), DS = sd(Rendimiento))

merge(x = adjusted.means, y = noadjusted.means, by = "Fertilizante", all = TRUE)

qqnorm(residuals(modelo))
qqline(residuals(modelo))

shapiro.test(residuals(modelo))


#### Ejemplo 3

set.seed(1)
bib <- find.BIB(trt = 12, b = 6, k = 6)
bib

design_to_N(bib)

######## NO INCLUIR EN EL LIBRO
bloq <- 1:6
k <- 6
Eval_Proyect <- as.data.frame(bib) %>%
  gather(columna,trt) %>%
  mutate(Id_Evaluador = paste("Evaluador", as.factor(rep(bloq,k))),
         Id_Presentacion = paste("Presentacion",as.factor(trt))) %>%
  select(Id_Evaluador, Id_Presentacion) %>%
  arrange(Id_Evaluador)

head(Eval_Proyect)

set.seed(1)
Z <- model.matrix(~0+Eval_Proyect$Id_Evaluador)
X <- model.matrix(~0+Eval_Proyect$Id_Presentacion)
Betas <- c(round(rnorm(12,6,.75),0))
us <- rnorm(dim(Z)[2], sd = 2)
y <- X %*% Betas + Z %*% us + rnorm(dim(X)[1], sd=0.2)

y[which(y>10)] <- 10

Eval_Proyect$Calificacion <- round(y[1:length(y),],0)

datos <- Eval_Proyect



head(datos)
modelo <- lme(Calificacion~Id_Presentacion, random = ~ 1 | Id_Evaluador, data = datos)

summary(modelo)
anova(modelo)
joint_tests(modelo)

Ajuste <- emmeans(modelo, ~Id_Presentacion)

contrast(emmeans(modelo, pairwise ~ Id_Presentacion))$contrasts

plot(Ajuste, comparisons = TRUE, alpha = .05)

adjusted.means <- cld(Ajuste, alpha = .05)

noadjusted.means <- Eval_Proyect %>%
  group_by(Id_Presentacion) %>%
  summarise(Promedio = mean(Calificacion), DS = sd(Calificacion))

merge(x = adjusted.means, y = noadjusted.means, by = "Id_Presentacion", all = TRUE)


qqnorm(residuals(modelo))
qqline(residuals(modelo))

shapiro.test(residuals(modelo))

