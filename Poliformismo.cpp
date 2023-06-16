#include "Poliformismo.hpp"

#include <iostream>
#include <fstream>

// CONSTRUCTORES

Poliformismo::Poliformismo() {
  cantidadVideos = 0;
  cantidadPeliculas = 0;
  cantidadSeries = 0;
}

// SETTERS AND GETTERS

void Poliformismo::setPtrVideo(int index, Video* video) {
  if (index >= 0 && index < MAX_VIDEOS) {
    arrPtrVideos[index] = video;

    if (Serie* seriePtr = dynamic_cast < Serie* > (video)) {
      arrPtrSeries[cantidadSeries] = seriePtr;
      cantidadSeries++;

    } else if (Pelicula* peliculaPtr = dynamic_cast < Pelicula* > (video)) {
      arrPtrPeliculas[cantidadPeliculas] = peliculaPtr;
      cantidadPeliculas++;
    }

  }
}

void Poliformismo::setCantidadVideos(int cantidadVideos) {
  cantidadVideos = cantidadVideos;
}

Video * Poliformismo::getPtrVideo(int index) {
  return arrPtrVideos[index];
}

int Poliformismo::getCantidadVideos() {
  return cantidadVideos;
}

// METODOS

/*
* reporteInventario() : imprime en pantalla la informacion que contiene cada objeto tipo Video en el vector.
*/
void Poliformismo::reporteInventario() {
  for (int i = 0; i < cantidadVideos; i++) {
    Video * video = arrPtrVideos[i];
    std::cout << video -> str() << std::endl;
  }
}

/*
* reporteCalificacion() : imprime en pantalla la informacion que contiene cada objeto de tipo Video que tenga
* coincidencia con el parametro <calificacion>.
*/
void Poliformismo::reporteCalificacion(double calificacion) {

  int total = 0;

  cout << "[*** reporteCalificacion ***]" << endl;

  for (int i = 0; i < cantidadVideos; i++) {
    Video * video = arrPtrVideos[i];

    if (video -> getCalificacion() == calificacion) {
      cout << video -> str() << std::endl;
      total++;
    }
  }

  cout << "Total: " << total << endl;
}

/*
* reporteGenero() : imprime en pantalla la informacion que contiene cada objeto de tipo Video que tenga
* coincidencia con el parametro <genero>.
*/
void Poliformismo::reporteGenero(std::string genero) {
  cout << "[*** reporteGenero ***]" << endl;

  int total = 0;

  for (int i = 0; i < cantidadVideos; i++) {
    Video * video = arrPtrVideos[i];
    if (video -> getGenero() == genero) {
      std::cout << video -> str() << std::endl;

      total++;
    }
  }

  cout << "Total: " << total << endl;
}

/*
* reportePeliculas() : imprime en pantalla la informacion que contiene cada objeto de tipo Video que tenga
* coincidencia con el parametro <oscares>.
*/
void Poliformismo::reportePeliculas(int oscares) {
  cout << "[*** reportePeliculas ***]" << endl;

  double total = 0;
  int c = 0;

  for (int i = 0; i < cantidadPeliculas; i++) {
    Pelicula * pelicula = arrPtrPeliculas[i];
    if (pelicula -> getOscares() == oscares) {

      std::cout << pelicula -> str() << std::endl;
      Video * videoPtr = static_cast < Video * > (pelicula);
      total += videoPtr -> getCalificacion();
      c++;
    }
  }

  if (c == 0) {
    cout << "no peliculas" << endl;
  } else {
    cout << "Promedio: " << total / c << endl;
  }

}

/*
* reporteSeries() : imprime en pantalla la informacion que contiene cada objeto de tipo Video que tenga
* coincidencia con el parametro <cantidadEpisodios>.
*/
void Poliformismo::reporteSeries(int cantidadEpisodios) {
  cout << "[*** reporteSeries ***]" << endl;

  double total = 0;
  int c = 0;

  for (int i = 0; i < cantidadSeries; i++) {
    Serie * serie = arrPtrSeries[i];
    if (serie -> getCantidad() == cantidadEpisodios) {
      Video * videoPtr = static_cast < Video * > (serie);
      total += videoPtr -> getCalificacion();
      c++;
      std::cout << serie -> str() << std::endl;
    }
  }

  if (c == 0) {
    cout << "no series" << endl;
  } else {
    cout << "CAL PROMEDIO: " << total / c << endl;
  }
}

/*
* leerArchivo() : captura toda la informacion a partir del nombre del archivo y devuelve un objeto del tipo Poliformismo.
*/
void Poliformismo::leerArchivo(std::string nombre) {
  std::ifstream archivo(nombre);
  if (archivo.is_open()) {
    std::string tipo;

    while (getline(archivo, tipo, ',')) {
      if (tipo == "P") {

        std::string id, titulo, genero;
        string duracionStr;
        string oscaresStr;
        string calificacionStr;

        getline(archivo, id, ',');
        getline(archivo, titulo, ',');
        getline(archivo, duracionStr, ',');
        getline(archivo, genero, ',');
        getline(archivo, calificacionStr, ',');
        getline(archivo, oscaresStr, '\n');

        Pelicula * pelicula = new Pelicula(id,
          titulo,
          std::stoi(duracionStr),
          genero,
          std::atof(calificacionStr.c_str()),
          std::stoi(oscaresStr));

        Poliformismo::setPtrVideo(cantidadVideos, pelicula);
        cantidadVideos++;
        
        //cout << pelicula->str() << endl;
      }

      if (tipo == "S") {
        std::string id, titulo, genero;
        std: string duracionStr, calificacionStr, cantidadEpisodiosStr;

        getline(archivo, id, ',');
        getline(archivo, titulo, ',');
        getline(archivo, duracionStr, ',');
        getline(archivo, genero, ',');
        getline(archivo, calificacionStr, ',');
        getline(archivo, cantidadEpisodiosStr, '\n');

        Serie * serie = new Serie(id,
          titulo,
          std::stoi(duracionStr),
          genero,
          std::atof(calificacionStr.c_str()));

        serie -> setCantidad(std::stoi(cantidadEpisodiosStr));

        Poliformismo::setPtrVideo(cantidadVideos, serie);
        cantidadVideos++;

      }

      if (tipo == "E") {
        std::string idSerie;
        std::string titulo, temporada, calificacionStr;
        std::string blanco;

        getline(archivo, idSerie, ',');
        getline(archivo, titulo, ',');
        getline(archivo, temporada, ',');
        getline(archivo, calificacionStr, ',');
        getline(archivo, blanco, ',');
        getline(archivo, blanco, '\n');

        Episodio episodio(titulo,
          std::stoi(temporada),
          std::stoi(calificacionStr));

        actualizar(idSerie, episodio);

      }

    }

    archivo.close();
  }
}

/*
* actualizar() : busca y actualiza la informacion de un objeto de tipo Serie a partir del <idSerie>.
*/
void Poliformismo::actualizar(string idSerie, Episodio episodio) {
  for (int i = 0; i < MAX_SERIES; i++) {
    Serie * serie = arrPtrSeries[i];

    if (serie != nullptr) {
      if (serie -> getId() == idSerie) {

        serie -> agregaEpisodio(episodio);

        Video * videoPtr = static_cast < Video * > (serie);
        videoPtr -> setCalificacion(serie -> calculaPromedio());
      }
    }
  }
}
