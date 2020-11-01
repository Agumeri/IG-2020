#include "aux.h"
#include "objrevolucion.h"
#include "objply.h"
#include "math.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   // completar ......(práctica 2)

   // creamos el vector de los vectores del perfil (perfil_original) y leemos los vertices
   std::vector<Tupla3f> perfil_original;
   ply::read_vertices(archivo, perfil_original);

   std::cout << "Tamaño perfil_original: " << perfil_original.size() << std::endl;
   
   // creamos la malla para el perfil escogido
   crearMalla(perfil_original, num_instancias);

}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
    
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   // NUMERO PARA DIVIDIRLO POR N DENTRO DE LAS TABLAS
   float angulo_radianes = 2*M_PI;
   
   // asignamos el valor correspondiente M y N
   this->M = perfil_original.size();
   this->N = num_instancias;

   // creacion de la tabla de vertices (la dejamos vacia)
   this->v.clear();
   
   // Añadimos los vertices a la tabla de vertices
   for(int i=0; i<=N-1; i++){
      for(int j=0; j<=M-1; j++){
         // creamos un objeto tupla3f auxiliar para ir obteniendo
         // los valores {x, y, z} correspondientes al punto actual
         Tupla3f aux;
         aux[0] = sin(angulo_radianes*i/N) * perfil_original[j][0]; // pos x
         aux[1] = perfil_original[j][1];                            // pos y
         aux[2] = cos(angulo_radianes*i/N) * perfil_original[j][0]; // pos z

         // ya obtenidas las coordenadas, metemos el vertice trasladado
         // en la tabla de vertices
         this->v.push_back(aux); 
      }
   }

   // Añadimos los triangulos correspondientes a la tabla de triangulos
   for(int i=0; i<=N-1; i++){
      for(int j=0; j<=M-2; j++){
         int a = M*i + j;
         int b = (M*(i+1))%N + j;

         // creamos dos tupla3i auxiliar para la cara a obtener (2 triangulos por cara)
         Tupla3i cara1(a,b,b+1), 
                 cara2(a,b+1,a+1);

         // añadimos ambos triangulos a la tabla de triangulos
         this->f.push_back(cara1);
         this->f.push_back(cara2);

      }
   }   

   std::cout << "HOLA NO ME HE ROTO" << std::endl;
}
