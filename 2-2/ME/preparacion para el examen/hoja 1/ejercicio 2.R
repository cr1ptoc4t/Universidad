xi <- c(7, 3, 2, 4, 5, 1, 8, 6, 1, 5, 3, 2, 4, 9, 8, 1, 0, 2, 4, 1, 2, 5, 6, 5, 4, 7, 1, 3, 0, 5, 8, 6, 3, 4, 0,
        10, 2, 5, 7, 4, 0, 2, 1, 5, 6, 4, 3, 5, 2, 3, 9, 7, 3, 4, 3, 5, 7, 4, 6, 5, 6, 1, 0, 5, 7, 8, 5, 2, 3, 10, 4,
        6, 2, 1, 1, 2, 6, 7, 4, 5, 4, 7, 6, 3, 5, 0, 2, 8, 2, 7, 8, 5, 2, 7, 1, 4, 6, 3, 5, 6)
nTotal <- length(xi)
tabla <- as.data.frame(table(xi))
tabla

#b
nalumnos_5 <- sum(xi == 5)
porcentaje_5 <- nalumnos_5 / nTotal * 100

#c
n_alumnos_6 <- sum(xi > 6)
porcentaje_6 <- n_alumnos_6 / nTotal * 100

#d
n_alumnos_aprobados <- sum(xi > 5)
porcentaje_aprobados <- n_alumnos_aprobados / nTotal * 100
#porcentaje_aprobados

#e
#media
tabla$xini <- as.numeric(tabla$xi) * as.numeric(tabla$Freq)
media <- sum(tabla$xini) / nTotal
#media

#mediana
tabla$Ni <- cumsum(tabla$Freq)
tabla
numMed <- nTotal / 2

NiMediana <- (max(tabla$Ni[tabla$Ni< numMed]))
mediana <- as.numeric(tabla$xi[tabla$Ni == NiMediana])
#mediana

#moda
freqMax <- max(tabla[, 2])
moda <- as.numeric(tabla$xi[tabla$Freq == freqMax])
#print("moda="); moda

#f
#varianza
tabla$xi_med_pow2_ni <- as.numeric((as.numeric(tabla$xi)-media)^2*tabla$Freq)
S <- sum(tabla$xi_med_pow2_ni)/nTotal
#print("S="); S

#coef variacion
V<- S/media
#print("V="); V

#g
#desv respecto media
sum<- sum(abs(as.numeric(tabla$xi)- media)*as.numeric(tabla$Freq))
Dx <- sum/nTotal
Dx

#desv resp mediana
sum <- sum(abs(as.numeric(tabla$xi)- mediana)*as.numeric(tabla$Freq))
Dme <- sum/nTotal
Dme
