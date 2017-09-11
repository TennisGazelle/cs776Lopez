## PA0, Part 1
The key logging problem

### Building
Please see the attached makefile found in `build`.
```bash
sudo apt-get install libmpich-dev
cd build
make
```
You will see `missionary-canibal.out` as your output.

### Running
You may run `make runParallel` which runs the following command.
```bash
mpirun -n x -host localhost ./solver
```
where x is the number of cores with which this run.
By default, to run with only one core, you may also just call `make run`.
