#include "Video.hpp"

// CONSTRUCTORES
Video::Video() {
  iD = "0000";
  titulo = "TC1030";
  duracion = 10;
  genero = "Computacion";
  calificacionPromedio = 100.0;
}

Video::Video( string iD,
			  string titulo,
			  int duracion,
			  string genero,
			  double calificacionPromedio) {
  Video::iD = iD;
  Video::titulo = titulo;
  Video::duracion = duracion;
  Video::genero = genero;
  Video::calificacionPromedio = calificacionPromedio;

}

// SETTERS  AND GETTERS
void Video::setId(string _iD) {
  iD = _iD;
}

void Video::setNombre(string _titulo) {
  titulo = _titulo;
}

void Video::setDuracion(int _duracion) {
  duracion = _duracion;
}

void Video::setGenero(string _genero) {
  genero = _genero;
}

void Video::setCalificacion(double _calificacionPromedio) {
  calificacionPromedio = _calificacionPromedio;
}

string Video::getId() {
  return iD;
}

string Video::getNombre() {
  return titulo;
}

int Video::getDuracion() {
  return duracion;
}

string Video::getGenero() {
  return genero;
}

double Video::getCalificacion() {
  return calificacionPromedio;
}

// METODOS
std::string Video::str() {
  return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacionPromedio);
}
