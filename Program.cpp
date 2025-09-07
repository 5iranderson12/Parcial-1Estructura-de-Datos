#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    // Autoevaluación y nombre completo
    std::cout << "=== PARCIAL 1 - MANEJO DE ESTRUCTURAS DE DATOS ===" << std::endl;
    std::cout << "Nombre completo: Anderson Saul Maravilla Callejas" << std::endl;
    std::cout << "Autoevaluacion: 10/10" << std::endl;
    std::cout << "=================================================" << std::endl << std::endl;
    
    // 1. Declarar un vector dinámico de temperaturas
    int numDias;
    std::cout << "¿Cuantos dias se registraran? ";
    std::cin >> numDias;
    
    std::vector<float> temperaturas(numDias);
    
    // Pedir temperaturas al usuario
    for (int i = 0; i < numDias; i++) {
        std::cout << "Ingrese la temperatura del dia " << (i + 1) << ": ";
        std::cin >> temperaturas[i];
    }
    
    std::cout << std::endl;
    
    // 2. Mostrar las temperaturas usando un puntero
    std::cout << "=== TEMPERATURAS REGISTRADAS ===" << std::endl;
    float* ptr = temperaturas.data(); // Puntero al inicio del vector
    float suma = 0.0f;
    
    for (int i = 0; i < numDias; i++) {
        std::cout << "Dia " << (i + 1) << ": " << *(ptr + i) << "°C" << std::endl;
        suma += *(ptr + i);
    }
    
    float promedio = suma / numDias;
    std::cout << "Temperatura promedio: " << promedio << "°C" << std::endl << std::endl;
    
    // 3. Buscar una temperatura específica
    float tempBuscada;
    std::cout << "Ingrese una temperatura para buscar: ";
    std::cin >> tempBuscada;
    
    bool encontrada = false;
    int posicion = -1;
    
    for (int i = 0; i < numDias; i++) {
        if (temperaturas[i] == tempBuscada) {
            encontrada = true;
            posicion = i;
            break;
        }
    }
    
    if (encontrada) {
        std::cout << "Temperatura " << tempBuscada << "°C encontrada en el dia " << (posicion + 1) << std::endl;
    } else {
        std::cout << "La temperatura " << tempBuscada << "°C no existe en el registro." << std::endl;
    }
    std::cout << std::endl;
    
    // 4. Ordenar las temperaturas
    std::cout << "=== TEMPERATURAS ORDENADAS (menor a mayor) ===" << std::endl;
    std::vector<float> temperaturasOrdenadas = temperaturas; // Copia para mantener el original
    std::sort(temperaturasOrdenadas.begin(), temperaturasOrdenadas.end());
    
    for (size_t i = 0; i < temperaturasOrdenadas.size(); i++) {
        std::cout << temperaturasOrdenadas[i] << "°C ";
    }
    std::cout << std::endl << std::endl;
    
    // 5. Manejo de una lista de equipos
    std::cout << "=== MANEJO DE EQUIPOS ===" << std::endl;
    std::list<std::string> equipos;
    
    // Insertar nombres de equipos
    int numEquipos;
    std::cout << "¿Cuantos equipos desea registrar? ";
    std::cin >> numEquipos;
    
    std::cin.ignore(); // Limpiar buffer
    
    for (int i = 0; i < numEquipos; i++) {
        std::string nombreEquipo;
        std::cout << "Ingrese el nombre del equipo " << (i + 1) << ": ";
        std::getline(std::cin, nombreEquipo);
        equipos.push_back(nombreEquipo);
    }
    
    // Mostrar la lista de equipos usando iterador
    std::cout << "\n=== LISTA DE EQUIPOS ===" << std::endl;
    int contador = 1;
    for (std::list<std::string>::iterator it = equipos.begin(); it != equipos.end(); ++it) {
        std::cout << contador << ". " << *it << std::endl;
        contador++;
    }
    
    // Buscar un equipo específico
    std::string equipoBuscado;
    std::cout << "\nIngrese el nombre del equipo a buscar: ";
    std::getline(std::cin, equipoBuscado);
    
    std::list<std::string>::iterator encontrado = std::find(equipos.begin(), equipos.end(), equipoBuscado);
    
    if (encontrado != equipos.end()) {
        std::cout << "Equipo '" << equipoBuscado << "' encontrado en la lista." << std::endl;
    } else {
        std::cout << "Equipo '" << equipoBuscado << "' no encontrado en la lista." << std::endl;
    }
    
    // Ordenar los equipos
    equipos.sort();
    std::cout << "\n=== EQUIPOS ORDENADOS ALFABETICAMENTE ===" << std::endl;
    contador = 1;
    for (std::list<std::string>::iterator it = equipos.begin(); it != equipos.end(); ++it) {
        std::cout << contador << ". " << *it << std::endl;
        contador++;
    }
    
    // Eliminar un equipo específico
    std::string equipoEliminar;
    std::cout << "\nIngrese el nombre del equipo a eliminar: ";
    std::getline(std::cin, equipoEliminar);
    
    size_t sizeAntes = equipos.size();
    equipos.remove(equipoEliminar);
    size_t sizeDespues = equipos.size();
    
    if (sizeAntes > sizeDespues) {
        std::cout << "Equipo '" << equipoEliminar << "' eliminado exitosamente." << std::endl;
    } else {
        std::cout << "Equipo '" << equipoEliminar << "' no encontrado para eliminar." << std::endl;
    }
    
    // Mostrar lista final de equipos
    std::cout << "\n=== LISTA FINAL DE EQUIPOS ===" << std::endl;
    if (equipos.empty()) {
        std::cout << "No hay equipos en la lista." << std::endl;
    } else {
        contador = 1;
        for (std::list<std::string>::iterator it = equipos.begin(); it != equipos.end(); ++it) {
            std::cout << contador << ". " << *it << std::endl;
            contador++;
        }
    }
    
    std::cout << "\n=== PROGRAMA TERMINADO ===" << std::endl;
    
    return 0;
}
