
Rendimientos <- c(-2.5, 0.6, -0.1, -1.2, -2.5, 1.7, 0.6, -1.7, 0.9, -3.9, 0.6, 1.7, 0.0, 2.3, 0.6,
                  2.8, 1.2, 0.9, 1.7, 0.6, -1.7, 0.6, -0.9, -3.6, -1.7)
n <- length(Rendimientos)

# a una tabla sin repeticiones ordenada d menor a mayor
xini<- as.data.frame(table(Rendimientos))
xini

# columna de frecuencias acumuladas
Ni <- cumsum(xini[,2])
Ni

# xini selecciona la segunda columna, fi es la frecuencia relativa
fi <- xini[,2]/n
fi

# la frecuencia relativa acumulada
Fi <- cumsum(fi)

# junta columnas a una tabla
TablaFrecuencia <-cbind (xini, Ni, fi, Fi)
TablaFrecuencia

colnames(TablaFrecuencia) <- c("xi", "ni", "Ni", "fi", "Fi")
TablaFrecuencia

cuts <- -4 : 3
cuts

TablaFrecAgrupada<- as.data.frame(table(cut(Rendimientos, breaks=cuts, right=TRUE)))
colnames(TablaFrecAgrupada) <- c("Li_1_Li", "ni")
TablaFrecAgrupada

Li
Li_1