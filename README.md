# filler - (Hive Helsinki - 42)

Filler is a project at Hive Helsinki that requires us to make a player for the game Filler...

Filler is an algorithmic game which consists of filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.

Each successfully placed piece yields a number of points, the goal of the game is to get the best score possible. Each player has to place as many pieces as possible while attempting to prevent their opponent from doing the same. At the end of the game, the one with the most points wins the match...

## Game format

In the project, you are provided with a VM (which is a ruby script), along with some pre made players. Player 1 will be aissigned `O` and Player 2 `X`. The VM controls the game, It provides each player with the updated map and a piece. The player must then read the map and give back to the VM coordinates for where to place the piece that was given to the player. When a player can no longer place any more piece or if the piece they have recieved will not fit in a valid place, the player will give the coordinates of `[0 0]`. This will then tell the VM that the player is out of the game. The game will continue with the remaining player until they cannot place any more pieces. The pieces can vary depending on the size of the map. They can look something like this ...

<img width="117" alt="Screenshot 2022-10-12 at 14 14 39" src="https://user-images.githubusercontent.com/86073849/195328693-b44a52d2-a630-4e51-8b9f-6924b97926ea.png">     <img width="117" alt="Screenshot 2022-10-12 at 14 14 27" src="https://user-images.githubusercontent.com/86073849/195328735-88699323-d6b8-4b45-a23b-447215b8afba.png">

The `.` represents and empty space whereas the `*` represents what will but placed on the map. They must be placed with the coordinates of starting point of the piece and not where there is a `*` within the piece.

## Strategy

My strategy is to attack the enemy and try to block them in. To do this, I have to read the map and and create a 2D integer array filled with respective values. `0` being an empty space, `-1` being one of my pieces, `-2` being the enemy pieces. Once I have the locations of where mine and the enemy pieces are, I can then create a heatmap. I do it in a way that places closest to the enemy will be a value of `1` then `2`, and so on. It will make something like this....

<img width="236" alt="Screenshot 2022-10-12 at 14 03 28" src="https://user-images.githubusercontent.com/86073849/195327756-460a3f7e-7855-4cfc-a925-bee9ae8d309c.png">

look like this ....

<img width="252" alt="Screenshot 2022-10-12 at 14 26 52" src="https://user-images.githubusercontent.com/86073849/195331079-7dbd316b-feb7-4ccb-9e7a-970dabae2766.png">

then this..

<img width="372" alt="Screenshot 2022-10-12 at 13 51 12" src="https://user-images.githubusercontent.com/86073849/195326031-63d5bb13-04de-4b8f-a0ca-e79cef2fc012.png">

After I set the heatmap, I will then read the piece given to me. I will read it is the same way I read the map. I create a 2D int array and assign values. A `.` will be given the value `0` and the `*` will be given the value `1`. Then I will go the solver part of it. I will go along the map coordinates looking for a valid place to put the piece. If it finds a valid place, it will add up all the heatmap values within the size of that piece on the map and save them to a variable. It will check every place of the map. At the end of all that. It will go with whatever had the smallest overall value. The reason I do this is because I want to put pieces as close as possible to the enemy so that I can eventually block them in making it impossible for them to place anymore pieces.
