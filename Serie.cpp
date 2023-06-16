#include "Serie.hpp"
#include <iostream>

// CONSTRUCTORES
Serie::Serie(): Video() {
  cantidad = 0;
}

Serie::Serie(std::string iD, std::string titulo, int duracion, std::string genero, double calificacionPromedio): Video(iD, titulo, duracion, genero, calificacionPromedio) {
  iD = iD;
  titulo = titulo;
  duracion = duracion;
  genero = genero;
  calificacionPromedio = calificacionPromedio;
  cantidad = 0;
}

// SETTERS AND GETTERS
void Serie::setEpisodio(int pos, Episodio episodio) {
  episodios[pos] = episodio;
}

void Serie::setCantidad(int _cantidad) {
  cantidad = _cantidad;
}

Episodio Serie::getEpisodio(int posicion) {

  return episodios[0];
}

int Serie::getCantidad() {
  return cantidad;
}

// METODOS

/*
* calculaPromedio() : calcula el promedio a partir del valor de <calificacion> de cada objeto tipo Episodio.
*/

double Serie::calculaPromedio() {
  double total = 0.0;

  for (int i = 0; i < cantidad; i++) {
    Episodio ep = episodios[i];

    total += ep.getCalificacion();
  }

  return total / cantidad;
}

/*
* agregaEpisodio() : agrega un objeto episodio a la lista del objeto Serie.
*/

void Serie::agregaEpisodio(Episodio episodio) {
  episodios[cantidad] = episodio;

  cantidad++;
}

/*
* str() : imprime en pantalla toda la informacion correspondiente al objeto Serie.
*/

std::string Serie::str() {
  string cadena = std::string(iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacionPromedio) + ' ' + to_string(cantidad));

  cadena += '\n';

  for (int i = 0; i < cantidad; i++) {
    cadena += '\t' + episodios[i].str() + '\n';
  }

  return cadena;

}
