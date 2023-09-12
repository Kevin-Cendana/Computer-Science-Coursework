library(tidyverse)
# Goal: Understand these functions:
# filter, group_by, summarize, mutate, select, rename, relocate

#mpg data
mpg

#find all the cars made after 2000
filter(mpg, year >= 2000)

#select() which columns to keep
select(mpg, manufacturer, hwy, cty)
mpg |> select(manufacturer, hwy, cty)

#changing order of the columns in select
mpg2 <- mpg |> select(manufacturer, hwy, cty)

#which manufacturer has the most fuel efficient cars? how to find out?
audi <- mpg2 |> filter(manufacturer == "audi") |> select(hwy) |> data.frame()
audi <- audi [,1] #extracting vector of data
mean(audi)

honda <- mpg2 |> filter(manufacturer == "honda") |> select(hwy) |> data.frame()
honda <- honda[,1] #extracting the vector of data
mean(honda)

#which manufacturers?
mpg2 |> count(manufacturer)

#group_by (much more clear than copy pasting the above for each manufacturer)
mpg2 |> group_by(manufacturer) |> summarize(avg_hwy = mean(hwy))

#find vehicle with the best hwy mpg in each class
mpg |> count(class)
mpg |> 
  group_by(class) |> 
  summarize(max_mpg = max(hwy))

#what do you search for in google?
# r dplyr max include whole row
# r dplyr summarize include whole row
# r dplyr summarize return all columns

#try to find most fuel efficient car
mpg |> filter(hwy == 44) #hard coding
mpg |>
  mutate(avg_mpg = (hwy + cty ) / 2)