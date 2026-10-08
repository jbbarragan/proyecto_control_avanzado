#!/usr/bin/env python3
"""Instala una copia del sitio en el repositorio actual. No hace commit ni push."""
import argparse, pathlib, shutil, subprocess, zipfile, hashlib
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--simulink',help='Ruta al .slx ACTUAL que corresponde a las capturas')
a=p.parse_args()
repo=pathlib.Path(subprocess.check_output(['git','rev-parse','--show-toplevel'],text=True).strip())
package=pathlib.Path(__file__).resolve().parents[1]
if a.simulink:
    model=pathlib.Path(a.simulink).resolve()
else:
    candidates=[x for x in repo.rglob('*.slx') if not any(v in x.parts for v in ('.git','node_modules','vendor','docs-aero2','aero2-just-the-docs'))]
    if len(candidates)!=1:
        print('Indica el modelo actual: python aero2-just-the-docs/scripts/install.py --simulink "ruta/modelo.slx"')
        for x in candidates: print('  '+str(x.relative_to(repo)))
        raise SystemExit(2)
    model=candidates[0]
if not model.is_file() or model.suffix.lower()!='.slx':raise SystemExit('No existe un archivo .slx en esa ruta.')
with zipfile.ZipFile(model) as z:
    if 'simulink/blockdiagram.xml' not in z.namelist():raise SystemExit('El archivo no contiene un modelo SLX reconocido.')
dest=repo/'docs-aero2';workflow=repo/'.github/workflows/aero2-pages.yml'
if dest.exists() or workflow.exists():raise SystemExit('Ya existe docs-aero2 o aero2-pages.yml. Revisa la instalación existente antes de reemplazarla.')
shutil.copytree(package/'site',dest)
shutil.copyfile(model,dest/'assets/downloads/AERO2_LQR_OBSERVADOR.slx')
config=dest/'_config.yml';config.write_text(config.read_text().replace('simulink_ready: false','simulink_ready: true'))
workflow.parent.mkdir(parents=True,exist_ok=True)
shutil.copyfile(package/'.github/workflows/aero2-pages.yml',workflow)
(dest/'.gitignore').write_text('_site/\n.jekyll-cache/\n.sass-cache/\n.bundle/\nvendor/\n')
print('Instalado en: '+str(dest))
print('Modelo incorporado: '+str(model.relative_to(repo) if model.is_relative_to(repo) else model))
print('SHA256: '+hashlib.sha256(model.read_bytes()).hexdigest())
print('Revisa Settings > Pages > Source: GitHub Actions.')
print('En la rama predeterminada del repositorio, ejecuta:')
print('git add docs-aero2 .github/workflows/aero2-pages.yml')
print('git commit -m "Documentar LQR y observador Aero 2"')
print('git push')
