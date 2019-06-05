#include "Particula.h"

Particula::Particula(float x, float y, float velx, float vely, float r,float K) : QGraphicsItem()  //Un constructor por defecto, que invoca al constructor de la clase base
{
    px = x;
    py = y;
    xa=0;
    ya=0;
    yi = y;
    vx = velx;
    vix=vx;
    vy = vely;
    viy=vy;
    rad = r;
    t1=0;
    t2=0;
    kx=K;
    ky=K;

}

Particula::~Particula()  //Un destructor por defecto
{

}

QRectF Particula::boundingRect() const  //Implementacion del metodo boundingRect
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);   // Creando el area rectangular para delimitar la Particula (es una particula circular)
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)    //Implementacion del metodo paint
{
        painter->setBrush(Qt::darkGreen);     // Color de relleno de la Particula
        painter->drawEllipse(boundingRect());  // Dibujando la Particula con el metodo drawEllipse y aprovechando las propiedades del rectangulo delimitador
        setPos(px,495-py);
}
void Particula::moverParticula(float dt, float vertlim)
{
    t1++;
    t2++;

    px = xi + vx*t1/* - (((((kx*(vix*vix)*(rad*rad))/250))*(t1*t1))/2)*/;//se establece la posicion en x con la ecuacion del movimiento
    py = yi + ((vy*t2)-((10*t2*t2)/2));//se establece la posicion en x con la ecuacion del movimiento

    setPos(px,vertlim-py);
//    if(((px-xa)>-1)&&((px-xa)<1)){
//        vx=0;
//        vix=0;
//    }
//    xa=px;
//    ya=py;
}

void Particula::colisionParticula(float horzlim, float vertlim)
{
    //Si la colision es con una barrera en sentido de avance horizontal (adelante o atras)
   if((px < rad) || (px > horzlim - rad)){
           vx = (-1)*vx*0.4;//Cuando hay una colision se invierte la velocidad y se multiplica por el coeficiente de restitucion
           if(px < rad){
               px=rad+1;//si sobre pasa los limites se ubica en el mas adecuado para la operacion
           }
           if(px > horzlim - rad){
               px=horzlim-(rad+1);//si sobre pasa los limites se ubica en el mas adecuado para la operacion
           }
           xi=px;//se cambia la posicion inicial en x debido a que la velocidad cambia de sentido y analizamos una nueva posicion inicial
           t1=0;//se inicializa nuevamente el tiempo con el que trabajamos en x debido a que tenemos un nuevo punto inicial
//           kx=kx*(-1);
//           vix=vx;
//           if(((px-xa)>-1)&&((px-xa)<1)){
//               vx=0;
//               vix=0;
//           }
   }

    //Si la colision es con una barrera en sentido de avance vertical (arriba o abajo)
    if((py < rad) || (py > vertlim - rad)){

        if(py < rad){
            py=rad+2;//si sobre pasa los limites se ubica en el mas adecuado para la operacion
            vy=(((vy*t2)-((10*t2*t2)/2))*(-1))*0.8;//Cuando hay una colision con la parte inferior se busca la velocidad con la cual llega, se multiplica por menos 1 para invertir el sentido  y se multiplica por el coeficiente de restitucion
            yi=py;//se cambia la posicion inicial en x debido a que la velocidad cambia de sentido y analizamos una nueva posicion inicial
            t2=0;//se inicializa nuevamente el tiempo con el que trabajamos en x debido a que tenemos un nuevo punto inicial
        }
        if(py > vertlim - rad){
            py=vertlim-(rad+1);//si sobre pasa los limites se ubica en el mas adecuado para la operacion
            vy = (-1)*vy*0.8;
        }

    }

}
