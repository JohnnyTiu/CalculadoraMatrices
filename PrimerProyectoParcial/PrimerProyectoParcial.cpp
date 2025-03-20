#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cctype>    // Para funciones como isdigit()
#include <string>    // Para manejar la entrada como string
using namespace std;

void PantallaInicio();
int menuPrincipal(const char* titulo, const char* opciones[], int nopciones);
int MenuSuma(const char* titulo2, const char* opciones2[], int nopciones2);
int MenuResta(const char* titulo3, const char* opciones3[], int nopciones3);
int MenuMultiplicacion(const char* titulo4, const char* opciones4[], int nopciones4);
int MenuReglas(const char* titulo6, const char* opciones6[], int nopciones6);
void IngresarMatriz(int**, int, int, int);
void SumaMatrices(int**, int**, int**, int, int);
void OperacionSumaMatrices();
void RestaMatrices(int**, int**, int**, int, int);
void OperacionRestaMatrices();
void MultiplicaMatrices(int**, int**, int**, int, int, int);
void OperacionMultiplicacionMatrices();
void MostrarMatriz(int**, int, int, int, int);
void TituloSuma();
void TituloResta();
void TituloMultiplicacion();
void ReglasSumaMatrices();
void ReglasRestaMatrices();
void ReglasMultiplicacionMatrices();
bool EsEntero(const string&);
void gotoxy(int, int);

int filasA = 0, columnasA = 0, filasB = 0, columnasB = 0;

int main()
{
    PantallaInicio();

    bool repite = true;
    int opcion;
    int nopciones = 5;
    int opcion2;
    int nopciones2 = 4;
    int opcion3;
    int nopciones3 = 4;
    int opcion4;
    int nopciones4 = 4;
    int opcion5;
    int nopciones5 = 5;
    int** matrizA = nullptr, ** matrizB = nullptr, ** resultado = nullptr;

    const char* tituloPrincipal = "Menu de opciones";
    const char* opciones[] = {
        "Suma de Matrices",
        "Resta de Matrices",
        "Multiplicacion de Matrices",
        "Reglas para cada operacion",
        "Salir del programa"
    };
    const char* tituloSuma = "Menu Suma De Matrices";
    const char* opciones2[] = {
        "Sumar Matrices",
        "Ver Reglas Para Sumar Matrices",
        "Regresar Al Menu Principal",
        "Salir Del Programa"
    };
    const char* tituloResta = "Menu Resta De Matrices";
    const char* opciones3[] = {
        "Restar Matrices",
        "Ver Reglas Para Restar Matrices",
        "Regresar Al Menu Principal",
        "Salir Del Programa"
    };
    const char* tituloMultiplicacion = "Menu Multiplicacion De Matrices";
    const char* opciones4[] = {
        "Multiplicar Matrices",
        "Ver Reglas Para Multiplicar Matrices",
        "Regresar Al Menu Principal",
        "Salir Del Programa"
    };
    const char* tituloReglas = "Menu de Reglas";
    const char* opciones5[] = {
        "Reglas Para Sumar Matrices",
        "Reglas Para Restar Matrices",
        "Reglas Para Multiplicar Matrices",
        "Regresar Al Menu Principal",
        "Salir del programa"
    };

    do {
        opcion = menuPrincipal(tituloPrincipal, opciones, nopciones);  // Mostramos menú principal

        switch (opcion) {
        case 1:
            do {
                opcion2 = MenuSuma(tituloSuma, opciones2, nopciones2);
                switch (opcion2) {
                case 1:
                    OperacionSumaMatrices();
                    break;
                case 2:
                    ReglasSumaMatrices();
                    break;
                case 3:
                    opcion = 0; // Reiniciar para que se muestre el menú principal
                    break;
                case 4:
                    repite = false; // Salir del programa
                    break;
                }
            } while (opcion2 != 3 && repite); // Si elige "Regresar al menú principal", salir del bucle interno
            break;
        case 2:
            do {
                opcion3 = MenuResta(tituloResta, opciones3, nopciones3);
                switch (opcion3) {
                case 1:
                    OperacionRestaMatrices();
                    break;
                case 2:
                    ReglasRestaMatrices();
                    break;
                case 3:
                    opcion = 0; // Reiniciar para que se muestre el menú principal
                    break;
                case 4:
                    repite = false; // Salir del programa
                    break;
                }
            } while (opcion3 != 3 && repite); // Si elige "Regresar al menú principal", salir del bucle interno
            break;
        case 3:
            do {
                opcion4 = MenuMultiplicacion(tituloMultiplicacion, opciones4, nopciones4);
                switch (opcion4) {
                case 1:
                    OperacionMultiplicacionMatrices();
                    break;
                case 2:
                    ReglasMultiplicacionMatrices();
                    break;
                case 3:
                    opcion = 0; // Reiniciar para que se muestre el menú principal
                    break;
                case 4:
                    repite = false; // Salir del programa
                    break;
                }
            } while (opcion4 != 3 && repite); // Si elige "Regresar al menú principal", salir del bucle interno
            break;
        case 4:
            do {
                opcion5 = MenuReglas(tituloReglas, opciones5, nopciones5);
                switch (opcion5) {
                case 1:
                    ReglasSumaMatrices();
                    break;
                case 2:
                    ReglasRestaMatrices();
                    break;
                case 3:
                    ReglasMultiplicacionMatrices();
                    break;
                case 4:
                    opcion = 0; // Reiniciar para que se muestre el menú principal
                    break;
                case 5:
                    repite = false; // Salir del programa
                    break;
                }
            } while (opcion5 != 4 && repite); // Si elige "Regresar al menú principal", salir del bucle interno
            break;
        case 5:
            repite = false;
            break;
        }
    } while (repite);

    gotoxy(24, 22); cout << "Gracias por usar el programa!!! Presione una tecla para cerrar la consola...";
    _getch();
    cout << endl;
    return 0;
}

