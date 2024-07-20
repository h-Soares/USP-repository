# para mi # 12

beta1 <- function(mi) {
    sample_sd <- 3.011
    sample_length <- 5

    # t2 > t1
    t1 <- (6.96 - mi) / (sample_sd / sqrt(sample_length))
    t2 <- (17.03 - mi) / (sample_sd / sqrt(sample_length))

    result <- pt(t2, df = sample_length - 1) - pt(t1, df = sample_length - 1)
    return(result)
}

power1 <- function(mi) {
    return(1 - beta1(mi))
}

# sequência de valores para mi
mi_values <- seq(0, 50, by = 0.1)

# valores da função poder para cada mi
power_values <- sapply(mi_values, power1)

plot(mi_values, power_values, type = "l", col = "black", lwd = 4.5, xlab = expression(mu), ylab = "Poder", 
main = "Curva de Poder")
abline(v = 12, col = "red", lty = 2, lwd = 3) # linha para mi = 12 (H0 verdadeira)
abline(h = 0.02, col = "red", lty = 2, lwd = 3) # linha para poder de 2% (ALPHA - Erro tipo I)

############################################################################################################

# para mi > 12

beta2 <- function(mi) {
    sample_sd <- 3.011
    sample_length <- 5

    t <- (16.038 - mi) / (sample_sd / sqrt(sample_length))

    result <- pt(t, df = sample_length - 1)
    return(result)
}

power2 <- function(mi) {
    return(1 - beta2(mi))
}

# sequência de valores para mi
mi_values2 <- seq(12, 60, by = 0.1)

# valores da função poder para cada mi
power_values2 <- sapply(mi_values2, power2)

plot(mi_values2, power_values2, type = "l", col = "black", lwd = 4.5, xlab = expression(mu), ylab = "Poder", 
main = "Curva de Poder")
abline(v = 12, col = "red", lty = 2, lwd = 3) # linha para mi = 12 (H0 verdadeira)
abline(h = 0.02, col = "red", lty = 2, lwd = 3) # linha para poder de 2% (ALPHA - Erro tipo I)

############################################################################################################

# comparando os testes

print(power1(13))
print(power2(13))

print(power1(20))
print(power2(20))