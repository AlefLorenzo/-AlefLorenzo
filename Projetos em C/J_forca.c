#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


void mostra_boneco(int erro) {
	printf(" +-------+\n");
	printf(" |       %c\n", erro >= 1 ? 'O' : ' ');
	printf(" |      %c%c%c\n",
	       erro >= 3 ? '/' : ' ',
	       erro >= 2 ? '|' : ' ',
	       erro >= 4 ? '\\' : ' ');
	printf(" |      %c %c\n",
	       erro >= 5 ? '/' : ' ',
	       erro >= 6 ? '\\' : ' ');
	printf(" |\n");
	printf("_|_\n\n");
}

int main() {
	setlocale(LC_ALL, "pt_PT");
	int vida = 7;
	int tamanho, v = 0;
	char letra, lacuna[20] = {0};
	char *palavras[7] = {
		"pterodartilo",
		"jaguatirica",
		"ornitorrinco",
		"lontra",
		"leopardo",
		"velociraptor",
		"babuino"
	};
	srand(time(NULL));
	int i = rand() % 7;
	char *palavra_da_vez = palavras[i];

	tamanho = strlen(palavra_da_vez);


	while (vida > 0 && v == 0) {
		system("clear");

		printf("Dica: É um animal!\n");


		mostra_boneco(7 - vida);

		printf("Quantidade de letras: %d\n", tamanho);

		for (int i = 0; i < tamanho; i++) {
			if (lacuna[i] == '\0') printf("_ ");
			else printf("%c ", lacuna[i]);
		}

		printf("\n\nDigite a letra: ");
		scanf(" %c", &letra);

		int count = 0;
		for (int i = 0; i < tamanho; i++) {
			if (palavra_da_vez[i] == letra && lacuna[i] != letra) {
				lacuna[i] = letra;
				count++;
			}
		}

		if (count == 0) {
			printf("Letra errada. Tente outra vez.\n");
			vida--;
		} else {
			printf("Parabéns, acertou!\n");
		}

		if (strcmp(palavra_da_vez, lacuna) == 0) {
			v = 1;
		}


		printf("Pressione ENTER para continuar...");
		getchar();
		getchar();
	}

	if (v == 1) {
		printf("\nParabéns! Você venceu com %d vidas restantes.\n", vida);
	} else {
		printf("\nVocê perdeu! A palavra era: %s\n", palavra_da_vez);
	}

	return 0;
}