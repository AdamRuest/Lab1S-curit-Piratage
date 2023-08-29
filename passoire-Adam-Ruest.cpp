#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	// Vulnérabilité: Nombre d'argument non vérifié, peux y avoir plus our moins assez d'argument
	// Exploit: Crash le programme
	// Correction: Confirmer le nombre d'argument
	if (argv.count() != 5)
	{
		// Vulnérabilité: Argument 0 non-utilisé
		// Exploit: Peut faire passer des un overflow dans cet argument
		// Correction: Ajuster les index 
		// 
		// Vulnérabilité: Format de argv non vérifié
		// Exploit: Crash le programmer
		// Correction: try catch
		try
		{
			int pansDeCloture{ stoi(argv[0]) };
			float montantAPayer{ stof(argv[1]) };
		
			float coutParPan{ montantAPayer / pansDeCloture };
			
			// Poteaux nécessaires pour faire une clôture en ligne droite
			// Vulnérabilité: Utilisation de mémoire inutile
			// Exploit: Injecter des données en mémoire
			// Correction: Enlever la variable inutile

			// Vulnérabilité: Nom de fichier limité
			// Exploit: Crash le programme
			// Correction: Utilisé un string
			string nomFichier = argv[2] + ".exe";
			// Vulnérabilité: Utilisation de fonction inutile
			// Exploit: Injecter des données en mémoire
			// Correction: Déclarer la variable directement

			ofstream fichier{ nomFichier };
			// Vulnérabilité: Aucun check de l'Existance du fichier
			// Exploit: Crash le programme
			// Correction: Ajouter un check voir si il est ouvert
			if (fichier.is_open)
			{
				fichier << argv[3];
			}

			// Vulnérabilité: Print un argument directement à la console
			// Exploit: Faire passer des commande
			// Correction: Ne pas le mettre en premier argument
			const char* msg{ argv[3] };
			printf(pansDeCloture, coutParPan, msg);

			// Vulnérabilité: Faire passer une commande console en argument
			// Exploit: Faire passer une commande malveillante
			// Correction: Honnêtement, aucune idée
			const char* commande{ argv[4] };
			system(commande);
		}
		catch (invalid_argument)
		{
			cout << "Le format de certains paramètres est invalide"
		}
	}
}