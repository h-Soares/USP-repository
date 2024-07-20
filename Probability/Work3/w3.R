is_in_IC <- function(IC, value) {
    lower_bound <- IC[1]
    upper_bound <- IC[2]
    return(value >= lower_bound && value <= upper_bound)
}

# 43
# Confidence Interval for the mean. Built with Normal(0, 25) (sd = 5) and Normal(0,1), Gama = 0.95, X_ for the mean
IC1 <- function(samples) {
    samples_mean <- mean(samples)
    lower_bound <- samples_mean - 2.191
    upper_bound <- samples_mean + 2.191
    interval <- c(lower_bound, upper_bound)
    return(interval)
}

p_correct_IC1 <- function(number_IC) {
    real_mean = 0
    correct_IC = 0
    for(i in 1:number_IC) {
        samples <- rnorm(n = 20, mean = real_mean, sd = 5)
        ic <- IC1(samples)

        if(is_in_IC(ic, real_mean))
            correct_IC <- correct_IC + 1
    }
    return(correct_IC / number_IC)
}

for(i in 1:5)
    print(p_correct_IC1(100))

# 44
# Confidence Interval for the lambda. Built with Normal(0,1), Gama = 0.95, X_ for the lambda
IC2 <- function(samples) {
    samples_mean <- mean(samples)
    lower_bound <- samples_mean - 1.96 * sqrt(samples_mean / 30)
    upper_bound <- samples_mean + 1.96 * sqrt(samples_mean / 30)
    interval <- c(lower_bound, upper_bound)
    return(interval)
}

p_correct_IC2 <- function(number_IC) {
    real_lambda = 3.25
    correct_IC = 0

    for(i in 1:number_IC) {
        samples <- rpois(n = 30, lambda = real_lambda)
        ic <- IC2(samples)

        if(is_in_IC(ic, real_lambda))
            correct_IC <- correct_IC + 1
    }
    return(correct_IC / number_IC)
}

for(i in 1:5)
    print(p_correct_IC2(100))