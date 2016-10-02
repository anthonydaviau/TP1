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

	std::ofstream ofs ("test.txt", std::ofstream::out);
	for(int i=0; i<retour.size();i++)
	{
		Ligne ligne = Ligne(retour[i]);
		ofs << ligne << std::endl;


	}
ofs.close();




	return 0;
}

