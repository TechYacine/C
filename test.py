import numpy as np
import matplotlib.pyplot as plt

# Définition d'une grille de points
x = np.linspace(-10, 10, 400)
y = np.linspace(-10, 10, 400)
X, Y = np.meshgrid(x, y)

# Calcul de la distance à l'origine dans le plan (x, y)
# Pour une ligne de charge infini le long de l'axe z, la projection dans le plan est radiale à partir de l'origine.
r = np.sqrt(X**2 + Y**2)

# Pour éviter une division par zéro au centre
r[r == 0] = 1e-6

# On définit le vecteur champ électrique.
# Pour un fil infini, la formule du champ est : E(r) = k / r, mais ici, on ne s'intéresse qu'à la direction.
# On calcule ainsi des composantes proportionnelles à (X, Y) / r^2 ce qui donne une direction radiale.
Ex = X / r**2
Ey = Y / r**2

# Création du diagramme de lignes de champ
plt.figure(figsize=(7, 7))
plt.streamplot(X, Y, Ex, Ey, density=1.5, linewidth=1, arrowsize=1.5, arrowstyle='->')
plt.title("Champ électrique radial d'une ligne de charge", fontsize=14)
plt.xlabel("x", fontsize=12)
plt.ylabel("y", fontsize=12)
# On ajoute une ligne verticale pour représenter le fil (situé sur x=0)
plt.axvline(0, color='k', linestyle='--', linewidth=1, label='Fil de charge')
plt.legend()
plt.grid(True)
plt.show()
