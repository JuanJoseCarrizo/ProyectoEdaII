# Sistema Inteligente de Gestión Logística y Optimización de Rutas (Provincia de Córdoba)

Parcial de la materia **Estructura de Datos y Algoritmos II** (Universidad Provincial de Ezeiza). Aplicación de escritorio modular en C++ y Qt6 para la simulación, persistencia binaria y optimización de flujos de transporte utilizando teoría de grafos.
---

## Datos Académicos
* ** Institución:** Universidad Provincial de Ezeiza (UPE)
* ** Materia:** Estructura de Datos y Algoritmos II
* ** Docente:** Osvaldo Pini
* ** Ciclo:** 2026
  
* ** Integrantes:**
*  Gomez Ornella
*  Juan Carrizo
*  Pablo Carrizo
*  Bertera Lautaro

---
## Tecnologías e Iconos Utilizados
Mantenemos el stack tecnológico alineado con las herramientas nativas modernas del desarrollo en C++:
[![](https://img.shields.io/badge/Language-C%2B%2B%2017-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)]
(https://isocpp.org/)[![](https://img.shields.io/badge/Framework-Qt%206.x-41CD52?style=for-the-badge&logo=qt&logoColor=white)]
(https://www.qt.io/)[![](https://img.shields.io/badge/Build%20System-CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)]
(https://cmake.org/)[![](https://img.shields.io/badge/Environment-Linux%20%2F%20Windows-000000?style=for-the-badge&logo=linux&logoColor=white)](https://www.kernel.org/)
---
## Descripción y Arquitectura Modular
El proyecto implementa una red de transporte interurbano centrada en la provincia de Córdoba. A diferencia de las soluciones monolíticas básicas, este sistema desacopla de forma estricta la interfaz visual de la lógica del negocio mediante los siguientes componentes técnicos:

### Estructura de Módulos (`.h` / `.cpp`)
* **`ciudad.h`:** Define el nodo base (`struct Ciudad`). Contiene campos estructurados estáticos como `char nombre[50]` para prevenir pérdidas de punteros volátiles y coordenadas absolutas `(x, y)` para mapeo en el canvas gráfico.
* **`grafo.h` / `grafo.cpp`:** Encapsula la red de caminos a través de una **Matriz de Adyacencia Dinámica** (`float** matriz`). Ofrece búsquedas de aristas directas en tiempo constante de $O(1)$.
* **`sistemagestionlogistico.h` / `.cpp`:** Funciona como controlador central de operaciones. Administra colecciones de nodos, llamadas al motor de optimización, persistencia en disco y un registro histórico estructurado.
* **`mainwindow.h` / `mainwindow.cpp`:** Maneja la capa de presentación visual montada sobre componentes `QGraphicsScene` y eventos controlados del framework Qt6.
---
## Funcionalidades Técnicas Clave
### 1. Motor de Optimización (Dijkstra)Implementación nativa del algoritmo de caminos mínimos. Al iniciar el cálculo, inicializa vectores auxiliares dinámicos en la memoria RAM (`distancias`, `visitados` y `padres`), ejecuta pasos de **relajación de aristas** y reconstruye la secuencia de viaje de forma inversa a partir del nodo destino. Toda la memoria auxiliar se libera mediante `delete[]` para mitigar fugas de memoria (*memory leaks*).
### 2. Gestión de Contingencias DinámicasEl software emula cortes de rutas terrestres en tiempo real mediante la asignación de una constante abstracta de infinito:$$\text{INF} = 999999.0f$$Cuando se reporta una ruta bloqueada, el controlador altera la celda simétrica en la Matriz de Adyacencia. Al realizar un nuevo cálculo, el algoritmo de Dijkstra se ve forzado a desviar el flujo logístico a través de carreteras provinciales alternativas sin romper la topología original del grafo.
### 3. Visualización Eficiente en la InterfazLa renderización gráfica utiliza un plano de vectores estáticos preestablecidos en pantalla (`QGraphicsLineItem*`). En lugar de redibujar elementos dinámicamente en cada ciclo de reloj (operación costosa para la CPU), el método `pintarRutaOptima` intercepta el camino devuelto por el algoritmo y tiñe las aristas involucradas con color verde activo (`setPen(azul)`).
### 4. Persistencia Segura e Historial en Pila BinariaEl historial de búsquedas del usuario se estructura en memoria mediante una **Pila Dinámica Enlazada** (`NodoHistorial*`). La persistencia a largo plazo se gestiona volcando bloques exactos de bytes en disco utilizando flujos binarios de la librería `<fstream>` mediante la estructura dedicada:

```cpp
struct RegistroHistorial {
    char origen[50];
    char destino[50];
    float distancia;
};

```Esto evita fallos de segmentación (Segmentation Faults) provocados por la serialización de punteros dinámicos o cadenas pesadas (std::string).

Para Compilar y Ejecutar
Este proyecto utiliza el sistema de construcción multiplataforma CMake.

Requisitos Previos
Compilador C++ compatible (GCC / MinGW 64-bit o Clang).

Librerías de Qt6 instaladas (módulos Core, Gui y Widgets).

CMake versión 3.16 o superior.

-

 LicenciaEste proyecto es de codigo abierto.
