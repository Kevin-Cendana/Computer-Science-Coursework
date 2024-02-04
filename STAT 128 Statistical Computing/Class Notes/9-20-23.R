# Goal: Join 2 DFs together

library(countrycode)
library(tidyverse)

d <- tibble(
  name = c("Clark", "Piu", "Alisa", "Yeji", "Harry"),
  country = c("US", "VN", "UA", "KR", "US")
)

country <- tibble(
  abbr = c("US", "VN", "UA", "KR"),
  name = c("United States", "Vietname", "Ukraine", "South Korea"),
  region = c("America", "Asia", "Europe", "Asia")
)

d <- tibble(
  names = c("Clark", "Maria", "Inja"),
  country = c("US", "MX", "KR")
)

countries <- codelist |> select(country.name.en, iso2c, region)

d |> left_join(countries, by = join_by(country == iso2c))