/*
 * ligne.cpp
 *
 *  Created on: 2016-10-02
 *      Author: etudiant
 */
#include "ligne.h"


Ligne::Ligne(const std::vector<std::string>& ligne_gtfs)
{
	this->m_id = (unsigned int)std::stoul(ligne_gtfs[0], nullptr, 0);
	this->m_numero = ligne_gtfs[2];
	this->m_description = ligne_gtfs[4];

	//route color
	this->m_categorie = couleurToCategorie(ligne_gtfs[7]);
	this->m_voyages = std::vector<Voyage*>();


}



CategorieBus Ligne::couleurToCategorie(std::string couleur)
{
	if(couleur == "97BF0D" )
	{
		return CategorieBus::METRO_BUS;
	}

	if(couleur == "013888" )
		{
			return CategorieBus::LEBUS;
		}

	if(couleur == "E04503”" )
		{
			return CategorieBus::EXPRESS;
		}

	if(couleur == "1A171B" || couleur == "003888")
		{
			return CategorieBus::COUCHE_TARD;
		}

	return CategorieBus::METRO_BUS;

}


std::string Ligne::categorieToString(CategorieBus c)
{
	switch(c)
	{
	case CategorieBus::METRO_BUS:
	return "METRO_BUS";
	break;

	case CategorieBus::LEBUS:
		return "LEBUS";
		break;

	case CategorieBus::EXPRESS:
		return "EXPRESS";
		break;

	case CategorieBus::COUCHE_TARD:
		return "COUCHE_TARD";
		break;

	default:
		return "erreur";
		break;

	}

}

CategorieBus Ligne::getCategorie() const
{
return this->m_categorie;
}

void Ligne::setCategorie(CategorieBus categorie)
{
this->m_categorie = categorie;
}

std::pair<std::string, std::string> Ligne::getDestinations() const
{
return std::pair<std::string, std::string>();
}

unsigned int Ligne::getId() const{
return this->m_id;
}

void Ligne::setId(unsigned int id){
this->m_id = id;
}

const std::string& Ligne::getNumero() const{
return this->m_numero;
}

void Ligne::setNumero(const std::string& numero){
this->m_numero = numero;
}

const std::vector<Voyage*>& Ligne::getVoyages() const{
return m_voyages;
}

void Ligne::setVoyages(const std::vector<Voyage*>& voyages){
this->m_voyages = voyages;
}

void Ligne::addVoyage(Voyage* ptr_voyage){
this->m_voyages.push_back(ptr_voyage);

}

const std::string& Ligne::getDescription() const{
return this->m_description;
}

void Ligne::setDescription(const std::string& description){
this->m_description = description;
}

std::ostream& operator <<(std::ostream& f, const Ligne& p_ligne){
f<< Ligne::categorieToString(p_ligne.m_categorie) + " " + std::to_string(p_ligne.m_id) +" : " + p_ligne.m_description;
return f;
}




