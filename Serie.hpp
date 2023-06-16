#ifndef Serie_hpp
#define Serie_hpp

#include "Episodio.hpp"
#include "Video.hpp"

class Serie: public Video {
  private: 
  
	  Episodio episodios[5];
	  int cantidad;

  public: 
  
  Serie();
  Serie( std::string iD,
	     std::string titulo,
	     int duracion,
	     std::string genero,
	     double calificacionPromedio);

	// SETTERS AND GETTERS
  void setEpisodio(int index, Episodio episodio);
  void setCantidad(int _cantidad);
  Episodio getEpisodio(int posicion);
  int getCantidad();

	// METODOS
  double calculaPromedio();
  void agregaEpisodio(Episodio episodio);
  std::string str() override;
};

#endif /* Serie_hpp */
