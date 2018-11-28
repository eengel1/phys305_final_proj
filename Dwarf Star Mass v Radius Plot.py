import numpy as np
import matplotlib.pyplot as plt
alldata = np.genfromtxt("dwarf_star.dat")
xarray = alldata[:, 0]
yarray = alldata[:, 1]
plt.plot(xarray, yarray, 'r-', lw=2, label="m v. r")
plt.xlabel('Mass (g)')
plt.ylabel('Radius (cm)')
plt.legend()
plt.show()
