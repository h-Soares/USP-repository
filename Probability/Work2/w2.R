dt <- read.table("https://dcm.ffclrp.usp.br/~rrosales/aulas/orto.txt", header=TRUE)
attach(dt)

### (1.i)
dt_sem_sequelas <- dt[dt$Sequelas == "N", ]
dt_com_sequelas <- dt[dt$Sequelas == "S", ]
meses <- sort(unique(dt$Fisioterapia))

# Função para calcular frequência de meses de fisioterapia
calc_freq <- function(data) {
  freq <- sapply(meses, function(x) sum(data$Fisioterapia == x))
  return(freq)
}

# Calcular frequências para pacientes SEM e COM sequelas
freq_sem_sequelas <- calc_freq(dt_sem_sequelas)
freq_com_sequelas <- calc_freq(dt_com_sequelas)

# Criar o gráfico de barras
barplot(rbind(freq_sem_sequelas, freq_com_sequelas), beside = TRUE, names.arg = meses, col = c("green", "red"), 
    main = "Frequência de meses de Fisioterapia para pacientes",
    xlab = "Meses de Fisioterapia", ylab = "Frequência", legend.text = c("Sem sequela", "Com sequela"))

## RESPOSTA:
# Aparentemente, a variável 'meses de fisioterapia' assume valores mais altos e com maior frequência para pacientes que ficaram com sequelas após o tratamento.
##

###

### (1.ii)
cirurgia_A <- dt[dt$Cirugia == "A", ]
cirurgia_M <- dt[dt$Cirugia == "M", ]
cirurgia_B <- dt[dt$Cirugia == "B", ]

freq_cirurgia_A <- calc_freq(cirurgia_A)
freq_cirurgia_M <- calc_freq(cirurgia_M)
freq_cirurgia_B <- calc_freq(cirurgia_B)

barplot(rbind(freq_cirurgia_A, freq_cirurgia_M, freq_cirurgia_B), beside = TRUE, names.arg = meses, 
        col = c("blue", "orange", "purple"), 
        main = "Frequência de meses de Fisioterapia para pacientes com cirurgia",
        xlab = "Meses de Fisioterapia", ylab = "Frequência", 
        legend.text = c("Complexa A", "Média M ", "Baixa B"))

## RESPOSTA:
# Mais uma vez, aparentemente, os valores mais altos da variável 'meses de fisioterapia' são assumidos, com maior frequência, por pacientes que 
# passaram por cirurgia de grau de complexidade médio ou alto, como é possível visualizar no gráfico considerando os valores 7 e 8.
##

###

### (4.a)
intervalos <- c(0, 2, 4, 6, 8, 10)
frequencias <- c(14, 28, 27, 11, 4)

# Pontos médios dos intervalos
pontos_medios <- (intervalos[-1] + intervalos[-length(intervalos)]) / 2

# Vetor para as contagens individuais dos intervalos
dados <- rep(pontos_medios, frequencias)

limite_y <- c(0, 0.170)
hist(dados, breaks = intervalos, col = "skyblue", xlab = "Nota", ylab = "Frequência", main = "Notas e suas frequências", prob=TRUE, ylim = limite_y)
text(pontos_medios, frequencias, labels = frequencias, pos = 3)

###

### (4.b)
# Considerando que, no intervalo [4, 6), metade dos alunos obtiveram nota 5 (13), teremos: (13 + 11 + 4) / 84 = 33%

###

### (4.c)

# Boxplot
boxplot(dados, horizontal = FALSE, col = "skyblue", main = "Boxplot")
text(x = frequencias, y = pontos_medios, labels = frequencias)

###

dt2 <- read.table("http://dcm.ffclrp.usp.br/~rrosales/aulas/cancer.txt",header=TRUE)


### (5.i)
# FP: Falso Positivo; FN: Falso Negativo
Idade_FP <- dt2[dt2$Grupo == 4, 3]
Idade_FN <- dt2[dt2$Grupo == 1, 3]

summary(Idade_FP)
sd(Idade_FP)
barplot(table(Idade_FP))
hist(Idade_FP)
boxplot(Idade_FP)

summary(Idade_FN)
sd(Idade_FN)
barplot(table(Idade_FN))
hist(Idade_FN)
boxplot(Idade_FN)

boxplot(list(Idade_FP, Idade_FN), names = c("FP", "FN"))

## Resposta:
# A afirmação está correta. Observa-se isso pelo comparativo do bloxpot da duas idades.
##

###