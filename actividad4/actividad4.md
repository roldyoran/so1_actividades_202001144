# Actividad 4 - Systemd Unit


Este documento describe cómo instalar y configurar un servicio `systemd` que ejecuta un script de Bash infinitamente, imprimiendo un saludo y la fecha actual.

## 1. Crear el Script

Se crea un script en Bash que imprimirá un saludo y la fecha actual en un bucle infinito:

```bash
#!/bin/bash

while true; do
    echo "Hola, la fecha actual es $(date)"
    sleep 1
done
```

Luego se guarda este script en una ubicación segura, /usr/local/bin/saludo.sh y se le da permisos de ejecucion.

```bash
sudo chmod +x /usr/local/bin/saludo.sh
```



# 2. Crear el Archivo de la Unidad de Servicio

Se crea un archivo de unidad para systemd llamado saludo.service en el directorio /etc/systemd/system/:


```bash
sudo nano /etc/systemd/system/saludo.service
```

Agregar el siguiente contenido al archivo:
```ini
[Unit]
Description=Servicio que imprime un saludo y la fecha actual
After=network.target

[Service]
ExecStart=/usr/local/bin/saludo.sh
Restart=always

[Install]
WantedBy=multi-user.target

```

# 3. Habilitar e Iniciar el Servicio

Ahora se habilita el servicio para que se inicie automáticamente al arrancar el sistema:

```bash
sudo systemctl enable saludo.service
```
Inicie el servicio manualmente:
```bash
sudo systemctl start saludo.service
```

4. Verificar los Logs del Servicio

Para revisar los logs generados por el servicio, se usa:
```bash
sudo journalctl -u saludo.service
```
# Resultado en terminal:
![ImagenLogs](/actividad4/logs.png)
