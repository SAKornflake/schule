/*---------------------------------------------
Autor: FZ
Programmanme: string_2
Version:3--final??
---------------------------------------------*/

#include "stdafx.h"
#include "iostream"
#include "string"


using namespace std;

																								            	              /*the string i am working with*/
	string Z;


void define(void)																					
	{
		Z = "cn=a106_p02,ou=A106,ou=Arbeitsstationen,ou=Ressourcen,ou=TS,ou=SCHULEN,o=ml3;IP: 192.168.228.1;MAC: 00-50-56-c0-00-01;IP: 192.168.112.1;MAC: 00-50-56-c0-00-08;IP: 10.1.106.2;MAC: c8-60-00-c7-06-cb;GUID: c7b8c3285f43f444b7be9d7637d594d5;";
		return;
	}

void pc_name(void)																			                 		/*function to search the name of the pc*/
	{
		int name = 0;
		name = Z.find("cn=");																	                	/*find the part of the string containing the name of the pc*/
		Z.erase(name, 3);																			                  /*delete all unnneedet information*/
		Z.erase(8);
		cout << "Der Pc hat den Namen: \t  \t "<< Z << endl;										/*output the name of the pc*/
		return;
	}

void pc_room(void)																					                /*function to find the pc room*/
	{
		int room = 0;
		room = Z.find("ou=");																		                /*find the part of the string containing the room of the pc*/
		room = room + 3;
		Z.erase(0, room);																			                  /*erase all unneedet information*/
		Z.erase(4);
		cout << "Der Pc steht in dem Raum: \t " << Z << endl;										/*output the room name*/
	}

void ip(void)																						                    /*function to find the ip beginning with 10*/
	{

		int ip = 0;
		for (int i = 0; i < 5; i++)																	            /*find the 4th ";" because after it there is the needet ip*/
		{
			ip = Z.find(";", ip);
			ip = ip + 1;  

		}
		ip = ip + 4;																			                    	/*deleate all unneedet information*/
		Z.erase(0, ip);
		Z.erase(10);
		cout << "Der Pc hat die IP: \t \t " << Z << endl;										  	/*output the ip*/
	}

void mac(void)																					                  	/*function to find the mac associated to the ip beginning with 10*/
	{
		int mac = 0;
		for (int i = 0; i < 5; i++)																            	/*find the ip, same as in void ip(void), only the name of the variable is different*/
		{
			mac = Z.find(";", mac);
			mac = mac + 1;

		}

		mac = mac + 20;																			                	  /*find the mac associated to the ip*/
		Z.erase(0, mac);																			                  /*delete all unneedet information*/
		Z.erase(17);
		cout << "Der Pc hat die Mac: \t \t " << Z << endl;											/*output the mac*/
		
	}

void corrected_mac(void)																			              /*function to get the correct ip*/
	{
		int mac = 0;																				                    /*same as the function above......*/
		for (int i = 0; i < 5; i++)		
		{
			mac = Z.find(";", mac);
			mac = mac + 1;

		}
		mac = mac + 20;		
		Z.erase(0, mac);
		Z.erase(17);
		
		Z.replace(2, 1, ":");																		                /*replace al " - " to ":" */
		Z.replace(5, 1, ":");
		Z.replace(8, 1, ":");
		Z.replace(11, 1, ":");
		cout << "Die korrigierte MAC lautet: \t " << Z << endl << endl;				  /*output the corrected mac adress*/
	}


int main()
	{

		define();
		cout << "Folgender String wurde bearbeitet:  " << endl << endl<<  Z << endl << endl << endl;			/*output whole string*/
		cout << "Erstes Komma: \t \t \t " << Z.find(",") <<endl;												
		cout << "Zweites Komma: \t \t \t " << Z.find(",", 15) << endl;											
		cout << "IP Adresse beginnend mit 10: \t " << Z.find("IP: 10") << endl;							
		cout << "MAC fuer IP beginnend mit 10: \t " << Z.find("IP: 10") + 15 << endl << endl;						
		pc_name();
		define();
		pc_room();
		define();
		ip();
		define();
		mac();
		define();
		corrected_mac();
		system("PAUSE");
		return 0;
	}
