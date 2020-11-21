#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cono.h"
#include "cilindro.h"
#include "esfera.h"
#include "luzposicional.h"
#include "luzdireccional.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO, TAPASEJECUCION} menu;
typedef enum {VACIO, CUBO, TETRAEDRO, OBJPLY, PEON, LATA, CONO, CILINDRO, ESFERA, OBJSIMULTANEOS} objetos;
typedef enum {INMEDIATO, DIFERIDO} dibujado;
typedef enum {DEFAULT, PUNTOS, LINEAS, SOLIDO, AJEDREZ} visualizado;

class Escena
{

   private:
 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    


   void clear_window();

   // inicialización de los enum
   menu modoMenu=NADA;
   objetos obj=VACIO;
   dibujado tipo_dibujo=INMEDIATO;
   visualizado tipo_visual=SOLIDO;

   
   // Objetos de la escena
   Ejes ejes;
   LuzDireccional * luz_d = nullptr;
   LuzPosicional * luz_p = nullptr;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro = nullptr ; // es importante inicializarlo a 'nullptr'
   // objetos PLY
    ObjPLY * obj_ply = nullptr; // creamos un objeto para poder dibujar los objetos ply
   //
   ObjRevolucion * peon = nullptr;
   ObjRevolucion * lata_inf = nullptr;
   ObjRevolucion * lata_sup = nullptr;
   ObjRevolucion * lata_cue = nullptr;

   Cono * cono = nullptr;
   Cilindro * cilindro = nullptr;
   Esfera * esfera = nullptr;

    //Array para comprobar que modos de visualizacion esta activado
    bool modo_visual[4] = {false,false,true,false}; // puntos, lineas, solido, ajedrez

    // Booleanos para las tapas
    bool tapas = true;

    
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

};
#endif
