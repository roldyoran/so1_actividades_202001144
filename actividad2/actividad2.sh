#!/bin/bash

# Se ingresa el usuario de github
GITHUB_USER=${GITHUB_USER:-"roldyoran"}

# Consultar la API de GitHub
response_json=$(curl -s "https://api.github.com/users/$GITHUB_USER")

 
# Verificar si la consulta no tuvo un error - (sudo apt-get install jq)
if [[ $(echo "$response_json" | jq -r .message) == "Not Found" ]]; then
  echo "Usuario no encontrado"
  exit 1
fi


# Extraer datos del JSON (sudo apt-get install jq)
user_id=$(echo "$response_json" | jq -r .id)
created_at=$(echo "$response_json" | jq -r .created_at)

# Crear el mensaje 
mensaje="Hola $GITHUB_USER. User ID: $user_id. Cuenta fue creada el: $created_at."

# Imprimir el mensaje antes de guardarlo
echo "$mensaje"


# Crear el log file con la fecha actual
fecha=$(date +%Y-%m-%d)
log_dir="/tmp/$fecha"
mkdir -p "$log_dir"
echo "$mensaje" > "$log_dir/saludos.log"
echo "Mensaje Guardado Exitosamente"

# Al finalizar ejecutar
# crontab -e
# Al final del archivo escribir y guardar:
# */5 * * * * /home/sopes/activadad2.sh