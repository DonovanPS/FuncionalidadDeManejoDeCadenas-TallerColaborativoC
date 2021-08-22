#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>

void convertirNombrePropio() {
    int tamano, aux = 0;
    char cadena[255], cadenaNomPropio[255];
    printf("\n>>Convertir en nombre propio<<"
           "\nDigite la cadena de texto...");
    gets(cadena);
    tamano = strlen(cadena);
    for (int i = 0; i < tamano; ++i) {
        if (aux == i) {
            cadenaNomPropio[i] = toupper(cadena[i]);
        } else {
            if (cadena[i] == ' ') {
                aux = i + 1;
                cadenaNomPropio[i] = cadena[i];
            } else {
                cadenaNomPropio[i] = cadena[i];
            }
        }
    }
    printf("%s \n", cadenaNomPropio);
    system("pause");
}


void numVecesPalabra() {
    int tamano, contador = 0, aux = 0;
    char cadena[255], cadenaAux[50], palabraComparar[50];
    printf("\n>>N%cmero de veces que existe una palabra<<"
           "\nDigite la cadena de texto...", 163);
    gets(cadena);

    tamano = strlen(cadena);

    cadena[tamano] = ' ';
    cadena[tamano + 1] = '\0';

    printf("Digite la palabra a buscar...");
    gets(palabraComparar);

    for (int i = 0; cadena[i] != '\0'; ++i) {
        if (cadena[i] == ' ') {
            cadenaAux[aux] = '\0';
            aux = 0;

            if (strcmp(palabraComparar, cadenaAux) == 0) {
                contador++;
            }
            memset(cadenaAux, 0, 50);
        } else {
            cadenaAux[aux] = cadena[i];
            aux++;
        }
    }
    printf("\nla palabra %s se repite %i ves%s \n", palabraComparar, contador, contador > 1 ? "es" : "");
    system("pause");
}

void encriptar() {
    char cadena[255], cadenaEncriptada[255];
    int tamano;

    printf("\n>>Encriptar<<"
           "\nDigite la cadena de texto a encpriptar...");
    gets(cadena);


    tamano = strlen(cadena);
    for (int i = 0; i < tamano; ++i) {

        if (cadena[i] == toupper(cadena[i])) {

            *(cadena + i) = tolower(*(cadena + i));

        } else {
            *(cadena + i) = toupper(*(cadena + i));
        }

        //descarta los digitos
        if (isalpha(*(cadena + i))) {
            //verifica los casos especiales X-Y-Z
            if ((*(cadena + i) > 87 && *(cadena + i) < 91) || (*(cadena + i) > 119)) {
                *(cadena + i) = *(cadena + i) - 23;
            } else {
                *(cadena + i) = *(cadena + i) + 3;
            }


            //*(cadena + i) = *(cadena + i) + 3;
        }
    }


    printf("\nLa frase encriptada es: %s\n", cadena);
    system("pause");

}

void desencriptar() {

    char cadena[255];
    int tamano;

    printf("\n>>Desencriptar<<"
           "\nDigite la cadena de texto a desencpriptar...");
    gets(cadena);
    tamano = strlen(cadena);


    for (int i = 0; i < tamano; ++i) {

        if (cadena[i] == toupper(cadena[i])) {
            *(cadena + i) = tolower(*(cadena + i));
        } else {
            *(cadena + i) = toupper(*(cadena + i));
        }

        if (isalpha(*(cadena + i))) {
            if (*(cadena + i) < 68 || (*(cadena + i) > 96 && *(cadena + i) < 100)) {
                *(cadena + i) = *(cadena + i) + 23;
            } else {
                *(cadena + i) = *(cadena + i) - 3;
            }
        }
    }
    printf("\nLa frase desencriptada es: %s \n", cadena);
    system("pause");
}

