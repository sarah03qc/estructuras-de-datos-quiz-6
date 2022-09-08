#include "Flight.h"
#include "List.h"
#include <time.h>

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    int horaSalida;
    int minutoSalida;
    cout << "Creando " << pCantidad << " de vuelos, en rango de: " << pStartHour << " a " << pEndHour << endl;
    List<Flight> lista = List<Flight>();  //creamos lista de vuelos
    pEndHour++;   //porque sino el rango se genera hasta uno menos que el maximo recibido
    srand((unsigned) time(NULL));   //la semilla
    while(pCantidad > 0) {    //ciclo para crear pCantidad de vuelos
        
        horaSalida = rand() % (pEndHour - pStartHour) + pStartHour; //el rango de hora, sacado por el min y el max
        //ahora minutos
        int max = 43;
        int min = 17;
        minutoSalida = rand() % (max - min) + min;     //el rango de minutos debe tomar en cuenta 17 para atras y delante (posible atraso)

        Flight *vuelo = new Flight(horaSalida, minutoSalida);

        int contad = 0;  //ahora hay que tomar en cuenta las restricciones de los minutos
        while(contad < lista.getSize()) {
            //se hace loop para poder revisar todos los elementos bien
            for(int i = 0; i < lista.getSize(); i++) {
                //iteramos a traves de la lista para tener cuidado de que los vuelos (y sus posibles retrasos)
                //no tengan el mismo tiempo de salida, si lo hacen se modifica. (aca no estamos tomando en cuenta las 
                //pistas porque no se les da gran mencion en el quiz)
                Flight *currentElement = lista.find(i);
            
                int elIntdeI = currentElement->getIntTimeValue(); //guardamos el valor int del elemento i de lista
                int intActual = vuelo->getIntTimeValue();  //igual con el vuelo actual
                if((((intActual - 17) == (elIntdeI)) || ((intActual + 17) == (elIntdeI)))) {
                    //si restados o sumados 17 es la misma que otra hora, se cambia
                    minutoSalida = rand() % (max - min) + min;
                }
            }
            contad++; 
        }
        lista.add(vuelo);   //despues ya agregamos el vuelo 
        cout << "\nVuelo creado a las: " << vuelo->flightTimeString() << " y el entero es: " << vuelo->getIntTimeValue() << endl;
        cout << "  " << endl;
        pCantidad--;
    }  
} 


int main() {
    //ejemplos del funcionamiento 
    //por ejemplo: aca estan creando 6 vuelos de horas aleatorias desde las 9 hasta las 19
    fillFlights(6, 9, 19);

    fillFlights(2, 5, 8);
}