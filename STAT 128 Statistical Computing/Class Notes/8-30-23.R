# library(palmerpenguins)
# library(tidyverse)
# 
# ggplot(data = mpg, mapping = aes(x = class, y = hwy)) +
#   geom_boxplot() +
#   labs(x = "class of vehicle",
#        y = "highway fuel efficiency (mpg)")


# 1 penguins
# How many rows are in penguins? How many columns?
      # 344 rows, 8 columns
#   What does the bill_depth_mm variable in the penguins data frame describe? Read the help for ?penguinsLinks to an external site. to find out.
      # "a number denoting bill depth (millimeters)"
# Make a scatterplot of bill_depth_mm vs. bill_length_mm. That is, make a scatterplot with bill_depth_mm on the y-axis and bill_length_mm on the x-axis. Describe the relationship between these two variables.
# What happens if you make a scatterplot of species vs. bill_depth_mm? What might be a better choice of geom?
#   Write the code to create the following graph. What does it show?
#   

library(palmerpenguins)
penguins
plot(bill_length_mm, bill_depth_mm, main = "penguin stuff",
     xlab = "bill length (mm)",
     ylab = "bill depth (mm)",
     pch = 19, frame = FALSE)

# scatter plot example
x <- mtcars$wt
y <- mtcars$mpg
# # Plot with main and axis titles
# # Change point shape (pch = 19) and remove frame.
plot(x, y, main = "Main title",
     xlab = "X axis title", ylab = "Y axis title",
     pch = 19, frame = FALSE)
# # Add regression line
plot(x, y, main = "Main title",
     xlab = "X axis title", ylab = "Y axis title",
     pch = 19, frame = FALSE)


abline(lm(y ~ x, data = mtcars), col = "blue")
