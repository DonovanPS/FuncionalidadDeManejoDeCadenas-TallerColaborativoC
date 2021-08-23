

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>


char *convertirNombrePropio(char cadena1[]) {
    char cadenaNomPropio[255];
    int aux = 0, auxi = 0;
    char *cadenaPropio = "";


    for (int i = 0; cadena1[i] != '\0'; ++i) {
        auxi++;
        if (aux == i) {
            cadenaNomPropio[i] = toupper(cadena1[i]);
        } else {
            if (cadena1[i] == ' ') {
                aux = i + 1;
                cadenaNomPropio[i] = cadena1[i];
            } else {
                cadenaNomPropio[i] = cadena1[i];
            }
        }
    }
    cadenaNomPropio[auxi] = '\0';
    memset(cadena1, 0, 250);

    cadenaPropio = cadenaNomPropio;

    return cadenaPropio;

}


int numVecesPalabra(char cadena2[], char palabraComparar[]) {
    int tamano, contador = 0, aux2 = 0;


    char cadenaAux[50];

    tamano = strlen(cadena2);

    cadena2[tamano] = ' ';
    cadena2[tamano + 1] = '\0';

    for (int i = 0; cadena2[i] != '\0'; ++i) {
        if (cadena2[i] == ' ') {
            cadenaAux[aux2] = '\0';
            aux2 = 0;

            if (strcmp(palabraComparar, cadenaAux) == 0) {
                contador++;
            }
            memset(cadenaAux, 0, 50);
        } else {
            cadenaAux[aux2] = cadena2[i];
            aux2++;
        }
    }

    return contador;
}


char *encriptar(char cadena3[]) {
    char *cadenaEncriptada = "";
    int tamano3;
    tamano3 = strlen(cadena3);
    for (int i = 0; i < tamano3; ++i) {

        if (cadena3[i] == toupper(cadena3[i])) {

            *(cadena3 + i) = tolower(*(cadena3 + i));
        } else {
            *(cadena3 + i) = toupper(*(cadena3 + i));
        }
        //descarta los digitos
        if (isalpha(*(cadena3 + i))) {
            //verifica los casos especiales X-Y-Z
            if ((*(cadena3 + i) > 87 && *(cadena3 + i) < 91) || (*(cadena3 + i) > 119)) {
                *(cadena3 + i) = *(cadena3 + i) - 23;
            } else {
                *(cadena3 + i) = *(cadena3 + i) + 3;
            }
        }
    }
    cadenaEncriptada = cadena3;
    return cadenaEncriptada;
}


char *desencriptar(char cadena4[]) {
    char *cadenaDesencriptada = "";
    int tamano4;

    tamano4 = strlen(cadena4);

    for (int i = 0; i < tamano4; ++i) {

        if (cadena4[i] == toupper(cadena4[i])) {
            *(cadena4 + i) = tolower(*(cadena4 + i));
        } else {
            *(cadena4 + i) = toupper(*(cadena4 + i));
        }

        if (isalpha(*(cadena4 + i))) {
            if (*(cadena4 + i) < 68 || (*(cadena4 + i) > 96 && *(cadena4 + i) < 100)) {
                *(cadena4 + i) = *(cadena4 + i) + 23;
            } else {
                *(cadena4 + i) = *(cadena4 + i) - 3;
            }
        }
    }

    cadenaDesencriptada = cadena4;
    return cadenaDesencriptada;
}


char *llenarCaracteres(char fuente1[], char fuente2[], int cant, int dire) {

    char aux[255], retor[255];
    char *retorno = "";
    for (int i = 0; i < cant; ++i) {
        aux[i] = fuente2[0];
    }

    if (dire == 1) {
        strcat(strcpy(retor, aux), fuente1);
    }
    if (dire == 2) {
        strcat(strcpy(retor, fuente1), aux);
    }
    retorno = retor;
    return retorno;
}

void *eliminarCaracteres(char cadena[255], char caracter[1]) {

    int indCadena = 0, indCadL = 0;
    int agregarCaracteer = 1;
    char *retorno = "";
    while (cadena[indCadena]) {
        agregarCaracteer = 1;
        int indCaracter = 0;
        while (caracter[indCaracter]) {

            if (cadena[indCadena] == toupper(caracter[indCaracter]) ||
                cadena[indCadena] == tolower(caracter[indCaracter])) {
                agregarCaracteer = 0;
            }
            indCaracter++;
        }
        if (agregarCaracteer) {
            cadena[indCadL] = cadena[indCadena];
            indCadL++;
        }
        indCadena++;
    }
    cadena[indCadL] = 0;

    retorno = cadena;
    return retorno;

}


