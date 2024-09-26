#include <iostream>
#include <random>
using namespace std;

void RetirarDinero(int cantidad);
void GenerarArregloLetras();
bool compararCadenas(const char *cadena1, const char *cadena2);
int CaracterAnumero(const char *cadena);
void NumeroAcaracter(int num, char *str);
void SinRepetir(char *original);
void SepararCaracteres(char *palabra);
void imprimirMatriz(int matriz[5][5]);
void rotar90(int matriz[5][5], int matrizRotada[5][5]);
void rotar180(int matriz[5][5], int matrizRotada[5][5]);
void rotar270(int matriz[5][5], int matrizRotada[5][5]);
long int calcularCaminos(int n);
int sumarNumerosAmigables(int limite);
void ConvertirAmayus(char *palabra);

int main()
{
    int opcion = 1;
    const char *cadena1 = "Hola";
    const char *cadena2 = "Hola";
    const char *cadena3 = "Mundo";
    const char *cadena = "123";
    char str[20] = {0};
    char original[100];
    int matriz[5][5];
    int cantidad;

    cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;
    cout << "*  Bienvenido a la practica #2 del laboratorio. *\n" << endl;
    cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n" << endl;
    cout << "A continuacion se le mostraran las opciones a elegir en dicho programa." << endl;

    while (opcion != 0) {
        cout << "\nOpciones de la practica #2." << endl;
        cout << "\n1. Retirar dinero." << endl;
        cout << "2. Generar lista con 200 letras mayusculas aleatorias e imprimir dicha lista y la cantidad de veces" << endl;
        cout << "que se repite cada letra." << endl;
        cout << "3. Comparar cadenas de caracteres." << endl;
        cout << "4. Convertir una cadena de caracteres numericos a un numero entero." << endl;
        cout << "5. Convertir un numero a cadena de caracteres numericos." << endl;
        cout << "6. Convertir a mayuscula." << endl;
        cout << "7. Eliminar caractertes repetidos." << endl;
        cout << "8. Separar caracter numericos del resto de caracteres." << endl;
        cout << "9. Generar matriz y rotarla 90, 180 y 270 grados." << endl;
        cout << "10. Calcular la cantidad de caminos posibles en una malla n*n." << endl;
        cout << "11. Hallar la suma de los numeros amigables menores a n." << endl;
        cout << "0. Salir del programa.\n" << endl;
        cout << "*     *     *     *     *\n" << endl;
        cout << "Por favor, ingrese una de las opciones mostradas anteriormente: "; cin >> opcion;
        cout << endl;
        cout << "Cargando la opcion: " << opcion << "...\n" << endl;

        switch (opcion) {
        case 1:
            cout << "Ingrese la cantidad a retirar: "; cin >> cantidad;
            RetirarDinero(cantidad);
            break;
        case 2:
            cout << "La lista generada es: " << endl;
            GenerarArregloLetras();
            break;
        case 3:
            cout << "Comparando 'Hola' y 'Hola': " << (compararCadenas(cadena1, cadena2) ? "Iguales" : "Diferentes") << endl;
            cout << "comparando 'Hola' y 'mundo': " << (compararCadenas(cadena1, cadena3) ? "Iguales" : "Diferentes") << endl;
            break;
        case 4:
            cout << "La cadena '123' en numeros es: " << CaracterAnumero(cadena) << endl;
            break;
        case 5:
            NumeroAcaracter(123, str);
            break;
        case 6:
            char palabra[50];
            cout << "Ingrese una palabra: "; cin >> palabra;
            ConvertirAmayus(palabra);
            break;
        case 7:
            cout << "Ingrese un cadena de caracteres: "; cin >> original;
            SinRepetir(original);
            break;
        case 8:
            cout << "Ingrese una cadena de caracteres: "; cin >> original;
            SepararCaracteres(original);
            break;
        case 9: {
            int contador = 1;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    matriz[i][j] = contador++;
                }
            }

            cout << "\nMatriz original:" << endl;
            imprimirMatriz(matriz);

            int matriz90[5][5], matriz180[5][5], matriz270[5][5];

            rotar90(matriz, matriz90);
            rotar180(matriz, matriz180);
            rotar270(matriz, matriz270);

            cout << "\nMatriz rotada 90 grados:" << endl;
            imprimirMatriz(matriz90);

            cout << "\nMatriz rotada 180 grados:" << endl;
            imprimirMatriz(matriz180);

            cout << "\nMatriz rotada 270 grados:" << endl;
            imprimirMatriz(matriz270);
            break;
        }
        case 10: {
            int n;
            cout << "Ingresa el tamano de la cuadricula (n): ";
            cin >> n;

            long caminos = calcularCaminos(n);
            cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
            break;
        }
        case 11: {
            int numero;

            cout << "Ingrese un numero: ";
            cin >> numero;

            int resultado = sumarNumerosAmigables(numero);
            cout << "El resultado de la suma es: " << resultado << endl;
            break;
        }
        case 0:
            cout << "Gracias por usar la practica #2, que tenga un feliz dia." << endl;
            break;
        default:
            cout << "La opcion no es valida.";
            break;
        }
    }
    return 0;
}

