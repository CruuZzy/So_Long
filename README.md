## Descripción

**so_long** este proyecto es un pequeño juego en 2D. Está diseñado para hacerte trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad 2D utilizando la librería **MiniLibX**. El objetivo es desarrollar un pequeño juego jugable en una ventana gráfica.

### Objetivo
El jugador controla un personaje que debe recoger todos los objetos (coleccionables) y llegar al punto de salida, evitando muros y otros obstáculos.

### Características mínimas:
1. **Mapas válidos**:
   - El mapa debe estar rodeado por muros (`1`).
   - Debe tener al menos un jugador (`P`), un coleccionable (`C`) y una salida (`E`).
   - El mapa debe ser rectangular y en un archivo `.ber`.

2. **Controles**:
   - Movimiento en cuatro direcciones: **WASD** o **flechas del teclado**.
   - El contador de movimientos del jugador debe mostrarse en la terminal.

3. **Colisiones**:
   - El jugador no puede atravesar muros (`1`).

4. **Condición de victoria**:
   - El jugador debe recoger todos los coleccionables (`C`) antes de poder salir por la puerta (`E`).

5. **Renderizado**:
   - Usa la librería **MiniLibX** para mostrar el juego en una ventana gráfica con sprites.

6. **Gestión de errores**:
   - Validación de mapas inválidos o archivos incorrectos.
   - Manejo adecuado de errores y memoria.

---