char *interseccion(char cadena[], char cadena2[]) {
    int tamano1, tamano2, cont = 0, contador = 0;
    char aux[255], aux2[255];
    char *cadenaSalida = "";

    tamano2 = strlen(cadena2);
    for (int i = tamano2 - 1; i >= 0; --i) {
        for (int j = 0; j < tamano2 - 1; ++j) {
            if (cadena2[i] == cadena2[j]) {
                cont++;
            }
        }
        if (cont > 1) {
            memset(aux, 0, 255);
            memset(aux2, 0, 255);

            for (int j = i + 1; j < tamano2 - 1; ++j) {
                aux[contador] = cadena2[j];
                contador++;
            }
            contador = 0;
            for (int j = 0; j < i; ++j) {
                aux2[j] = cadena2[j];
            }
            memset(cadena2, 0, 255);
            strcat(strcpy(cadena2, aux2), aux);

            tamano2 = strlen(cadena2);
        }
        cont = 0;
    }

    tamano1 = strlen(cadena);
    tamano2 = strlen(cadena2);
    memset(aux, 0, 255);
    cont = 0;
    contador = 0;
    for (int i = 0; i < tamano2; ++i) {
        for (int j = 0; j < tamano1; ++j) {
            if (cadena2[i] == cadena[j]) {
                cont++;
            }
        }
        if (cont > 0) {
            aux[contador] = cadena2[i];
            contador++;
            cont = 0;
        }
    }

    cadenaSalida = aux;
    return cadenaSalida;
}

void diferenciaCadenas(char cadena1[], char cadena2[]) {
    int sizeCadena1 = strlen(cadena1);
    int sizeCadena2 = strlen(cadena2);
    int index = 0;
    char resultado[255];
    int same;
    for (int i = 0; i < sizeCadena1; i++) {
        same = 0;
        for (int j = 0; j < sizeCadena2; j++) {
            if (cadena1[i] == cadena2[j] && (cadena1[i] != '\n' || cadena2[j] != '\n')) {
                same = 0;
                break;
            } else same = 1;
        }
        if (same == 1) {
            resultado[index] = cadena1[i];
            index++;
        }
    }

    printf("%s \n", resultado);
}

void borrarCaracteres(char cadena1[], char cadena2[], int direccion) {
    int sizeCadena1 = strlen(cadena1);
    int sizeCadena2 = strlen(cadena2);
    int index = 0;
    char resultadoIzquierda;
    char resultadoDerecha[255];

    if (direccion == 1) { // Por izquierda
        for (int i = 0; i < sizeCadena1; i++) {
            int same = 0;
            for (int j = 0; j < sizeCadena2; j++) {
                if (cadena1[i] == cadena2[j]) {
                    same = 1;
                    break;
                } else same = 0;
            }

            if (same == 1) index++;
            else break;
        }
        printf("%s", &cadena1[index]);
    } else { // Por derecha
        index = sizeCadena1;
        for (int i = sizeCadena1 - 1; i >= 0; i--) {
            int same = 0;
            for (int j = 0; j < sizeCadena2; j++) {
                if (cadena1[i] == cadena2[j]) {
                    same = 1;
                    break;
                } else same = 0;
            }

            if (same == 1) index--;
            else break;
        }
        for (int i = 0; i < index; i++) {
            resultadoDerecha[i] = cadena1[i];
        }

        printf("%s", resultadoDerecha);
    }

}

int isValidEmail(char email[]) {
    return strchr(email, '@') && strchr(email, '.');
}

