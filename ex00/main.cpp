#include "Bureaucrat.hpp"
#include <iostream>
#include <string>


int main() {
    // Prueba 1: Intentar crear un Bureaucrat con nota inválida
    try {
        Bureaucrat jefe("Manolo", 0); // Esto va a lanzar GradeTooHighException
        std::cout << jefe << std::endl; // Esto no llegará a ejecutarse
    }
    catch (const std::exception& e) {
        // Capturamos por referencia a la clase base (std::exception)
        // e.what() llamará polimórficamente al what() de tu excepción
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Prueba 2: Intentar forzar el error con incrementos
    try {
        Bureaucrat currante("Paco", 2);
        std::cout << currante << std::endl;

        currante.incrementGrade(); // Nota baja a 1
        std::cout << currante << std::endl;

        currante.incrementGrade(); // Esto lanzará la excepción (1 - 1 = 0, inválido)
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        // También puedes capturar la clase específica si quieres
        std::cerr << "Excepción específica: " << e.what() << std::endl;
    }

    return 0;
}
