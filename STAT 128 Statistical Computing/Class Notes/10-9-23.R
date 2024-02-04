# Mean squared error
# y: our actual data
# y^: predicted data (aka 'y hat' lol)
# to find a good prediction of the gap between data: (y - y^)^2 

# sample data
y <- c(0,1,1,2)
x <- c(0,0,2,2)
plot(x,y)

model <- lm(y ~ x) # get an average of the differences
yhat <- predict(model,data.frame(x = x))

# MSE: Mean Squared Error
mean((y - yhat)^2)

# random notes for hw:
# MAD: mean (the average), absolute (value), deviation (diff b/t each data point & mean)