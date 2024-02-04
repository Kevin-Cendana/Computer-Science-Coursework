# goal: pivot data to make it tidy

library(tidyverse)

b2 <- billboard |> pivot_longer ( # pivot (original is 317x79, new is 24092x5)
  cols = starts_with("wk"),       # select all cols starting with 'wk;
  names_to = "week",              # store them all in a new col 'weeks'
  values_to = "rank"              # use the values from 'rank'
) |> mutate(                      # after, mutate modifies or adds columns
  week = parse_number(week)      # new week column has values 1,2,3.. from wk1,w2,w3..
)
ggplot(b2,mapping=aes(x=week,y=rank,group=track)) + geom_line()

# How many rank values are missing?
r = b2 |> pull(rank)
mean(is.na(r)) # 0.7797194 this means 78% of data is missing a value!

b3 <- filter(b2, week<=10)
ggplot(b3, mapping = aes(x = week, y = rank, group = track)) + 
  geom_line(alpha = 0.2, color = "blue") +
  scale_y_reverse()

# Finding some #1 songs
filter(b2, rank == 1) |> distinct(track) |> pull(track)

# Find all data for no 1 tracks
b4 <- filter(b2, track %in% no1track)

b5 <- billboard
q = b5 |> pull('wk')
