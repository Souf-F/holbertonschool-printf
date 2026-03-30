# _printf

Recréation de la fonction `printf` de la librairie standard C. Projet réalisé dans le cadre de la formation Holberton School.

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```

## Requirements

- Ubuntu 20.04 LTS
- GCC
- Git
- Style Betty

## Spécificateurs gérés

- `%c` — affiche un caractère
- `%s` — affiche une chaîne (affiche `(null)` si NULL)
- `%%` — affiche un `%` littéral

## Exemple

```c
#include "main.h"

int main(void)
{
    _printf("Hello %s\n", "world");
    _printf("Char: %c\n", 'A');
    _printf("Percent: %%\n");
    return (0);
}
```

```
Hello world
Char: A
Percent: %
```

## Man page

```bash
man ./man_3_printf
```

## Testing

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o printf_test
./printf_test
```

Vérifier les fuites mémoire :

```bash
valgrind --leak-check=full --track-origins=yes ./printf_test
```

## Flowchart

```mermaid
---
config:
  theme: neutral
  look: classic
---
flowchart TB
    A["Appel de _printf()"] --> B["Lire la chaîne de format"]
    B --> C{"Caractère suivant ?"}
    C -- Caractère normal --> D["Afficher tel quel"]
    C -- % trouvé --> E{"Caractère après le % ?"}
    C -- Fin de chaîne --> H["Écrire dans stdout"]
    E -- %% --> D2["Afficher un seul %"]
    E -- %c --> G4["Insérer le caractère"]
    E -- %s --> G2["Insérer la chaîne"]
    D2 --> B
    G4 --> D3["Ajouter au résultat"]
    G2 --> D3
    D --> B
    D3 --> B
    H --> I["Retourner le nombre de caractères affichés"]
```

## Fichiers

- `_printf.c` — fonction principale
- `print_char.c` — gère `%c`
- `print_string.c` — gère `%s`
- `main.h` — prototypes

## Auteur

Voir le fichier `AUTHORS`.