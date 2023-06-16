//
//  Episodio.cpp
//  Avance3
//
//  Created by Ma. Guadalupe Roque Díaz de León on 11/06/23.
//


#include "Episodio.hpp"

// Constructores
Episodio::Episodio() {
  temporada = 0;
  calificacion = 0;
  titulo = "";
}

Episodio::Episodio(std::string titulo, int temporada, int calificacion) {
  Episodio::titulo = titulo;
  Episodio::temporada = temporada;
  Episodio::calificacion = calificacion;

}

//GETTERS AND SETTERS
void Episodio::setTitulo(std::string titulo) {
  Episodio::titulo = titulo;
}

void Episodio::setTemporada(int temporada) {
  Episodio::temporada = temporada;
}

void Episodio::setCalificacion(int calificacion) {
  Episodio::calificacion = calificacion;
}

std::string Episodio::getTitulo() {
  return titulo;
}

int Episodio::getTemporada() {
  return temporada;
}

int Episodio::getCalificacion() {
  return calificacion;
}

std::string Episodio::str() {
  return titulo + ' ' + std::to_string(temporada) + ' ' + std::to_string(calificacion);

}
