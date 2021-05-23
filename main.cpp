/*
Este programa recibe a través de redireccionamiento un input de x numeros (del 1 al 6) los cuales serán "encriptados" a través de un algoritmo DFS recursivo. Sin saber la estructura del árbol, no sería posible entender la conversión.

Creado por A01027541 Maximiliano Sapién y A01027446 Karen Morgado

5/21/21

ITESM CSF
*/

#include <iostream>
#include <bits/stdc++.h>
#include <string> 
#include <chrono>
using namespace std;
using namespace std::chrono;

class Graph{
public:
  //Variables
	map<int, bool> visited;
	map<int, list<int>> adj;
  int contador = 0;
  int operaciones = 0;

	// function to add an edge to tree
	void AddEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v, string num);

  //Encrypt function
  void Encrypt(int v, string num);

  //Operaciones counter funct
  void Operaciones();
};

void Graph::AddEdge(int v, int w){
	adj[v].push_back(w); // Add w to v’s list.
}

//DFS ALG
void Graph::DFS(int v, string num){
  if(visited[6]==true && contador<num.length()){  //Resetting the tree
    for(int m = 0; m <= 6; m++){
      operaciones++;
      visited[m] = false;
    }
  }
  else if(contador>=num.length()){
    return;
  }

	// Mark the current node as visited and
	visited[v] = true;

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

void Graph::Encrypt(int v, string num)
{
  char ctemp = num[contador];
  string stemp{ctemp};
  int realnum;

  try {
	  realnum = stoi(stemp);
  } 

  catch (...){
    return;
  }

  switch(v){
    case 0:
      if(realnum == 1 || realnum == 6){
        //cout<<"contador: "<<contador;
        cout<<"A"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 1:
      if(realnum == 2 || realnum == 5){
        //cout<<"contador: "<<contador;
        cout<<"B"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 2:
      if(realnum == 4 || realnum == 6){
        //cout<<"contador: "<<contador;
        cout<<"C"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 3:
      if(realnum == 3 || realnum == 1){
        //cout<<"contador: "<<contador;
        cout<<"D"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 4:
      if(realnum == 3 || realnum == 4){
        //cout<<"contador: "<<contador;
        cout<<"E"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 5:
      if(realnum == 2 || realnum == 6){
        //cout<<"contador: "<<contador;
        cout<<"F"<<"";
        contador++;
        operaciones++;
      }
      return;

    case 6:
      if(realnum == 1 || realnum == 5){
        //cout<<"contador: "<<contador;
        cout<<"G"<<"";
        contador++;
        operaciones++;
      }
      return;
  } 
}

void Graph::Operaciones()
{
  cout<<operaciones<<endl;
}

// Driver code
int main() {

  //input system
  string file;
  cin>>file;
  ifstream inFile;
  inFile.open(file);

  if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
  }

  string num; //variable para el input del txt
  int counter = -1;

  string test; //varible temporal
  while (getline(inFile, test)) { //read and define num
    if(counter == 0) {
      num = test;
      counter++;
    }
    counter++;
  }

  for(int j = 0; j<=num.length()-1;j++){
    char ctemp = num[j];
    string stemp{ctemp};
    int catcher; //variable usada para verificar input correcto
    try {
      catcher = stoi(stemp);
    } 
    catch (...){
      cout<<"Input incorrecto, por favor sólo inputs númericos sin espacios."<<endl;
      abort();
    }
  }


  //contadores
  int veces = 0;
  veces = num.length()/3 + (num.length())%3; //definimos las veces que se ejecuta el método

	//tree
	Graph g;
  g.AddEdge(0, 1);
	g.AddEdge(0, 4);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(4, 5);
	g.AddEdge(4, 6);

  auto start = high_resolution_clock::now();

  for(int i = 0; i <= veces; i++) { //repetición del método
    g.DFS(0, num);
  }
  cout<<" "<<endl;

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout <<"Tiempo: " << duration.count() << " microsegundos" << endl;

  cout<<"Operaciones: "<<"";
  g.Operaciones();
  
	return 0;
}

