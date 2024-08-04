
## Parte 3: Gestión de Permisos

### 1. Creación de Archivos y Directorios
Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él. Luego, crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.

```bash
# Cambiar a usuario1
su - usuario1
```

# Crear archivo1.txt y escribir algo en él
```bash
echo "Contenido del archivo1" > ~/archivo1.txt
```

# Crear directorio1 y archivo2.txt dentro de él
```bash
mkdir ~/directorio1
echo "Contenido del archivo2" > ~/directorio1/archivo2.txt
```

### 2. Verificar Permisos
Verifica los permisos del archivo y directorio usando el comando `ls -l` y `ls -ld` respectivamente.

```bash
ls -l ~/archivo1.txt
```

Resultado:
```bash
-rw-r--r-- 1 usuario1 usuario1 19 Aug  3 12:34 /home/usuario1/archivo1.txt
```

```bash
ls -ld ~/directorio1
```

Resultado:
```bash
drwxr-xr-x 2 usuario1 usuario1 4096 Aug  3 12:34 /home/usuario1/directorio1
```

### 3. Modificar Permisos usando `chmod` con Modo Numérico
Cambia los permisos del `archivo1.txt` para que sólo `usuario1` pueda leer y escribir (permisos `rw-`), el grupo pueda leer (permisos `r--`) y nadie más pueda hacer nada.

```bash
chmod 640 ~/archivo1.txt
```

Verifica los permisos:

```bash
ls -l ~/archivo1.txt
```

Resultado:
```bash
-rw-r----- 1 usuario1 usuario1 19 Aug  3 12:34 /home/usuario1/archivo1.txt
```

### 4. Modificar Permisos usando `chmod` con Modo Simbólico
Agrega permiso de ejecución al propietario del `archivo2.txt`.

```bash
chmod u+x ~/directorio1/archivo2.txt
```

Verifica los permisos:

```bash
ls -l ~/directorio1/archivo2.txt
```

Resultado:
```bash
-rwxr--r-- 1 usuario1 usuario1 19 Aug  3 12:34 /home/usuario1/directorio1/archivo2.txt
```

### 5. Cambiar el Grupo Propietario
Cambia el grupo propietario de `archivo2.txt` a `grupo1`.

```bash
sudo chown :grupo1 ~/directorio1/archivo2.txt
```

Verifica el grupo propietario:

```bash
ls -l ~/directorio1/archivo2.txt
```

Resultado:
```bash
-rwxr--r-- 1 usuario1 grupo1 19 Aug  3 12:34 /home/usuario1/directorio1/archivo2.txt
```

### 6. Configurar Permisos de Directorio
Cambia los permisos del `directorio1` para que sólo el propietario pueda entrar (permisos `rwx`), el grupo pueda listar contenidos pero no entrar (permisos `r--`), y otros no puedan hacer nada.

```bash
chmod 744 ~/directorio1
```

Verifica los permisos:

```bash
ls -ld ~/directorio1
```

Resultado:
```bash
drwxr--r-- 2 usuario1 usuario1 4096 Aug  3 12:34 /home/usuario1/directorio1
```

### 7. Comprobación de Acceso
Intenta acceder al `archivo1.txt` y `directorio1/archivo2.txt` como `usuario2`. Nota cómo el permiso de directorio afecta el acceso a los archivos dentro de él.

```bash
# Cambiar a usuario2
su - usuario2

# Intentar acceder a archivo1.txt
cat /home/usuario1/archivo1.txt
# Esperado: Permiso denegado

# Intentar acceder a archivo2.txt
cat /home/usuario1/directorio1/archivo2.txt
# Esperado: Permiso denegado debido a los permisos del directorio
```

### 8. Verificación Final
Verifica los permisos y propietario de los archivos y directorio nuevamente con `ls -l` y `ls -ld`.

```bash
# Cambiar a usuario1
su - usuario1

# Verificar archivo1.txt
ls -l ~/archivo1.txt
```

Resultado:
```bash
-rw-r----- 1 usuario1 usuario1 19 Aug  3 12:34 /home/usuario1/archivo1.txt
```

```bash
# Verificar directorio1
ls -ld ~/directorio1
```

Resultado:
```bash
drwxr--r-- 2 usuario1 usuario1 4096 Aug  3 12:34 /home/usuario1/directorio1
```

```bash
# Verificar archivo2.txt
ls -l ~/directorio1/archivo2.txt
```

Resultado:
```bash
-rwxr--r-- 1 usuario1 grupo1 19 Aug  3 12:34 /home/usuario1/directorio1/archivo2.txt
```
```

Guarda este contenido en tu archivo `.md` y súbelo a tu repositorio de GitHub en el folder `actividad3`. Luego, proporciona el link al folder `actividad3` a tus estudiantes para que puedan acceder y completar la actividad.