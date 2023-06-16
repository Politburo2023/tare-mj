//
//  main.cpp
//  Avance3
//
//  Created by Ma. Guadalupe Roque Díaz de León on 11/06/23.
//

#include <iostream>
#include "Video.hpp"
#include "Poliformismo.hpp"
#include "Episodio.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"

int main() {
  // Declaracion de objetos
  Video viernes {
    "100",
    "Computer",
    100,
    "Ing.",
    100
  };
  Episodio episodio_viernes {
    "Exito_2023",
    100,
    100
  };
  Pelicula peli {
    "0008",
    "Tigres_Campeones_8*",
    888,
    "Deportes",
    100.0,
    8
  };

  Poliformismo neflix;

  // Pruebas de la sobrecarga del operador <<
  cout << viernes << endl;
  cout << peli << endl;
  cout << episodio_viernes << endl;

  neflix.leerArchivo("InventarioFinal.csv");

  cout << *neflix.getPtrVideo(0) << endl;
  cout << neflix.getPtrVideo(0) -> str() << endl;

  return 0;
}
