(function(){
'use strict';
function ready(){
 const button=document.getElementById('theme-toggle');
 function setTheme(theme){document.documentElement.dataset.theme=theme;if(window.jtd&&typeof window.jtd.setTheme==='function')window.jtd.setTheme(theme);try{localStorage.setItem('aero-theme',theme)}catch(e){}if(button){button.textContent=theme==='dark'?'Modo claro':'Modo oscuro';button.setAttribute('aria-label','Activar '+button.textContent.toLowerCase());}}
 setTheme(document.documentElement.dataset.theme||'dark');
 if(button)button.addEventListener('click',()=>setTheme(document.documentElement.dataset.theme==='dark'?'light':'dark'));
 const slider=document.getElementById('pole');
 function gains(){const p=Number(slider.value);document.getElementById('pole-value').textContent=p;document.getElementById('gains').textContent=`β = ${3*p} · l = ${3*p*p} · m = ${-8*p*p*p} · Polo triple = −${p} s⁻¹ · Escala 1/p = ${(1000/p).toFixed(2)} ms`;}
 if(slider){slider.addEventListener('input',gains);gains();}
 const dialog=document.createElement('dialog');dialog.className='image-dialog';dialog.innerHTML='<div class="dialog-tools"><button type="button" class="btn" data-size>Tamaño original</button><button type="button" class="btn" data-close>Cerrar</button></div><div class="image-scroll"><img alt=""></div>';document.body.append(dialog);const zoomImg=dialog.querySelector('img');dialog.querySelector('[data-close]').addEventListener('click',()=>dialog.close());dialog.querySelector('[data-size]').addEventListener('click',()=>{dialog.classList.toggle('original');dialog.querySelector('[data-size]').textContent=dialog.classList.contains('original')?'Ajustar imagen':'Tamaño original'});document.querySelectorAll('figure a').forEach(a=>a.addEventListener('click',e=>{if(typeof dialog.showModal!=='function')return;e.preventDefault();const img=a.querySelector('img');zoomImg.src=img.src;zoomImg.alt=img.alt;dialog.classList.remove('original');dialog.querySelector('[data-size]').textContent='Tamaño original';dialog.showModal()}));
 const copy=document.getElementById('copy-code');if(copy)copy.addEventListener('click',async()=>{const source=document.getElementById('matlab-source');const status=document.getElementById('copy-status');try{await navigator.clipboard.writeText(source.textContent);status.textContent='Código copiado.'}catch(e){const selection=window.getSelection();const range=document.createRange();range.selectNodeContents(source);selection.removeAllRanges();selection.addRange(range);status.textContent='Código seleccionado. Usa Ctrl+C o ⌘C.'}});
}
if(document.readyState==='loading')document.addEventListener('DOMContentLoaded',ready);else ready();
})();
