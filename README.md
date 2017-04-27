## RGBTouch  

Ejemplo de uso de la librería **ADCTouch** para Arduino; podés encontrarla en el
*library manager* o bajarla e instalarla manualmente desde [acá](https://github.com/martin2250/ADCTouch).
> Observación: Este repositorio esta organizado para usarse en [PlatformIO](http://platformio.org/). También está disponible el archivo para [Fitzing](http://fritzing.org/home/) junto con el sketch .ino.

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
![esquemático](/fritzing/RGBTouch_bb.png)  

### Et voilà!
![et voilà](/img/GIF_daylight.gif)

### Más
Para una explicación mas detallada del código y la librería visitá el [blog](https://derfaq.github.io/2017-04-26-RGBTouch/). 
Sugerencias, aportes, issues, pulls requests, es bienvenido y se agradece.
