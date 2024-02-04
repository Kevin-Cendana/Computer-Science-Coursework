# Notes: 
# Dataset is from CSC173 Data Visualizations, featuring DFW (drop fail withdraw) rates & enrollment from 2022

library(tidyverse)
library(shiny)

# List columns of interest to keep
cols_to_keep <- c("College", "Department", "Subject", "Course", "Course Description", 
                  "Course Division", "Course Units", "Terms Offered", "Total Enrollment", 
                  "Avg Enrollment per Term", "Fall Terms", "Spring Terms", "All")

# Load data set (skip first 3 rows of header info, limit to 500 cols to load faster)
dfw_data <- read_csv("DFW_Rate_2022.csv", skip = 3, n_max = 500, col_select = cols_to_keep)

# Clean by converting to numeric values, removing white space etc
dfw_data <- dfw_data |>
  mutate(across(c("Fall Terms", "Spring Terms", "All"), ~as.numeric(gsub("%", "", .)))) |>
  na.omit() |>
  mutate(across(where(is.character), str_trim))  

# Identify numeric columns
numeric_cols <- c("Total Enrollment", "Avg Enrollment per Term", "Fall Terms", "Spring Terms", "All")

# User interface
ui <- fluidPage(
  titlePanel("CSUS Enrollment Rates 2022"),
  HTML("Made by Kevin Cendana :)"),
  sidebarLayout(
    sidebarPanel(
      selectInput("selectVariable", "Select Column:",
                  choices = numeric_cols,
                  selected = numeric_cols[1]),
      sliderInput("sampleSize", "Sample Size:",
                  min = 1,
                  max = nrow(dfw_data),
                  value = 50),
      selectInput("selectStat", "Select Statistical Measure:",
                  choices = c("Mean", "Median"),
                  selected = "Mean")
    ),
    mainPanel(
      textOutput("statText"),
      plotOutput("histPlot"),
      HTML('<a href="https://drive.google.com/file/d/17OdoY8Mm_hYTE0kjWzUzVfbVWJohxIKX/view?usp=sharing" target="_blank">Source: CSUS Drop/Fail/Withdrawal Rates for CSC 173: Data Visualizations</a>'),
    )
  ),
  tags$style(HTML("body { background-color: #f2f2f2; }")) # Background looks prettier w/ color
)


# Server logic
server <- function(input, output) {
  # Creating reactive data set based on user input
  filteredData <- reactive({
    dfw_data[, input$selectVariable, drop = FALSE]
  })
  
  # Display whatever stat user picked
  output$statText <- renderText({
    if (input$selectStat == "Mean") {
      stat_value <- mean(filteredData()[[1]], na.rm = TRUE)
      stat_name <- "Mean"
    } else if (input$selectStat == "Median") {
      stat_value <- median(filteredData()[[1]], na.rm = TRUE)
      stat_name <- "Median"
    }
    
    # Round the value to nearest hundredth
    stat_value_rounded <- round(stat_value, 2)
    
    # Determine what to print based on what the user picked
    suffix <- ifelse(input$selectVariable %in% c("Total Enrollment", "All"), 
                     " students per course",
                     "% D/F/W (Dropped, Failed, or Withdrew)")
    
    # Append % symbol for specific columns (more accurate) and add the suffix
    if (input$selectVariable %in% c("Fall Terms", "Spring Terms", "All")) {
      stat_value_text <- paste0(format(stat_value_rounded, nsmall = 2), suffix)
    } else {
      stat_value_text <- paste0(stat_value_rounded, suffix)
    }
    
    paste(stat_name, "of", input$selectVariable, ":", stat_value_text)
  })
  
  # Display w/e histogram user picked
  output$histPlot <- renderPlot({
    var_symbol <- rlang::sym(input$selectVariable) # Convert input variable to a symbol
    ggplot(filteredData(), aes(!!var_symbol)) +
      geom_histogram(bins = input$sampleSize) +
      labs(title = paste("Histogram: ", input$selectVariable),
           caption = "Histogram generated based on user selection")
  })
}

# Run :)
shinyApp(ui, server)
