# Reporte Aero 2 — Universidad Iberoamericana Ciudad de México

El paquete incluye el reporte HTML completo, las siete imágenes originales, un sitio **nativo Just the Docs/Jekyll**, MATLAB descargable, selector oscuro/claro, búsqueda, ampliación de imágenes, calculadora del polo del observador y publicación con GitHub Actions.

## 1. Revisión inmediata

Abre `REPORTE_AERO2.html` en tu navegador. Las imágenes están incorporadas al HTML; el código MATLAB también se puede descargar desde esa vista. Las ecuaciones se renderizan mediante MathJax 3.2.2 desde CDN y requieren conexión; sin ella se conserva su fuente TeX. La versión del sitio se publica con Just the Docs real, no con una imitación del tema.

## 2. Instalar en tu Codespace

Sube `AERO2_JustTheDocs.zip` a la raíz del repositorio usando el explorador de archivos de VS Code. Ejecuta desde esa raíz:

```bash
unzip -n AERO2_JustTheDocs.zip
python3 aero2-just-the-docs/scripts/install.py
```

El instalador encuentra el modelo si solo existe un `.slx` candidato. Si hay varios, muestra sus rutas y termina sin instalar. Selecciona el que corresponde a tus capturas:

```bash
python3 aero2-just-the-docs/scripts/install.py --simulink "carpeta/nombre_actual.slx"
```

**Elige el modelo actual.** No se incluyó el archivo antiguo recuperado porque no coincide con las capturas. El instalador copia tu archivo, sin modificar su contenido, a `docs-aero2/assets/downloads/AERO2_LQR_OBSERVADOR.slx`, activa el botón de descarga y muestra su SHA256.

Se crean exclusivamente `docs-aero2/` y `.github/workflows/aero2-pages.yml`. El instalador no hace commit/push y se detiene si esas rutas ya existen. Conserva tus originales. El sitio se construye solo desde `docs-aero2`, por lo que no publica automáticamente todos los archivos del repositorio. Se publican sus siete imágenes y los archivos descargables incluidos allí.

## 3. Obtener un enlace permanente con GitHub Pages

En la página de tu repositorio:

1. Abre **Settings → Pages → Build and deployment**.
2. En **Source**, selecciona **GitHub Actions**.
3. En Codespaces, asegúrate de estar en la rama predeterminada del repositorio. Consulta la rama actual con `git branch --show-current`.
4. Guarda y sube los nuevos archivos:

```bash
git add docs-aero2 .github/workflows/aero2-pages.yml
git commit -m "Documentar LQR y observador Aero 2"
git push
```

Si trabajas en una rama distinta, integra el cambio a la rama predeterminada mediante tu flujo habitual. El workflow publica únicamente esa rama.

5. Abre **Actions → Publicar reporte Aero 2** y espera a que terminen `build` y `deploy`.
6. El trabajo `deploy` y **Settings → Pages** muestran la URL definitiva, generalmente `https://USUARIO.github.io/REPOSITORIO/`.

Comparte esa URL: el reporte permanece disponible aunque cierres el Codespace. El URL temporal del puerto de Codespaces sirve únicamente para previsualización. No necesitas contratar un servidor ni ejecutar MATLAB para visitar el sitio. La disponibilidad de Pages en repositorios privados depende del plan y de las políticas de la cuenta.

Si ya publicas otra web desde este repositorio, revisa el workflow existente antes de habilitar este: GitHub Pages utiliza un sitio por repositorio y este flujo publicará el reporte como su contenido. El instalador no elimina ni desactiva workflows anteriores.

## 4. Vista previa local opcional

No necesitas Ruby en Codespaces para publicar: GitHub Actions lo instala en su propio entorno. Si quieres previsualizar el sitio Just the Docs antes de subirlo, en un Codespace Ubuntu con permisos sudo:

```bash
sudo apt-get update
sudo apt-get install -y ruby-full build-essential zlib1g-dev
gem install bundler --user-install
export PATH="$(ruby -r rubygems -e 'puts Gem.user_dir')/bin:$PATH"
cd docs-aero2
bundle config set --local path vendor/bundle
bundle install
bundle exec jekyll serve --host 0.0.0.0 --port 4000 --baseurl ""
```

