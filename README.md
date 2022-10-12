# filler - (Hive Helsinki - 42)

Filler is a project at Hive Helsinki that requires us to make a player for the game Filler...

Filler is an algorithmic game which consists of filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.

Each successfully placed piece yields a number of points, the goal of the game is to get the best score possible. Each player has to place as many pieces as possible while attempting to prevent their opponent from doing the same. At the end of the game, the one with the most points wins the match...

## Game format

In the project, you are provided with a VM (which is a ruby script), along with some pre made players. Player 1 will be aissigned `O` and Player 2 `X`. The VM controls the game, It provides each player with the updated map and a piece. The player must then read the map and give back to the VM coordinates for where to place the piece that was given to the player. When a player can no longer place any more piece or if the piece they have recieved will not fit in a valid place, the player will give the coordinates of `[0 0]`. This will then tell the VM that the player is out of the game. The game will continue with the remaining player until they cannot place any more pieces.

## Strategy

My stategy was to read the map and and create a 2D integer array filled with respective values. `0` being an empty space, `-1` being one of my pieces, `-2` being the enemy pieces. Once I had the locations of where mine and the enemy pieces were, I could then create a heatmap. I did it in a way that places closest to the enemy would be a value of `1` then `2`, and so on. It would make something like this....

<img width="236" alt="Screenshot 2022-10-12 at 14 03 28" src="https://user-images.githubusercontent.com/86073849/195327756-460a3f7e-7855-4cfc-a925-bee9ae8d309c.png">

look like this ....

<img width="372" alt="Screenshot 2022-10-12 at 13 51 12" src="https://user-images.githubusercontent.com/86073849/195326031-63d5bb13-04de-4b8f-a0ca-e79cef2fc012.png">
