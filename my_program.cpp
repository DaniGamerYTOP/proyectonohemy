#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
using namespace std;
int main(){
	
	srand(time(0)); // Inicializa la semilla para generar un numero aleatorio
	int N, vidas; // Valores definidos por el docente
	int num=0, rand_num;
	int vMax=0, vMin=0;
	int cant_num=0, cant_primos=0, cant_comp=0, cant_wagstaff=0, cant_sophie=0, cant_mersenne=0;
	float wins=0, cant_num_gen=0; // Cantidad de victorias, Cantidad de numeros generados, float para evitar division de enteros
	int menu; //Variable de seleccion para el menú
	bool win, salir=false; 
	
	setlocale(LC_ALL, "spanish");
	
	// Presentacion
	
	cout<<"El objetivo de este programa es crear una  aplicación que permita despertar el\ninterés de los estudiantes hacia las mátematicas y ayudarlos a aprender. "<<endl;
	cout<<endl<<"Asignatura: Algoritmos y Programación\nGrupo: A1"<<endl<<endl;
	cout<<"Integrantes: "<<endl;
	cout<<"- Breyner Autista"<<endl;
	cout<<"- Lucas Hernandez 0222510011"<<endl;
	cout<<"- Melanie Romero 0222510021"<<endl;
	cout<<"- Daniel Borre 0222510016"<<endl;
	system("pause");
	
	
	for (;;){ //Bucle principal
		
		system("cls");
		cout<<"GAMES PRIME NUMBERS"<<endl<<endl;
		cout<<"\t1. INICIAR JUEGO"<<endl;
		cout<<"\t2. MOSTRAR ESTADISTICAS"<<endl;
		cout<<"\t3. SALIR"<<endl;
		
		do { // Validar la elección
			
		cout<<endl<<"¿Que opción elige?: "; cin>>menu;
		if (menu<1||menu>3) cout<<endl<<"Opción inválida"<<endl;
		
		} while(menu<1||menu>3);
		system("cls");
		switch(menu){
		
			case 1: {
				
				win=false; 
				cout<<"Ingrese el válor máximo del juego: "; cin>>N;
				cout<<"Ingrese el número de vidas: "; cin>>vidas;
				rand_num= 1 + rand() % N; // Asignación número aleatorio
				cant_num_gen++;
				if (rand_num>vMax) vMax=rand_num;
				if (rand_num<vMin||vMin==0) vMin=rand_num;

				for (int i=0; (i<vidas)&&!win; i++){ // Iniciar juego
					system("cls");
					cout<<rand_num<<endl;
					cout<<"Vidas: "<<vidas-i<<endl;
		
					do { // Validar que el número no sobrepase el límite
						cout<<"Ingrese un número entre 1 y "<<N<<": ";
						cin>>num;
					} while(num>N||num<1);
					
					cant_num++; // Incrementar la cantidad de números ingresados
					if (num==rand_num) {
						
						win=true; wins++;
						system("cls");
						cout<<"\n\n\n\n\n\t[ -/-/-/- VICTORIA -/-/-/- ]";
						system("color a7");
						Beep(600, 300);
						Sleep(50);
						Beep(900, 700);
						Sleep(100);
						system("cls");
						system("color 07");
						cout<<"[ -/-/-/- VICTORIA -/-/-/- ]"<<endl<<endl;
						cout<<"Adivinaste el número en "<<i+1; if (i>0) cout<<" intentos"<<endl; else cout<<" intento"<<endl;
						system("pause");
					}
					else {
						system("cls");
						
						if (i<vidas-1){
							cout<<"Número equivocado"<<endl<<endl;
							if (num<rand_num) cout<<"El número es mayor que "<<num<<endl;
							else cout<<"El número es menor que "<<num<<endl;
							system("pause");
						} 
					}
					
				}	
				
				if (!win) { // Derrota
					system("cls");
					system("color c7");
					cout<<"\n\n\n\n\n\t[-/-/-/- Derrota -/-/-/- ]";
					Beep(300, 300);
					Sleep(50);
					Beep(200, 700);
					Sleep(100);
					system("cls");
					system("color 07");
					cout<<"[-/-/-/- Derrota -/-/-/-]"<<endl;
					cout<<"Te quedaste sin vidas ;("<<endl;
					cout<<"El número era "<<rand_num<<endl;
					system("pause");
					
				}
				break;
			} 
		
			case 2:{
				system("cls");
				cout<<"ESTADISTICAS"<<endl<<endl;
				if (cant_num_gen>=1) {  // Validar que haya jugado al menos una vez (que haya generado al menos un numero)
				
					cout<<"- Cantidad de números ingresados: "<<cant_num<<endl;
					cout<<"- Porcentaje de aciertos: "<<fixed<<setprecision(2)<<wins/cant_num*100<<"%"<<endl;
					cout<<"- Valor máximo generado: "<<vMax<<endl;
					cout<<"- Valor mínimo generado: "<<vMin<<endl;
					cout<<"- Cantidad de números primos: "<<cant_primos; 
					
					if(cant_primos!=0) {
						
						cout<<"\t("<<cant_primos/cant_num_gen*100<<"%"<<" del total de números generados)"; 
						cout<<endl<<"- Cantidad de primos de Wagstaff"<<cant_wagstaff<<"\t("<<fixed<<setprecision(2)<<cant_wagstaff/cant_primos*100<<"%"<<" del total de números primos)";
						cout<<endl<<"- Cantidad de primos de Sophie Germain:"<<cant_sophie<<"\t("<<fixed<<setprecision(2)<<cant_sophie/cant_primos*100<<"%"<<" del total de números primos)";
						cout<<endl<<"- Cantidad de primos de Mersenne: "<<cant_mersenne<<"\t("<<fixed<<setprecision(2)<<cant_mersenne/cant_primos*100<<"%"<<" del total de números primos)";
						
					}
					cout<<endl<<"- Cantidad de números compuestos: "<<cant_comp<<endl;
						
				}
				else cout<<"Para ver las estadísticas debe jugar al menos una vez"<<endl;
				system("pause");
				break;
			}
			
			case 3:{
				exit(0);
			}
		
		
		
		} // Fin switch
		
	} // Fin bucle menu
	
		
	
} // Fin main
