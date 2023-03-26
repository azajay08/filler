# Filler Visualiser

https://user-images.githubusercontent.com/86073849/197409618-cf82e8b3-edb3-466e-bdd2-2b73ccabfae6.mov 

This is a visualiser for the project (filler) in Hive Helsinki. The project is written in C. For the purpose of the project, the game (filler) is displayed on the standard output, but it doesn't really look pretty. So I wanted to spruce it up a bit and dip my toe in the world of python by creating
a visualiser to go with my project using `Pygame`.

To use it, clone the repository into root of your project repository..
```
git clone https://github.com/azajay08/Visualizer.git Visualizer
```


To run the visualiser, it needs to be run with python3 and have Pygame installed. You need to pipe it at the end of the regular command used to run a normal match on in the terminal. After the pipe, run it like a python file with the correct path for example...
`./<path/filler_vm> -f <path/map> -p1 <path/player1> -p2 <path.player2> | python3 <path/filler_vis.py>`

for example from the root of the project ...
```
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 resources/players/grati.filler | python3 Visualizer/filler_vis.py
```
