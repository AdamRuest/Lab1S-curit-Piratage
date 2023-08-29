#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	// Vuln�rabilit�: Nombre d'argument non v�rifi�, peux y avoir plus our moins assez d'argument
	// Exploit: Crash le programme
	// Correction: Confirmer le nombre d'argument
	if (argv.count() != 5)
	{
		// Vuln�rabilit�: Argument 0 non-utilis�
		// Exploit: Peut faire passer des un overflow dans cet argument
		// Correction: Ajuster les index 
		// 
		// Vuln�rabilit�: Format de argv non v�rifi�
		// Exploit: Crash le programmer
		// Correction: try catch
		try
		{
			int pansDeCloture{ stoi(argv[0]) };
			float montantAPayer{ stof(argv[1]) };
		
			float coutParPan{ montantAPayer / pansDeCloture };
			
			// Poteaux n�cessaires pour faire une cl�ture en ligne droite
			// Vuln�rabilit�: Utilisation de m�moire inutile
			// Exploit: Injecter des donn�es en m�moire
			// Correction: Enlever la variable inutile

			// Vuln�rabilit�: Nom de fichier limit�
			// Exploit: Crash le programme
			// Correction: Utilis� un string
			string nomFichier = argv[2] + ".exe";
			// Vuln�rabilit�: Utilisation de fonction inutile
			// Exploit: Injecter des donn�es en m�moire
			// Correction: D�clarer la variable directement

			ofstream fichier{ nomFichier };
			// Vuln�rabilit�: Aucun check de l'Existance du fichier
			// Exploit: Crash le programme
			// Correction: Ajouter un check voir si il est ouvert
			if (fichier.is_open)
			{
				fichier << argv[3];
			}

			// Vuln�rabilit�: Print un argument directement � la console
			// Exploit: Faire passer des commande
			// Correction: Ne pas le mettre en premier argument
			const char* msg{ argv[3] };
			printf(pansDeCloture, coutParPan, msg);

			// Vuln�rabilit�: Faire passer une commande console en argument
			// Exploit: Faire passer une commande malveillante
			// Correction: Honn�tement, aucune id�e
			const char* commande{ argv[4] };
			system(commande);
		}
		catch (invalid_argument)
		{
			cout << "Le format de certains param�tres est invalide"
		}
	}
}