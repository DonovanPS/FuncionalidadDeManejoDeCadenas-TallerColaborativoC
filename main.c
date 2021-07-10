#include <stdio.h>

int main() {

    int op=0;
    char *mainmenu = "\n>>>MENU PRINCIPAL<<<\n"
                     "1. Convertir en nombre propio\n"
                     "2. N%cmero de veces que existe una palabra \n"
                     "3. Encriptar \n"
                     "4. Desencriptar \n"
                     "5. Agregar caracteres por <- %c ->\n"
                     "6. Borrar caracteres\n"
                     "7. Intersecci%cn\n"
                     "8. Diferencia entre dos cadenas\n"
                     "9. Borrar caracteres <- %c ->\n"
                     "10.Validar correo electr%cnico\n"
                     "11.Salir \n" ;

    while (op!= 11){
        printf(mainmenu,163,162,162,162,162);
        scanf("%i",& op);
        fflush(stdin);

        switch (op) {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            case 11:
                printf("\nGracias por usar nuestro software\n");
                break;

            default:
                printf("\nError digite un numero entre 1 y 11 \n");
                break;
        }
    }

    return 0;
}
