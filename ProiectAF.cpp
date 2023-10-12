//Generare continut fisier cu format impus

#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Nod{
	int ID;
	char nume[50];
	char prefix[50];
	char sufix[50];
};

struct Nodstyle{
	int ID;
	char nume[50];
	char backgroundcolor[50];
	char color[50];
	char fontsize[50];
	char fontalign[50];
};

int main()
{
	list<struct Nod> Html;
	list<struct Nod> Elemente;
	
	Nod el;
	
		el.ID=1;
		strcpy(el.nume,"html");
		strcpy(el.prefix,"<html>");
		strcpy(el.sufix,"</html>");
		Html.push_back(el);
		
		el.ID=2;
		strcpy(el.nume,"head");
		strcpy(el.prefix,"<head>");
		strcpy(el.sufix,"</head>");
		Html.push_back(el);
		
		el.ID=3;
		strcpy(el.nume,"body");
		strcpy(el.prefix,"<body>");
		strcpy(el.sufix,"</body>");
		Html.push_back(el);
		
		el.ID=4;
		strcpy(el.nume,"style");
		strcpy(el.prefix,"<style>");
		strcpy(el.sufix,"</style>");
		Html.push_back(el);
		
	Nod el2;
		
		el2.ID=1;
		strcpy(el2.nume,"titlu pagina");
		strcpy(el2.prefix,"<title>");
		strcpy(el2.sufix,"</title>");
		Elemente.push_back(el2);
		
		el2.ID=2;
		strcpy(el2.nume,"titlu");
		strcpy(el2.prefix,"<h1>");
		strcpy(el2.sufix,"</h1>");
		Elemente.push_back(el2);
		
		el2.ID=3;
		strcpy(el2.nume,"paragraf");
		strcpy(el2.prefix,"<p>");
		strcpy(el2.sufix,"</p>");
		Elemente.push_back(el2);
		
		
	list<struct Nodstyle> Style;
	
	Nodstyle el3;
	
		el3.ID=1;
		strcpy(el3.nume,"html");
		strcpy(el3.backgroundcolor,"\tbackground-color: ");
		Style.push_back(el3);
		
		el3.ID=2;
		strcpy(el3.nume,"h1");
		strcpy(el3.color,"\tcolor: ");
		strcpy(el3.fontsize,"\tfont-size: ");+
		strcpy(el3.fontalign,"\ttext-align: ");
		Style.push_back(el3);
		
		el3.ID=3;
		strcpy(el3.nume,"p");
		strcpy(el3.color,"\tcolor: ");
		strcpy(el3.fontsize,"\tfont-size: ");
		strcpy(el3.fontalign,"\ttext-align: ");
		Style.push_back(el3);
	
	
	// "Interfata"

	cout << "Pentru a crea fisierul Html apasati tasta enter" << endl;
	cin.ignore();
	
	ofstream MyFile("fisier.html"); //Deschiderea fisierului
	if(!MyFile)
	{
		cout << "Crearea fisierului a esuat!"<< endl;
		return 1;
	}

	std::list<Nod>::iterator it=Html.begin();
	MyFile << (it)->prefix << endl << endl; /// <html>
	
	it++;
	MyFile << (it)->prefix << endl << endl; /// <header>
	
	
	string temp;
	cout << "Introduceti titlul paginii: ";
	getline(cin,temp);
	
	std::list<Nod>::iterator itel=Elemente.begin();
	MyFile << (itel)->prefix << temp << (itel)->sufix << endl << endl;
	
	MyFile << (it)->sufix << endl << endl; /// </header>
	
	it++;
	MyFile << (it)->prefix << endl << endl;  /// <body>


Post:
	itel++;
	cout << "Introduceti headerul: ";
	getline(cin,temp);
	MyFile << (itel)->prefix << temp << (itel)->sufix << endl << endl; // <h1> </h1>
	
	itel++;
Text:
	cout << "Introduceti textul: ";
	getline(cin,temp);
	MyFile << (itel)->prefix << temp << (itel)->sufix << endl << endl; // <p> </p>


	cout << "Doriti sa adaugati un nou text? ";
	getline(cin,temp);
	if(temp=="da")
	{
		goto Text;
	}
		
	cout << "Doriti sa adaugati un noua postare? ";
	getline(cin,temp);
	if(temp=="da")
	{
		itel--;itel--;
		goto Post;
	}


	MyFile << (it)->sufix << endl << endl;  /// </body>
	
	
	std::list<Nodstyle>::iterator itstyle=Style.begin();
	
	it++;
	MyFile << (it)->prefix << endl << endl; /// <style>
	
		cout << "Culoarea de fundal a paginii: ";
		getline(cin,temp);
		MyFile << (itstyle)->nume << "{" << endl;
		MyFile << (itstyle)->backgroundcolor << temp << ";" << endl;
		
	MyFile << "}" << endl << endl;
	
	itstyle++;
		cout << "Culoarea headerului: ";
		getline(cin,temp);
		MyFile << (itstyle)->nume << "{" << endl;
		MyFile << (itstyle)->color << temp << ";" << endl;
		
		cout << "Marimea fontului: ";
		getline(cin,temp);
		MyFile << (itstyle)->fontsize << temp << ";" << endl;
		
		cout << "Alinierea fontului: ";
		getline(cin,temp);
		MyFile << (itstyle)->fontalign << temp << ";" << endl;
	
	MyFile << "}" << endl << endl;
	
	itstyle++;
		cout << "Culoarea textului: ";
		getline(cin,temp);
		MyFile << (itstyle)->nume << "{" << endl;
		MyFile << (itstyle)->color << temp << ";" << endl;
		
		cout << "Marimea fontului: ";
		getline(cin,temp);
		MyFile << (itstyle)->fontsize << temp << ";" << endl;
		
		cout << "Alinierea fontului: ";
		getline(cin,temp);
		MyFile << (itstyle)->fontalign << temp << ";" << endl;
	
	MyFile << "}" << endl << endl;
	
	MyFile << (it)->sufix << endl << endl; /// </style>
	it--;it--;it--;
	MyFile << (it)->sufix;  /// </html>
	
	

	MyFile.close();
	cout << "\nTextul a fost generat in fisier!\n";
	
	
	system("pause");
	return 0;
}

