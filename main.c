#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>

void convertirNombrePropio(){
    int tamano,aux=0;
    char cadena[255],cadenaNomPropio[255];
    printf("\n>>Convertir en nombre propio<<"
           "\nDigite la cadena de texto...");
    gets(cadena);
    tamano= strlen(cadena);
    for (int i = 0; i < tamano; ++i) {
        if (aux==i){
            cadenaNomPropio[i]= toupper(cadena[i]);
        } else{
            if (cadena[i]==' '){
                aux=i+1;
                cadenaNomPropio[i]= cadena[i];
            } else{
                cadenaNomPropio[i]=cadena[i];
            }
        }
    }
    printf("%s \n",cadenaNomPropio);
    system( "pause" );
}


void numVecesPalabra(){
    int tamano,contador=0,aux=0;
    char cadena[255],cadenaAux[50],palabraComparar[50];
    printf("\n>>N%cmero de veces que existe una palabra<<"
           "\nDigite la cadena de texto...",163);
    gets(cadena);

    tamano= strlen(cadena);

    cadena[tamano]=' ';
    cadena[tamano+1]='\0';

    printf("Digite la palabra a buscar...");
    gets(palabraComparar);

    for (int i = 0; cadena[i] != '\0'; ++i) {
        if (cadena[i]==' '){
            cadenaAux[aux]='\0';
            aux=0;

            if (strcmp(palabraComparar,cadenaAux)==0){
                contador++;
            }
            memset(cadenaAux,0,50);
        } else{
            cadenaAux[aux]=cadena[i];
            aux++;
        }
    }
    printf("\nla palabra %s se repite %i ves%s \n",palabraComparar,contador,contador>1? "es":"");
    system( "pause" );
}

void encriptar(){
    char cadena[255],cadenaEncriptada[255];
    int tamano;

    printf("\n>>Encriptar<<"
           "\nDigite la cadena de texto a encpriptar...");
    gets(cadena);


    tamano= strlen(cadena);
    for (int i = 0; i < tamano ; ++i) {

        if (cadena[i]==toupper(cadena[i])){

            *(cadena + i) = tolower(*(cadena + i));

        } else{
            *(cadena + i) = toupper(*(cadena + i));
        }

        //descarta los digitos
        if(isalpha(*(cadena + i))){
            //verifica los casos especiales X-Y-Z
            if((*(cadena + i) > 87 && *(cadena + i)<91) ||(*(cadena + i)>119)){
                *(cadena+i) = *(cadena+i) - 23;
            } else{
                *(cadena + i) = *(cadena + i) + 3;
            }


                //*(cadena + i) = *(cadena + i) + 3;
        }
    }


    printf("\nLa frase encriptada es: %s\n",cadena);
    system( "pause" );

}

void desencriptar(){

    char cadena[255];
    int tamano;

    printf("\n>>Desencriptar<<"
           "\nDigite la cadena de texto a desencpriptar...");
    gets(cadena);
    tamano= strlen(cadena);


    for (int i = 0; i < tamano ; ++i) {

        if (cadena[i]==toupper(cadena[i])){
            *(cadena + i) = tolower(*(cadena + i));
        } else{
            *(cadena + i) = toupper(*(cadena + i));
        }

        if(isalpha(*(cadena + i))){
            if(*(cadena + i) < 68  ||(*(cadena + i) >96 && *(cadena + i)<100)){
                *(cadena+i)= *(cadena+i) + 23;
            }else{
                *(cadena+i)= *(cadena+i) - 3;
            }
        }
    }
    printf("\nLa frase desencriptada es: %s \n",cadena);
    system( "pause" );
}

void eliminarCaracteres(){
    char cadena[]= "Sogamoso Ciudad del Sol y del Acero", carac[5];
    int indCadena=0, indCadL=0;
    int agregarCaracteer= 1;
    printf(cadena);
    printf("\nIngrese el caracter a borrar");
    scanf("%s", carac);

    while (cadena[indCadena]){
        agregarCaracteer=1;
        int indCaracter=0;
        while (carac[indCaracter]){
            if (cadena[indCadena] == carac[indCaracter]){
                agregarCaracteer=0;
            }
            indCaracter++;
        }
        if (agregarCaracteer){
            cadena[indCadL]= cadena[indCadena];
            indCadL++;
        }
        indCadena++;
    }
    cadena[indCadL]=0;

    printf(cadena);
    system("pause");

}
void llenarCaracteres(char fuente1[], char fuente2[], int cant, int dire, char destino[]){
    int i= 0, j = 0;
    char letra[244];
    while (cant>1) {
        printf("%s", fuente2);
        --cant;
    }

    if (dire== 1){

        while (fuente2[i] != '\0'){
            destino[i]= fuente2[i];
            i++;
        } while (fuente1[j] != '\0'){
            destino[i+j]= fuente1[j];
            j++;
        }
        destino[i+j]= '\0';
    }
    if (dire==2){

        while (fuente1[i] != '\0'){
            destino[i]= fuente1[i];
            i++;
        } while (letra[j] != '\0'){
            destino[i+j]= letra[j];
            j++;

        }
        destino[i+j]= '\0';
    }
    system("pause");
}

int main() {

    int op=0;
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
                     "11.Salir \n" ;

    while (op!= 11){
        printf(mainmenu,163,162,162,162,162);
        scanf("%i",& op);
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
                int cantidad=0, direccion=0;
                void llenarCaracteres(char fuente1[], char fuente2[], int can, int dire, char destino[]);
                printf("Ingrese la cadena de texto");
                scanf("%s", &cadena);
                printf("Ingrese el caracter a insertar");
                scanf("%s", &letras);
                printf("Ingrese direccion 1. Izquierda  2. Derecha");
                scanf("%d", &direccion);
                printf("Ingrese la cantidad de caracteres");
                scanf("%d", &cantidad);
                llenarCaracteres(cadena, letras, cantidad, direccion, cadenaFinal);
                printf("%s" , cadenaFinal);
                break;

            case 6:
                eliminarCaracteres();
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
