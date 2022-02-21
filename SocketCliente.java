import java.net.*;
import java.io.*;
import java.util.Scanner;

public class SocketCliente
 {
     /** Programa principal, crea el socket cliente */
     public static void main (String [] args)
     {
         new SocketCliente();
     }
     
   
     public SocketCliente()
     {
         try
         {
           
             Socket socket = new Socket ("localhost", 25557);
             System.out.println ("conectado");

           
             socket.setSoLinger (true, 10);
             
        
             DataInputStream bufferEntrada =
                new DataInputStream (socket.getInputStream());
                
                DataOutputStream bufferSalida =
                new DataOutputStream (socket.getOutputStream());
                
                
             
             
             int Entero;
             String num;
             Scanner sc =new Scanner(System.in);
             do{
                System.out.println("Digitar numero para enviar: ");
                Entero = sc.nextInt();
                num = String.valueOf(Entero);
                DatoSocket aux = new DatoSocket (num);
                aux.writeObject (bufferSalida);

                DatoSocket dato = new DatoSocket("");
                dato.readObject(bufferEntrada);
                System.out.println ("El servidor envia: " + dato.toString());


             }while(Entero!=0);



             socket.close();
         }
         catch (Exception e)
         {
             e.printStackTrace();
         }
     }
}
