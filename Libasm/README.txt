# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 17:45:04 by jschirad          #+#    #+#              #
#    Updated: 2020/02/25 15:35:33 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Lenguaje de ensamblador. Lenguaje simbólico que se ha definido para que se puedan escribir programas con una sintaxis próxima al lenguaje de máquina,
pero sin tener que escribir el código en binario, sino utilizando una serie de mnemónicos más fáciles de entender para el programador.
Para ejecutar estos programas también es necesario un proceso de traducción, generalmente denominado ensamblaje, pero más sencillo que en los lenguajes de alto nivel.

Un programa ensamblador escrito con sintaxis NASM está formado por tres secciones o segmentos:
.data para los datos inicializados, .bss para los datos no inicializados y .text para el código:

		section		.data	sección en la que se definen datos inicializados, datos a los que damos un valor inicial.

		section		.bss	sección en la que se definen datos sin inicializar.

		section		.text	sección en la que se incluyen las instrucciones del programa.

La sección .text permite también definir variables y, por lo tanto, permitiría prescindir también de la sección .data,
aunque no es recomendable. Por lo tanto, esta es la única sección realmente obligatoria en todo programa.

La sección .text debe empezar siempre con la directiva global, que indica al GCC cuál es el punto de inicio del código.
Cuando se utiliza GCC para generar un ejecutable, el nombre de la etiqueta donde se inicia la ejecución del código se ha de denominar obligatoriamente main;
también ha de incluir una llama- da al sistema operativo para finalizar la ejecución del programa y devolver el control al terminal desde el que hemos llamado al programa.

Sección .data, variables inicializadas
Las variables de esta sección se definen utilizando las siguientes directivas:
• db:  byte, 8 bits.
• dw:  palabra (word), 2 bytes = 16 bits.
• dd:  doble palabra(doubleword), 2 palabras = 4 bytes = 32 bits.
• dq:  cuádruple palabra(quadword), 4 palabras = 8 bytes = 64 bits.

Sección .bss, variables no inicializadas
Dentro de esta sección se declaran y se reserva espacio para las variables de
nuestro programa para las cuales no queremos dar un valor inicial.
Hay que utilizar las directivas siguientes para declarar variables no inicializa- das:
• resb: reserva espacio en unidades de byte
• resw: reserva espacio en unidades de palabra, 2 bytes
• resd: reserva espacio en unidades de doble palabra, 4 bytes
• resq: reserva espacio en unidades de cuádruple palabra, 8 bytes

Tipos de instrucciones

1) Instrucciones de transferencia de datos:

• mov destino,fuente:instruccióngenéricaparamoverundatodesdeun origen a un destino.
• push fuente:instrucciónquemueveeloperandodelainstrucciónala cima de la pila.
• pop destino:mueve el dato que se encuentraenlacimadelapilaalope- rando destino.
• xchg destino, fuente: intercambia contenidos de los operandos.


2) Instrucciones aritméticas y de comparación:

• add destino, fuente: suma aritmética de los dos operandos.
• adc destino,fuente: suma aritmética de los dos operandos considerando el bit de transporte.
• sub destino, fuente: resta aritmética de los dos operandos.
• sbbdestino,fuente:restaaritméticadelosdosoperandosconsiderando el bit de transporte.
• inc destino: incrementa el operando en una unidad.
• dec destino: decrementa el operando en una unidad.
• mul fuente: multiplicación entera sin signo.
• imul fuente: multiplicación entera con signo.
• div fuente: división entera sin signo.
• idiv fuente: división entera con signo.
• neg destino: negación aritmética en complemento a 2.
• cmp destino,fuente:comparación de los dos operandos;hace una resta sin guardar el resultado.

3) Instrucciones lógicas y de desplazamiento:

