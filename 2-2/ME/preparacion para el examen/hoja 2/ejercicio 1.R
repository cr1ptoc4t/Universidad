xi <- c(2, 2, 2, 4, 7, 7, 10, 10)
yi <- c(3, 4, 5, 5, 4, 5, 3, 5)
nij <- c(5, 10, 17, 19, 20, 16, 9, 4)
n<-100
tabla<-as.data.frame(cbind(xi, yi, nij))

mediax<-sum(xi)/length(xi)
mediay<-sum(yi)/length(yi)

Sx<- 0
Sy<-0
r<-cov(xi, yi )/(Sx*Sy)