void RetirarDinero(int cantidad) {
    int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int monedas[] = {500, 200, 100, 50};

    int billetesUsados[6] = {0, 0, 0, 0, 0, 0};
    int monedasUsadas[4] = {0, 0, 0, 0};
    int residuo = cantidad;

    for (int i = 0; i < 6; i++) {
        billetesUsados[i] = residuo / billetes[i];
        residuo %= billetes[i];
    }

    for (int i = 0; i < 4; i++) {
        monedasUsadas[i] = residuo / monedas[i];
        residuo %= monedas[i];
    }

    cout << "50.000$ : " << billetesUsados[0] << endl;
    cout << "20.000$ : " << billetesUsados[1] << endl;
    cout << "10.000$ : " << billetesUsados[2] << endl;
    cout << "5.000$ : " << billetesUsados[3] << endl;
    cout << "2.000$ : " << billetesUsados[4] << endl;
    cout << "1.000$ : " << billetesUsados[5] << endl;

    cout << "500$ : " << monedasUsadas[0] << endl;
    cout << "200$ : " << monedasUsadas[1] << endl;
    cout << "100$ : " << monedasUsadas[2] << endl;
    cout << "50$ : " << monedasUsadas[3] << endl;

    if (residuo > 0) {
        cout << "Su faltante es: " << residuo << endl;
    }
    else {
        cout << "La cantidad fue exacta." << endl;
    }
}
/*
 * #Problema 1 arduino

void loop() {
    int cantidad = 0;

    while (Serial.available() == 0){
    }
    if (Serial.available() > 0) {
        cantidad = Serial.parseInt();
    }
    RetirarDinero(cantidad);

}

void RetirarDinero(int cantidad) {
    int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int monedas[] = {500, 200, 100, 50};

    int billetesUsados[6] = {0, 0, 0, 0, 0, 0};
    int monedasUsadas[4] = {0, 0, 0, 0};
    int residuo = cantidad;

    for (int i = 0; i < 6; i++) {
        billetesUsados[i] = residuo / billetes[i];
        residuo %= billetes[i];
    }

    for (int i = 0; i < 4; i++) {
        monedasUsadas[i] = residuo / monedas[i];
        residuo %= monedas[i];
    }

    Serial.print("50.000$ : ");
    Serial.println(billetesUsados[0]);
    Serial.print("20.000$ : ");
    Serial.println(billetesUsados[1]);
    Serial.print("10.000$ : ");
    Serial.println(billetesUsados[2]);
    Serial.print("5.000$ : ");
    Serial.println(billetesUsados[3]);
    Serial.print("2.000$ : ");
    Serial.println(billetesUsados[4]);
    Serial.print("1.000$ : ");
    Serial.println(billetesUsados[5]);

    Serial.print("500$ : ");
    Serial.println(monedasUsadas[0]);
    Serial.print("200$ : ");
    Serial.println(monedasUsadas[1]);
    Serial.print("100$ : ");
    Serial.println(monedasUsadas[2]);
    Serial.print("50$ : ");
    Serial.println(monedasUsadas[3]);

    if (residuo > 0) {
        Serial.print("Su faltante es: ");
        Serial.println(residuo);
    }
    else {
        Serial.println("La cantidad fue exacta.");
    }
    Serial.println("Ingrese una cantidad de dinero: ");
}
*/

void GenerarArregloLetras() {
    char letra;
    char lista[200];
    int contador = 0;

    for (int i = 0; i < 200; i++) {
        letra = rand() % 26 + 65;
        lista[i] = letra;
    }
    cout << lista << endl;
    for (int i = 65; i <= 90; i++) {
        for (int j = 0; j < 200; j++) {
            letra = i;
            if (letra == lista[j]) {
                contador += 1;
            }
        }
        cout << letra << ": " << contador << endl;
        contador = 0;
    }
}

bool compararCadenas(const char *cadena1, const char *cadena2) {
    int i = 0;

    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }

    if (cadena1[i] == '\0' && cadena2[i] == '\0')
        return true;
    else
        return false;
}

