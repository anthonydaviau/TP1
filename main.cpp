/*
 * main.cpp
 *
 *  Created on: 2016-10-02
 *      Author: etudiant
 */
#include "auxiliaires.h"
#include "ligne.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


int main()
{
	std::vector<std::vector<std::string>> retour = std::vector<std::vector<std::string>>();
	std::string nomfichier = std::string("routes.txt");
	lireFichier(nomfichier, retour, ',', true);
	//std::vector<std::vector<std::string>> tri = std::vector<std::vector<std::string>>();

	std::ofstream ofs ("test.txt", std::ofstream::out);




	int nbLignes = retour.size();
	ofs << "Chargement des données terminé en" << " 5 "<< "secondes\n" << "======================\n" << "LIGNES DE LA RTC\n"
			<< "COMPTE = " << nbLignes << "\n======================\n";




	for(int i=0; i<retour.size();i++)
	{
		Ligne ligne = Ligne(retour[i]);
		ofs << ligne << std::endl;


	}
ofs.close();




	return 0;
}