void PantallaInicio() {
    gotoxy(1, 4);  cout << "*********  *********  ****       *********  ***   ***  ***        *********  *******    *********  ********   *********";
    gotoxy(1, 5);  cout << "*********  ***   ***  ****       *********  ***   ***  ***        ***   ***  ********   *********  ****  ***  ***   ***";
    gotoxy(1, 6);  cout << "***        ***   ***  ****       ***        ***   ***  ***        ***   ***  ***   ***  ***   ***  ****  ***  ***   ***";
    gotoxy(1, 7);  cout << "***        *********  ****       ***        ***   ***  ***        *********  ***   ***  ***   ***  ********   *********";
    gotoxy(1, 8);  cout << "*********  ***   ***  *********  *********  *********  *********  ***   ***  ********   *********  ***  ****  ***   ***";
    gotoxy(1, 9);  cout << "*********  ***   ***  *********  *********  *********  *********  ***   ***  *******    *********  ***   ***  ***   ***";
    gotoxy(2, 11);  cout << "                                                *******    *********";
    gotoxy(2, 12);  cout << "                                                ********   ***";
    gotoxy(2, 13);  cout << "                                                ***   ***  *******";
    gotoxy(2, 14);  cout << "                                                ***   ***  *******";
    gotoxy(2, 15);  cout << "                                                ********   ***";
    gotoxy(2, 16);  cout << "                                                *******    *********";
    gotoxy(2, 18); cout << "               ***   ***  *********  *********  ********   *********  *********  *********  *********";
    gotoxy(2, 19); cout << "               ***   ***  ***   ***  *********  ****  ***  *********  *********  ***        ***      ";
    gotoxy(2, 20); cout << "               *********  ***   ***     ***     ****  ***     ***     ***        *******    *********";
    gotoxy(2, 21); cout << "               ** *** **  *********     ***     ********      ***     ***        *******    *********";
    gotoxy(2, 22); cout << "               **     **  ***   ***     ***     ***  ****  *********  *********  ***              ***";
    gotoxy(2, 23); cout << "               **     **  ***   ***     ***     ***   ***  *********  *********  *********  *********";
    gotoxy(40, 28);  system("PAUSE");
}

