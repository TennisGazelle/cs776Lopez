# Gnuplot script file for plotting data in file "force.dat"
      # This file is called   force.p
      set   autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
      set xlabel "Iteration (Generation tick)"
      set ylabel "Fitness"
      #set key 0.01,100
      #set label "Yield Point" at 0.003,260
      #set arrow from 0.0028,250 to 0.003,280
      set yr [0:40]
      set xr [0:500]
      set terminal png size 600,600 enhanced font 'Verdana,10'

    set title "Dejong Function 3 for 0.0001 Mutation Probability and 0.2 Crossover Probability"
    set output 'dejong_3_smallMut_smallCross.png'
    plot "../out/Dejong_3_0.000100_0.200000" using 1:2 title 'Min' with linespoints , \
         "../out/Dejong_3_0.000100_0.200000" using 1:3 title 'Max' with linespoints , \
         "../out/Dejong_3_0.000100_0.200000" using 1:4 title 'Avg' with linespoints

    set title "Dejong Function 3 for 0.01 Mutation Probability and 0.2 Crossover Probability"
    set output 'dejong_3_largeMut_smallCross.png'
    plot "../out/Dejong_3_0.010000_0.200000" using 1:2 title 'Min' with linespoints , \
         "../out/Dejong_3_0.010000_0.200000" using 1:3 title 'Max' with linespoints , \
         "../out/Dejong_3_0.010000_0.200000" using 1:4 title 'Avg' with linespoints

    set title "Dejong Function 3 for 0.0001 Mutation Probability and 0.99 Crossover Probability"
    set output 'dejong_3_smallMut_largeCross.png'
    plot "../out/Dejong_3_0.000100_0.990000" using 1:2 title 'Min' with linespoints , \
         "../out/Dejong_3_0.000100_0.990000" using 1:3 title 'Max' with linespoints , \
         "../out/Dejong_3_0.000100_0.990000" using 1:4 title 'Avg' with linespoints

    set title "Dejong Function 3 for 0.01 Mutation Probability and 0.99 Crossover Probability"
    set output 'dejong_3_largeMut_largeCross.png'
    plot "../out/Dejong_3_0.010000_0.990000" using 1:2 title 'Min' with linespoints , \
         "../out/Dejong_3_0.010000_0.990000" using 1:3 title 'Max' with linespoints , \
         "../out/Dejong_3_0.010000_0.990000" using 1:4 title 'Avg' with linespoints
