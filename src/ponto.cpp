#include "ponto.h"

Ponto::Ponto(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Ponto::distancia(Ponto outro){
    return sqrt((x - outro.x)*(x - outro.x) + (y - outro.y)*(y - outro.y));
}

double Ponto::getX(){
    return x;
}

double Ponto::getY(){
    return y;
}

void Ponto::setX(double x){
    this->x = x;
}

void Ponto::setY(double y){
    this->y = y;
}

//Resolução do sistema Ax = b, sendo A = matrix, b = vetor, N = ordem de matrix
//Créditos à professora Cláudia Galarda Varassin pela criação da função que foi poucamente modificada para atender à nossos anseios
vector<double> Ponto::resolucaoDeSistemaLinear(double** matrix, double* vetor, int N){
	double A[N][N], X[N], soma, b[N], m, maior,aux, baux;
	int n,k,i,j, imaior;
	vector<double> x;
	n = N;
	for(i = 0; i < n; i++){
		b[i] = vetor[i];
		for(j = 0; j < n; j++){
			A[i][j] = matrix[i][j];
		}
	}

//    	// Mostrando os dados do problema
//    	    printf("\n --- Sistema  fornecido ---\n");
//    	    for(i=0;i< n;i++)
//    	    {
//    	      for(j=0;j< n;j++)
//    	      {
//    	        printf("  %10.3f ", A[i][j]);
//    	      }
//    	      printf(" | b[%d]: %10.3f\n", i, b[i]);
//    	    }
//    	    printf(" -------------------------------------\n");
//    	// fim de  mostrando os dados do problema

	//     Triangularizacao
		for(k=0;k<(n-1);k++)
		{
			//identificar qual eh a melhor linha pivo
			maior=fabs(A[k][k]);
			imaior=k;
		for(i=k+1;i<n;i++)
			{
			  if(fabs(A[i][k])> maior){maior=fabs(A[i][k]); imaior=i;}
			}
		if(imaior!=k)// Trocar linha k com linha imaior
			{
		   for(j=0;j<n;j++)
			   {
			aux=A[k][j];
			A[k][j]=A[imaior][j];
			A[imaior][j]=aux;
			   }
		   baux=b[k];
			   b[k]=b[imaior];
		   b[imaior]=baux;
		}// fim do if troca de linhas
		   // melhor linha pivo identificada
		   for(i=(k+1);i<n;i++)
		   {
			   m = A[i][k]/A[k][k];
			   A[i][k]=0; // para visualização da matriz triangularizada
			   //A[i][k]=A[i][k]- m*A[k][k];; // para ver o valor que fica na memória

			   for(j=(k+1);j<n;j++)
			   {
				  A[i][j]= A[i][j]- m*A[k][j];
			   } // fim  j
			   b[i]= b[i]- m*b[k];

			} // fim linha i


		} // fim etapa K


	//   resolvendo  o sistema  Triangular Superior via Subst. Regressiva
		// calculo de x da última equação (indice: n-1, em C)
		X[n-1]= b[n-1]/A[n-1][n-1];

		// Calculo das variáveis: começando  da penúltima linha (n-2) até a primeira (indice é zero).
		for(i=(n-2);i>=0;i--)
		{
		  soma=b[i];
		  for(j=i+1;j<n;j++)
		  {
			soma = soma - A[i][j]*X[j];
		  }
		  X[i]= soma/A[i][i];
		}

//    	   // Mostrando a solucao
//    	    printf("\n O Vetor solucao:\n");
//    	    for(i=0;i< n;i++)
//    	    {
//    	       printf(" X[%d]: %.7f\n", i, X[i]);
//    	    }

		for(int i = 0; i < N; i++){
			x.push_back(X[i]);
		}

		return x;
}
