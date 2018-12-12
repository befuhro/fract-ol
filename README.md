# Fract'ol

## Objectifs
Fract'ol est projet d'école qui reproduit des différentes fractales  
Il est realisé en C à l'aide de la minilibx (librairie minimaliste propre a l'ecole 42)  
Les fractales que j'ai réalisé pour ce projet sont celles de mandelbrot, julia (qui sont imposées) et celle du burningship (optionnelle)  
Pour la partie bonus, j'ai implémenter le multithreading grâce à la librairie pthread et différentes couleurs disponibles  

## Contraintes techniques  
Ce projet à été réalisé sur un imac et ne fonctionne malheureusement pas sous linux  

## Lancement du programme  
Un Makefile est présent sur le repo, il faudra donc utiliser la commande suivant pour compiler le projet
```
make
```
Si vous lancer le binaire, vous pourrez voir l'usage pour visualiser les différentes fractales.
```
./fractol
usage:	fractol mandelbrot
	fractol julia
	fractol burningship
```

## Utilisation du programme 
* Changer de couleurs: clique gauche et clique droit  
* Zoommer et dézoomer: molette de la souris  
* Stoper le mouvement de julia: L
* Déplacement: flèches
 
## Notions abordees
* Les nombres complexes  
* Le plan complexe  
* Les fractales  
* Multithreading  
* Capture de différents évènements

## Rendu  
### Mandelbrot  
![alt text](https://github.com/befuhro/fract-ol/blob/master/pictures/Mandelbrot.png)
  
### Julia
![alt text](https://github.com/befuhro/fract-ol/blob/master/pictures/Julia1.png)
![alt text](https://github.com/befuhro/fract-ol/blob/master/pictures/Julia2.png)
  
## Burningship
![alt text](https://github.com/befuhro/fract-ol/blob/master/pictures/Burningship1.png)
![alt text](https://github.com/befuhro/fract-ol/blob/master/pictures/Burningship2.png)
