#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
ifstream f ("input.txt");
ifstream g ("input.txt");




class Matrice {
protected:
    int count=0;
public:
    int mat[100][100];
    int n; //noduri
    Matrice(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    }
    ~Matrice(){
    delete mat;
    }

};

class Vector {
protected:
    int* v[100];
    int dim;
public:
    Vector(int* v, int dim){
    for(int i=0;i<dim;i++)
        v[i]=0;
    }
    ~Vector(){
    dim=0;
    }

};

class Lista {
protected:

    int n;
public:
    vector<int> lis[100];
    Lista(){
    n=0;
    }
};




class Graf{
protected:
    int n;//nr de noduri
    int t[100];
    int r[100][100];
public:
    Graf(){};
    virtual ~Graf() { };
    virtual void addEdge(int u, int v){};


};

class Graf_Neorientat : public Graf{
protected:

public:
    Lista L;

    void addEdge(int u, int v)
{
    L.lis[u].push_back(v);
    L.lis[v].push_back(u);
}

friend void operator>>(istream& input, Graf_Neorientat& A)
{
    input>>A.n;
    int x,y;
    while(input){
        input>>x;
        input>>y;
        A.addEdge(x,y);
    }
}
friend void operator<<(ostream& output, Graf_Neorientat A){
    for (int v = 0; v < A.n; ++v)
    {
        cout << "\n Lista adiacenta a nodului "
             << v << "\n nod ";
        for (auto x : A.L.lis[v])
           cout << "-> " << x;
        printf("\n");
    }
}


};

class Graf_Orientat : public Graf{
public:
    Matrice M;

    void addEdge(int u, int v)
{
    M.mat[v][u]=1;
    M.mat[u][v]=1; ///
}

    friend void operator>>(istream& input, Graf_Orientat& A)
    {
	input >> A.n;

	int x,y;
	while(input){
        input>>x;
        input>>y;
        A.addEdge(x,y);
	}

}
friend void operator<<(ostream& output, Graf_Orientat A){
   int i, j;
   cout<<"\n";
   cout<<"Matricea de adiacenta este: "<<endl;
   for(i = 0; i < A.n; i++) {
      for(j = 0; j < A.n; j++) {
         cout << A.M.mat[i][j] << " ";
      }
      cout << endl;
   }
}

void vectorDeTati(int x,int y){
    int k,j=0;
    k=x;
    cout<<"vector de tati: ";
    while(k!=y){
        for(int p=0;p<5;p++){
            if(M.mat[k][p]==1){
                cout<<p<<" ";
                k==p;
                break;
            }
        }
    }

}
};



int main(){
    Graf_Neorientat ob;
    f>>ob;
    cout<<ob;
    Graf_Orientat ob2;
    g>>ob2;
    cout<<ob2;

    f.close();
    g.close();
}
