#code by: Juan Pablo Diaz Lemus
#import SerialComun
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np



df=pd.read_csv('C:\\Users\\57320\\Desktop\\Prueba\\DatosVelocidad.csv')
df2=pd.read_csv('C:\\Users\\57320\\Desktop\\Prueba\\DatosVelocidadControlada.csv')

datosArr=df.to_numpy()
datosArr2=df2.to_numpy()
datosArr=datosArr.reshape((1,300))
datosArr2=datosArr2.reshape((1,300))


referencia=np.zeros(len(datosArr2[0]))+120
plt.style.use('bmh')

fig,axes=plt.subplots()

axes.plot(datosArr2[0][5:]+10, label='Velocidad de giro en RPM Controlada')
axes.plot(referencia,label='Referencia del controlador')
axes.legend(loc=1)
#axes.plot(datosArr1[0][5:], label='Velocidad de giro en RPM')
axes.set_title('Velocidad de giro con controlador')
print(referencia)
plt.show()

