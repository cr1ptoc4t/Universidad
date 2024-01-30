xi <- c(300, 600, 400, 1200, 1500)
ni <-c(20,30,40,60,50)


#dividir la columna entre n, sumar y meterlo en otra variable n
DistFreq <- as.data.frame(cbind(xi, ni))
DistFreq

n<-sum(DistFreq[,2])
n<- sum(DistFreq$ni)

DistFreq[,3]<-DistFreq[,2]/n

# renombrar variables
names(DistFreq) <- c("xi", "ni", "fi")

#
DistFreq$fi <- DistFreq$ni/n

DistFreq$Ni <- cumsum(DistFreq$ni)

DistFreq$Fi <- cumsum(DistFreq$ni)

DistFreq

DistFreq$Fi2 <- DistFreq$Ni/n