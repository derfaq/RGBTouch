## RGB Touch
Ejemplo de uso de la librería ADCTouch para Arduino; podés encontrarla en el
*library manager* o bajarla e instalarla manualmente desde [acá](https://github.com/martin2250/ADCTouch)
> Obs: como estoy usando [platformio](http://platformio.org/) para programar, el scketch para el ide de arduino lo podes encontrar en este repositorio en /src/RGBTouch.cpp, simplemente copiá y pega el código.

### Descripción
ADCTouch es una librería que nos permite crear un sensor capacitivo sin ningún circuito externo,
con solo un trozo de cable ya es suficiente. La mayoría de las librerías para sensado táctil
capacitivo (touch) requieren dos pins y una resistencia para adquirir mediciones precisas. Esta
librería hace uso del cableado interno del chip AVR para obterner una resolución decente con solo
un pin.

Tenía a mano un led RGB y cables de colores, así que decidí probarla. Midiendo los valores
a través del puerto serie al acercar y tocar con la mano los cables, me encontré con la grata
sorpresa que estos variaban aproximadamente entre -5...260 (tocando el cable con aislación),
valores ideales para pasarlos directamente a analogWrite().

### El circuito

### Más