int menuPrincipal(const char* titulo, const char* opciones[], int nopciones) {
    int opcionSeleccionada = 1; // Opción inicial
    int tecla;
    bool repite = true;

    do {
        system("CLS");
        gotoxy(30, 8); cout << "**********************************************************" << endl;
        gotoxy(30, 9); cout << "***                   " << titulo << "                 ***" << endl;
        gotoxy(30, 10); cout << "**********************************************************" << endl;

        for (int i = 0; i < nopciones; i++) {
            gotoxy(43, 11 + i); // Centra las opciones correctamente
            if (i + 1 == opcionSeleccionada) {
                cout << " ==> " << opciones[i]; // Muestra la opción con indicador
            }
            else {
                cout << "     " << opciones[i]; // Muestra la opción sin indicador
            }
        }

        gotoxy(30, 16); cout << "**********************************************************" << endl;
        gotoxy(18, 19); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

        tecla = _getch(); // Captura la tecla presionada

        switch (tecla) {
        case 72: // Flecha arriba
            if (opcionSeleccionada > 1) opcionSeleccionada--;
            break;
        case 80: // Flecha abajo
            if (opcionSeleccionada < nopciones) opcionSeleccionada++;
            break;
        case 13: // Enter
            repite = false;
            break;
        }
    } while (repite);

    return opcionSeleccionada;
}

int MenuSuma(const char* titulo2, const char* opciones2[], int nopciones2) {
    int opcionSeleccionada2 = 1; // Opción inicial
    int tecla2;
    bool repite2 = true;

    do {
        system("CLS");
        gotoxy(30, 8); cout << "**********************************************************" << endl;
        gotoxy(30, 9); cout << "***               " << titulo2 << "                ***" << endl;
        gotoxy(30, 10); cout << "**********************************************************" << endl;

        for (int i = 0; i < nopciones2; i++) {
            gotoxy(43, 11 + i); // Centra las opciones correctamente
            if (i + 1 == opcionSeleccionada2) {
                cout << " ==> " << opciones2[i]; // Muestra la opción con indicador
            }
            else {
                cout << "     " << opciones2[i]; // Muestra la opción sin indicador
            }
        }

        gotoxy(30, 15); cout << "**********************************************************" << endl;
        gotoxy(16, 17); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

        tecla2 = _getch(); // Captura la tecla presionada

        switch (tecla2) {
        case 72: // Flecha arriba
            if (opcionSeleccionada2 > 1) opcionSeleccionada2--;
            break;
        case 80: // Flecha abajo
            if (opcionSeleccionada2 < nopciones2) opcionSeleccionada2++;
            break;
        case 13: // Enter
            repite2 = false;
            break;
        }
    } while (repite2);

    return opcionSeleccionada2;
}

int MenuResta(const char* titulo3, const char* opciones3[], int nopciones3) {
    int opcionSeleccionada3 = 1; // Opción inicial
    int tecla3;
    bool repite3 = true;

    do {
        system("CLS");
        gotoxy(30, 8); cout << "**********************************************************" << endl;
        gotoxy(30, 9); cout << "***               " << titulo3 << "               ***" << endl;
        gotoxy(30, 10); cout << "**********************************************************" << endl;

        for (int i = 0; i < nopciones3; i++) {
            gotoxy(43, 11 + i); // Centra las opciones correctamente
            if (i + 1 == opcionSeleccionada3) {
                cout << " ==> " << opciones3[i]; // Muestra la opción con indicador
            }
            else {
                cout << "     " << opciones3[i]; // Muestra la opción sin indicador
            }
        }

        gotoxy(30, 15); cout << "**********************************************************" << endl;
        gotoxy(16, 17); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

        tecla3 = _getch(); // Captura la tecla presionada

        switch (tecla3) {
        case 72: // Flecha arriba
            if (opcionSeleccionada3 > 1) opcionSeleccionada3--;
            break;
        case 80: // Flecha abajo
            if (opcionSeleccionada3 < nopciones3) opcionSeleccionada3++;
            break;
        case 13: // Enter
            repite3 = false;
            break;
        }
    } while (repite3);

    return opcionSeleccionada3;
}

