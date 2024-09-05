#include <iostream>

using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
};

//nodo *p, *l, *puntero;
//nodo var1, var2;

typedef struct nodo *TpLista; 

 TpLista crearNodo(){
     	TpLista nuevo=NULL;
     	//nodo *nuevo=NULL;
     	nuevo= new(struct nodo);
     	cout<<"Ingresar valor ---> ";
		cin>>nuevo->nro;
		cout<<endl;
		nuevo->sgte =NULL;
		return nuevo;
	 }

void MostrarLista(TpLista lista){

	int i=0;
	TpLista t=lista;
	while(t != NULL){
		cout<<i+1<<") "<<t->nro<<endl;
		t=t->sgte;
		i++;
	}
	
}

void InsertaInicio(TpLista &lista){
	TpLista n=NULL;
	n= crearNodo();
	if(lista != NULL)
		n->sgte = lista;
	lista=n;
}

void InsertaFinal(TpLista &lista){
	TpLista n=NULL, t=lista;
	n= crearNodo();
	
	if(lista == NULL)
		lista=n;
	else{
		while(t->sgte != NULL)
			t=t->sgte;
		t->sgte = n;	
		
	}
	
}

void InsertaPosicion(TpLista &lista, short pos){
	
	TpLista t=lista, n=NULL, q=NULL;
	int x=1;
	bool flag=false;
	if(pos ==1){
		InsertaInicio(lista);
		return;
	}
	
	n=crearNodo();
	
	while(x!=pos && t->sgte != NULL){
		q=t;// reservando la direccion de memoria del anterior nodo
		t=t->sgte;// pasa al siguiente nodo
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag ==true){
		q->sgte = n;
		n->sgte = t;
	}
	else{
		cout<<"\n\t ERROR: posicion "<<pos<<" Esta fuera de rango"<<endl;
		system("pause");
	}

}

void EliminarInicio(TpLista &lista){
	TpLista t=lista;
	lista=lista->sgte;
	cout<<"\nNodo eliminado es "<<t->nro<<endl;
	delete(t);	
}

void EliminarFinal(TpLista &lista){
	TpLista t=lista, q=NULL;
	if(lista->sgte==NULL){
		lista=NULL;
		cout<<"\nNodo eliminado es "<<t->nro<<endl;
		delete(t);
		return;
	}
	
	
	while(t->sgte != NULL){
		q=t;
		t=t->sgte;
	}
	q->sgte = NULL;
	cout<<"\nNodo eliminado es "<<t->nro<<endl;
	delete(t);	
}




void menu(){
	system("CLS");
	cout<<"\t\nLISTA SIMPLEMENTE ENLAZADA"<<endl<<endl;
	cout<<"1.- Insertar al Inicio"<<endl;
	cout<<"2.- Insertar al Final"<<endl;
	cout<<"3.- Insertar por posicion"<<endl;
	cout<<"4.- Mostrar Lista"<<endl<<endl;
	cout<<"5.- Eliminar primer nodo"<<endl;
	cout<<"6.- Eliminar ultimo nodo"<<endl;
	cout<<"7.- Eliminar por Posicion"<<endl;
	cout<<"8.- Buscar y Reemplazar valor de un nodo"<<endl<<endl;
	cout<<"0.- Salir del menu"<<endl<<endl;
	cout<<" Ingresar opcion ---> ";
}


int main(){
	char opc=' ';
	TpLista lista=NULL;
	//nodo *lista=NULL;
	short pos;
	do{
		menu();
		cin>>opc;
		switch(opc){
			case '1':{
				InsertaInicio(lista);
				break;
				}				
			case '2':{
				InsertaFinal(lista);
				break;
			}
			case '3':{
				if(lista==NULL){
					cout<<"No permite esta opcion, lista esta vacia"<<endl;
				}
				else{
					cout<<"Ingresar Posicion --> ";
					cin>>pos;
					InsertaPosicion(lista, pos);
				}
			
				break;
			}
			case '4':{
				MostrarLista(lista);
				break;
			}
			case '5':{
				EliminarInicio(lista);
				break;
			}
			case '6':{
				EliminarFinal(lista);
				break;
			}
			case '7':{
				cout<<"Opcion 4"<<endl;
				break;
			}
			case '8':{
				cout<<"Opcion 4"<<endl;
				break;
			}			
			
			
			
			default:
				cout<<"Opcion elegida No existe..."<<endl;
		}
		system("pause");
		
	}while(opc != '0');
	
}