Abre **Ports → 4000 → Open in Browser**. Conserva privado el puerto para una revisión personal. Ctrl+C detiene la vista previa. Para volver a la raíz ejecuta `cd ..`.

El workflow utiliza el `base_path` informado por GitHub Pages; los enlaces de imágenes, estilos y descargas usan `relative_url`, por lo que funcionan tanto en dominios raíz como en `/REPOSITORIO/`.

## 5. Archivos para editar

| Archivo | Contenido |
|---|---|
| `docs-aero2/index.html` | Portada, autoría, resumen y objetivos |
| `docs-aero2/modelo.html` | Modelo y parámetros |
| `docs-aero2/lqr.html` | Q, R, Riccati y estabilidad nominal |
| `docs-aero2/referencias-control.html` | Seguimiento y saturación |
| `docs-aero2/observador.html` | Derivación y ajuste de p |
| `docs-aero2/simulink.html` | Diagramas y flujo de señales |
| `docs-aero2/resultados.html` | Las cinco gráficas y discusión |
| `docs-aero2/codigo.html` | Código visible y botones de descarga |
| `docs-aero2/bibliografia.html` | Referencias y alcance de las fuentes |
| `docs-aero2/assets/downloads/` | Los archivos que se descargan |
| `docs-aero2/_config.yml` | Título, tema y configuración |

Después de cualquier cambio:

```bash
git add docs-aero2
git commit -m "Actualizar reporte Aero 2"
git push
```

Si cambias el `.m`, actualiza también el bloque visible en `codigo.html` para conservar su concordancia. Puedes regenerarlo con este comando, desde la raíz del repositorio:

```bash
python3 - <<'PY'
from pathlib import Path
import html,re
p=Path('docs-aero2/codigo.html')
code=Path('docs-aero2/assets/downloads/AERO2_LQR_OBSERVADOR.m').read_text()
s=p.read_text()
s=re.sub(r'(<code id="matlab-source">).*?(</code>)',lambda m:m[1]+html.escape(code)+m[2],s,flags=re.S)
p.write_text(s)
PY
```

Para actualizar el Simulink descargable, copia el archivo actual a la ruta de descargas y confirma ese cambio con git. El sitio no interpreta internamente el modelo; debes mantener las capturas acordes a su versión.

## 6. Precisiones del reporte

- Se conservaron Q = diag(270,80,1,1), R = diag(0.1,0.05), p = 200 y el modelo original.
- La derivación exacta entrega β = 600, l = 120000, m = −64000000.
- R penaliza voltaje; el saturador impone ±24 V.
- La captura muestra observación en paralelo; no se da por hecho que el LQR cierre el lazo usando el observador.
- Los apuntes mencionados no pudieron recuperarse; su referencia queda explícitamente pendiente de autor, año y páginas. No se inventaron citas.
- La copia histórica `finalfinalpert(1).slx` no coincide con el diagrama actual y no se incluyó como si fuera ese modelo.
- Se validaron cálculos con SciPy, sintaxis JavaScript, integridad de imágenes, coincidencia del código visible, estructura HTML y flujo del instalador. No se ejecutó MATLAB/QUARC ni un ensayo físico.
- El entorno de elaboración no dispone de Ruby/Jekyll ni de una vista de navegador habilitada; la compilación real y revisión visual final deben completarse con `bundle exec jekyll build` o con el workflow incluido. No se afirma una publicación ya realizada.

## 7. Problemas frecuentes

- **Error 404 en Pages:** revisa que el workflow terminó y que Source sea GitHub Actions.
- **Workflow omitido:** el push debe llegar a la rama predeterminada. También puedes usar Run workflow desde esa rama.
- **Build falla al descargar gems:** revisa la conectividad del runner y los logs de `bundle install`.
- **Descarga .slx pendiente:** ejecuta el instalador con `--simulink` antes de publicar.
- **El modelo no abre en MATLAB:** revisa versión de MATLAB/Simulink, QUARC y dependencias del modelo; la web no los sustituye.
- **Las ecuaciones aparecen como TeX:** permite acceso a `cdn.jsdelivr.net` o instala MathJax localmente si necesitas una publicación sin CDN.