a) Operaciones lógicas:
• and destino, fuente: operación 'y' lógica.
• or destino, fuente: operación 'o' lógica.
• xor destino, fuente: operación `o exclusiva ́ lógica.
• not destino: negación lógica bit a bit.
• testdestino,fuente:comparación lógica de los dos operandos;hace una 'y' lógica sin guardar el resultado.

b) Operaciones de desplazamiento:
• saldestino,fuente/shldestino,fuente:desplazamientoaritmético/lógico a la izquierda.
• sar destino, fuente: desplazamiento aritmético a la derecha.
• shr destino, fuente: desplazamiento lógico a la derecha.
• rol destino, fuente: rotación lógica a la izquierda.
• ror destino, fuente: rotación lógica a la derecha.
• rcl destino,fuente: rotación lógica a la izquierda considerando el bit de transporte.
• rcr destino,fuente: rotación lógica a la derecha con siderando el bit de transporte.

4) Instrucciones de ruptura de secuencia:

a) Salto incondicional:
• jmp etiqueta: salta de manera incondicional a la etiqueta.

b) Saltos que consultan un bit de resultado concreto:
• je etiqueta/jz etiqueta: salta a la etiqueta si igual,si el bit de cero es activo.
• jne etiqueta/jnz etiqueta: salta a la etiqueta si diferente,si el bit de cero no es activo.
• jc etiqueta/jnc etiqueta: salta a la etiqueta si el bit de transporte es activo.
• jnc etiqueta: salta a la etiqueta si el bit de transporte no es activo.
• jo etiqueta: salta a la etiqueta si el bit de desbordamiento es activo.
• jno etiqueta: salta a la etiqueta si el bit de desbordamiento no es activo.
• js etiqueta: salta a la etiqueta si el bit de signo es activo.
• jns etiqueta: salta a la etiqueta si el bit de signo no es activo.

c) Saltos condicionales sin considerar el signo:
• jb etiqueta / jnae etiqueta: salta a la etiqueta si es más pequeño.
• jbe etiqueta / jna etiqueta: salta a la etiqueta si es más pequeño o igual.
• ja etiqueta / jnbe etiqueta: salta a la etiqueta si es mayor.
• jae etiqueta / jnb etiqueta: salta a la etiqueta si es mayor o igual.

d) Saltos condicionales considerando el signo:
• jl etiqueta / jnge etiqueta: salta si es más pequeño.
• jle etiqueta / jng etiqueta: salta si es más pequeño o igual.
• jg etiqueta / jnle etiqueta: salta si es mayor.
• jge etiqueta / jnl etiqueta: salta si es mayor o igual.


e) Otras instrucciones de ruptura de secuencia:
• loop etiqueta: decrementa el registro rcx y salta si rcx es diferente de cero.
• call etiqueta: llamada a subrutina.
• ret: retorno de subrutina.
• iret: retorno de rutina de servicio de interrupción (RSI).
• int servicio: llamada al sistema operativo.

5) Instrucciones de entrada/salida:

• in	destino,fuente: lectura del puerto de E/S especificado en el operando fuente y se guarda en el operando destino.
• out	destino,fuente: escritura del valor especificado por el operando fuente en el puerto de E/S especificado en el operando destino.


Los registros de datos, como su nombre indica, contienen generalmente datos. (Sí, lo sé, no parecen gran cosa, pero es lo que hay) A veces se les llama "de propósito general", y la verdad es que es un nombre más apropiado
 si bien un poco más largo. Aunque tiene distinto nombre cada uno de ellos, cuentan básicamente con la misma funcionalidad, con algunas
excepciones. Determinadas operaciones -por ejemplo la multiplicación- exigen que los operandos estén en registros específicos. En ese caso no quedarán más narices que usar esos concretamente.

AX es a menudo llamado acumulador, más por motivos históricos que por otra cosa.
BX se puede usar como registro base en algunos modos de direccionamiento, es decir, para apuntar a posiciones de memoria con él.
CX es usado por algunas instrucciones como contador (en ciclos, rotaciones..)
DX o registro de datos; a veces se usa junto con AX en esas instrucciones especiales mencionadas.
