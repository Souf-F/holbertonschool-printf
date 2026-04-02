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
- `%d` — affiche un entier décimal
- `%i` — affiche un entier (identique à %d)
- `%%` — affiche un `%` littéral

## Exemple

```c
#include "main.h"

int main(void)
{
    _printf("Hello %s\n", "world");
    _printf("Char: %c\n", 'A');
    _printf("Number: %d\n", 42);
    _printf("Negative: %i\n", -7);
    _printf("Percent: %%\n");
    return (0);
}
```

```
Hello world
Char: A
Number: 42
Negative: -7
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
---
config:
  theme: neutral
  look: classic
  layout: dagre
---
flowchart TB
    B["va_start"] --> C["index = 0, count = 0"]
    C --> D@{ label: "format[index] == '\\0' ?" }
    D -- Oui → fin --> END1["va_end"]
    END1 --> END2["return (-1)"]
    D -- Non → on continue --> E@{ label: "format[index] == '%' ?" }
    E -- Non --> F["write(format[index])"]
    F --> G["count++, index++"]
    G --> D
    E -- Oui --> H{"Que vaut format[index + 1] ?"}
    H -- %% --> I1@{ label: "write '%'" }
    H -- %c --> I2["print_char(va_arg)"]
    H -- %s --> I3["print_string(va_arg)"]
    H -- %d / %i --> I4["print_int(va_arg)"]
    I1 --> J["count += retour"]
    I2 --> J
    I3 --> J
    I4 --> J
    J --> K["index += 2"]
    K --> D

    D@{ shape: diamond}
    E@{ shape: diamond}
    I1@{ shape: rect}
## Fichiers

- `_printf.c` — fonction principale
- `print_char.c` — gère `%c`
- `print_string.c` — gère `%s`
- `print_int.c` — gère `%d` et `%i`
- `main.h` — prototypes

## Auteur

[Soufiane FILALI](https://github.com/Souf-F) — Voir le fichier [AUTHORS](AUTHOR.txt) pour plus de détails.