int MenuMultiplicacion(const char* titulo4, const char* opciones4[], int nopciones4) {
    int opcionSeleccionada4 = 1; // Opción inicial
    int tecla4;
    bool repite4 = true;

    do {
        system("CLS");
        gotoxy(24, 9); cout << "*******************************************************************" << endl;
        gotoxy(24, 10); cout << "***               " << titulo4 << "               ***" << endl;
        gotoxy(24, 11); cout << "*******************************************************************" << endl;

        for (int i = 0; i < nopciones4; i++) {
            gotoxy(37, 12 + i); // Centra las opciones correctamente
            if (i + 1 == opcionSeleccionada4) {
                cout << " ==> " << opciones4[i]; // Muestra la opción con indicador
            }
            else {
                cout << "     " << opciones4[i]; // Muestra la opción sin indicador
            }
        }

        gotoxy(24, 16); cout << "*******************************************************************" << endl;
        gotoxy(16, 18); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

        tecla4 = _getch(); // Captura la tecla presionada

        switch (tecla4) {
        case 72: // Flecha arriba
            if (opcionSeleccionada4 > 1) opcionSeleccionada4--;
            break;
        case 80: // Flecha abajo
            if (opcionSeleccionada4 < nopciones4) opcionSeleccionada4++;
            break;
        case 13: // Enter
            repite4 = false;
            break;
        }
    } while (repite4);

    return opcionSeleccionada4;
}

int MenuReglas(const char* titulo5, const char* opciones5[], int nopciones5) {
    int opcionSeleccionada5 = 1; // Opción inicial
    int tecla5;
    bool repite5 = true;

    do {
        system("CLS");
        gotoxy(30, 8); cout << "**********************************************************" << endl;
        gotoxy(30, 9); cout << "***                   " << titulo5 << "                   ***" << endl;
        gotoxy(30, 10); cout << "**********************************************************" << endl;

        for (int i = 0; i < nopciones5; i++) {
            gotoxy(43, 11 + i); // Centra las opciones correctamente
            if (i + 1 == opcionSeleccionada5) {
                cout << " ==> " << opciones5[i]; // Muestra la opción con indicador
            }
            else {
                cout << "     " << opciones5[i]; // Muestra la opción sin indicador
            }
        }

        gotoxy(30, 16); cout << "**********************************************************" << endl;
        gotoxy(18, 19); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

        tecla5 = _getch(); // Captura la tecla presionada

        switch (tecla5) {
        case 72: // Flecha arriba
            if (opcionSeleccionada5 > 1) opcionSeleccionada5--;
            break;
        case 80: // Flecha abajo
            if (opcionSeleccionada5 < nopciones5) opcionSeleccionada5++;
            break;
        case 13: // Enter
            repite5 = false;
            break;
        }
    } while (repite5);

    return opcionSeleccionada5;
}

// Función para ingresar una matriz con validación
void IngresarMatriz(int** matriz, int filas, int columnas, int numMatriz) {
    string entrada;
    int valor;

    gotoxy(43, 6); cout << "Ingresando valores para la Matriz " << numMatriz << ":";

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            bool entradaValida = false;

            do {
                // Borra la entrada anterior
                gotoxy(42, 8 + i * 2); cout << "                                                   ";
                gotoxy(42, 8 + i * 2); cout << "Ingrese un numero entero para [" << i << "][" << j << "]: ";

                cin >> entrada;

                if (EsEntero(entrada)) {
                    valor = stoi(entrada);
                    entradaValida = true;

                    // 🔹 Borra completamente el mensaje de error cuando la entrada es correcta
                    gotoxy(42, 12 + filas * 2); cout << "                                                   ";
                }
                else {
                    // 🔹 Borra cualquier mensaje de error anterior antes de mostrar uno nuevo
                    gotoxy(42, 12 + filas * 2); cout << "                                                   ";
                    gotoxy(42, 12 + filas * 2); cout << "ERROR: Ingrese solo numeros enteros...";
                }

            } while (!entradaValida);

            matriz[i][j] = valor;
        }
    }

    // 🔹 Asegurar que no quede ningún mensaje de error al final
    gotoxy(42, 12 + filas * 2); cout << "                                                   ";
}


void TituloSuma() {
    gotoxy(40, 0);  cout << "------------------------------------------";
    gotoxy(40, 1);  cout << "|  +  |                            |  +  |";
    gotoxy(40, 2);  cout << "|~~~~~~      Suma De Matrices      ~~~~~~|";
    gotoxy(40, 3);  cout << "|  +  |                            |  +  |";
    gotoxy(40, 4);  cout << "------------------------------------------";
}