int CaracterAnumero(const char *cadena) {
    int num = 0;
    bool negativo = false;

    if (*cadena == '-') {
        negativo = true;
        cadena++;
    }

    while (*cadena != '\0') {
        if (*cadena >= '0' && *cadena <= '9') {
            num = num * 10 + (*cadena - '0');
        } else {
            break;
        }
        cadena++;
    }

    if (negativo) {
        num = -num;
    }

    return num;
}


void NumeroAcaracter(int num, char *str) {
    int aux = num;
    int i = 0;
    bool esNegativo = false;

    if (num < 0) {
        esNegativo = true;
        num = -num;
    }

    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);

    if (esNegativo) {
        str[i++] = '-';
    }

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    cout << "El numero " << aux << " en cadena de caracteres es: " << str << endl;
}

void ConvertirAmayus(char *palabra) {

    char aux[50];
    int i = 0;
    while (*palabra != '\0') {
        if (*palabra >= 'a' && *palabra <= 'z') {
            aux[i] = *palabra - 32;
            palabra++;
            i++;
        }
        else {
            aux[i] = *palabra;
            palabra++;
            i++;
        }
    }
    cout << aux;
}
/*
 * #Problema 6 arduino
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese una palabra: ");
}

void loop() {
    char palabra;
    while (Serial.available() == 0){
    }
    if (Serial.available() > 0) {
        palabra = Serial.read();
    }
    char palabra1[] = {palabra};
    ConvertirAmayus(palabra1);
}

void ConvertirAmayus(char *palabra) {
    int b = 0;
    while (*palabra != '\0') {
        b++;
        palabra++;
    }

    palabra -= b;

    char aux[b];
    int i = 0;
    while (*palabra != '\0') {
        if (*palabra >= 'a' && *palabra <= 'z') {
            aux[i] = *palabra - 32;
            palabra++;
            i++;
        }
        else {
            aux[i] = *palabra;
            palabra++;
            i++;
        }
    }
    Serial.print(aux);
}
*/

void SinRepetir(char *original) {
    char resultado[100];
    int k = 0;

    for (int i = 0; original[i] != '\0'; i++) {
        bool repetido = false;

        for (int j = 0; j < k; j++) {
            if (original[i] == resultado[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido){
            resultado[k++] = original[i];
        }
    }
    resultado[k] = '\0';

    cout << "Original: " << original << endl;
    cout << "Sin repetidos: " << resultado << endl;
}

void SepararCaracteres(char *palabra) {
    char aux[100] = "", aux2[100] = "";
    int i = 0, j = 0, k = 0;

    while (palabra[i] != '\0') {
        if ((palabra[i] >= 'a' && palabra[i] <= 'z') || (palabra[i] >= 'A' && palabra[i] <= 'Z')) {
            aux[j] = palabra[i];
            j++;
        } else {
            aux2[k] = palabra[i];
            k++;
        }
        i++;
    }
    aux[j] = '\0';
    aux2[k] = '\0';

    cout << "Original: " << palabra << endl;
    cout << "Texto: " << aux << " Numero: " << aux2 << endl;
}

void imprimirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotar90(int matriz[5][5], int matrizRotada[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizRotada[j][4 - i] = matriz[i][j];
        }
    }
}

void rotar180(int matriz[5][5], int matrizRotada[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizRotada[4 - i][4 - j] = matriz[i][j];
        }
    }
}

void rotar270(int matriz[5][5], int matrizRotada[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizRotada[4 - j][i] = matriz[i][j];
        }
    }
}

long int factorial(int num) {
    long result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

long int calcularCaminos(int n) {
    long caminos = factorial(2 * n) / (factorial(n) * factorial(n));
    return caminos;
}

int sumaDivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

int sumarNumerosAmigables(int limite) {
    int sumaTotal = 0;
    for (int a = 1; a < limite; a++) {
        int b = sumaDivisores(a);
        if (b > a && b < limite && sumaDivisores(b) == a) {
            sumaTotal += a + b;
        }
    }
    return sumaTotal;
}

/*
 * #Problema 17 arduino
int sumarNumerosAmigables(int limite);

void setup() {
    Serial.begin(9600);
    Serial.println("Ingrese un numero: ");
}

void loop() {
    int numero;
    while (Serial.available() == 0){
    }
    if (Serial.available() > 0) {
        numero = Serial.parseInt();
    }
    int resultado = sumarNumerosAmigables(numero);
    Serial.println("El resultado de la suma es: ");
    Serial.print(resultado);
    Serial.println();
    Serial.println("Ingresa un numero: ");
}

int sumaDivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

int sumarNumerosAmigables(int limite) {
    int sumaTotal = 0;
    for (int a = 1; a < limite; a++) {
        int b = sumaDivisores(a);
        if (b > a && b < limite && sumaDivisores(b) == a) {
            sumaTotal += a + b;
        }
    }
    return sumaTotal;
}
*/



