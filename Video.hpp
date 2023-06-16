#ifndef Video_hpp
#define Video_hpp
#include <iostream>

#include <stdio.h>
#include <string>

using namespace std;

class Video {
  protected:
	  string iD;
	  string titulo;
	  int duracion;
	  string genero;
	  double calificacionPromedio;

  public:

      Video();
	  Video( string _iD,
		     string _titulo,
		     int _duracion1,
		     string _genero,
		     double _calificacionPromedio);


			friend std::ostream & operator << (std::ostream & os,
				const Video & video) {
				os << video.iD << "-";
				os << video.titulo << "-";
				os << video.duracion << "-";
				os << video.genero << "-";
				os << video.calificacionPromedio << std::endl;
				
				return os;
			}

  // SETTERS AND GETTERS
  void setId(string _iD);
  void setNombre(string _titulo);
  void setDuracion(int _duracion);
  void setGenero(string _genero);
  void setCalificacion(double _calificacionPromedio);

  string getId();
  string getNombre();
  int getDuracion();
  string getGenero();
  double getCalificacion();
  void getEpisodio();

  // METODOS
  virtual string str();
};

#endif /* Video_hpp */