void TituloResta() {
    gotoxy(40, 0); cout << "-------------------------------------------";
    gotoxy(40, 1); cout << "|  -  |                             |  -  |";
    gotoxy(40, 2); cout << "|~~~~~~      Resta De Matrices      ~~~~~~|";
    gotoxy(40, 3); cout << "|  -  |                             |  -  |";
    gotoxy(40, 4); cout << "-------------------------------------------";
}

void TituloMultiplicacion() {
    gotoxy(37, 0); cout << "----------------------------------------------------";
    gotoxy(37, 1); cout << "|  -  |                                      |  -  |";
    gotoxy(37, 2); cout << "|~~~~~~      Multiplicacion De Matrices      ~~~~~~|";
    gotoxy(37, 3); cout << "|  -  |                                      |  -  |";
    gotoxy(37, 4); cout << "----------------------------------------------------";
}

void SumaMatrices(int** matrizA, int** matrizB, int** resultado, int filas, int columnas) {
    // Sumar las matrices
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j]; // Se suman las matrices
        }
    }

    // Mostrar la matriz resultante después de sumar
    gotoxy(50, 14); cout << "Resultado de la Suma:";
    MostrarMatriz(resultado, filas, columnas, 56, 16);
}

void OperacionSumaMatrices() {
    system("CLS");
    TituloSuma();

    int filasA, columnasA, filasB, columnasB;

    // Pedir dimensiones y validar que sean iguales
    do {
        gotoxy(40, 6); cout << "Ingresando las dimensiones para cada matriz...";
        gotoxy(40, 8); cout << "Ingrese el numero de filas de la Matriz A: ";
        cin >> filasA;
        gotoxy(40, 9); cout << "Ingrese el numero de columnas de la Matriz A: ";
        cin >> columnasA;

        gotoxy(40, 11); cout << "Ingrese el numero de filas de la Matriz B: ";
        cin >> filasB;
        gotoxy(40, 12); cout << "Ingrese el numero de columnas de la Matriz B: ";
        cin >> columnasB;

        if (filasA != filasB || columnasA != columnasB) {
            gotoxy(34, 15); cout << "ERROR: Ambas matrices deben tener las mismas dimensiones.";
            gotoxy(40, 17); cout << "Presione una tecla para intentarlo nuevamente...";
            _getch();
            system("CLS");
            TituloSuma();
        }
    } while (filasA != filasB || columnasA != columnasB);

    // Reservar memoria dinámica para las matrices
    int** matrizA = new int* [filasA];
    int** matrizB = new int* [filasA];
    int** resultado = new int* [filasA];

    for (int i = 0; i < filasA; i++) {
        matrizA[i] = new int[columnasA];
        matrizB[i] = new int[columnasA];
        resultado[i] = new int[columnasA];
    }

    // Ingresar los valores de las matrices
    system("CLS");
    TituloSuma();
    IngresarMatriz(matrizA, filasA, columnasA, 1);

    gotoxy(30, 20); cout << "Presione una tecla para ingresar los datos de la segunda matriz...";
    _getch();

    system("CLS");
    TituloSuma();
    IngresarMatriz(matrizB, filasA, columnasA, 2);

    gotoxy(20, 17); cout << "Presione cualquier tecla para ver las matrices ingresadas y el resultado...";
    _getch();

    // Mostrar las matrices ingresadas antes de la suma
    system("CLS");
    TituloSuma();

    gotoxy(39, 6);
    cout << "Matriz A:";
    MostrarMatriz(matrizA, filasA, columnasA, 39, 8);

    gotoxy(74, 6); cout << "Matriz B:";
    MostrarMatriz(matrizB, filasA, columnasA, 74, 8);

    SumaMatrices(matrizA, matrizB, resultado, filasA, columnasA);

    gotoxy(35, 25); cout << "Presione una tecla para volver al menu de sumas...";
    _getch();

    // Liberar memoria
    for (int i = 0; i < filasA; i++) {
        delete[] matrizA[i];
        delete[] matrizB[i];
        delete[] resultado[i];
    }
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
}