int main() {

    int op = 0;
    char *mainmenu = "\n      >>>MENU PRINCIPAL<<<\n"
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
                     "11.Salir \n";

    while (op != 11) {
        printf(mainmenu, 163, 162, 162, 162, 162);
        scanf("%i", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                //Convertir en nombre propio
                printf("\n>>Convertir en nombre propio<<");

                char cadena[255];

                printf("\nDigite la cadena de texto...");

                fgets(cadena, 255, stdin);

                char *resultado1 = convertirNombrePropio((cadena));

                printf("%s \n", resultado1);

                printf("\nPresione una tecla para continuar . . .");
                getchar();

                break;

            case 2:
                //Número de veces que existe una palabra

                printf("\n>>N%cmero de veces que existe una palabra<<", 163);
                char caden2[255], palabraComparar[50];
                printf("\nDigite la cadena de texto...");
                gets(caden2);


                printf("Digite la palabra a buscar...");
                gets(palabraComparar);
                fflush(stdin);

                int *contador = (int *) numVecesPalabra(caden2, palabraComparar);
                printf("\nla palabra %s se repite %i ves%s \n", palabraComparar, contador,
                       (int) contador > 1 ? "es" : "");
                printf("\nPresione una tecla para continuar . . .");
                getchar();


                break;

            case 3:
                //Encriptar

                printf("\n>>Encriptar<<");
                char cadena3[255];

                printf("\nDigite la cadena de texto a encpriptar...");
                gets(cadena3);

                char *cadenaEncriptada = encriptar((cadena3));

                printf("\nLa frase encriptada es: %s\n", cadenaEncriptada);
                printf("\nPresione una tecla para continuar . . .");
                getchar();
                break;

            case 4:
                //Desencriptar

                printf("\n>>Desencriptar<<");
                char cadena4[255];
                printf("\nDigite la cadena de texto a desencpriptar...");
                gets(cadena4);

                char *cadenaDesencriptada = desencriptar(cadena4);

                printf("\nLa frase desencriptada es: %s \n", cadenaDesencriptada);
                printf("\nPresione una tecla para continuar . . .");
                getchar();
                break;

            case 5:


                //Agregar caracteres por <- ó ->

                printf("\n>>Llenar Caracteres<<");
                char cadena5[255], letras[55];
                int cantidad = 0, direccion = 0;
                printf("\n Ingrese la cadena de texto...");
                gets(cadena5);
                printf("\n Ingrese el caracter a insertar...");
                scanf("%c", &letras);
                printf("\n Ingrese direccion 1. Izquierda  2. Derecha...");

                scanf("%i", &direccion);
                printf("\n Ingrese la cantidad de caracteres...");
                scanf("%i", &cantidad);

                printf("%s\n", llenarCaracteres(cadena5, letras, cantidad, direccion));
                printf("\nPresione una tecla para continuar . . .");
                getchar();
                getchar();
                break;

            case 6:

                //Borrar caracteres

                printf("\n>>Eliminar un caracter de una cadena<<");
                char cadena6[255], caracter[1];
                printf("\nIngrese la cadena...");
                gets(cadena6);
                printf("\nIngrese el caracter a borrar...");
                scanf("%s", caracter);

                printf("\n%s \n", eliminarCaracteres(cadena6, caracter));

                printf("\nPresione una tecla para continuar . . .");
                getchar();
                getchar();
                break;

            case 7:
                //Intersección
                printf("\n>>Diferencia entre dos cadenas<<");

                char cadena7[255], cadena27[255];

                printf("\nDigite la cadena de texto uno...");
                fgets(cadena7, 255, stdin);

                printf("\nDigite la cadena de texto dos...");
                fgets(cadena27, 255, stdin);

                printf("\nLa Interseccion es: %s \n", interseccion(cadena7, cadena27));
                printf("\nPresione una tecla para continuar . . .");
                getchar();

                break;

            case 8:
                // Diferencia de 2 cadenas
                printf("Diferencia entre cadenas \n");
                char cadena1[255], cadena2[255];
                printf("Ingrese la primera cadena: ");
                fgets(cadena1, 255, stdin);
                printf("Ingrese la segunda cadena: ");
                fgets(cadena2, 255, stdin);

                diferenciaCadenas(strlwr(cadena1), strlwr(cadena2));
                break;
            case 9:
                // Borrar caracteres por izquiera o derecha
                printf("Borrar caracteres por izquierda derecha \n");
                char *primerCadena[255], *segundaCadena[255];
                int orientacion = 0;

                printf("Ingrese la primera cadena: ");
                fgets(primerCadena, 255, stdin);
                printf("Ingrese la segunda Cadena: ");
                fgets(segundaCadena, 255, stdin);
                printf("1. Por IZQUIERDA | 2. Por DERECHA: ");
                scanf("%d", &orientacion);

                borrarCaracteres(strlwr(primerCadena), strlwr(segundaCadena), orientacion);
                break;
            case 10:
                //Validar correo electrónico
                printf("Ingrese su email...");
                char email[255];
                scanf("%s", email);
                if (isValidEmail(email))printf("\nEl email es valido\n");
                else printf("\nEl email no es valido\n");

                printf("\nPresione una tecla para continuar . . .");
                getchar();
                getchar();
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

