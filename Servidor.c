
#include <Socket_Servidor.h>
#include <Socket.h>
#include <string.h>
#include <stdio.h>

main ()
{
	int Socket_Servidor;
	int Socket_Cliente;
        int Aux;
       int Longitud_Cadena;
       int numero;
       char Cadena[100];

	
	Socket_Servidor = Abre_Socket_Inet ("cpp_java");
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket servidor\n");
		exit (-1);
	}

	Socket_Cliente = Acepta_Conexion_Cliente (Socket_Servidor);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket de cliente\n");
		exit (-1);
	}


   Longitud_Cadena = 5;
    strcpy (Cadena, "");
    Aux = htonl (Longitud_Cadena);


    do{

  
    	Lee_Socket (Socket_Cliente, (char *)&Aux, sizeof(Longitud_Cadena));
    	Longitud_Cadena= ntohl(Aux);
	
	
		Lee_Socket(Socket_Cliente,Cadena, Longitud_Cadena);
		numero = atoi(Cadena);

		//Longitud=ntohl(Auxiliar);
		printf("Numero recibido en el servidor: %d\n",numero);

		numero = numero + 1;

		sprintf(Cadena,"%d",numero);
		Escribe_Socket (Socket_Cliente, (char *)&Aux, sizeof(Longitud_Cadena));
		Escribe_Socket(Socket_Cliente, Cadena, Longitud_Cadena);
    	
		

    }while (numero!=0);
    
 
	
	close (Socket_Cliente);
	close (Socket_Servidor);

}