// Función para sumar dos matrices
// Recibe tres punteros a punteros a int, que son las dos matrices a sumar y la matriz resultado, y las dimensiones de las matrices
// Función para sumar dos matrices y mostrar el resultado
void RestaMatrices(int** matrizA, int** matrizB, int** resultado, int filas, int columnas) {
    // Restar las matrices
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j]; // Se restan las matrices
        }
    }

    // Mostrar la matriz resultante después de restar
    gotoxy(50, 14); cout << "Resultado de la Resta:";
    MostrarMatriz(resultado, filas, columnas, 56, 16);
}

void OperacionRestaMatrices() {
    system("CLS");
    TituloResta();  // Cambia a un título específico para la resta

    int filasA, columnasA, filasB, columnasB;

    // Pedir dimensiones y validar que sean iguales
    do {
        gotoxy(40, 6); cout << "Ingresando las dimensiones para cada matriz...";
        gotoxy(40, 8); cout << "Ingrese el numero de filas de la Matriz A: ";
        cin >> filasA;
        gotoxy(40, 9); cout << "Ingrese el numero de columnas de la Matriz A: ";
        cin >> columnasA;

        gotoxy(40, 11); cout << "Ingrese el numero de filas de la Matriz B: ";
        cin >> filasB;
        gotoxy(40, 12); cout << "Ingrese el numero de columnas de la Matriz B: ";
        cin >> columnasB;

        if (filasA != filasB || columnasA != columnasB) {
            gotoxy(34, 15); cout << "ERROR: Ambas matrices deben tener las mismas dimensiones.";
            gotoxy(40, 17); cout << "Presione una tecla para intentarlo nuevamente...";
            _getch();
            system("CLS");
            TituloResta();  // Usar el título de la resta
        }
    } while (filasA != filasB || columnasA != columnasB);

    // Reservar memoria dinámica para las matrices
    int** matrizA = new int* [filasA];
    int** matrizB = new int* [filasA];
    int** resultado = new int* [filasA];

    for (int i = 0; i < filasA; i++) {
        matrizA[i] = new int[columnasA];
        matrizB[i] = new int[columnasA];
        resultado[i] = new int[columnasA];
    }

    // Ingresar los valores de las matrices
    system("CLS");
    TituloResta();
    IngresarMatriz(matrizA, filasA, columnasA, 1);

    gotoxy(30, 17); cout << "Presione una tecla para ingresar los datos de la segunda matriz...";
    _getch();

    system("CLS");
    TituloResta();
    IngresarMatriz(matrizB, filasA, columnasA, 2);

    gotoxy(30, 17); cout << "Presione cualquier tecla para ver las matrices ingresadas y el resultado...";
    _getch();

    // Mostrar las matrices ingresadas antes de la resta
    system("CLS");
    TituloResta();

    gotoxy(39, 6); cout << "Matriz A:";
    MostrarMatriz(matrizA, filasA, columnasA, 39, 8);

    gotoxy(74, 6); cout << "Matriz B:";
    MostrarMatriz(matrizB, filasA, columnasA, 74, 8);

    RestaMatrices(matrizA, matrizB, resultado, filasA, columnasA);

    gotoxy(35, 25); cout << "Presione una tecla para volver al menu de restas...";
    _getch();

    // Liberar memoria
    for (int i = 0; i < filasA; i++) {
        delete[] matrizA[i];
        delete[] matrizB[i];
        delete[] resultado[i];
    }
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
}

void MultiplicaMatrices(int** matrizA, int** matrizB, int** resultado, int filasA, int columnasA, int columnasB) {
    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            resultado[i][j] = 0;
        }
    }

    // Multiplicación de matrices
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {  // Recorre la columna de A y la fila de B
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Mostrar la matriz resultante después de la multiplicación
    gotoxy(50, 14); cout << "Resultado de la Multiplicacion:";
    MostrarMatriz(resultado, filasA, columnasB, 56, 16);
}

