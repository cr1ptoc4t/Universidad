#a <- c(8, 8, 7, 8, 7, 9, 9, 5, 6, 7, 8, 8)

#tabla<-as.data.frame(table(a))
#tabla$Ni <- cumsum(tabla$Freq)

#tabla
#quantile(a, 0.75)

Litros <- c(30,30,30,35,35,35,35,35,40,40,40,40,40,45,45,45)

Precio <- c(1.35,1.4,1.42,1.3,1.32,1.35,1.4,1.42,1.3,1.32,1.35,1.4,1.42,1.3,1.32,1.35)

nij <- c(2,6,7,1,7,5,7,4,8,12,7,3,1,10,9,2)

DF <- data.frame(Litros,Precio,nij)

media_Litros <- sum(DF$Litros * DF$nij) / sum(DF$nij)
media_Precio <- sum(DF$Precio * DF$nij) / sum(DF$nij)


sxy <- sum((DF$Litros - media_Litros) * (DF$Precio - media_Precio) * DF$nij) / sum(DF$nij)

sx<- sqrt(var(Litros))
sy<-sqrt(var(Precio))

coef<- sxy/(sx*sy)
coef