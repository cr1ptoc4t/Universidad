xi <- c(0, 10, 20, 30,40)
ni <- c(2, 4, 7, 5, 2)

TF <- as.data.frame(cbind(xi, ni))
n <- sum(TF$ni)

TF$xini <- TF$xi*TF$ni
TF$xi2ni <- TF$xi^2*TF$ni
TF$xi3ni <- TF$xi^3*TF$ni
TF$xi4ni <- TF$xi^4*TF$ni
TF