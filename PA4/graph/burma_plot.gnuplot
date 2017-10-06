# Gnuplot script file for plotting data in file "force.dat"
      set   autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
      set xlabel "Iteration (Generation tick)"
      set ylabel "Fitness"

      set yr [0:50]
      set xr [0:500]
      set terminal png size 600,600 enhanced font 'Verdana,10'
      
      set title "Burma for 0.0001 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_smallMut_smallCross.png'
      plot "../out/Burma_0.000100_0.200000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.000100_0.200000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.000100_0.200000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.001 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_mediumMut_smallCross.png'
      plot "../out/Burma_0.001000_0.200000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.001000_0.200000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.001000_0.200000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.01 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_largeMut_smallCross.png'
      plot "../out/Burma_0.010000_0.200000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.010000_0.200000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.010000_0.200000.tsv" using 1:4 title 'Avg' with linespoints

      set title "Burma for 0.0001 Mutation Probabiltiy and 0.67 Crossover Probabiltiy"
      set output 'burma/burma_smallMut_mediumCross.png'
      plot "../out/Burma_0.000100_0.670000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.000100_0.670000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.000100_0.670000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.001 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_mediumMut_mediumCross.png'
      plot "../out/Burma_0.001000_0.670000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.001000_0.670000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.001000_0.670000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.01 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_largeMut_mediumCross.png'
      plot "../out/Burma_0.010000_0.670000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.010000_0.670000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.010000_0.670000.tsv" using 1:4 title 'Avg' with linespoints

      set title "Burma for 0.0001 Mutation Probabiltiy and 0.99 Crossover Probabiltiy"
      set output 'burma/burma_smallMut_largeCross.png'
      plot "../out/Burma_0.000100_0.990000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.000100_0.990000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.000100_0.990000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.001 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_mediumMut_largeCross.png'
      plot "../out/Burma_0.001000_0.990000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.001000_0.990000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.001000_0.990000.tsv" using 1:4 title 'Avg' with linespoints
      set title "Burma for 0.01 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set output 'burma/burma_largeMut_largeCross.png'
      plot "../out/Burma_0.010000_0.990000.tsv" using 1:2 title 'Min' with linespoints , \
            "../out/Burma_0.010000_0.990000.tsv" using 1:3 title 'Max' with linespoints , \
            "../out/Burma_0.010000_0.990000.tsv" using 1:4 title 'Avg' with linespoints
