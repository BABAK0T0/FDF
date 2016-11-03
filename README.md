# FDF - WIREFRAME

This project consists to create a graphical representation of a land by wireframe("Fil De Fer - FDF" in French) by connecting different points (x, y, z) by segments.
The land will be stocked in a file passed in parameters.

### Installing

Clone the project

```
git clone https://github.com/BABAK0T0/FDF
```

Then execute Makefile

```
make re
```

### Running

Choose a map in folder "maps" to print or create an other with ".fdf" extenstion

```
./fdf maps/example.fdf
```

### Events

KEYS | DESCRIPTION
:-- |:-:| --:
`ESC` | Exit the program
`ARROW` | Move map(x,y)
`+ / -` | Zoom
`Page up / Page down` | Move map(z)
`C` | Random color

### Example

![maps_example][/Users/nrandria/Desktop/Screen\ Shot\ 2016-11-03\ at\ 4.28.21\ PM.png]

### Deployment

Develop for UNIX systems

### Built With

* [Minilibx] - The framework for graphical user interface development

