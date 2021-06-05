/*
Este programa recibe a través de redireccionamiento un input de x numeros (del 1 al 6) los cuales serán "encriptados" a través de un algoritmo DFS recursivo. Sin saber la estructura del árbol, no sería posible entender la conversión.

Creado por A01027541 Maximiliano Sapién y A01027446 Karen Morgado

5/21/21

ITESM CSF
*/

#include <iostream>
#include <string> 
#include <chrono>
#include <map>
#include <list>
#include <fstream>
using namespace std;
using namespace std::chrono;

class Graph{
public:
  //Variables
	map<int, bool> visited;
	map<int, list<int> > adj;
  int contador = 0;
  int operaciones = 0;
  string resultado;

	// function to add an edge to tree
	void AddEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v, string num);

  //Encrypt function
  void Encrypt(int v, string num);

  //Operaciones counter funct
  void ResOperaciones();
};

void Graph::AddEdge(int v, int w){
	adj[v].push_back(w); // Add w to v’s list.
}

//DFS ALG
void Graph::DFS(int v, string num){
  if(visited[14]==true && contador<num.length()){  //Resetting the tree
    for(int m = 0; m <= 14; m++){
      visited[m] = false;
    }
  }
  else if(contador>=num.length()){
    return;
  }

	// Mark the current node as visited
	visited[v] = true;
  operaciones++;

  //Método encriptar
  Encrypt(v, num);

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i){
    operaciones++;
    if (!visited[*i]){
      DFS(*i, num);
    }
  }
}

void Graph::Encrypt(int v, string num){
  char ctemp = num[contador];
  string stemp(1, ctemp);
  int realnum;

  try {
	  realnum = stoi(stemp);
  } 

  catch (...){
    return;
  }

  switch(v){
    case 0:
      if(realnum == 1){
        resultado.append("A"); contador++;
      }
      return;

    case 1:
      if(realnum == 2){
        resultado.append("B"); contador++;
      }
      return;

    case 2:
      if(realnum == 5){
        resultado.append("C"); contador++;
      }
      return;

    case 3:
      if(realnum == 6){
        resultado.append("D"); contador++;
      }
      return;

    case 4:
      if(realnum == 3){
        resultado.append("E"); contador++;
      }
      return;

    case 5:
      if(realnum == 4){
        resultado.append("F"); contador++;
      }
      return;

    case 6:
      if(realnum == 1){
        resultado.append("G"); contador++;
      }
      return;

    case 7:
      if(realnum == 2){
        resultado.append("H"); contador++;
      }
      return;

    case 8:
      if(realnum == 6){
        resultado.append("B"); contador++;
      }
      return;

    case 9:
      if(realnum == 3){
        resultado.append("F"); contador++;
      }
      return;

    case 10:
      if(realnum == 2){
        resultado.append("D"); contador++;
      }
      return;

    case 11:
      if(realnum == 6){
        resultado.append("E"); contador++;
      }
      return;

    case 12:
      if(realnum == 4){
        resultado.append("C"); contador++;
      }
      return;

    case 13:
      if(realnum == 1){
        resultado.append("H"); contador++;
      }
      return;

    case 14:
      if(realnum == 5){
        resultado.append("G"); contador++;
      }
      return;
  } 
}

void Graph::ResOperaciones(){
  cout<<"Operaciones: "<<operaciones<<endl;
  cout<<"Resultado: "<<resultado<<endl;
}

// Driver code
int main() {

  //input system
  string num; //variable para el input del txt
  cin>>num;

  for(int j = 0; j<=num.length()-1;j++){
    char ctemp = num[j];
    string stemp(1, ctemp);
    int catcher; //variable usada para verificar input correcto
    try {
      catcher = stoi(stemp);
    } 
    catch (...){
      cout<<"Input incorrecto, por favor sólo inputs númericos sin espacios 1 al 6."<<endl;
      abort();
    }
    if(catcher>6 || catcher<0){
      cout<<"Input incorrecto, por favor sólo inputs númericos sin espacios del 1 al 6."<<endl;
      abort();
    }
  }


  //contadores
  int veces = 0;
  veces = num.length()/3 + (num.length())%3; //definimos las veces que se ejecuta el método

	//tree
	Graph g;
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(2, 4);
  g.AddEdge(1, 5);
  g.AddEdge(5, 6);
  g.AddEdge(5, 7);
  g.AddEdge(0, 8);
  g.AddEdge(8, 9);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(8, 12);
  g.AddEdge(12, 13);
  g.AddEdge(12, 14);

  auto start = high_resolution_clock::now();

  for(int i = 0; i <= veces; i++) { //repetición del método
    g.DFS(0, num);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout <<"Tiempo: " << duration.count() << " microsegundos" << endl;
  g.ResOperaciones();
  
	return 0;
}

