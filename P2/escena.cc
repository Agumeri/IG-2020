#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
    // .......COMPLETAR: ...
    // ..... CREAR DATOS, NO LA ESTRUCTURA DE LA ESCENA.
    cubo = new Cubo();
    tetraedro = new Tetraedro();
    obj_ply = new ObjPLY("plys/ant.ply");
    peon = new ObjRevolucion("plys/peon.ply",10,false,false);
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
   // creamos un entero que pasaremos a draw para indicar el modo de dibujado
   int modo_dibujado = 0;

   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla

	change_observer();
   ejes.draw();

   // seleccion del modo de dibujado
   if(tipo_dibujo==INMEDIATO) modo_dibujado = 1;
   
   if(tipo_dibujo==DIFERIDO) modo_dibujado = 2;

   // Seleccion del objeto a dibujar
   if(obj == CUBO) cubo->draw(modo_dibujado, modo_visual[0], modo_visual[1], modo_visual[2], modo_visual[3]);
   
   if(obj == TETRAEDRO) tetraedro->draw(modo_dibujado, modo_visual[0], modo_visual[1], modo_visual[2], modo_visual[3]);
   
   //Distintos casos segun el objeto PLY
   if(obj == OBJPLY) obj_ply->draw(modo_dibujado, modo_visual[0], modo_visual[1], modo_visual[2], modo_visual[3]);
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA){
            modoMenu=NADA;
            printf("\nSelecciona un modo de los disponibles:\n");
            printf("'O': Seleccion de objeto\n");
            printf("'V': Seleccion de modo de visualización\n");
            printf("'D': Seleccion de dibujado\n");
            printf("'Q': Salir del programa\n");       
         }else {
            salir=true ;
         }
         break ;
      case 'O' :
         // ESTAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO; 
         printf("Opciones disponibles: \n'C': Cubo \n'T': Tetraedro \n'H': Objeto PLY \n");
         break ;
        case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         printf("Opciones disponibles: \n'L': Linea; \n'P': Puntos \n'S': Solido\n'A': Ajedrez\n");
         modoMenu=SELVISUALIZACION;
         break ;
       case 'D' :
         // ESTAMOS EN MODO SELECCION DE DIBUJADO
         printf("Opciones disponibles: \n'1': Modo inmediato; \n'2': Modo diferido\n");
         modoMenu=SELDIBUJADO;
         break ;
         // COMPLETAR con los diferentes opciones de teclado
      

      // MENUS DE LAS FIGURAS SELECCIONADAS
         //CUBO
         case 'C':
         // ESTAMOS EN MODO CUBO SELECCIONADO
         if(modoMenu==SELOBJETO){
            if(obj != CUBO){
               printf("Cubo seleccionado.\n");
               obj=CUBO;
            }else{
               printf("Ocultando cubo\n");
               obj=VACIO;
            }
         }
         break;

         //-------------------------------------------------
         //TETRAEDRO
         case 'T':
         // ESTAMOS EN MODO Tetraedro SELECCIONADO
         if(modoMenu==SELOBJETO){
            if(obj != TETRAEDRO){
               printf("Tetraedro seleccionado.\n");
               obj=TETRAEDRO;
            }else{
               printf("Ocultando Tetraedro\n");
               obj=VACIO;
            }
         }
         break;

         //-------------------------------------------------
         //OBJETO PLY
         case 'H':
         // ESTAMOS EN MODO Tetraedro SELECCIONADO
         if(modoMenu==SELOBJETO){
            if(obj != OBJPLY){
               printf("Objeto PLY seleccionado.\n");
               obj=OBJPLY;
            }else{
               printf("Ocultando objeto PLY\n");
               obj=VACIO;
            }
         }
         break;
      //*********************************************************************

      // MENU DEL MODO DE DIBUJADO
         // INMEDIATO
         case '1':
            if (modoMenu == SELDIBUJADO)
            {
               if (tipo_dibujo != INMEDIATO)
               {
                  printf("Modo de dibujado INMEDIATO seleccionado.\n");
                  tipo_dibujo = INMEDIATO;
               } else {
                  printf("El modo de dibujado actual es el INMEDIATO.\n");
               }
            }
         break;

         // DIFERIDO
         case '2':
            if (modoMenu == SELDIBUJADO)
            {
               if (tipo_dibujo != DIFERIDO)
               {
                  printf("Modo de dibujado DIFERIDO seleccionado.\n");
                  tipo_dibujo = DIFERIDO;
               } else {
                  printf("El modo de dibujado actual es el DIFERIDO.\n");
               }
            }
         break;
      //**************************************************************************

      // MENU DEL MODO DE VISUALIZACION
         // PUNTOS
         case 'P':
            if (modoMenu == SELVISUALIZACION)
            {
               if (tipo_visual != PUNTOS && !modo_visual[0])
               {
                  printf("Visualizacion en modo PUNTOS activada.\n");
                  tipo_visual = PUNTOS;
                  modo_visual[0] = true;
                  break;
               }
               else
               {
                  printf("Visualizacion en modo PUNTOS desactivada.\n");
                  tipo_visual = DEFAULT;
                  modo_visual[0] = false;
               }
            }
         break;

         // LINEAS
         case 'L':
            if (modoMenu == SELVISUALIZACION)
            {
               if (tipo_visual != LINEAS && !modo_visual[1])
               {
                  printf("Visualizacion en modo LINEAS activada.\n");
                  tipo_visual = LINEAS;
                  modo_visual[1] = true;
                  break;
               }
               else
               {
                  printf("Visualizacion en modo LINEAS desactivada.\n");
                  tipo_visual = DEFAULT;
                  modo_visual[1] = false;
               }
            }
         break;

         // SOLIDO
         case 'S':
            if (modoMenu == SELVISUALIZACION)
            {
               if (tipo_visual != SOLIDO && !modo_visual[2])
               {
                  printf("Visualizacion en modo SOLIDO activada.\n");
                  tipo_visual = SOLIDO;
                  modo_visual[2] = true;
                  break;
               }
               else
               {
                  printf("Visualizacion en modo SOLIDO desactivada.\n");
                  tipo_visual = DEFAULT;
                  modo_visual[2] = false;
               }
            }
         break;

         // AJEDREZ
         case 'A':
            if (modoMenu == SELVISUALIZACION)
            {
               if (tipo_visual != AJEDREZ && !modo_visual[3])
               {
                  printf("Visualizacion en modo AJEDREZ activada.\n");
                  tipo_visual = AJEDREZ;
                  modo_visual[3] = true;
                  break;
               }
               else
               {
                  printf("Visualizacion en modo AJEDREZ desactivada.\n");
                  tipo_visual = DEFAULT;
                  modo_visual[3] = false;
               }
            }
         break;
      //**************************************************************************
   }
   


   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
