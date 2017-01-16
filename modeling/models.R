library(overseer)


models <- Overseer$new()

#pull in the model file here
models$add_model_file("ex1.cpp")
models$add_model_file("ex2.cpp")

models