empresas_esp <- c(1000000,1100000, 1200000, 1300000, 1400000)
empresas_am<- c(10000, 11000,12000,13000,14000,15000, 16000)
ni_esp<-c(4,6,6,2,2)
ni_am<-c(2, 2, 4,4,4,2,2)

#esp -> media, s^2, s y v

tabla_esp<- cbind(empresas_esp, ni_esp)
n_esp<-sum(ni_esp)
media_esp<-sum(tabla_esp[,1]*tabla_esp[,2]/n_esp)
media_esp

#s^2 = 1/N (sumatorio (xi-media^2))
sumatorio<- (tabla_esp[,1] - media_esp)^2* tabla_esp[,2]
s_2<-sum(sumatorio)/n_esp
s_2

S<- sqrt(s_2)

V<- S/media_esp
V