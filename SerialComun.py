import serial
import pandas as pd

# Configura el puerto serie
ser = serial.Serial('COM8', 9600)  # Reemplaza 'COMx' con el nombre de tu puerto serie

# Lee los datos del puerto serie
data = []
for i in range(300):
    try:
        line = ser.readline().decode('utf-8').strip()
        print(line)
        if line:
            data.append(float(line))
    except KeyboardInterrupt:
        break

# Cierra el puerto serie
ser.close()

# Crea un DataFrame con los datos y guarda en un archivo CSV
df = pd.DataFrame({'VelocidadGiro': data})
#df.to_csv('C:\\Users\\57320\\Desktop\\Prueba\\DatosVelocidadControlada.csv', index=False)

