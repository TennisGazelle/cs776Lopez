# Gnuplot script file for plotting data in file "force.dat"
      # This file is called   force.p
      set   autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
      set title "Dejong Function 1 for 0.0001 Mutation Probabiltiy and 0.2 Crossover Probabiltiy"
      set xlabel "Iteration (Generation tick)"
      set ylabel "Fitness"
      #set key 0.01,100
      #set label "Yield Point" at 0.003,260
      #set arrow from 0.0028,250 to 0.003,280
      set yr [0:100]
      set xr [0:500]
      set terminal png size 600,600 enhanced font 'Verdana,10'
      set output 'introduction.png'

      plot "../out/Dejong_1_0.000100_0.200000" using 1:2 title 'Min' with linespoints , \
           "../out/Dejong_1_0.000100_0.200000" using 1:3 title 'Max' with linespoints , \
           "../out/Dejong_1_0.000100_0.200000" using 1:4 title 'Avg' with linespoints

    #set output 'intro2.png'
    #plot "../out/Dejong_1_0.001000_0.200000" using 1:2 title 'Min' with linespoints , \
    #       "../out/Dejong_1_0.001000_0.200000" using 1:3 title 'Max' with linespoints , \
    #       "../out/Dejong_1_0.001000_0.200000" using 1:4 title 'Avg' with linespoints