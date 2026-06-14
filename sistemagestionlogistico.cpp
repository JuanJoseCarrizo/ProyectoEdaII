#include "sistemagestionlogistico.h"
#include <fstream>
#include <iostream>
#include <cstring>



SistemaLogistico::SistemaLogistico() {

    grafo = new Grafo(10);

    cantidadCiudades=0;
    capacidadCiudades=10;
    ciudades=new Ciudad[capacidadCiudades];

    historial = nullptr;

    cargarHistorial();
}
//Constructor: cuando el sistema arranca, reserva memoria dinámica para un nuevo 
//objeto Grafo que se configura inicialmente para soportar hasta 10 ciudades
//NO agrada mucho, hay que modificarlo porque se puede desbordar

SistemaLogistico::~SistemaLogistico() {

    delete grafo;
    delete[] ciudades;

    while (historial != nullptr) {

        NodoHistorial* auxiliar = historial;

        historial = historial->siguiente;

        delete auxiliar;
    }
}
//Destructor: cuando el programa se cierra, libera la memoria que ocupaba 
//el objeto grafo para evitar fugas de memoria.


void SistemaLogistico::cargarMapaInicial()
{
    agregarCiudad("Cordoba Capital", 0, 0);
    agregarCiudad("Villa Carlos Paz", -50, 20);
    agregarCiudad("Villa Maria", 150, 100);
    agregarCiudad("Rio Cuarto", 50, 250);
    agregarCiudad("Bell Ville", 220, 100);
    agregarCiudad("San Francisco", 350, 50);
    agregarCiudad("Jesus Maria", 80, -50);
    agregarCiudad("Alta Gracia", -20, 80);
    agregarCiudad("Marcos Juarez", 320, 140);

    agregarRuta(0,1,35);
    agregarRuta(0,2,146);
    agregarRuta(0,4,200);
    agregarRuta(0,6,50);
    agregarRuta(0,7,36);

    agregarRuta(1,3,215);
    agregarRuta(1,7,40);

    agregarRuta(2,3,136);
    agregarRuta(2,4,63);
    agregarRuta(2,8,170);

    agregarRuta(4,3,220);
    agregarRuta(4,5,195);
    agregarRuta(4,8,100);

    agregarRuta(6,5,320);
    agregarRuta(6,4,180);

    agregarRuta(8,5,80);

    agregarRuta(7,2,120);
}


void SistemaLogistico::registrarHistorial(
    int origen,
    int destino,
    ResultadoRuta resultado)
{
    NodoHistorial* nuevoNodo =
        new NodoHistorial();

    strcpy(
        nuevoNodo->dato.origen,
        obtenerNombreCiudad(origen).c_str()
    );

    strcpy(
        nuevoNodo->dato.destino,
        obtenerNombreCiudad(destino).c_str()
    );

    nuevoNodo->dato.distancia =
        resultado.distanciaTotal;

    nuevoNodo->siguiente = historial;

    historial = nuevoNodo;
}

void SistemaLogistico::guardarHistorial() {

    std::ofstream archivo("historial.txt");

    if (!archivo.is_open()) {
        return;
    }

    NodoHistorial* aux = historial;

    while (aux != nullptr) {

        archivo
            << aux->dato.origen
            << "|"
            << aux->dato.destino
            << "|"
            << aux->dato.distancia
            << "\n";

        aux = aux->siguiente;
    }

    archivo.close();
}

void SistemaLogistico::cargarHistorial() {

    std::ifstream archivo("historial.txt");

    if (!archivo.is_open()) {
        return;
    }

    std::string origen;
    std::string destino;
    float distancia;

    while (getline(archivo, origen, '|')) {

        getline(archivo, destino, '|');

        archivo >> distancia;
        archivo.ignore();

        NodoHistorial* nuevo =
            new NodoHistorial();

        strcpy(
            nuevo->dato.origen,
            origen.c_str()
        );

        strcpy(
            nuevo->dato.destino,
            destino.c_str()
        );

        nuevo->dato.distancia =
            distancia;

        nuevo->siguiente = historial;

        historial = nuevo;
    }

    archivo.close();
}

void SistemaLogistico::inicializar() {
    cargarDatos();
}
//Prepara el sistema cuando arranca
//En este caso, su única tarea es llamar a la función cargarDatos() 
//para recuperar el mapa guardado en el disco.

void SistemaLogistico::agregarCiudad(std::string nombre, float x, float y) {
    
    //si el vector se llena, se tiene que expandir manualmente
    if (cantidadCiudades == capacidadCiudades) {
        capacidadCiudades *= 2; //duplicamos la capacidad máxima
        Ciudad* nuevoArreglo = new Ciudad[capacidadCiudades]; //creamos un arreglo nuevo más grande

        //copiamos todas las ciudades del anterior al nuevo
        for (int i = 0; i < cantidadCiudades; i++) {
            nuevoArreglo[i] = ciudades[i];
        }

        delete[] ciudades; // destruimos el viejo vector que quedó chico
        ciudades = nuevoArreglo; // apuntamos al nuevo espacio ampliado
    }

    Ciudad nueva;
    //Se crea una estructura temporal/auxiliar de tipo Ciudad llamada nueva

    nueva.id = cantidadCiudades;//contador de ciudades

    strncpy(nueva.nombre, nombre.c_str(), 49);
    //strncpy: Copia el texto de nombre dentro del arreglo de caracteres fijo de la estructura Ciudad
    nueva.nombre[49] = '\0';
    //Se asegura que el último carácter sea el terminador nulo, indicando el fin de la cadena de texto. 
    //Esto es importante para cuando usemos los archivos binarios despues

    nueva.x = x;
    nueva.y = y;

    // se le asigna la nueva ciudad en la última posición libre e incrementamos el contador
    ciudades[cantidadCiudades] = nueva;
    cantidadCiudades++;
    //queda apuntando al siguiente elemento que marcara el id del proximo
}

