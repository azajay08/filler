#! /usr/bin/env bash

echo "\n\n-----*****superjeannot map02*****-----\n\n"

for i in {1..5}; do ./filler_vm -f maps/map02 -p1 players/superjeannot.filler -p2 ../ajones.filler -q; done