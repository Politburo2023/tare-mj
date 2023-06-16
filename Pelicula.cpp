#include "Pelicula.hpp"
#include "Video.hpp"

// CONSTRUCTORES

Pelicula::Pelicula() {
  oscares = 100;
}

Pelicula::Pelicula( std::string iD,
					std::string titulo,
					int duracion, 
					std::string genero,
					double calificacion,
					int oscares) : Video(iD, titulo, duracion, genero, calificacion) {
  Pelicula::oscares = oscares;
}

// SETTERES AND GETTERS
void Pelicula::setOscares(int _oscares) {
  oscares = _oscares;
}

int Pelicula::getOscares() {
  return oscares;
}

// METODOS
std::string Pelicula::str() {
  return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacionPromedio) + ' ' + std::to_string(oscares);
}
