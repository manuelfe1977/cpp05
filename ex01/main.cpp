#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

int main() {
    std::cout << "===== PRUEBA 1: Creación de Formularios Válidos e Inválidos =====" << std::endl;
    try {
        Form f1("Contrato Estándar", 50, 25);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nIntentando crear formulario con nota requerida de 0 (Muy alta)..." << std::endl;
        Form f2("Formulario Ilegal Alta", 0, 100);
    } catch (const std::exception& e) {
        std::cerr << "Capturada excepción esperada: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nIntentando crear formulario con nota requerida de 151 (Muy baja)..." << std::endl;
        Form f3("Formulario Ilegal Baja", 100, 151);
    } catch (const std::exception& e) {
        std::cerr << "Capturada excepción esperada: " << e.what() << std::endl;
    }

    std::cout << "\n===== PRUEBA 2: Firma Exitosa (Grado suficiente) =====" << std::endl;
    try {
        Bureaucrat jefe("Hermes Conrad", 10);
        Form contrato("Subida de Sueldo", 20, 20); // Requiere grado 20, Hermes tiene 10 (puede firmar)

        std::cout << jefe << std::endl;
        std::cout << contrato << std::endl;

        // El burócrata intenta firmar
        jefe.signForm(contrato);

        // Verificamos que el estado del formulario cambió a firmado
        std::cout << contrato << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n===== PRUEBA 3: Firma Fallida (Grado insuficiente) =====" << std::endl;
    try {
        Bureaucrat becario("Fry", 120);
        Form contratoTopSecret("Planos del Área 51", 15, 5); // Requiere grado 15, Fry tiene 120 (no puede)

        std::cout << becario << std::endl;
        std::cout << contratoTopSecret << std::endl;

        // El burócrata intenta firmar, debería pillar el catch interno de signForm e imprimir el por qué
        becario.signForm(contratoTopSecret);

        // Verificamos que el formulario sigue sin firmar
        std::cout << contratoTopSecret << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado (no debería salir de signForm): " << e.what() << std::endl;
    }

    std::cout << "\n===== PRUEBA 4: Intentar firmar un formulario ya firmado =====" << std::endl;
    try {
        Bureaucrat jefe("Hermes Conrad", 10);
        Form autorizacion("Permiso de Vacaciones", 50, 50);

        jefe.signForm(autorizacion); // Primera firma: Éxito
        jefe.signForm(autorizacion); // Segunda firma: ¿Qué pasa aquí? Depende de tu código, suele volver a decir que está firmado o mantenerse igual.
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n===== FIN DE LAS PRUEBAS =====" << std::endl;
    return 0;
}
