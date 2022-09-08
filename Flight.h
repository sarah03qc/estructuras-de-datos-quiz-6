#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

// Quiz #6
// 1. (DONE) Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. (DONE) Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. (DONE) Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. (DONE) En el test.cpp, implementar la función fillFlights()  

// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h  (NOTA de Sarah: yo use mi propia lista en lugar de la del profe
//                                            entonces tambien la voy a adjuntar, junto con Node.h)

class Flight {

    private: 
        time_t flightTime; 

    public: 
        string aerolinea;
        int num_vuelo;
        int cantid_pasajeros;
        
        string hour;
        string minutee;
        string completa;
        string completa2;
        int horaAsint;
        
        Flight(int pHour, int pMinutes) {
            flightTime = time(NULL);
            tm *currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;    //se cambia la hora por la especificada
            currentTime->tm_min = pMinutes;  //al igual que los minutos

            //construimos esto aca para tener acceso a las horas asignadas, pero se retorna en 
            //sus metodos correspondientes
            stringstream h;
            stringstream m;
            h << pHour;    //usamos stringstream para pasar de int a string
            m << pMinutes;

            if(h.str().size() == 1) {
                //significa que la hora es entre 0 y 9, por lo que hay que agregar un cero
                hour = "0" + h.str();    //lo juntamos en un string
            } else {
                //solo se pone normal
                hour = h.str();
            }
            if(m.str().size() == 1) {
                //significa que los minutos son entre 0 y 9, por lo que hay que agregar un cero
                minutee = "0" + m.str();
            } else {
                //solo se pone normal
                minutee = m.str();
            }
            completa = hour + ":" + minutee;  //para dar la string como hora
            completa2 = hour + minutee;     //para el metodo que representa hora como un int (luego se hara int)
        }

        string flightTimeString() {
            //retorna una string del tiempo asignado
            //se construyo antes
            return completa;
        }

        int getIntTimeValue() {
            stringstream convertir(completa2);
            convertir >> horaAsint;             //lo volvemos a convertir a entero y lo retornamos
            return horaAsint;   
        }
};