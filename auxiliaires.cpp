/*
 * auxiliaire.cpp
 *
 *  Created on: 2016-10-02
 *      Author: etudiant
 */
#include "auxiliaires.h"
#include <fstream>


std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> retour = std::vector<std::string>();

	std::string addv = std::string();

	for(int i = 0; i<s.length(); i++)
	{
		if(s[i] == delim)
		{
			retour.push_back(addv);
			addv = std::string();

		}
		else
		{
			addv+=s[i];
		}


	}
			return retour;

}

void lireFichier(std::string nomFichier, std::vector<std::vector<std::string>>& resultats, char delimiteur, bool rm_entete)
{

	std::ifstream ifs (nomFichier, std::ifstream::in);

	std::string s = std::string();

	while(!ifs.eof())
	{



		char c = ifs.get();
		if(c=='\n')
			{
			if(!rm_entete)
			{
				std::vector<std::string> ligne ;
							ligne = split(s,delimiteur);
							resultats.push_back(ligne);
							s = std::string();

			}
			else
			{
				rm_entete = false;
				s = std::string();
			}


			}
		else
		{
			s+=c;
		}
	}




}