void OperacionMultiplicacionMatrices() {
    system("CLS");
    TituloMultiplicacion();

    int filasA, columnasA, filasB, columnasB;

    // Pedir dimensiones y validar que sean compatibles
    do {
        gotoxy(40, 6); cout << "Ingresando las dimensiones para cada matriz...";
        gotoxy(40, 8); cout << "Ingrese el numero de filas de la Matriz A: ";
        cin >> filasA;
        gotoxy(40, 9); cout << "Ingrese el numero de columnas de la Matriz A: ";
        cin >> columnasA;

        gotoxy(40, 11); cout << "Ingrese el numero de filas de la Matriz B: ";
        cin >> filasB;
        gotoxy(40, 12); cout << "Ingrese el numero de columnas de la Matriz B: ";
        cin >> columnasB;

        if (columnasA != filasB) {
            gotoxy(34, 15); cout << "ERROR: El numero de columnas de A debe coincidir con las filas de B.";
            gotoxy(40, 17); cout << "Presione una tecla para intentarlo nuevamente...";
            _getch();
            system("CLS");
            TituloMultiplicacion();
        }
    } while (columnasA != filasB);

    // Reservar memoria dinámica para las matrices
    int** matrizA = new int* [filasA];
    int** matrizB = new int* [filasB];
    int** resultado = new int* [filasA];

    for (int i = 0; i < filasA; i++) {
        matrizA[i] = new int[columnasA];
    }
    for (int i = 0; i < filasB; i++) {
        matrizB[i] = new int[columnasB];
    }
    for (int i = 0; i < filasA; i++) {
        resultado[i] = new int[columnasB];
    }

    // Ingresar los valores de las matrices
    system("CLS");
    TituloMultiplicacion();
    IngresarMatriz(matrizA, filasA, columnasA, 1);

    gotoxy(30, 17); cout << "Presione una tecla para ingresar los datos de la segunda matriz...";
    _getch();

    system("CLS");
    TituloMultiplicacion();
    IngresarMatriz(matrizB, filasB, columnasB, 2);

    gotoxy(30, 17); cout << "Presione cualquier tecla para ver las matrices ingresadas y el resultado...";
    _getch();

    // Mostrar las matrices ingresadas antes de la multiplicación
    system("CLS");
    TituloMultiplicacion();

    gotoxy(39, 6);
    cout << "Matriz A:";
    MostrarMatriz(matrizA, filasA, columnasA, 39, 8);

    gotoxy(74, 6); cout << "Matriz B:";
    MostrarMatriz(matrizB, filasB, columnasB, 74, 8);

    MultiplicaMatrices(matrizA, matrizB, resultado, filasA, columnasA, columnasB);

    gotoxy(35, 26); cout << "Presione una tecla para volver al menu de multiplicacion...";
    _getch();

    // Liberar memoria
    for (int i = 0; i < filasA; i++) {
        delete[] matrizA[i];
        delete[] resultado[i];
    }
    for (int i = 0; i < filasB; i++) {
        delete[] matrizB[i];
    }
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
}


// Función para mostrar la matriz
// Recibe un puntero a un puntero a int, que es la matriz, y las dimensiones de la matriz
void MostrarMatriz(int** matriz, int filas, int columnas, int posX, int posY) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            gotoxy(posX + j * 5, posY + i * 2); // Espaciado adecuado
            cout << matriz[i][j];
        }
    }
}

// Función para verificar si la entrada es un número entero
bool EsEntero(const string& entrada) {
    if (entrada.empty()) return false;

    int inicio = (entrada[0] == '-') ? 1 : 0; // Permite negativos

    for (size_t i = inicio; i < entrada.length(); ++i) {
        if (!isdigit(entrada[i])) return false;
    }

    return true;
}

void ReglasSumaMatrices() {
    system("CLS");
    TituloSuma();
    gotoxy(10, 6); cout << "Para Sumar Matrices, estas deben de tener obligatoriamente el mismo numero de filas y columnas";
    gotoxy(16, 7); cout << "Es decir, no se puede sumar una matriz de 3x2 con otra de 3x3. Esto es asi ya que,";
    gotoxy(25, 8); cout << "Se suman los terminos que ocupan el mismo lugar en las matrices.";
    gotoxy(56, 10); cout << "Por Ejemplo:";
    gotoxy(25, 12); cout << "     Matriz 1:                  Matriz 2:                 Resultado:";
    gotoxy(25, 13); cout << "     A   B   C                  A   B   C                 A   B   C";
    gotoxy(25, 14); cout << "    -----------                -----------               -----------";
    gotoxy(25, 15); cout << "0  | 2 | 3 | 5 |           0  | 1 | 6 | 2 |          0  | 3 | 9 | 7 |";
    gotoxy(25, 16); cout << "    -----------                -----------               -----------";
    gotoxy(25, 17); cout << "1  | 1 | 6 | 2 |     +     1  | 6 | 3 | 1 |    =     1  | 7 | 9 | 3 |";
    gotoxy(25, 18); cout << "    -----------                -----------               -----------";
    gotoxy(25, 19); cout << "2  | 2 | 1 | 4 |           2  | 1 | 7 | 2 |          2  | 3 | 8 | 6 |";
    gotoxy(25, 20); cout << "    -----------                -----------               -----------";
    gotoxy(35, 24); cout << "Presione una tecla para regresar al menu de reglas...";
    _getch();
}

