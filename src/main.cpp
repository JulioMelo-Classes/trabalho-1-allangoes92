#include <iostream>
#include <vector>
#include "Keno_Bet.cpp"
#include "../data/bet_01.dat"
using namespace std;

/*!
 *Esta função implementa um sub algoritmo utilizado pelo Quick Sort.
 *Ele utiliza como parâmetro um vetor de alocação dinâmica e os limites esquerdo e direito.
 *É nele que realmente ocorre a ordenação.
 *Para essa versão do algoritmo foi escolhido sempre o último elemento como pivô e os elementos são trocados de posição em função do pivô
 *O separador antes retornar o novo limite esquerdo ou direito a ser chamado recursivavmente pelo quick sort é o índice do low, que inicia com -1, mas é corrigido no retorno com +1.
*/

int particiona (std::vector<int> & A, int left, int right){
    int pivot = A[right];
    int low = left-1;

    for (int high = left; high <= right - 1; high++)
    {
        if (A[high] < pivot)
        {
            low++;
            std::swap(A[low], A[high]);
        }
    }
    std::swap (A[low+1], A[right]);
    return (low+1);
}

/*!
 *Esta função implementa o algoritmo Quick Sort.
 *Ele utiliza como parâmetro um vetor de alocação dinâmica e os limites esquerdo e direito.
*/

void quicksort(std::vector<int> & A, int left, int right){
	int pivo;
    if(left<right){
            pivo = particiona(A, left, right);
            quicksort(A, left, pivo-1);
            quicksort(A, pivo+1, right);
    }
}



//g++ src/Keno_Bet.cpp main.cpp -I./include -o bin/main
int main(int argc, char *argv[]){

  KenoBet k;
  cout << ">>> Lendo arquivo de apostas [" << "data/bet_01.dat" << "], por favor aguarde.." << endl;
  
  cout << "   --------------------------------------------------------------------" << endl;
  k.m_wage = argv[1];
  for(int i=2; i<argc; i++)
    k.m_spots.push_back(argv[i]);
  cout << "Você apostará um total de $" << k.get_wage() << " créditos." << endl;
  quicksort(k.get_spots(), k.get_spots().begin(), k.get_spots().end());
  cout << "Sua aposta tem " << k.get_spots().size() << " números, eles são: [";
  for(int* i=k.get_spots().begin(); i<k.get_spots().end(); i++)
  {
    cout << " " << *i;
  }
  cout << " ]" << endl;
  cout << "        ----------+-----------" << endl;
  return 0;
}
/*
>>> Lendo arquivo de apostas [data/bet_03.dat], por favor aguarde..
--------------------------------------------------------------------
>>> Aposta lida com sucesso!
    Você apostará um total de $1500 créditos.
    Jogará um total de 3 rodadas, apostando $500 créditos por rodada

    Sua aposta tem 3 números, eles são: [ 12 21 64 ]
        ----------+-----------
        Hits      | Retorno
        0         | 0
        1         | 1
        2         | 2
        3         | 16
        ------------------------------------------------------------
        Esta é a rodada #1 de 3, sua aposta é $500. Boa sorte!
        Os números sorteados são: [ 3 6 12 20 21 23 26 27 28 31 32 35 45 48 55 59 63 64 69 74 ]
        
        Você acertou os números [ 12 21 64 ], um total de 3 hits de 3
        Sua taxa de retorno é 16, assim você sai com: $8000
        Você possui um total de: $9000 créditos.
        ------------------------------------------------------------
        Esta é a rodada #2 de 3, sua aposta é $500. Boa sorte!
        Os números sorteados são: [ 2 3 7 10 15 17 18 21 23 28 29 33 37 40 41 43 50 71 72 79 ]
        
        Você acertou os números [ 21 ], um total de 1 hit de 3
        Sua taxa de retorno é 1, assim você sai com: $500
        Você possui um total de: $9000 créditos.
        ------------------------------------------------------------
        Esta é a rodada #3 de 3, sua aposta é $500. Boa sorte!
        Os números sorteados são: [ 4 8 10 16 20 23 28 30 32 34 45 46 50 51 52 63 64 68 74 80 ]
        
        Você acertou os números [ 64 ], um total de 1 hit de 3
        Sua taxa de retorno é 1, assim você sai com: $500
        Você possui um total de: $9000 créditos.
>>> Fim das rodadas!
--------------------------------------------------------------------

======= Sumário =======
>>> Você gastou um total de $1500 créditos
>>> Hooray! você ganhou $7500 créditos!
>>> Você está saindo do jogo com um total de $9000 créditos.
*/