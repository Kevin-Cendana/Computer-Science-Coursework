
  # assignment 1
# ~~~~~~~~~`penguins~~~~~~~~~`
# 1) How many rows are in penguins? How many columns?
      # 344 rows, 8 columns

# 2) What does the bill_depth_mm variable in the penguins data frame describe? Read the help for ?penguinsLinks to an external site. to find out.
      # "a number denoting bill depth (millimeters)"

# 3) Make a scatterplot of bill_depth_mm vs. bill_length_mm. That is, make a scatterplot with bill_depth_mm on the y-axis and bill_length_mm on the x-axis. Describe the relationship between these two variables.
  library(palmerpenguins)      # load data frame to use
  head(penguins)               # display the first few rows of dataframe
  x <- penguins$bill_length_mm # assign value to variable
  y <- penguins$bill_depth_mm  # assign value to variable
  
  # plot() arguments: 
  # plot(x data, y data, main title, x label, y label, plot character / symbol, border or no border)
  plot(x, y, main = "penguin stuff",
       xlab = "bill length (mm)",
       ylab = "bill depth (mm)",
       pch = 20, frame = FALSE)

# 4) What happens if you make a scatterplot of species vs. bill_depth_mm? What might be a better choice of geom?
    # I ran the above code from 3) but replaced the x axis with species. It showed a box plot graph which would be a better fit.
  
# 5) Write the code to create the following graph [pictured: geom box plot]. What does it show?
    # Regarding the body mass for each island, the geom box plot shows the spread with quartiles and whiskers,
    # and outliers are shown with points
  
  library(palmerpenguins)
  library(tidyverse)

  ggplot(data = penguins, mapping = aes(x = island, y = body_mass_g)) +
    geom_boxplot() +
    labs(x = "island",
         y = "body mass (g)")

# ~~~~~~~diamonds~~~~~~~
# 1)  Make a histogram of the carat variable in the diamonds dataset that is available when you load the 
  # tidyverse package. Experiment with different binwidths.  What binwidth reveals the most interesting patterns?
  install.packages("tidyverse")
  library(tidyverse)
  ggplot(diamonds, aes(x=carat)) + 
    geom_histogram(binwidth=.08, fill="skyblue", color="black", alpha=0.7) +
    labs(title="Histogram of Carat in Diamonds Dataset", x="Carat", y="Count")
  # I think a binwdith of .08 shows a good amount of data without being too overbearing.
  
# 2) Write the code to create the following graph. What does it show?
  # plot() arguments: 
  # plot(x data, y data, main title, x label, y label, plot character / symbol, border or no border)
  plot(x, y, main = "diamonds",
       xlab = "carat",
       ylab = "price in US dollars",
       pch = 20, frame = FALSE)


  
  
  