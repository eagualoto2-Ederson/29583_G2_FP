Algoritmo porciones_de_la_pizza
	//definicion de las variables 
	Definir a, Ap, At, Pc, Ac Como Real
	definir b, c Como Entero
	//variables utilizados
	radio_piza<-a
	n_comensales<-b
	n_porciones<-c
	Area_total<-At
	Area_porciones<-Ap
	Porcion_por_comemsales<-Pc
	Araea_por_comensal<-Ac
	//procedeimiento 
	Escribir a,"ingrese el radio de la pizza"
	Leer a
	Escribir b, "ingrese el numero de comensales "
	leer b
	Escribir c, "ingrese el total de porciones "
	leer c
	At<-(3.1416*a^2)
	Ap<-(At/c)
	Pc<-(c/b)
	Ac<-(Ap*Pc)
	Escribir"el area total de la pizza es : " At "cm2"
	Escribir "cada porcion tiene un areas : " Ap "cm2"
	Escribir "a cada comensal le corresponde : " Pc "porciones"
	Escribir "El area total  por comensal es de : " Ac "cm2"
	
FinAlgoritmo
