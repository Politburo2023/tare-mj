#ifndef Pelicula_hpp
#define Pelicula_hpp

#include <stdio.h>

#include <string>

#include "Video.hpp"

#include <iostream>

class Pelicula: public Video {
  private:
  	int oscares;

  public:
    // constructores
    Pelicula();
	Pelicula(	std::string iD,
			    std::string titulo,
			    int duracion,
			    std::string genero,
			    double calificacion,
			    int oscares);

	friend std::ostream & operator << (std::ostream & os,
		const Pelicula & obj) {
		os << obj.Video::iD << "-";
		os << obj.Video::titulo << "-";
		os << obj.Video::duracion << "-";
		os << obj.Video::genero << "-";
		os << obj.Video::calificacionPromedio << "-";
		os << obj.oscares << std::endl;
		
		return os;
	}

  // GETTERS AND SETTERS
  void setOscares(int oscares);
  int getOscares();

  // METODOS
  std::string str() override;
};

#endif /* Pelicula_hpp */