void ReglasRestaMatrices() {
    system("CLS");
    TituloResta();
    gotoxy(10, 6); cout << "Para Restar Matrices, estas deben de tener obligatoriamente el mismo numero de filas y columnas";
    gotoxy(16, 7); cout << "Es decir, no se puede restar una matriz de 3x2 con otra de 3x3. Esto es asi ya que,";
    gotoxy(25, 8); cout << "Se restan los terminos que ocupan el mismo lugar en las matrices.";
    gotoxy(56, 10); cout << "Por Ejemplo:";
    gotoxy(25, 12); cout << "     Matriz 1:                  Matriz 2:                 Resultado:";
    gotoxy(25, 13); cout << "     A   B   C                  A   B   C                 A   B   C";
    gotoxy(25, 14); cout << "    -----------                -----------               -----------";
    gotoxy(25, 15); cout << "0  | 2 | 6 | 5 |           0  | 1 | 6 | 2 |          0  | 1 | 0 | 3 |";
    gotoxy(25, 16); cout << "    -----------                -----------               -----------";
    gotoxy(25, 17); cout << "1  | 6 | 6 | 2 |     -     1  | 1 | 3 | 1 |    =     1  | 5 | 3 | 1 |";
    gotoxy(25, 18); cout << "    -----------                -----------               -----------";
    gotoxy(25, 19); cout << "2  | 2 | 7 | 4 |           2  | 1 | 1 | 2 |          2  | 1 | 6 | 2 |";
    gotoxy(25, 20); cout << "    -----------                -----------               -----------";
    gotoxy(35, 24); cout << "Presione una tecla para regresar al menu de reglas...";
    _getch();
}

void ReglasMultiplicacionMatrices() {
    system("CLS");
    TituloMultiplicacion();
    gotoxy(15, 6); cout << "Para poder obtener el producto dos matrices, la primera debe de tener el mismo numero de columnas";
    gotoxy(15, 7); cout << "que filas de la segunda. La matriz resultante quedará con el mismo numero de filas de la";
    gotoxy(31, 8); cout << "primera y con el mismo numero de columnas de la segunda.";
    gotoxy(15, 10); cout << "Es decir, si tenemos una matriz 2x3 y la multiplicamos por otra de orden 3x5, la matriz";
    gotoxy(46, 11); cout << "resultante sera de orden 2x5";
    gotoxy(50, 13); cout << "(2x3) x (3x5) = (2x5)";
    gotoxy(55, 15); cout << "Por Ejemplo:";
    gotoxy(10, 17); cout << "     Matriz 1:            Matriz 2:                  Procedimiento:                   Resultado:";
    gotoxy(10, 18); cout << "     A   B                A   B   C                                                   A    B   C";
    gotoxy(10, 19); cout << "    -------              -----------           ---------------------------           --------------";
    gotoxy(10, 20); cout << "0  | 2 | 6 |         0  | 1 | 6 | 2 |         | 2*1+6*1  2*6+6*3  2*2+6*1 |       0 |  8 | 30 | 10 |";
    gotoxy(10, 21); cout << "    -------     x        -----------     =    ----------------------------     =     --------------";
    gotoxy(10, 22); cout << "1  | 6 | 6 |         1  | 1 | 3 | 1 |         | 6*1+6*1  6*6+6*3  6*2+6*1 |       1 | 12 | 54 | 18 |";
    gotoxy(10, 23); cout << "    -------              -----------           ---------------------------           --------------";
    gotoxy(35, 26); cout << "Presione una tecla para regresar al menu de reglas...";
    _getch();
}

// Función para mover el cursor a una posición específica en la consola
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
 