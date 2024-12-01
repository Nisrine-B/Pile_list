// Pile_list.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Header.h"
#include "PileL.h"

int main()
{
	locale::global(locale("fr_FR.UTF-8"));

	//création de la 1ère pile d'entiers
	PileL<int> pile_entiers1;

	cout << PINK << "\n-Alimentation de la pile\n" << RESET;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 4; ++i) {
		int randomValue = rand() % 100;
		pile_entiers1.push(randomValue);
		cout << "Ajouté : " << randomValue;
		Rl;
	}
	Rl;

	//size
	cout << "La 1ère pile contient : " << pile_entiers1.size() << " éléments.\n";

	cout << PINK << "-Affichage de Pile 1\n" << RESET;
	pile_entiers1.print();
	Rl;

	//création d'une 2ème pile
	PileL<int> pile_entiers2;
	cout << GREEN << "*On crée la 2ème pile.\n*Elle est encore vide, on va essayer de la dépiler.\n" << RESET;
	pile_entiers2.pop();
	Rl;

	//inverser la pile 1 dans la pile 2
	cout << PINK << "-On inverse la 1ère pile dans la 2ème et on affiche cette dernière.\n" << RESET;
	pile_entiers2 = pile_entiers1.reverse();
	pile_entiers2.print();
	Rl;

	cout << PINK << "-On dépile la 2ème pile.\n" << RESET;
	cout << "Elément dépilé est " << pile_entiers2.pop(); Rl; Rl;
	cout << PINK << "-Après dépilement\n" << RESET;
	pile_entiers2.print();
	Rl;

	cout << "\n\n\n****************************************Fin Programme ************************************************\n\n";
	return 0;
}
