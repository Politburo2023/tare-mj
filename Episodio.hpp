#ifndef Episodio_hpp
#define Episodio_hpp
#include <iostream>

#include <string>

class Episodio {
  private:
	  std::string titulo;
	  int temporada;
	  int calificacion;

  public:
	  Episodio();
	  Episodio(std::string titulo, int temporada, int calificacion);

	  friend std::ostream & operator << (std::ostream & os,
	    const Episodio & episodio) {
	    os << episodio.titulo << "-";
	    os << episodio.temporada << "-";
	    os << episodio.calificacion << std::endl;
	
	    return os;
	  }

	//SETTERES AND GETTERS
  void setTitulo(std::string titulo);
  void setTemporada(int temporada);
  void setCalificacion(int calificacion);

  std::string getTitulo();
  int getTemporada();
  int getCalificacion();

	// METODOS
  std::string str();
};

#endif /* Episodio_hpp */
