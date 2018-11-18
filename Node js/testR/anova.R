# require(jsonlite)
suppressMessages(require(jsonlite))
args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
  stop("At least one argument must be supplied.n", call.=FALSE)
}

asaltos <- fromJSON(args[1])
mes <- fromJSON(args[2])
tipo <- fromJSON(args[3])
X <- model.matrix(~1+mes+tipo)
#X

tX <- t(X)

XTX <- tX %*% X
#XTX

XTY <- tX %*% asaltos
#XTY

inv.XTX <- solve(XTX)
#inv.XTX

Beta.Coef <- inv.XTX %*% XTY
#Beta.Coef

modelo <- lm(asaltos~mes+tipo)
summ  <-summary(modelo)
aov <- anova(modelo)
print(toJSON(aov,pretty = T))
#predict(modelo, data.frame(mes = rep(10,2), tipo = c(0,1)), type = 'response')

#qqnorm(residuals(modelo, type = "deviance"))
#qqline(residuals(modelo, type = "deviance"))

#shapiro.test(residuals(modelo, type = "deviance"))