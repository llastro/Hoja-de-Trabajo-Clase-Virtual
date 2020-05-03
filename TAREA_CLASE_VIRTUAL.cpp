

#include <iostream>

#include <string>

#include <iomanip>

using namespace std;


struct empl{

  int codigo;

  string nombre;

  string puesto;

  int departamento;

  float salario;

};


void pausar_pantalla(){

     

    string empty;

    cout << "\nPresione "ENTER" para continuar:  \n";

    getline(cin,empty);

};


int main() {

  int n=5;

  

 

  float *total, var=0.0;

  total = &var;


  empl *empleado; 

  empleado= new empl[n]; 

  

  string *departamento=NULL; 


  string depa[]={"Gerencia","Administración","Producción"};

  

  departamento=depa; 

  


  for (int i=0; i<n; i++){

    cout << "Ingrese Codigo del empleado a buscar:  (" <<i+1<< "): ";

    cin >> empleado[i].codigo;


    cout << "Ingrese Nombre del empleado a buscar:  (" <<i+1<< "): ";

    cin.ignore(200, '\n');

    getline(cin, empleado[i].nombre);


    cout << "Ingrese Puesto del empleado seleccionado:  (" <<i+1<< "): ";

    getline(cin, empleado[i].puesto);


    int var1=0;

    bool centinela=false;

    while (centinela==false){

      cout << "Ingrese el departamento del empleado:  (" <<i+1<< ")" << "\n";

      for (int ii=0; ii<3; ii++){

        cout << "'"<< ii+1 <<"' " << departamento[ii] <<"  ";

      }

      cout << ": ";


      cin >> var1;

      var1=var1-1;

      if (var1>=0 and var1<=2){

        empleado[i].departamento=var1;

        centinela=true;

      } else {

        cout << "El ingreso es invalido... \n El ingreso es invalido ...." << endl;

        centinela=false;

      }

    }

    cout << "Ingrese Salario del empleado asignado: (" <<i+1<< "): ";

    cin >> empleado[i].salario;

    

    *total+=empleado[i].salario;


    limpiar_pantalla();

  }


  cout << "----- Planilla ------" << endl;

    cout << "|"<< "\t"<<"Código"<<setw(5);

    cout << "|"<< "\t"<<"Nombre"<<setw(5);

    cout << "|"<< "\t"<<"Puesto"<<setw(5);

    cout << "|"<< "\t"<<"Departamento"<<setw(5);

    cout << "|"<< "\t"<<"Salario"<<setw(5)<<"|"<<"\n";

    cout << "____________"<< "\n";


  for (int i=0; i<n; i++){

    cout <<"\t"<<empleado[i].codigo<<setw(8);

    cout <<"\t"<<empleado[i].nombre<<setw(6);

    cout <<"\t"<<empleado[i].puesto<<setw(8);

    cout <<"\t"<<departamento[empleado[i].departamento]<<setw(5);

    cout << "\t"<<empleado[i].salario<<setw(5)<<"\n";

  }

  

  cout <<"\n \n Planilla a Liquidar es: " << *total << "\n";


