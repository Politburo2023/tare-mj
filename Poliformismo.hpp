
#ifndef POLIFORMISMO_HPP
#define POLIFORMISMO_HPP

#include "Video.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"
#include <limits> 

const int MAX_VIDEOS = 100;
const int MAX_PELICULAS = 50;
const int MAX_SERIES = 50;

class Poliformismo {
private:
    Video* arrPtrVideos[MAX_VIDEOS]  = { nullptr };;
    Pelicula* arrPtrPeliculas[MAX_PELICULAS]  = { nullptr };;
    Serie* arrPtrSeries[MAX_SERIES]  = { nullptr };;
    
    int cantidadVideos;
    int cantidadPeliculas;
    int cantidadSeries;

public:
    Poliformismo();
    
    // SETTERS AND GETTERS
    void setPtrVideo(int index, Video* video);
    void setCantidadVideos(int cantidadVideos);
    Video* getPtrVideo(int index);
    int getCantidadVideos();
    
    // METODOS
    void reporteInventario();
    void reporteCalificacion(double calificacion);
    void reporteGenero(std::string genero);
    void reportePeliculas(int oscares);
    void reporteSeries(int cantidadEpisodios);
    void leerArchivo(const std::string nombre);
    
private:
	void actualizar(string idSerie, Episodio episodio);
};

#endif // POLIFORMISMO_HPP
