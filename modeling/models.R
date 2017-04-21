library(overseer)


models <- Overseer$new()

#pull in the model file here
models$add_model_file("01_mpa_shum_adults.cpp")
models$add_model_file("02_mpa_guellec_adults.cpp")
models$add_model_file("03_mpa_staatz_adults.cpp")
models$add_model_file("05_mpa_vanhest_adults.cpp")
models$add_model_file("13_mpa_dewinter_adults.cpp")

models