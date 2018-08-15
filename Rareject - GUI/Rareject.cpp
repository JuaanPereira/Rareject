/*----------------------------------------------------------------------*/
/* - Realizado por: Juan Pablo Pereira Caro & Diego Rodríguez Vicente   */
/* - Clase: 2º DAM - IES TEIS                                           */
/* - Año: 2018                                                          */
/* ---> Proyecto de fin de grado <---                                   */
/*----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool Inyectar(DWORD PID, char *NOMBRE_DLL);

int main() {

	string NOMBRE_DLL;
	int PID, OPCION_ESCOGIDA;

		cout << "|--------------------------------------------------------|\n\n";
		cout << "|    Juan Pablo Pereira Caro y Diego Rodriguez Vicente   |\n\n"; 
		cout << "|                       Rareject v.0.0.1                 |\n\n"; 
		cout << "|--------------------------------------------------------|\n\n";
		cout << "|---------------------MENU PRINCIPAL---------------------|\n\n";
		cout << "|* 1. Inyectar DLL                                       |\n\n";
		cout << "|* 99. Salir                                             |\n\n";
		cout << "|--------------------------------------------------------|\n\n";
		cout << "|-> Introduce la opcion escogida:";
		cin >> OPCION_ESCOGIDA;
		cout << "|                                                        |\n\n";
		cout << "|--------------------------------------------------------|\n\n";
	
		if (OPCION_ESCOGIDA == 1) {

			cout << "- Introduce el PID del programa:";
			cin >> PID;
			cout << "- Introduce el nombre del DLL:";
			cin >> NOMBRE_DLL;

			char ruta[MAX_PATH];
			GetFullPathName(LPCWSTR((NOMBRE_DLL.c_str())), MAX_PATH, LPWSTR(ruta), NULL); 

			Inyectar(PID, ruta);

		}



}

bool Inyectar(DWORD PID, char *NOMBRE_DLL) {
	LPCWSTR library = LPCWSTR("kernel32.dll");

		HANDLE Proceso = OpenProcess(PROCESS_ALL_ACCESS, false, PID); /*Obtenemos y almacenamos en la variable Proceso el "process handle" (valor entero que identifica un proceso en Windows)*/

		while(Proceso){ /* Mientras exista el Proceso... */

			/* Para inyectar una biblioteca dinámica en un proceso utilizaremos la función "LoadLibrary", LoadLibrary carga un módulo especificado
			en el espacio de direcciones del proceso que deseemos, nuestro objetivo es asignar la suficiente memoria en el espacio de direcciones
			del proceso que soporte cargar la ruta de la DLL que queremos inyectar en dicho proceso. */
			LPVOID LoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle(library), "LoadLibraryA");

			/* Asignamos la memoria suficiente en el proceso para poder "soportar" el tamaño total de la ruta donde se encuentre el DLL */
			LPVOID ResMemDLL = VirtualAllocEx(Proceso, NULL, strlen(NOMBRE_DLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			/* Escribimos la ruta del DLL en la memoria del proceso */
			WriteProcessMemory(Proceso, ResMemDLL, NOMBRE_DLL, strlen(NOMBRE_DLL), NULL);
			
			/*  Creamos un hilo remoto el cual empezará en la dirección de memoria del proceso asignada anteriormente, */
			HANDLE HiloRemoto = CreateRemoteThread(Proceso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, ResMemDLL, 0, NULL);
			
			/* Esperamos por el hilo */
			WaitForSingleObject(HiloRemoto, INFINITE);
			
			/* Liberamos la memoria */
			VirtualFreeEx(Proceso, ResMemDLL, strlen(NOMBRE_DLL), MEM_RELEASE); 
			
			/* Cerramos los "handles" (un handle en informática es un tipo de puntero inteligente que hace referencia
			a una región de memoria) */

			CloseHandle(HiloRemoto);
			CloseHandle(Proceso);

			return true;

		}

		/* En caso de que nunca se entre en el while significará que dicho proceso no existe */
		cout << "- El proceso no existe...";
		return false;
}