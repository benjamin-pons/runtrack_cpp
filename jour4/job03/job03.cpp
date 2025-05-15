#include <stdio.h>
#include <string.h>

void inverser_chaine(char *str) {
    char *debut = str;                
    char *fin = str + strlen(str) - 1;   
    char temp;

    while (debut < fin) {
        temp = *debut;
        *debut = *fin;
        *fin = temp;

        debut++;
        fin--;
    }
}

int main() {
    char chaine[100];

    printf("Entrez une chaîne de caractères : ");
    fgets(chaine, sizeof(chaine), stdin);


    size_t len = strlen(chaine);
    if (len > 0 && chaine[len - 1] == '\n') {
        chaine[len - 1] = '\0';
    }

    inverser_chaine(chaine);

    printf("Chaîne inversée : %s\n", chaine);

    return 0;
}
