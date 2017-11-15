# TimerGeek
Esta libreria se diseño para evitar el uso del delay() en arduino o con ediciones evitar sleep() en C++, que frenenan todo el flujo del programa mientras se ejecutan, impidiendo por ejemplo leer el estado de un boton.

## Uso
En el ejemplo [Timer_Once](https://github.com/leonardon473/TimerGeek/blob/master/examples/Timer_Once/Timer_Once.ino "Ejemplo Timer_Once") se muestra como despues de 4000 segundos de haber enviado la letra 'I' por serial, se ejecute la función blink() que imprimira "Fin" y en medio de este proceso podras ejecutar más acciones para prueba de ello cuando envias una 'M' se imprime "Medio".
