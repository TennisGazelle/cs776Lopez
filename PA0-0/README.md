## PA0, Part 1
The missionaries and cannibals problem

If there is a valid solution to the initial conditions of this problem, the output will look something like this:
```
Queue has: 1 - History has: 0
Queue has: 3 - History has: 1
Queue has: 3 - History has: 2
Queue has: 3 - History has: 3
Queue has: 2 - History has: 4
Queue has: 2 - History has: 5
Queue has: 2 - History has: 6
Queue has: 2 - History has: 7
Queue has: 2 - History has: 8
Queue has: 2 - History has: 9
Queue has: 2 - History has: 10
Queue has: 2 - History has: 11
Queue has: 2 - History has: 12
Queue has: 2 - History has: 13
Queue has: 2 - History has: 14
Queue has: 2 - History has: 15
Queue has: 2 - History has: 16
Queue has: 2 - History has: 17
Queue has: 2 - History has: 18
Queue has: 3 - History has: 19
Queue has: 4 - History has: 20
solution: State [11]
               Left                Right
   Cannibals:  0                   3
Missionaries:  0                   3
  Boat is on:  RIGHT
   State [10]
                  Left                Right
      Cannibals:  1                   2
   Missionaries:  1                   2
     Boat is on:  LEFT
      State [9]
                     Left                Right
         Cannibals:  1                   2
      Missionaries:  0                   3
        Boat is on:  RIGHT
         State [8]
                        Left                Right
            Cannibals:  3                   0
         Missionaries:  0                   3
           Boat is on:  LEFT
            State [7]
                           Left                Right
               Cannibals:  2                   1
            Missionaries:  0                   3
              Boat is on:  RIGHT
               State [6]
                              Left                Right
                  Cannibals:  2                   1
               Missionaries:  2                   1
                 Boat is on:  LEFT
                  State [5]
                                 Left                Right
                     Cannibals:  1                   2
                  Missionaries:  1                   2
                    Boat is on:  RIGHT
                     State [4]
                                    Left                Right
                        Cannibals:  1                   2
                     Missionaries:  3                   0
                       Boat is on:  LEFT
                        State [3]
                                       Left                Right
                           Cannibals:  0                   3
                        Missionaries:  3                   0
                          Boat is on:  RIGHT
                           State [2]
                                          Left                Right
                              Cannibals:  2                   1
                           Missionaries:  3                   0
                             Boat is on:  LEFT
                              State [1]
                                             Left                Right
                                 Cannibals:  2                   1
                              Missionaries:  2                   1
                                Boat is on:  RIGHT
                                 State [0]
                                                Left                Right
                                    Cannibals:  3                   0
                                 Missionaries:  3                   0
                                   Boat is on:  LEFT

```

Otherwise, the output will say...
```
Game space searched, solution not found
```

### Building
Please see the attached makefile found in `build`.
```
cd build
make
```
You will see `missionary-canibal.out` as your output.

### Running
You may run `make run` which runs the following command.
```
./missionary-canibal.out
```
