#include "aux.h"
#include "objrevolucion.h"
#include "math.h"
#include "esfera.h"


Esfera::Esfera(int num_vert_perfil, int num_instancias_perf, float r){
    // establecemos el valor del radio
    this->radio = r;

    // creamos un vector de tuplas3f auxiliar para pasarlo como tabla de vertices
    std::vector<Tupla3f> tabla_vertices_aux;

    // Pasamos a crear los vertices del perfil. Como lo hemos orientado para que el objeto se cree de 
    // abajo hacia arriba, primero pondremos el vertice inferior, luego el resto de vertices
    // hasta llegar al último, el vértice superior (todo mediante un for)
    // tabla_vertices_aux.push_back( {0.0,-radio,0.0} );

    for(int i=1; i<num_vert_perfil; i++){
        tabla_vertices_aux.push_back( {sin(2*i*M_PI/num_instancias_perf)*radio,   // posicion x
                                       cos(2*i*M_PI/num_instancias_perf)*radio,   // posicion y
                                       0.0} );                                  // posicion z
    }

    // tabla_vertices_aux.push_back( {0,radio,0.0} );

    // crear malla del cono
    crearMalla(tabla_vertices_aux,num_instancias_perf,true,true);
}