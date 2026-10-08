# Proyecto de Control Avanzado — listo para subir

## Subir desde el navegador

1. Descomprime este ZIP en tu computadora.
2. Abre tu repositorio en GitHub, pestaña Code, rama predeterminada.
3. Pulsa Add file → Upload files.
4. Arrastra TODO EL CONTENIDO de la carpeta descomprimida: `.github`, `docs-aero2`, `ControlAvJoshua` y los archivos de la raíz. No arrastres la carpeta exterior ni el ZIP.
5. Guarda con Commit changes en la rama predeterminada.
6. En Settings → Pages conserva Source: GitHub Actions.
7. Abre Actions. Ahora debe aparecer «Publicar reporte Aero 2». El commit inicia la ejecución. Al finalizar build y deploy, Settings → Pages muestra Visit site.

## Rutas correctas

- `.github/workflows/aero2-pages.yml`
- `docs-aero2/Gemfile`
- `docs-aero2/_config.yml`
- `docs-aero2/index.html`
- `docs-aero2/assets/downloads/AERO2_LQR_OBSERVADOR.slx`
- `ControlAvJoshua/` contiene todos los originales, respaldos y compilaciones.

## Qué se corrigió

Se movió el workflow que estaba dentro de `.github/workflows/.github/workflows/` a su ruta correcta. El contenido de `docs-aero2/site/` quedó directamente en `docs-aero2/`. El botón de descarga de Simulink ya estaba activado y se conservó.

Todos los archivos originales se conservaron. Solo se amplió la lista `exclude` de `_config.yml` para que Jekyll no publique los materiales auxiliares ni vuelva a procesar una carpeta `site/` antigua que permanezca al cargar sobre el repositorio existente. No se modificaron el reporte, las imágenes, MATLAB ni los modelos Simulink.

Los dos `.slx` recibidos tienen distinto contenido: se conservan ambos en sus ubicaciones correspondientes. La descarga web utiliza el que ya habías colocado en assets/downloads.

## Si subes sobre el repositorio actual

GitHub reemplaza los archivos de la misma ruta, pero no borra automáticamente las rutas antiguas. Las copias anteriores en `docs-aero2/site/` quedan excluidas de la compilación y el workflow anidado antiguo no es reconocido por GitHub Actions. No necesitas borrarlas para que funcione esta organización. Después puedes eliminar esas dos rutas antiguas si deseas limpiar duplicados.

No vuelvas a ejecutar el instalador de scripts: esta entrega ya está organizada. Los instructivos anteriores y el instalador se conservaron como material auxiliar; para subir este paquete sigue este README.

## Verificación

Se comprobó que los 88 archivos de entrada están presentes y que 87 conservan exactamente sus bytes; el restante es `_config.yml`, cuyo único cambio es la lista de exclusión. El manifiesto ORGANIZACION_ARCHIVOS.json registra rutas y hashes antes/después. El ZIP contiene 90 archivos, todos menores de 25 MiB. No se ejecutó MATLAB ni se publicó desde esta sesión; la compilación Jekyll y el despliegue se ejecutan mediante GitHub Actions.