void eliminarCaracteres(char cadena[255], char caracter[1]) {

    int indCadena = 0, indCadL = 0;
    int agregarCaracteer = 1;
    while (cadena[indCadena]) {
        agregarCaracteer = 1;
        int indCaracter = 0;
        while (carac[indCaracter]) {
            if (cadena[indCadena] == carac[indCaracter]) {
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

    printf(cadena);
    system("pause");

}

void llenarCaracteres(char fuente1[], char fuente2[], int cant, int dire, char destino[]) {
    int i = 0, j = 0;
    char letra[244];
    while (cant > 1) {
        printf("%s", fuente2);
        --cant;
    }

    if (dire == 1) {

        while (fuente2[i] != '\0') {
            destino[i] = fuente2[i];
            i++;
        }
        while (fuente1[j] != '\0') {
            destino[i + j] = fuente1[j];
            j++;
        }
        destino[i + j] = '\0';
    }
    if (dire == 2) {

        while (fuente1[i] != '\0') {
            destino[i] = fuente1[i];
            i++;
        }
        while (letra[j] != '\0') {
            destino[i + j] = letra[j];
            j++;

        }
        destino[i + j] = '\0';
    }
    system("pause");
}

char *interseccion(char cadena[], char cadena2[]){
    int tamano1,tamano2,cont=0,contador=0;
    char aux[255], aux2[255];
    char *cadenaSalida="";

    tamano2= strlen(cadena2);
    for (int i = tamano2-1; i >= 0; --i) {
        for (int j = 0; j <tamano2-1; ++j) {
            if (cadena2[i]==cadena2[j]){
                cont++;
            }
        }
        if (cont>1){
            memset(aux,0,255);
            memset(aux2,0,255);

            for (int j = i+1; j < tamano2-1; ++j) {
                aux[contador]=cadena2[j];
                contador++;
            }
            contador=0;
            for (int j = 0; j < i; ++j) {
                aux2[j]=cadena2[j];
            }
            memset(cadena2,0,255);
            strcat(strcpy(cadena2, aux2), aux);

            tamano2= strlen(cadena2);
        }
        cont=0;
    }

    tamano1= strlen(cadena);
    tamano2= strlen(cadena2);
    memset(aux,0,255);
    cont=0;
    contador=0;
    for (int i = 0; i < tamano2; ++i) {
        for (int j = 0; j < tamano1; ++j) {
            if (cadena2[i]==cadena[j]){
                cont++;
            }
        }
        if (cont>0){
            aux[contador]=cadena2[i];
            contador++;
            cont=0;
        }
    }

    cadenaSalida=aux;
    return cadenaSalida;
}

char *diferenciaCadenas(char cadena1[], char cadena2[]) {
    int sizeCadena1 = strlen(cadena1);
    int sizeCadena2 = strlen(cadena2);
    int index = 0;
    char *resultado = "";
    for (int i = 0; i < sizeCadena1; i++) {
        int same = 0;
        for (int j = 0; j < sizeCadena2; j++) {
            if (cadena1[i] == cadena2[j]) {
                same = 0;
                break;
            } else same = 1;;
        }
        if (same == 1) {
            resultado[index] = cadena1[i];
            index++;
        }
    }
    return resultado;
}

char *borrarCaracteres(char cadena1[], char cadena2[], int direccion) {
    int sizeCadena1 = strlen(cadena1);
    int sizeCadena2 = strlen(cadena2);
    int index = 0;
    char *resultado = "";

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
        resultado = &cadena1[index];
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
            resultado[i] = cadena1[i];
        }
    }

    return resultado;
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
                convertirNombrePropio();
                break;
            case 2:
                numVecesPalabra();
                break;
            case 3:
                encriptar();
                break;
            case 4:
                desencriptar();
                break;
            case 5:
                char cadena[255], letras[55], cadenaFinal[255], aux[255];
                int cantidad = 0, direccion = 0;
                void llenarCaracteres(char fuente1[], char fuente2[], int can, int dire, char destino[]);
                printf("\n>>Llenar Caracteres<<"
                       "\n Ingrese la cadena de texto");
                scanf("%s", &cadena);
                printf("\n Ingrese el caracter a insertar");
                scanf("%s", &letras);
                printf("\n Ingrese direccion 1. Izquierda  2. Derecha");
                scanf("%d", &direccion);
                printf("\n Ingrese la cantidad de caracteres");
                scanf("%d", &cantidad);
                llenarCaracteres(cadena, letras, cantidad, direccion, cadenaFinal);
                printf("%s", cadenaFinal);
                break;
            case 6:
                char cadena[255], caracter[1];
                printf("\n>>Eliminar un caracter de una cadena"
                       "<<" "\nIngrese el cadena");
                scanf("%s", cadena);
                printf("\nIngrese el caracter a borrar");
                scanf("%s", caracter);
                eliminarCaracteres(cadena, caracter);
                break;
            case 7:
                char cadena7[255],cadena27[255];
                printf("\n>>Diferencia entre dos cadenas<<"
                       "\nIngrese la primera cadena");
                fgets(cadena7,255,stdin);
                printf("\nIngrese la cadena de texto dos...");
                fgets(cadena27,255,stdin);
                printf("\nLa Interseccion es es: %s \n",interseccion(cadena7,cadena27));
                break;
            case 8:
                // Diferencia de 2 cadenas
                char cadena1[255], cadena2[255];
                printf("Ingrese la primera cadena: ");
                gets(cadena1, 255, stdin);
                printf("Ingrese la segunda cadena: ");
                gets(cadena2, 255, stdin);
                char *result = diferenciaCadenas(strlwr(cadena1), strlwr(cadena2));
                printf("%s", result);
                break;
            case 9:
                // Borrar caracteres por izquiera o derecha
                char primerCadena[255], segundaCadena[255];
                int orientacion = 0;
                printf("Ingrese la primera cadena: ");
                gets("%s", primerCadena);
                printf("Ingrese la segunda Cadena: ");
                gets("%s", segundaCadena);
                printf("1. Por IZQUIERDA | 2. Por DERECHA: ");
                scanf("%d", &orientacion);
                char *resultado = borrarCaracteres(strlwr(primerCadena), strlwr(segundaCadena), orientacion);
                printf("%s", resultado);
                break;
            case 10:
                char email[255];
                printf("Ingrese su email");
                scanf("%s", email);
                if (isValidEmail(email))printf("El email es valido");
                else printf("El email no es valido");
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
