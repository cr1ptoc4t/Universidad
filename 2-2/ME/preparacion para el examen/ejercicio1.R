
Rendimientos <- c(-2.5, 0.6, -0.1, -1.2, -2.5, 1.7, 0.6, -1.7, 0.9, -3.9, 0.6, 1.7, 0.0, 2.3, 0.6,
                  2.8, 1.2, 0.9, 1.7, 0.6, -1.7, 0.6, -0.9, -3.6, -1.7)
n <- length(Rendimientos)

# a una tabla sin repeticiones ordenada d menor a mayor
xini<- as.data.frame(table(Rendimientos))
xini

fi<- xini[, 2]
Fi <- cumsum(fi)

tabla <- cbind(xini, Fi)
#tabla

Cuts<- c(-4:3)

intervalos<-cut(Rendimientos, breaks = Cuts, right = TRUE)
tabla_agrupada<- as.data.frame(table(intervalos))
#tabla_agrupada

# marca de clase
Li_1<-Cuts[-1]
Li<-Cuts[-length(Cuts)]
xi<- (Li_1 + Li)/2
xi
tablafinal<-cbind(tabla_agrupada, xi)
tablafinal