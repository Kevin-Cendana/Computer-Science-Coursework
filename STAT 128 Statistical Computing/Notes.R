library(tidyverse)
library(nycflights13)

#sequence
5 |> seq(20) #prints 5 to 20
seq(20) #prints 1 to 20

#retrieving and removing base
base(pi) #prints 3.14
rm(pi) #removing pi

#filtering 
# df |> filter(attribute = 0)
# filter(df, attribute = 0)
flights |> filter(dep_delay > 120)
filter(flights, dep_delay > 120)

#filtering boolean logic
# filter(df, condition)
# df %>% filter (condition)
filter(flights, (month == 1 | month == 2))
flights %>% filter (month == 1 | month == 2)


# learn tibble, vector