void SistemaLogistico::agregarRuta(int origen, int destino, float km) {
    grafo->agregarRuta(origen, destino, km);
}
//el sistema logístico no sabe cómo manejar grafos directamente, así que le "delega" el 
//trabajo a su objeto interno grafo usando el operador flecha (->) porque es un puntero

void SistemaLogistico::cortarRuta(int origen, int destino) {
    grafo->cortarRuta(origen, destino);
}
//igual que el anterior, le pide al grafo que rompa la conexión entre esas dos ciudades en la matriz de adyacencia

ResultadoRuta SistemaLogistico::calcularRutaOptima(int origen, int destino) {
    ResultadoRuta resultado = grafo->calcularDijkstra(origen, destino);
    //le pide al grafo que ejecute el Algoritmo de Dijkstra entre el origen y el destino
    //el camino y los kilómetros se guardan en la variable resultado.

    registrarHistorial(origen,destino,resultado);
     guardarHistorial();
    //método para registrar el resultado en la pila historial
    
    return resultado;
    //Finalmente, devuelve el resultado
}



void SistemaLogistico::guardarDatos() {
    std::ofstream archivo("ciudades.dat", std::ios::binary);
    //Abre (o crea) un archivo llamado ciudades.dat en modo de escritura binaria (std::ios::binary)
    //ofstream (Output File Stream): Se usa exclusivamente para escribir/guardar datos en un archivo (crea el archivo si no existe)
    //Cuando se abre un archivo con fstream, por defecto se maneja en modo .txt
    //pero para guardar estructuras como el struct o la matriz utilizamos el modificador ios::binary
    
    if (!archivo.is_open()) {
        std::cout << "Error al guardar archivo.\n";
        return;
    }//chequea que el archivo se abra correctamente, sino tira error

    for (int i = 0; i < cantidadCiudades; i++) {
        archivo.write(
            reinterpret_cast<const char*>(&ciudades[i]),//reinterpreta al struct como char y le manda por referencia la direccion
            sizeof(Ciudad) //calcula tamaño en bytes de Ciudad
        );
        //Al hacer todo esto la ciudad se guarda en el archivo .dat como una copia identica o "foto"
    }

   archivo.close();

   guardarHistorial();

    std::cout << "Datos guardados correctamente.\n";
}

void SistemaLogistico::cargarDatos() {
    std::ifstream archivo("ciudades.dat", std::ios::binary);
    //ifstream (Input File Stream): Se usa exclusivamente para leer/cargar datos desde un archivo hacia tu programa.
    //Abre el archivo ciudades.dat en modo de lectura binaria

    if (!archivo.is_open()) {
        return;
    }
    //archivo.is_open(): Es un método propio de los flujos de fstream
    //Si el archivo no existe, sale en silencio sin lanzar errores

    // se reinicia el contador de ciudades a 0
    cantidadCiudades = 0;
   
    Ciudad ciudadAuxiliar; //auxiliar para guardar datos que se usan en el bucle que sigue

    while (
        archivo.read(
            reinterpret_cast<char*>(&ciudadAuxiliar),
            sizeof(Ciudad)
        )
    ) {
        agregarCiudad(ciudadAuxiliar.nombre, ciudadAuxiliar.x, ciudadAuxiliar.y);
    }
    //bucle de lectura: archivo.read extrae del archivo el número exacto de bytes 
    //que componen una Ciudad y los vuelca en la variable temporal ciudadAuxiliar
    //Si todo sale bien, mete esa ciudad en el vector ciudades
    //el ciclo se detiene automáticamente cuando se llega al final del archivo (EOF)

    archivo.close();
}

void SistemaLogistico::mostrarHistorial() {

    std::cout << "\n===== HISTORIAL =====\n";

    NodoHistorial* auxiliar = historial;

    while (auxiliar != nullptr) {

        std::cout
            << "Origen: "
            << auxiliar->dato.origen
            << "\n";

        std::cout
            << "Destino: "
            << auxiliar->dato.destino
            << "\n";

        std::cout
            << "Distancia: "
            << auxiliar->dato.distancia
            << " km\n";

        std::cout
            << "---------------------\n";

        auxiliar = auxiliar->siguiente;
    }
}
Grafo& SistemaLogistico::getGrafo() {
    return *grafo;
}
//Getter: Como grafo es un puntero interno (Grafo*), este método devuelve el objeto 
//"desapuntado" (utilizando el asterisco *) en forma de referencia (Grafo&), 
//permitiendo que otras partes del programa interactúen con la matriz sin romper el 
//encapsulamiento. Esto es para evitar que alguien lo pueda modificar y romperlo

std::string SistemaLogistico::obtenerNombreCiudad(int id) {
    //verificamos que el ID sea válido y exista
    if (id >= 0 && id < cantidadCiudades) {
        return ciudades[id].nombre;
    }
    return "Ciudad Desconocida";//si no encuentra nada

}

